cmake_minimum_required(VERSION 3.22)
project(seif_FWD C)

set(CMAKE_C_STANDARD 99)

add_executable(seif_FWD main.c defines.h card/card.h card/card.c terminal/terminal.h terminal/terminal.c server/server.h server/server.c)
