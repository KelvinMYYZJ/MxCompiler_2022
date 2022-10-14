cmake_minimum_required(VERSION 3.10.2)
project(MxCompiler_2022)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-pthread)
add_link_options(-pthread)
# ------------------the following is to be modified----------------------------
set(lib_dir_names Frontend misc)
set(program_names code)

# -----------------------------------------------------------------------------
# -----compile with debug info on local machine and compile with O2 on OJ------
if(LOCALTEST)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/runtime)
  add_compile_options(-std=c++2a -g)
  message("!!!local!!!")
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
  add_compile_options(-std=c++2a -o2)
  add_definitions(-DONLINE_JUDGE)
endif()
# ----------------------compiling the antlr runtime----------------------------
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -g -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   -Ofast")
set(antlr_runtime_dir ${PROJECT_SOURCE_DIR}/antlr_runtime)
set(antlr_src_dir ${antlr_runtime_dir}/src)
set(antlr_src_sub_dirs
    ${antlr_src_dir}/atn
    ${antlr_src_dir}/dfa
    ${antlr_src_dir}/internal
    ${antlr_src_dir}/misc
    ${antlr_src_dir}/support
    ${antlr_src_dir}/tree
    ${antlr_src_dir}/tree/pattern
    ${antlr_src_dir}/tree/xpath)
file(
  GLOB
  antlr4-cpp-src
  ${antlr_src_dir}/*.cpp
  ${antlr_src_dir}/atn/*.cpp
  ${antlr_src_dir}/dfa/*.cpp
  ${antlr_src_dir}/internal/*.cpp
  ${antlr_src_dir}/misc/*.cpp
  ${antlr_src_dir}/support/*.cpp
  ${antlr_src_dir}/tree/*.cpp
  ${antlr_src_dir}/tree/pattern/*.cpp
  ${antlr_src_dir}/tree/xpath/*.cpp)
include_directories(${antlr_src_dir} ${antlr_src_sub_dirs})
add_library(antlr4-cpp-runtime ${antlr4-cpp-src})
# -----------------------------------------------------------------------------
set(src_base_dir ${CMAKE_SOURCE_DIR}/src)
foreach(lib_dir_name ${lib_dir_names})
  set(now_lib_dir ${src_base_dir}/${lib_dir_name})
  list(APPEND lib_dirs ${now_lib_dir})
  file(GLOB_RECURSE tmp_files ${now_lib_dir}/*.cpp)
  list(APPEND src_files ${tmp_files})
endforeach()
message("lib_dirs is : ${lib_dirs}")
message("src_files is : ${src_files}")
set(main_base_dir ${src_base_dir})
foreach(program_name ${program_names})
  set(now_main_file ${main_base_dir}/${program_name}.cpp)
  message("${program_name} ${now_main_file} ${src_files}")
  add_executable(${program_name} ${now_main_file} ${src_files}) 
  target_include_directories(${program_name} PUBLIC ${lib_dirs})
  target_link_libraries(${program_name} antlr4-cpp-runtime)
endforeach()
