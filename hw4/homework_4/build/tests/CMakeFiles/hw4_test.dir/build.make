# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/hw4_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/hw4_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/hw4_test.dir/flags.make

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o: tests/CMakeFiles/hw4_test.dir/flags.make
tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o: ../tests/test_named_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_test.dir/test_named_vector.cpp.o -c /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_named_vector.cpp

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_test.dir/test_named_vector.cpp.i"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_named_vector.cpp > CMakeFiles/hw4_test.dir/test_named_vector.cpp.i

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_test.dir/test_named_vector.cpp.s"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_named_vector.cpp -o CMakeFiles/hw4_test.dir/test_named_vector.cpp.s

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.requires:

.PHONY : tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.requires

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.provides: tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/hw4_test.dir/build.make tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.provides.build
.PHONY : tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.provides

tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.provides.build: tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o


tests/CMakeFiles/hw4_test.dir/test_main.cpp.o: tests/CMakeFiles/hw4_test.dir/flags.make
tests/CMakeFiles/hw4_test.dir/test_main.cpp.o: ../tests/test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/hw4_test.dir/test_main.cpp.o"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw4_test.dir/test_main.cpp.o -c /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_main.cpp

tests/CMakeFiles/hw4_test.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw4_test.dir/test_main.cpp.i"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_main.cpp > CMakeFiles/hw4_test.dir/test_main.cpp.i

tests/CMakeFiles/hw4_test.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw4_test.dir/test_main.cpp.s"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests/test_main.cpp -o CMakeFiles/hw4_test.dir/test_main.cpp.s

tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.requires:

.PHONY : tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.requires

tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.provides: tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/hw4_test.dir/build.make tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.provides.build
.PHONY : tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.provides

tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.provides.build: tests/CMakeFiles/hw4_test.dir/test_main.cpp.o


# Object files for target hw4_test
hw4_test_OBJECTS = \
"CMakeFiles/hw4_test.dir/test_named_vector.cpp.o" \
"CMakeFiles/hw4_test.dir/test_main.cpp.o"

# External object files for target hw4_test
hw4_test_EXTERNAL_OBJECTS =

../bin/hw4_test: tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o
../bin/hw4_test: tests/CMakeFiles/hw4_test.dir/test_main.cpp.o
../bin/hw4_test: tests/CMakeFiles/hw4_test.dir/build.make
../bin/hw4_test: ../lib/libipb_algorithm.a
../bin/hw4_test: tests/CMakeFiles/hw4_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/hw4_test"
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw4_test.dir/link.txt --verbose=$(VERBOSE)
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && /usr/bin/cmake -D TEST_TARGET=hw4_test -D TEST_EXECUTABLE=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/bin/hw4_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=hw4_test_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D CTEST_FILE=/home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests/hw4_test_tests-b12d07c.cmake -P /usr/local/lib/cmake/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/hw4_test.dir/build: ../bin/hw4_test

.PHONY : tests/CMakeFiles/hw4_test.dir/build

tests/CMakeFiles/hw4_test.dir/requires: tests/CMakeFiles/hw4_test.dir/test_named_vector.cpp.o.requires
tests/CMakeFiles/hw4_test.dir/requires: tests/CMakeFiles/hw4_test.dir/test_main.cpp.o.requires

.PHONY : tests/CMakeFiles/hw4_test.dir/requires

tests/CMakeFiles/hw4_test.dir/clean:
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/hw4_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/hw4_test.dir/clean

tests/CMakeFiles/hw4_test.dir/depend:
	cd /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4 /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/tests /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests /home/fanyang/Documents/cv_cpp/modern_cpp_sol/hw4/homework_4/build/tests/CMakeFiles/hw4_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/hw4_test.dir/depend

