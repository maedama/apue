add_executable(bufmode bufmode.c)
target_link_libraries(bufmode apue)

add_executable(stdin2stdout stdin2stdout.c)
target_link_libraries(stdin2stdout apue)

add_executable(stdin2stdout2 stdin2stdout2.c)
target_link_libraries(stdin2stdout2 apue)

add_executable(streampos streampos.c)
target_link_libraries(streampos apue)

add_executable(buf buf.c)
target_link_libraries(buf apue)

add_executable(tmpfile tmpfile.c)
target_link_libraries(tmpfile apue)

add_executable(mytmpfile mytmpfile.c)
target_link_libraries(mytmpfile apue)

add_executable(tempnam tempnam.c)
target_link_libraries(tempnam apue)
