cmake_minimum_required(VERSION 2.8)
project(tf_pcd_bin_txt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

find_package(PCL 1.8)
include_directories(
        include
        ${PCL_INCLUDE_DIRS}
)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)
add_library(${PROJECT_NAME} SHARED
        ${SRC_DIR}
        )
target_link_libraries(${PROJECT_NAME}
        ${PCL_LIBRARIES}
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(bin2pcd bin2pcd.cpp)
target_link_libraries(bin2pcd ${PROJECT_NAME})

add_executable(pcd2txt pcd2txt.cpp)
target_link_libraries(pcd2txt ${PROJECT_NAME})

add_executable(txt2pcd txt2pcd.cpp)
target_link_libraries(txt2pcd ${PROJECT_NAME})
