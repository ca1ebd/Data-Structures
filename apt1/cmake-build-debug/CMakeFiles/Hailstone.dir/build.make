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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cdud8\Desktop\Data-Structures\apt1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hailstone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hailstone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hailstone.dir/flags.make

CMakeFiles/Hailstone.dir/Hailstone/main.cpp.obj: CMakeFiles/Hailstone.dir/flags.make
CMakeFiles/Hailstone.dir/Hailstone/main.cpp.obj: ../Hailstone/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hailstone.dir/Hailstone/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Hailstone.dir\Hailstone\main.cpp.obj -c C:\Users\cdud8\Desktop\Data-Structures\apt1\Hailstone\main.cpp

CMakeFiles/Hailstone.dir/Hailstone/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hailstone.dir/Hailstone/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cdud8\Desktop\Data-Structures\apt1\Hailstone\main.cpp > CMakeFiles\Hailstone.dir\Hailstone\main.cpp.i

CMakeFiles/Hailstone.dir/Hailstone/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hailstone.dir/Hailstone/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cdud8\Desktop\Data-Structures\apt1\Hailstone\main.cpp -o CMakeFiles\Hailstone.dir\Hailstone\main.cpp.s

# Object files for target Hailstone
Hailstone_OBJECTS = \
"CMakeFiles/Hailstone.dir/Hailstone/main.cpp.obj"

# External object files for target Hailstone
Hailstone_EXTERNAL_OBJECTS =

Hailstone.exe: CMakeFiles/Hailstone.dir/Hailstone/main.cpp.obj
Hailstone.exe: CMakeFiles/Hailstone.dir/build.make
Hailstone.exe: CMakeFiles/Hailstone.dir/linklibs.rsp
Hailstone.exe: CMakeFiles/Hailstone.dir/objects1.rsp
Hailstone.exe: CMakeFiles/Hailstone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Hailstone.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hailstone.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hailstone.dir/build: Hailstone.exe

.PHONY : CMakeFiles/Hailstone.dir/build

CMakeFiles/Hailstone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Hailstone.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Hailstone.dir/clean

CMakeFiles/Hailstone.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cdud8\Desktop\Data-Structures\apt1 C:\Users\cdud8\Desktop\Data-Structures\apt1 C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug C:\Users\cdud8\Desktop\Data-Structures\apt1\cmake-build-debug\CMakeFiles\Hailstone.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hailstone.dir/depend

