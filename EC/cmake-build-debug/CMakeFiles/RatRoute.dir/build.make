# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = Z:\Data-Structures\EC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Z:\Data-Structures\EC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RatRoute.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RatRoute.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RatRoute.dir/flags.make

CMakeFiles/RatRoute.dir/RatRoute/main.cpp.obj: CMakeFiles/RatRoute.dir/flags.make
CMakeFiles/RatRoute.dir/RatRoute/main.cpp.obj: ../RatRoute/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Z:\Data-Structures\EC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RatRoute.dir/RatRoute/main.cpp.obj"
	C:\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RatRoute.dir\RatRoute\main.cpp.obj -c Z:\Data-Structures\EC\RatRoute\main.cpp

CMakeFiles/RatRoute.dir/RatRoute/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RatRoute.dir/RatRoute/main.cpp.i"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Z:\Data-Structures\EC\RatRoute\main.cpp > CMakeFiles\RatRoute.dir\RatRoute\main.cpp.i

CMakeFiles/RatRoute.dir/RatRoute/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RatRoute.dir/RatRoute/main.cpp.s"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S Z:\Data-Structures\EC\RatRoute\main.cpp -o CMakeFiles\RatRoute.dir\RatRoute\main.cpp.s

# Object files for target RatRoute
RatRoute_OBJECTS = \
"CMakeFiles/RatRoute.dir/RatRoute/main.cpp.obj"

# External object files for target RatRoute
RatRoute_EXTERNAL_OBJECTS =

RatRoute.exe: CMakeFiles/RatRoute.dir/RatRoute/main.cpp.obj
RatRoute.exe: CMakeFiles/RatRoute.dir/build.make
RatRoute.exe: CMakeFiles/RatRoute.dir/linklibs.rsp
RatRoute.exe: CMakeFiles/RatRoute.dir/objects1.rsp
RatRoute.exe: CMakeFiles/RatRoute.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Z:\Data-Structures\EC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RatRoute.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RatRoute.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RatRoute.dir/build: RatRoute.exe

.PHONY : CMakeFiles/RatRoute.dir/build

CMakeFiles/RatRoute.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RatRoute.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RatRoute.dir/clean

CMakeFiles/RatRoute.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" Z:\Data-Structures\EC Z:\Data-Structures\EC Z:\Data-Structures\EC\cmake-build-debug Z:\Data-Structures\EC\cmake-build-debug Z:\Data-Structures\EC\cmake-build-debug\CMakeFiles\RatRoute.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RatRoute.dir/depend

