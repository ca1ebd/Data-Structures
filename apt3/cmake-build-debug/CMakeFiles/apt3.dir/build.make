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
CMAKE_SOURCE_DIR = Z:\Data-Structures\apt3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Z:\Data-Structures\apt3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/apt3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/apt3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/apt3.dir/flags.make

CMakeFiles/apt3.dir/main.cpp.obj: CMakeFiles/apt3.dir/flags.make
CMakeFiles/apt3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Z:\Data-Structures\apt3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/apt3.dir/main.cpp.obj"
	C:\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\apt3.dir\main.cpp.obj -c Z:\Data-Structures\apt3\main.cpp

CMakeFiles/apt3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/apt3.dir/main.cpp.i"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Z:\Data-Structures\apt3\main.cpp > CMakeFiles\apt3.dir\main.cpp.i

CMakeFiles/apt3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/apt3.dir/main.cpp.s"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S Z:\Data-Structures\apt3\main.cpp -o CMakeFiles\apt3.dir\main.cpp.s

# Object files for target apt3
apt3_OBJECTS = \
"CMakeFiles/apt3.dir/main.cpp.obj"

# External object files for target apt3
apt3_EXTERNAL_OBJECTS =

apt3.exe: CMakeFiles/apt3.dir/main.cpp.obj
apt3.exe: CMakeFiles/apt3.dir/build.make
apt3.exe: CMakeFiles/apt3.dir/linklibs.rsp
apt3.exe: CMakeFiles/apt3.dir/objects1.rsp
apt3.exe: CMakeFiles/apt3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Z:\Data-Structures\apt3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable apt3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\apt3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/apt3.dir/build: apt3.exe

.PHONY : CMakeFiles/apt3.dir/build

CMakeFiles/apt3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\apt3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/apt3.dir/clean

CMakeFiles/apt3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" Z:\Data-Structures\apt3 Z:\Data-Structures\apt3 Z:\Data-Structures\apt3\cmake-build-debug Z:\Data-Structures\apt3\cmake-build-debug Z:\Data-Structures\apt3\cmake-build-debug\CMakeFiles\apt3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/apt3.dir/depend

