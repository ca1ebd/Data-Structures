#ifndef _DRAWINGWINDOW_H
#define _DRAWINGWINDOW_H

/*
    drawing_window.h
	
    Class definition for the drawing_window class.

    author: C. Painter-Wakefield

    last modified: 8/31/2018
*/

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include <string>
#include <thread>
#include <mutex>

using namespace std;
using namespace sf;

/******************************************************************************

    class drawing_window

    The drawing_window class provides a simple 2-D drawing interface on
    top of SFML.  A drawing_window is initialized with set dimensions, which
    cannot be changed; the user can draw points of any color (RGB) or
    grayscale level at any coordinate within the original dimensions.

    The main differences between using this class and using raw SFML are:
      - The drawing_window object remembers what you've previously drawn; you
        don't have to continuously refresh in a loop (that is done for you).

      - Points are drawn using VertexArrays rather than RectangleShapes; you
        of course can do this with raw SFML, but it is extra work.  The
        drawing_window object does this for you.  The advantage is *much*
        smoother performance.  The drawing_window uses two triangles to draw
        each point, just like a RectangleShape, so resizing of the window
        works - it just rescales to larger "pixels".

    Basic usage:
        // create the window
        drawing_window win(width, height, "My Window");

        // start the window running - this will take over the program,
        // so you need to either launch your user interface code in a new
        // thread (don't launch the drawing window in a new thread, it won't
        // work properly due to properties of OpenGL), or use the start()
        // method provided to both at once.  Here, the assumption is you
        // have some function "user_interface" which takes in a pointer to
        // the drawing window.
        win.start(user_interface, &win);

        // (In your own thread, e.g., driven by user_interface):
        // draw points on the window
        win.set_color(x, y, r, g, b); 
        win.set_gray(x2, y2, graylevel);

        // Either let the user click the close button on the window
        while (!win.is_stopped()) { };

        // Or manage closing it yourself (user can still close the window)
        win.stop();

******************************************************************************/

class drawing_window {
public:
    // constructors, destructor
    drawing_window() { _width = 0; _height = 0; _title = "Drawing Window"; _stop_on_close = true; }
    drawing_window(string t) { _width = 0; _height = 0; _title = t; _stop_on_close = true; }
    drawing_window(unsigned w, unsigned h, string t = "Drawing Window", bool stop_on_close = true) {
        initialize(w, h, t, stop_on_close);
    }
    ~drawing_window() { _destroy(); }

    // initialize window
    void initialize(unsigned w, unsigned h, string t = "Drawing Window", bool stop_on_close = true) {
        _width = w; _height = h; _title = t; _stop_on_close = stop_on_close; _setup();
    }

    // start/stop running the drawing window
    template<class Function, class... Args>
    void start(Function &&f, Args&&... args) {
        _is_running = true;
        thread t(f, args...);
        start();
        t.join();
    }

    void start();

    void stop();

    // find out if drawing window is stopped (i.e., either stop() was
    // called or user clicked the close button on the window and 
    // stop_on_close = true)
    bool is_stopped() { return !_is_running; }
    
    // resize window
    void resize(unsigned width, unsigned height);

    // get current width and height
    unsigned get_width()  { return _width; }
    unsigned get_height() { return _height; }

    // draw a point
    void set_color(unsigned x, unsigned y, char r, char g, char b);
    void set_gray(unsigned x, unsigned y, char grayval) {
        set_color(x, y, grayval, grayval, grayval);
    }

private:
    // bigger powers of 2 than 16 don't seem to work on some graphics
    // cards.
    static const unsigned PATCH_SIZE = 16;

    // the function that will handle the event loop; must be static
    // to allow running it in a new thread.  Unfortunately, that means
    // we have to pass this object into the static function!
    static void _draw(drawing_window *);

    // the patch struct lets us tile the window with VertexArrays, and
    // only update when needed.
    struct patch {
        void draw(RenderWindow& target) { 
            update();
            target.draw(points);
        }

        void set_point(unsigned x, unsigned y, char r, char g, char b) {
            // prevent vertex array updates while changing the patch
            mtx.lock();
            data[x][y][0] = r;
            data[x][y][1] = g;
            data[x][y][2] = b;
            dirty = true;
            mtx.unlock();
        }
        void update();

        VertexArray points;
        unsigned    x_off = 0, y_off = 0;
        unsigned    width = 0, height = 0;
        bool        dirty = true;
        char        data[PATCH_SIZE][PATCH_SIZE][3];
        mutex       mtx;
    };

    bool          _is_running = false;
    unsigned      _width, _height;
    string        _title;
    bool          _stop_on_close;
    RenderWindow *_window = nullptr;
    unsigned      _patch_count;
    patch*        _patches = nullptr;
    mutex         _draw_mtx;

    void _setup();
    void _destroy();
    void _process_events();
    void _draw();
    void _open();
    void _close();
};

#endif
