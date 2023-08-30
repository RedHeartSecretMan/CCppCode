cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(use_tensor)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

aux_source_directory(src file_list)
message("Processing source file: ${file_list}")

add_executable(use_tensor_rand ${file_list})
target_link_libraries(use_tensor_rand "${TORCH_LIBRARIES}")
set_property(TARGET use_tensor_rand PROPERTY CXX_STANDARD 17)
