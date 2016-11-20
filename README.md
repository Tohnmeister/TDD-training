TDD-training
============

Building C++ projects
---------------------

CMake project files are provided to build the C++ exercises and solutions in a cross-platform way.
Each directory that contains a `CMakeLists.txt` file corresponds with a CMake project and can be built as shown below.
There are projects for each exercise and solution,
a project containing all exercises, a project containing all solutions,
and a project containing both all exercises and solutions.

To build a CMake project, execute the following commands in the project's directory
(e.g., the directory this README is located in):

	> mkdir build
	> cd build
	> cmake -DCMAKE_BUILD_TYPE=Debug ..
	> make -j $(nproc)    # or replace by any other build system used on your platform

The resulting binaries will be created in the `build` directory, e.g.:

	> "./exercises/00 my first unit test/cpp/My first unit test/00_my_first_unit_test"
	
	Running main() from gmock_main.cc
	[==========] Running 1 test from 1 test case.
	[----------] Global test environment set-up.
	[----------] 1 test from FuzzyDateTest
	[ RUN      ] FuzzyDateTest.exampleTest
	[       OK ] FuzzyDateTest.exampleTest (0 ms)
	[----------] 1 test from FuzzyDateTest (0 ms total)
	
	[----------] Global test environment tear-down
	[==========] 1 test from 1 test case ran. (0 ms total)
	[  PASSED  ] 1 test.
