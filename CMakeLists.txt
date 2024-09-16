# Require CMake 3.15+ (matching scikit-build-core) Use new versions of all
# policies up to CMake 3.27
cmake_minimum_required(VERSION 3.15...3.27)

# Scikit-build-core sets these values for you, or you can just hard-code the
# name and version.
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)


set(MYMATH_MODULE_NAME mymath)
add_library(${MYMATH_MODULE_NAME} STATIC src/mymath.cpp)
set_target_properties(${MYMATH_MODULE_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Find the module development requirements (requires FindPython from 3.17 or
# scikit-build-core's built-in backport)
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

# Add a library using FindPython's tooling (pybind11 also provides a helper like
# this)
python_add_library(_core MODULE src/binder.cpp WITH_SOABI)
target_include_directories(_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(_core PRIVATE pybind11::headers ${MYMATH_MODULE_NAME})

# This is passing in the version as a define just as an example
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})



set(Stubgen_Executable "${CMAKE_CURRENT_SOURCE_DIR}/.venv/bin/stubgen")
if(WIN32)
    set(Stubgen_Executable "${CMAKE_CURRENT_SOURCE_DIR}/.venv/Scripts/stubgen.exe")
endif()

# add_custom_command(TARGET ${PYMODULE_NAME} POST_BUILD 
#     COMMAND ${Stubgen_Executable} -m ${PYMODULE_NAME} -o . 
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} 
#     COMMENT "Use stubgen to create .pyi for statement completion"
# )

# Require CMake 3.15+ (matching scikit-build-core) Use new versions of all
# policies up to CMake 3.27

# The install directory is the output (wheel) directory
install(TARGETS _core DESTINATION tleng3)