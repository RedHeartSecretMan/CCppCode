mkdir CMakeBuild
cd CMakeBuild
cmake -D CMAKE_PREFIX_PATH=/Users/WangHao/Applications/Runtime/libtorch/share/cmake ..
cmake --build . --config Release
