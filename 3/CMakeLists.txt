add_executable(seek seek.c)
target_link_libraries(seek apue)

add_executable(hole hole.c)
target_link_libraries(hole apue)

add_executable(stdin_to_stdout stdin_to_stdout.c)
target_link_libraries(stdin_to_stdout apue)

add_executable(getflag getflag.c)
target_link_libraries(getflag apue)

add_executable(write_pattern write_pattern.c)
target_link_libraries(write_pattern apue)

add_executable(shared_fd shared_fd.c)
target_link_libraries(shared_fd apue)

add_executable(fsync fsync.c)
target_link_libraries(fsync apue)
