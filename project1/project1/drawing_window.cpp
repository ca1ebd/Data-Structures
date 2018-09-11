/*
    drawing_window.cpp

    Implementation code for the drawing_window class.

    author: C. Painter-Wakefield

    last modified: 8/31/2018
*/

#include <string>
#include <thread>
#include <cmath> 

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "drawing_window.h"

using namespace std;
using namespace sf;


// resize the window
void drawing_window::resize(unsigned width, unsigned height) {
    _draw_mtx.lock();
    _width = width;
    _height = height;
    _setup();
    _draw_mtx.unlock();
    if (_window != nullptr) {
        _window->setSize({_width, _height});
        _window->setView(View(FloatRect(0, 0, _width, _height)));
    }
}

// draw a point on the drawing window, which will later get drawn
// on the SFML RenderWindow 
void drawing_window::set_color(unsigned x, unsigned y, char r, char g, char b) {
    unsigned pw = ceil(_width / double(PATCH_SIZE));
    unsigned ph = ceil(_height / double(PATCH_SIZE));

    _patches[(x / PATCH_SIZE) * ph + (y / PATCH_SIZE)].set_point(x % PATCH_SIZE, y % PATCH_SIZE, r, g, b);
}

// start running the drawing window - note you must handle any
// user interaction in a separate loop!
void drawing_window::start() {
    if (_window == nullptr) _open();
    _is_running = true;

    clock_t last_draw = 0;

    // run the program as long as the window is open, redrawing approximately
    // 60 times per second
    while (_is_running) {
        // process pending events
        _process_events();

        // check that enough time has passed to worry about redraw
        clock_t now = clock();
        if (last_draw != 0 && (now - last_draw) / double(CLOCKS_PER_SEC) < (1.0 / 60.0)) {
            unsigned millis_to_wait = ((1.0 / 60.0) - (now - last_draw) / double(CLOCKS_PER_SEC)) * 1000;
            this_thread::sleep_for(chrono::milliseconds(millis_to_wait));
            continue;
        }
        if (!_is_running) break;

        last_draw = now;
        _draw();
    }
}

// Close the window and stop drawing
void drawing_window::stop() {
    _is_running = false;
    _close();
}

// Open a new RenderWindow, closing existing one if necessary
void drawing_window::_open() {
    _window = new RenderWindow(VideoMode(_width, _height), _title);
}

// Close the window
void drawing_window::_close() {
    if (_window != nullptr) {
        _window->close();
        delete _window;
        _window = nullptr;
    }
}

// process pending events
void drawing_window::_process_events() {
    sf::Event event;
    _draw_mtx.lock();
    while (_window->pollEvent(event)) {
        // "close requested" event: depends on _stop_on_close -
        // we either stop entirely, or ignore the request
        if (event.type == sf::Event::Closed && _stop_on_close) stop();
    }
    _draw_mtx.unlock();
}

// Redraw all patches
void drawing_window::_draw() {
    // draw patches
    _draw_mtx.lock();
    if (_patches != nullptr) {
        for (int i = 0; i < _patch_count; i++) {
            if (_window->isOpen()) {
                _patches[i].draw(*_window);
            }
        }
    }

    // show on screen
    _window->display();
    _draw_mtx.unlock();
}

// _setup: setup the patches collection 
// should only be called when the window is closed
void drawing_window::_setup() {
    if (_patches != nullptr) {
        delete[] _patches;
        _patches = nullptr;
    }

    // calculate number of patches needed
    unsigned pw = ceil(_width / double(PATCH_SIZE));
    unsigned ph = ceil(_height / double(PATCH_SIZE));

    _patch_count = pw * ph;
    _patches = new patch[_patch_count];

    for (int x = 0; x < pw; x++) {
        for (int y = 0; y < ph; y++) {
            if (x == pw - 1 && _width % PATCH_SIZE != 0) {
                _patches[x * ph + y].width = _width % PATCH_SIZE;
            } else {
                _patches[x * ph + y].width = PATCH_SIZE;
            }
        
            if (y == ph - 1 && _height % PATCH_SIZE != 0) {
                _patches[x * ph + y].height = _height % PATCH_SIZE;
            } else {
                _patches[x * ph + y].height = PATCH_SIZE;
            }

            _patches[x * ph + y].x_off = x * PATCH_SIZE;
            _patches[x * ph + y].y_off = y * PATCH_SIZE;
            _patches[x * ph + y].dirty = true;
            _patches[x * ph + y].update();
        }
    }
}

// destroy: close things down, delete used memory 
void drawing_window::_destroy() {
    if (_window != nullptr) {
        _window->close();
        delete _window;
    }
    if (_patches != nullptr) {
        delete[] _patches;
    }
}

void drawing_window::patch::update() {
    mtx.lock(); // prevent changes to this patch while refreshing the vertex array
    if (dirty) {
        points.clear();
        points.setPrimitiveType(Triangles);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Color c(data[x][y][0], data[x][y][1], data[x][y][2]);
                points.append({{float(x + x_off), float(y + y_off)}, c});
                points.append({{float(x + x_off + 1), float(y + y_off)}, c});
                points.append({{float(x + x_off), float(y + y_off + 1)}, c});
                points.append({{float(x + x_off + 1), float(y + y_off)}, c});
                points.append({{float(x + x_off + 1), float(y + y_off + 1)}, c});
                points.append({{float(x + x_off), float(y + y_off + 1)}, c});
            }
        }
        dirty = false;
    }
    mtx.unlock();
}

