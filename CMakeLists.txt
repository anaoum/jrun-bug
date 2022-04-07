cmake_minimum_required(VERSION 3.13)

set(PICO_COMPILER pico_arm_gcc)
set(PICO_PLATFORM rp2040)
set(PICO_BOARD pico)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include("$ENV{PICO_SDK_PATH}/pico_sdk_init.cmake")

project(hello C CXX ASM)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    src/main.c
    lib/SEGGER_RTT/RTT/SEGGER_RTT.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    lib/SEGGER_RTT/RTT
)

target_link_libraries(${PROJECT_NAME}
    pico_runtime
)

pico_add_extra_outputs(${PROJECT_NAME})
