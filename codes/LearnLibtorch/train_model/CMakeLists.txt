cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(train_model)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# 使用 python 脚本下载数据集
option(DOWNLOAD_MNIST "Download the MNIST dataset from the internet" ON)
if (DOWNLOAD_MNIST)
  message(STATUS "Downloading MNIST dataset")
  execute_process(
    COMMAND python ${CMAKE_CURRENT_LIST_DIR}/../tools/download_mnist.py
      -d ${CMAKE_BINARY_DIR}/data
    ERROR_VARIABLE DOWNLOAD_ERROR)
  if (DOWNLOAD_ERROR)
    message(FATAL_ERROR "Error downloading MNIST dataset: ${DOWNLOAD_ERROR}")
  endif()
endif()

aux_source_directory(src source_file_list)

# 遍历 ${source_file_list} 中的每个源文件
foreach(source_file ${source_file_list})
  message("Processing source file: ${source_file}")
  if(${source_file} STREQUAL "src/demo.cpp")
    get_filename_component(source_file_name_we ${source_file} NAME_WE)
    add_executable(${source_file_name_we} ${source_file})
    target_compile_features(${source_file_name_we} PUBLIC cxx_range_for)
    target_link_libraries(${source_file_name_we} "${TORCH_LIBRARIES}")
    set_property(TARGET ${source_file_name_we} PROPERTY CXX_STANDARD 17)
  elseif(${source_file} STREQUAL "src/mnist.cpp")
    get_filename_component(source_file_name_we ${source_file} NAME_WE)
    add_executable(${source_file_name_we} ${source_file})
    target_compile_features(${source_file_name_we} PUBLIC cxx_range_for)
    target_link_libraries(${source_file_name_we} "${TORCH_LIBRARIES}")
    set_property(TARGET ${source_file_name_we} PROPERTY CXX_STANDARD 17)
  endif()
endforeach()
