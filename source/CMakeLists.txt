PROJECT(Test1)
PROJECT(Test2)
PROJECT(Test3)

add_executable(TEST1 test1.cpp)
add_executable(TEST2 test2.cpp)
add_executable(TEST3 test3.cpp)

target_link_libraries(TEST1 PRIVATE Pool)
target_link_libraries(TEST2 PRIVATE Pool)
target_link_libraries(TEST3 PRIVATE Pool)