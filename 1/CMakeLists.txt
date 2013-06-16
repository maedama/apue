add_executable(myls myls.c)
target_link_libraries(myls apue)

add_executable(myecho myecho.c)
target_link_libraries(myecho apue)

add_executable(printpid printpid.c)
target_link_libraries(printpid apue)

add_executable(myshell myshell.c)
target_link_libraries(myshell apue)
