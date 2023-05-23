cmake_minimum_required(VERSION 3.9.1)
project(my_library_project)
set(LIBS "-lgomp -lpthread -lm -ldl -fopenmp ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -W -O2 ${LIBS}")
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

set(ROOT_DIR /home/maicg/Documents/Me/faceRecogCplus)
set(SOURCES
    yoloface.cpp
)
message(MaiCG)
message(${SOURCES})

set(ncnn_DIR ${ROOT_DIR}/3rdparty/ncnn/lib/cmake/ncnn)
set(OpenCV_DIR ${ROOT_DIR}/3rdparty/opencv/lib) #opencv me
find_package (ncnn REQUIRED) 
find_package( OpenCV REQUIRED )
include_directories(${ROOT_DIR}/3rdparty/faiss/include)

add_library(src SHARED ${SOURCES})

set(LINKLIB 
    ncnn
    ${OpenCV_LIBS} 
    ${CMAKE_SOURCE_DIR}/3rdparty/faiss/lib/libfaiss.so)
target_link_libraries(src PRIVATE ${LINKLIB})
