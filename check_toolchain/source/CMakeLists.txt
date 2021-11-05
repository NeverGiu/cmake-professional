add_library(foo SHARED foo.cpp)

# Conditionally add -fcode-hoisting option using variables
# if(CXX_COMPILER_ID STREQUAL GNU AND
#         NOT CXX_COMPILER_VERSION VERSION_LESS 7)
#         target_compile_options(foo PRIVATE -fcode-hoisting)
# endif()

# Same thing using generator expressions instead(TODO: Debug to fixed up)
# target_compile_options(foo
#         PRIVATE
#         $<$<AND:$<CXX_COMPILER_ID:GNU>,
#         $<VERSION_GREATER_EQUAL:$<CXX_COMPILER_VERSION>,7>>:-fcode-hoisting>
#         )

# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)
# set(extraOpts " -Wall -Wextra")
# set(CMAKE_C_FLAGS_DEBUG_INIT ${extraOpts})
# set(CMAKE_CXX_FLAGS_DEBUG_INIT ${extraOpts})

# GCC Create system32 target on system64 platform
# -----------------------------------------------
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i686)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_FLAGS_INIT -m32)
set(CMAKE_CXX_FLAGS_DEBUG_INIT -m32)

set(CMAKE_EXE_LINKER_FLAGS_INIT -m32)
set(CMAKE_SHARED_LINKER_FLAGS_INIT -m32)
set(CMAKE_MODULE_LINKER_FLAGS_INIT -m32)

math(EXPR bitness "${CMAKE_SIZEOF_VOID_P} * 4")
message(STATUS "${bitness}-bit build")


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
target_link_directories(foo PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

add_executable(execute master.cpp)

target_link_libraries(execute PUBLIC foo)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
