# CMakeLists.txt for xensiv-pas-gas-sensor (library only, no main)
cmake_minimum_required(VERSION 3.10)
project(xensiv_pas_gas_sensor C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror")

option(BUILD_CO2 "Build CO2 sensor support" ON)
option(BUILD_R290 "Build R290 sensor support" ON)

# Library sources (no main.c)
set(SENSOR_SRC
    xensiv_pas_gas.c
    xensiv_pas_gas_platform.c
)

# add_library(xensiv_pas_gas_sensor STATIC ${SENSOR_SRC})

# if(BUILD_CO2)
#     target_compile_definitions(xensiv_pas_gas_sensor PRIVATE XENSIV_PAS_GAS_CO2)
# endif()

# if(BUILD_R290)
#     target_compile_definitions(xensiv_pas_gas_sensor PRIVATE XENSIV_PAS_GAS_R290)
# endif()

# # Include directories
# target_include_directories(xensiv_pas_gas_sensor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(xensiv_pas_gas_sensor_co2 STATIC
    xensiv_pas_gas.c
    xensiv_pas_gas_platform.c
)
target_compile_definitions(xensiv_pas_gas_sensor_co2 PRIVATE XENSIV_PAS_GAS_CO2)
target_include_directories(xensiv_pas_gas_sensor_co2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# R290 library
add_library(xensiv_pas_gas_sensor_r290 STATIC
    xensiv_pas_gas.c
    xensiv_pas_gas_platform.c
)
target_compile_definitions(xensiv_pas_gas_sensor_r290 PRIVATE XENSIV_PAS_GAS_R290)
target_include_directories(xensiv_pas_gas_sensor_r290 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})