cmake_minimum_required(VERSION 3.4...3.18)
project(tleng3 LANGUAGES C CXX)
set(PYMODULE_NAME tleng3)
set(MYMATH_MODULE_NAME mymath)


add_library(${MYMATH_MODULE_NAME} STATIC src/mymath.cpp)
set_target_properties(${MYMATH_MODULE_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)


# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/pybind11")
pybind11_add_module(${PYMODULE_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/binder.cpp")

target_include_directories(${PYMODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PYMODULE_NAME} PRIVATE 
    mymath
)


# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(${PYMODULE_NAME} PRIVATE VERSION_INFO= "${EXAMPLE_VERSION_INFO}")


set(Stubgen_Executable "${CMAKE_CURRENT_SOURCE_DIR}/.venv/bin/stubgen")
if(WIN32)
    set(Stubgen_Executable "${CMAKE_CURRENT_SOURCE_DIR}/.venv/Scripts/stubgen.exe")
endif()

add_custom_command(TARGET ${PYMODULE_NAME} POST_BUILD 
    COMMAND ${Stubgen_Executable} -m ${PYMODULE_NAME} -o . 
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
    COMMENT "Use stubgen to create .pyi for statement completion"
)