cmake_minimum_required(VERSION 2.8.2)
include("${CMAKE_CURRENT_SOURCE_DIR}/../../../../CMake/SetupGoogletest.cmake")

project(01_prime_number)
setup_tdd_project_with_googletest("PrimeNumber")
