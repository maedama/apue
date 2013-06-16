add_executable(myls myls.c)
target_link_libraries(myls apue)

add_executable(myecho myecho.c)
target_link_libraries(myecho apue)

add_executable(printpid printpid.c)
target_link_libraries(printpid apue)

add_executable(myshell myshell.c)
target_link_libraries(myshell apue)

add_executable(printerror printerror.c)
target_link_libraries(printerror apue)

add_executable(printuid printuid.c)
target_link_libraries(printuid apue)
