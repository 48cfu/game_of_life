cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project (GameOfLife  VERSION 1.0.0 LANGUAGES CXX)
add_executable(GameOfLife ${CMAKE_CURRENT_SOURCE_DIR}/source//GameOfLife.cpp)

add_library(TCONSOLE ${CMAKE_CURRENT_SOURCE_DIR}/source/ToConsole.cpp)
add_library(NBOARD ${CMAKE_CURRENT_SOURCE_DIR}/source/NormalBoard.cpp)
add_library(SBOARD ${CMAKE_CURRENT_SOURCE_DIR}/source/SpecializedBoard.cpp)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/source )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/headers/board )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/headers/printer )

# MESSAGE ("Source path: ${CMAKE_CURRENT_SOURCE_DIR}/headers")

target_link_libraries(SBOARD
    PUBLIC
        NBOARD
    PRIVATE
        TCONSOLE
)

#actually also everything else
target_include_directories(SBOARD
    PUBLIC 
        $<INSTALL_INTERFACE:include> 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/headers>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/source #actually not needed. No header file in headers
)

target_compile_options(SBOARD PRIVATE -Werror)
target_compile_features(SBOARD PRIVATE cxx_std_17)

target_link_libraries(GameOfLife SBOARD)

#INSTALL THIS LIBRARY
include(GNUInstallDirs)
install(TARGETS GameOfLife
    EXPORT gameoflife-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT gameoflife-export
  FILE
    GameOfLife.cmake
  NAMESPACE
    MY_PRECIOUS::
  DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/GameOfLife
)
MESSAGE ("MY_PRECIOUS::GAMEOfLife INStalled in: ${CMAKE_INSTALL_LIBDIR}/cmake/GameOfLife")

