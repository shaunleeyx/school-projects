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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shaunlee/CPSC-3500-P2_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPSC_3500_P2_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPSC_3500_P2_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPSC_3500_P2_1.dir/flags.make

CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o: CMakeFiles/CPSC_3500_P2_1.dir/flags.make
CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o: ../schedsim.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o -c /Users/shaunlee/CPSC-3500-P2_1/schedsim.cpp

CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shaunlee/CPSC-3500-P2_1/schedsim.cpp > CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.i

CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shaunlee/CPSC-3500-P2_1/schedsim.cpp -o CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.s

# Object files for target CPSC_3500_P2_1
CPSC_3500_P2_1_OBJECTS = \
"CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o"

# External object files for target CPSC_3500_P2_1
CPSC_3500_P2_1_EXTERNAL_OBJECTS =

CPSC_3500_P2_1: CMakeFiles/CPSC_3500_P2_1.dir/schedsim.cpp.o
CPSC_3500_P2_1: CMakeFiles/CPSC_3500_P2_1.dir/build.make
CPSC_3500_P2_1: CMakeFiles/CPSC_3500_P2_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPSC_3500_P2_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPSC_3500_P2_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPSC_3500_P2_1.dir/build: CPSC_3500_P2_1

.PHONY : CMakeFiles/CPSC_3500_P2_1.dir/build

CMakeFiles/CPSC_3500_P2_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPSC_3500_P2_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPSC_3500_P2_1.dir/clean

CMakeFiles/CPSC_3500_P2_1.dir/depend:
	cd /Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shaunlee/CPSC-3500-P2_1 /Users/shaunlee/CPSC-3500-P2_1 /Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug /Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug /Users/shaunlee/CPSC-3500-P2_1/cmake-build-debug/CMakeFiles/CPSC_3500_P2_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPSC_3500_P2_1.dir/depend

