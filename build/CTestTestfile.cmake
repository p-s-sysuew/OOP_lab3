# CMake generated Testfile for 
# Source directory: /home/pavel/MyFiles/OOP_labs/OOP_lab3
# Build directory: /home/pavel/MyFiles/OOP_labs/OOP_lab3/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/home/pavel/MyFiles/OOP_labs/OOP_lab3/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/home/pavel/MyFiles/OOP_labs/OOP_lab3/CMakeLists.txt;36;add_test;/home/pavel/MyFiles/OOP_labs/OOP_lab3/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
