# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\romik\projects\graphbuilder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\romik\projects\graphbuilder\build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/Graph.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Graph.cpp.obj: C:/Users/romik/projects/graphbuilder/src/Graph.cpp
CMakeFiles/main.dir/src/Graph.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\romik\projects\graphbuilder\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/Graph.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Graph.cpp.obj -MF CMakeFiles\main.dir\src\Graph.cpp.obj.d -o CMakeFiles\main.dir\src\Graph.cpp.obj -c C:\Users\romik\projects\graphbuilder\src\Graph.cpp

CMakeFiles/main.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Graph.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\romik\projects\graphbuilder\src\Graph.cpp > CMakeFiles\main.dir\src\Graph.cpp.i

CMakeFiles/main.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Graph.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\romik\projects\graphbuilder\src\Graph.cpp -o CMakeFiles\main.dir\src\Graph.cpp.s

CMakeFiles/main.dir/src/GraphBuilder.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GraphBuilder.cpp.obj: C:/Users/romik/projects/graphbuilder/src/GraphBuilder.cpp
CMakeFiles/main.dir/src/GraphBuilder.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\romik\projects\graphbuilder\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/GraphBuilder.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GraphBuilder.cpp.obj -MF CMakeFiles\main.dir\src\GraphBuilder.cpp.obj.d -o CMakeFiles\main.dir\src\GraphBuilder.cpp.obj -c C:\Users\romik\projects\graphbuilder\src\GraphBuilder.cpp

CMakeFiles/main.dir/src/GraphBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GraphBuilder.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\romik\projects\graphbuilder\src\GraphBuilder.cpp > CMakeFiles\main.dir\src\GraphBuilder.cpp.i

CMakeFiles/main.dir/src/GraphBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GraphBuilder.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\romik\projects\graphbuilder\src\GraphBuilder.cpp -o CMakeFiles\main.dir\src\GraphBuilder.cpp.s

CMakeFiles/main.dir/src/GraphDrawer.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GraphDrawer.cpp.obj: C:/Users/romik/projects/graphbuilder/src/GraphDrawer.cpp
CMakeFiles/main.dir/src/GraphDrawer.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\romik\projects\graphbuilder\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/GraphDrawer.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GraphDrawer.cpp.obj -MF CMakeFiles\main.dir\src\GraphDrawer.cpp.obj.d -o CMakeFiles\main.dir\src\GraphDrawer.cpp.obj -c C:\Users\romik\projects\graphbuilder\src\GraphDrawer.cpp

CMakeFiles/main.dir/src/GraphDrawer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GraphDrawer.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\romik\projects\graphbuilder\src\GraphDrawer.cpp > CMakeFiles\main.dir\src\GraphDrawer.cpp.i

CMakeFiles/main.dir/src/GraphDrawer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GraphDrawer.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\romik\projects\graphbuilder\src\GraphDrawer.cpp -o CMakeFiles\main.dir\src\GraphDrawer.cpp.s

CMakeFiles/main.dir/src/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.obj: C:/Users/romik/projects/graphbuilder/src/main.cpp
CMakeFiles/main.dir/src/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\romik\projects\graphbuilder\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cpp.obj -MF CMakeFiles\main.dir\src\main.cpp.obj.d -o CMakeFiles\main.dir\src\main.cpp.obj -c C:\Users\romik\projects\graphbuilder\src\main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\romik\projects\graphbuilder\src\main.cpp > CMakeFiles\main.dir\src\main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\romik\projects\graphbuilder\src\main.cpp -o CMakeFiles\main.dir\src\main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/Graph.cpp.obj" \
"CMakeFiles/main.dir/src/GraphBuilder.cpp.obj" \
"CMakeFiles/main.dir/src/GraphDrawer.cpp.obj" \
"CMakeFiles/main.dir/src/main.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/src/Graph.cpp.obj
main.exe: CMakeFiles/main.dir/src/GraphBuilder.cpp.obj
main.exe: CMakeFiles/main.dir/src/GraphDrawer.cpp.obj
main.exe: CMakeFiles/main.dir/src/main.cpp.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: CMakeFiles/main.dir/linkLibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\romik\projects\graphbuilder\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\romik\projects\graphbuilder C:\Users\romik\projects\graphbuilder C:\Users\romik\projects\graphbuilder\build C:\Users\romik\projects\graphbuilder\build C:\Users\romik\projects\graphbuilder\build\CMakeFiles\main.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend

