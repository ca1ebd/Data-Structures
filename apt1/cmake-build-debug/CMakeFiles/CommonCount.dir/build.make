# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/caleb/Desktop/clion-2018.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/caleb/Desktop/clion-2018.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caleb/Desktop/Data-Structures/apt1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CommonCount.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CommonCount.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CommonCount.dir/flags.make

CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o: CMakeFiles/CommonCount.dir/flags.make
CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o: ../CommonCount/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o -c /home/caleb/Desktop/Data-Structures/apt1/CommonCount/main.cpp

CMakeFiles/CommonCount.dir/CommonCount/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CommonCount.dir/CommonCount/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caleb/Desktop/Data-Structures/apt1/CommonCount/main.cpp > CMakeFiles/CommonCount.dir/CommonCount/main.cpp.i

CMakeFiles/CommonCount.dir/CommonCount/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CommonCount.dir/CommonCount/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caleb/Desktop/Data-Structures/apt1/CommonCount/main.cpp -o CMakeFiles/CommonCount.dir/CommonCount/main.cpp.s

# Object files for target CommonCount
CommonCount_OBJECTS = \
"CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o"

# External object files for target CommonCount
CommonCount_EXTERNAL_OBJECTS =

CommonCount: CMakeFiles/CommonCount.dir/CommonCount/main.cpp.o
CommonCount: CMakeFiles/CommonCount.dir/build.make
CommonCount: CMakeFiles/CommonCount.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CommonCount"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CommonCount.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CommonCount.dir/build: CommonCount

.PHONY : CMakeFiles/CommonCount.dir/build

CMakeFiles/CommonCount.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CommonCount.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CommonCount.dir/clean

CMakeFiles/CommonCount.dir/depend:
	cd /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caleb/Desktop/Data-Structures/apt1 /home/caleb/Desktop/Data-Structures/apt1 /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles/CommonCount.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CommonCount.dir/depend

