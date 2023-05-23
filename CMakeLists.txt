cmake_minimum_required(VERSION 3.9.1)
project(faceDetection)
set(LIBS "-lgomp -lpthread -lm -ldl -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -W -O2 ${LIBS}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(ncnn_DIR ${CMAKE_SOURCE_DIR}/3rdparty/ncnn/lib/cmake/ncnn)
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/3rdparty/opencv/lib) #opencv me
find_package (ncnn REQUIRED) 
find_package( OpenCV REQUIRED )

include_directories(${CMAKE_SOURCE_DIR}/3rdparty/faiss/include)


#7.1.add executable file
add_executable(faceDetection main.cpp)

add_subdirectory(src)

# #7.2.add library file
# add_library(faceDetection SHARED ${MBF_COMPILE_CODE})

set(MYLIB 
    src
    ncnn
    ${OpenCV_LIBS} 
    ${CMAKE_SOURCE_DIR}/3rdparty/faiss/lib/libfaiss.so)

#8.add link library
target_link_libraries(faceDetection ${MYLIB} )