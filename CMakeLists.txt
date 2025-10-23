# CMakeLists.txt for xensiv-pas-gas-sensor (library only, no main)
cmake_minimum_required(VERSION 3.10)
project(xensiv_pas_gas_sensor C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror")

# Library sources (no main.c)
set(SENSOR_SRC
    src/xensiv_pas_gas.c
    src/xensiv_pas_gas_platform.c
    src/xensiv_pas_gas_co2.c
    src/xensiv_pas_gas_r290.c
    src/xensiv_pas_gas_a2l.c
)

add_library(xensiv_pas_gas_sensor STATIC ${SENSOR_SRC})

# Include directories
target_include_directories(xensiv_pas_gas_sensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
