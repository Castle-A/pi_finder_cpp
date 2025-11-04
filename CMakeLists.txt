cmake_minimum_required(VERSION 3.16)
project(pi_finder_cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig QUIET)
if (PkgConfig_FOUND)
  pkg_check_modules(MPFR_PKG mpfr)
  pkg_check_modules(GMP_PKG gmp)
endif()

if (MPFR_PKG_FOUND AND GMP_PKG_FOUND)
  message(STATUS "Using MPFR via pkg-config")
  add_library(mpfr::mpfr INTERFACE IMPORTED)
  target_include_directories(mpfr::mpfr INTERFACE ${MPFR_PKG_INCLUDE_DIRS})
  target_link_directories(mpfr::mpfr INTERFACE ${MPFR_PKG_LIBRARY_DIRS})
  target_link_libraries(mpfr::mpfr INTERFACE ${MPFR_PKG_LIBRARIES})

  add_library(gmp::gmp INTERFACE IMPORTED)
  target_include_directories(gmp::gmp INTERFACE ${GMP_PKG_INCLUDE_DIRS})
  target_link_directories(gmp::gmp INTERFACE ${GMP_PKG_LIBRARY_DIRS})
  target_link_libraries(gmp::gmp INTERFACE ${GMP_PKG_LIBRARIES})
else()
  find_path(MPFR_INCLUDE_DIR mpfr.h)
  find_library(MPFR_LIBRARY NAMES mpfr)
  find_path(GMP_INCLUDE_DIR gmp.h)
  find_library(GMP_LIBRARY NAMES gmp)
  if (NOT MPFR_INCLUDE_DIR OR NOT MPFR_LIBRARY OR NOT GMP_INCLUDE_DIR OR NOT GMP_LIBRARY)
    message(FATAL_ERROR "MPFR/GMP not found. Install via your package manager or vcpkg (see README).")
  endif()
  add_library(mpfr::mpfr INTERFACE IMPORTED)
  set_target_properties(mpfr::mpfr PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${MPFR_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${MPFR_LIBRARY}")

  add_library(gmp::gmp INTERFACE IMPORTED)
  set_target_properties(gmp::gmp PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
    INTERFACE_LINK_LIBRARIES "${GMP_LIBRARY}")
endif()

add_executable(pi_finder src/main.cpp)
target_include_directories(pi_finder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(pi_finder PRIVATE mpfr::mpfr gmp::gmp)
