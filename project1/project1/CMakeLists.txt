cmake_minimum_required(VERSION 3.1)
project(image_editor)

include_directories(include)

link_directories(lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
find_package(Threads REQUIRED)

add_executable(image_editor main.cpp image_editor.cpp drawing_window.cpp)
target_link_libraries(image_editor sfml-graphics sfml-system sfml-window ${CMAKE_THREAD_LIBS_INIT})

# Copy single files
macro(resource_files files)
    foreach(file ${files})
        message(STATUS "Copying resource ${file}")
        file(COPY ${file} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endforeach()
endmacro()

# Copy full directories
macro(resource_dirs dirs)
    foreach(dir ${dirs})
        # Replace / at the end of the path (copy dir content VS copy dir)
        string(REGEX REPLACE "/+$" "" dirclean "${dir}")
            file(GLOB files "${dirclean}/*.*")
        message(STATUS "Copying directory ${dirclean}")
        foreach(file ${files})
            resource_files(${file})
        endforeach()
    endforeach()
endmacro()

resource_dirs(bin/)
resource_dirs(sampleinputs/)
