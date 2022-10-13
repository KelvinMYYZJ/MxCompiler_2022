cmake_minimum_required(VERSION 3.10.2)
project(MxCompiler_2022)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE "Debug")


# compile with debug info on local machine and compile with O2 on OJ
if(LOCALTEST)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/runtime)
  add_compile_options(-std=c++2a -g)
  message("!!!local!!!")
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
  add_compile_options(-std=c++2a -o2)
  add_definitions(-DONLINE_JUDGE)
endif()


SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -g -ggdb")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   -Ofast")
SET(antlr_runtime_dir ${PROJECT_SOURCE_DIR}/antlr_runtime)
SET(antlr_src_dir ${antlr_runtime_dir}/src)
SET(src_dir ${PROJECT_SOURCE_DIR}/src/)
set(frontend_src_dir ${src_dir}/Frontend)
set(antlr_src_sub_dirs
  ${antlr_src_dir}/atn
  ${antlr_src_dir}/dfa
  ${antlr_src_dir}/internal
  ${antlr_src_dir}/misc
  ${antlr_src_dir}/support
  ${antlr_src_dir}/tree
  ${antlr_src_dir}/tree/pattern
  ${antlr_src_dir}/tree/xpath
)
file(GLOB forntend_cpp_src ${frontend_src_dir}/*.cpp)
message(${forntend_cpp_src})

include_directories(
  ${frontend_src_dir}
  ${src_dir}
  ${antlr_src_dir}
  ${antlr_src_sub_dirs}
)
file(GLOB antlr4-cpp-src
        ${antlr_src_dir}/*.cpp
        ${antlr_src_dir}/atn/*.cpp
        ${antlr_src_dir}/dfa/*.cpp
        ${antlr_src_dir}/internal/*.cpp
        ${antlr_src_dir}/misc/*.cpp
        ${antlr_src_dir}/support/*.cpp
        ${antlr_src_dir}/tree/*.cpp
        ${antlr_src_dir}/tree/pattern/*.cpp
        ${antlr_src_dir}/tree/xpath/*.cpp
        )
add_library (antlr4-cpp-runtime ${antlr4-cpp-src})
add_executable(code ${src_dir}/main.cpp ${forntend_cpp_src})
target_link_libraries(code antlr4-cpp-runtime)
