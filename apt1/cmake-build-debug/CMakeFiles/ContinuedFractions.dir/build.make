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
include CMakeFiles/ContinuedFractions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ContinuedFractions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ContinuedFractions.dir/flags.make

CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o: CMakeFiles/ContinuedFractions.dir/flags.make
CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o: ../ContinuedFractions/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o -c /home/caleb/Desktop/Data-Structures/apt1/ContinuedFractions/main.cpp

CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caleb/Desktop/Data-Structures/apt1/ContinuedFractions/main.cpp > CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.i

CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caleb/Desktop/Data-Structures/apt1/ContinuedFractions/main.cpp -o CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.s

# Object files for target ContinuedFractions
ContinuedFractions_OBJECTS = \
"CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o"

# External object files for target ContinuedFractions
ContinuedFractions_EXTERNAL_OBJECTS =

ContinuedFractions: CMakeFiles/ContinuedFractions.dir/ContinuedFractions/main.cpp.o
ContinuedFractions: CMakeFiles/ContinuedFractions.dir/build.make
ContinuedFractions: CMakeFiles/ContinuedFractions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ContinuedFractions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ContinuedFractions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ContinuedFractions.dir/build: ContinuedFractions

.PHONY : CMakeFiles/ContinuedFractions.dir/build

CMakeFiles/ContinuedFractions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuedFractions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuedFractions.dir/clean

CMakeFiles/ContinuedFractions.dir/depend:
	cd /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caleb/Desktop/Data-Structures/apt1 /home/caleb/Desktop/Data-Structures/apt1 /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug /home/caleb/Desktop/Data-Structures/apt1/cmake-build-debug/CMakeFiles/ContinuedFractions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuedFractions.dir/depend
