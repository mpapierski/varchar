CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
ENABLE_TESTING ()
INCLUDE_DIRECTORIES ("include")
ADD_EXECUTABLE (test_suite
	tests/test_suite.cpp)
ADD_TEST (varchar_test_suite
	test_suite)