# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build

# Include any dependencies generated for this target.
include src/lib/CMakeFiles/mat_serialization.dir/depend.make

# Include the progress variables for this target.
include src/lib/CMakeFiles/mat_serialization.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib/CMakeFiles/mat_serialization.dir/flags.make

src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.o: src/lib/CMakeFiles/mat_serialization.dir/flags.make
src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.o: ../src/lib/serialize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.o"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mat_serialization.dir/serialize.cpp.o -c /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/src/lib/serialize.cpp

src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mat_serialization.dir/serialize.cpp.i"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/src/lib/serialize.cpp > CMakeFiles/mat_serialization.dir/serialize.cpp.i

src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mat_serialization.dir/serialize.cpp.s"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/src/lib/serialize.cpp -o CMakeFiles/mat_serialization.dir/serialize.cpp.s

# Object files for target mat_serialization
mat_serialization_OBJECTS = \
"CMakeFiles/mat_serialization.dir/serialize.cpp.o"

# External object files for target mat_serialization
mat_serialization_EXTERNAL_OBJECTS =

../results/lib/libmat_serialization.a: src/lib/CMakeFiles/mat_serialization.dir/serialize.cpp.o
../results/lib/libmat_serialization.a: src/lib/CMakeFiles/mat_serialization.dir/build.make
../results/lib/libmat_serialization.a: src/lib/CMakeFiles/mat_serialization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../results/lib/libmat_serialization.a"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && $(CMAKE_COMMAND) -P CMakeFiles/mat_serialization.dir/cmake_clean_target.cmake
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mat_serialization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib/CMakeFiles/mat_serialization.dir/build: ../results/lib/libmat_serialization.a

.PHONY : src/lib/CMakeFiles/mat_serialization.dir/build

src/lib/CMakeFiles/mat_serialization.dir/clean:
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib && $(CMAKE_COMMAND) -P CMakeFiles/mat_serialization.dir/cmake_clean.cmake
.PHONY : src/lib/CMakeFiles/mat_serialization.dir/clean

src/lib/CMakeFiles/mat_serialization.dir/depend:
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5 /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/src/lib /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw5/homework_5/build/src/lib/CMakeFiles/mat_serialization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib/CMakeFiles/mat_serialization.dir/depend

