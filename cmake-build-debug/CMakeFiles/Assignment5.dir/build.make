# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment5.dir/flags.make

CMakeFiles/Assignment5.dir/proj5.cpp.obj: CMakeFiles/Assignment5.dir/flags.make
CMakeFiles/Assignment5.dir/proj5.cpp.obj: ../proj5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment5.dir/proj5.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment5.dir\proj5.cpp.obj -c C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\proj5.cpp

CMakeFiles/Assignment5.dir/proj5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment5.dir/proj5.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\proj5.cpp > CMakeFiles\Assignment5.dir\proj5.cpp.i

CMakeFiles/Assignment5.dir/proj5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment5.dir/proj5.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\proj5.cpp -o CMakeFiles\Assignment5.dir\proj5.cpp.s

CMakeFiles/Assignment5.dir/proj5.cpp.obj.requires:

.PHONY : CMakeFiles/Assignment5.dir/proj5.cpp.obj.requires

CMakeFiles/Assignment5.dir/proj5.cpp.obj.provides: CMakeFiles/Assignment5.dir/proj5.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Assignment5.dir\build.make CMakeFiles/Assignment5.dir/proj5.cpp.obj.provides.build
.PHONY : CMakeFiles/Assignment5.dir/proj5.cpp.obj.provides

CMakeFiles/Assignment5.dir/proj5.cpp.obj.provides.build: CMakeFiles/Assignment5.dir/proj5.cpp.obj


CMakeFiles/Assignment5.dir/passserver.cpp.obj: CMakeFiles/Assignment5.dir/flags.make
CMakeFiles/Assignment5.dir/passserver.cpp.obj: ../passserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment5.dir/passserver.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment5.dir\passserver.cpp.obj -c C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\passserver.cpp

CMakeFiles/Assignment5.dir/passserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment5.dir/passserver.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\passserver.cpp > CMakeFiles\Assignment5.dir\passserver.cpp.i

CMakeFiles/Assignment5.dir/passserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment5.dir/passserver.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\passserver.cpp -o CMakeFiles\Assignment5.dir\passserver.cpp.s

CMakeFiles/Assignment5.dir/passserver.cpp.obj.requires:

.PHONY : CMakeFiles/Assignment5.dir/passserver.cpp.obj.requires

CMakeFiles/Assignment5.dir/passserver.cpp.obj.provides: CMakeFiles/Assignment5.dir/passserver.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Assignment5.dir\build.make CMakeFiles/Assignment5.dir/passserver.cpp.obj.provides.build
.PHONY : CMakeFiles/Assignment5.dir/passserver.cpp.obj.provides

CMakeFiles/Assignment5.dir/passserver.cpp.obj.provides.build: CMakeFiles/Assignment5.dir/passserver.cpp.obj


# Object files for target Assignment5
Assignment5_OBJECTS = \
"CMakeFiles/Assignment5.dir/proj5.cpp.obj" \
"CMakeFiles/Assignment5.dir/passserver.cpp.obj"

# External object files for target Assignment5
Assignment5_EXTERNAL_OBJECTS =

Assignment5.exe: CMakeFiles/Assignment5.dir/proj5.cpp.obj
Assignment5.exe: CMakeFiles/Assignment5.dir/passserver.cpp.obj
Assignment5.exe: CMakeFiles/Assignment5.dir/build.make
Assignment5.exe: CMakeFiles/Assignment5.dir/linklibs.rsp
Assignment5.exe: CMakeFiles/Assignment5.dir/objects1.rsp
Assignment5.exe: CMakeFiles/Assignment5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Assignment5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment5.dir/build: Assignment5.exe

.PHONY : CMakeFiles/Assignment5.dir/build

CMakeFiles/Assignment5.dir/requires: CMakeFiles/Assignment5.dir/proj5.cpp.obj.requires
CMakeFiles/Assignment5.dir/requires: CMakeFiles/Assignment5.dir/passserver.cpp.obj.requires

.PHONY : CMakeFiles/Assignment5.dir/requires

CMakeFiles/Assignment5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment5.dir/clean

CMakeFiles/Assignment5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5 C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5 C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug C:\Users\WorkD\CLionProjects\untitled\DSA\Assignment5\cmake-build-debug\CMakeFiles\Assignment5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment5.dir/depend
