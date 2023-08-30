mkdir CMakeBuild
cd CMakeBuild
cmake -D CMAKE_PREFIX_PATH=`python -c 'import torch; print(torch.utils.cmake_prefix_path)'` ..
cmake --build . --config Release
