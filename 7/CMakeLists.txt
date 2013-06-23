add_executable(helloworld helloworld.c)
target_link_libraries(helloworld apue)

add_executable(atexit atexit.c)
target_link_libraries(atexit apue)

add_executable(myechoall myechoall.c)
target_link_libraries(myechoall apue)

add_executable(jmp jmp.c)
target_link_libraries(jmp apue)

add_executable(statval statval.c)
target_link_libraries(statval apue)



