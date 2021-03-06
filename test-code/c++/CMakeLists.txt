cmake_minimum_required(VERSION 2.8)
add_definitions("-std=c++1y")

find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)
pkg_check_modules(EIGEN REQUIRED eigen3)
pkg_check_modules(NLOPT nlopt)

include_directories(${YAML_CPP_INCLUDEDIR} ${EIGEN_INCLUDE_DIRS})

set(libs ${YAML_CPP_LIBRARIES})
set(target_list yaml_test union_test eigen_test function)

foreach(target ${target_list})
  add_executable(${target} src/${target}.cpp)
  target_link_libraries(${target} ${libs})
endforeach()

if (${NLOPT_FOUND})
  include_directories(${NLOPT_INCLUDE_DIRS})
  link_directories(${NLOPT_LIBRARY_DIRS})
  add_executable(nlopt_tutorial src/nlopt_tutorial.cpp)
  target_link_libraries(nlopt_tutorial ${libs})
endif()
