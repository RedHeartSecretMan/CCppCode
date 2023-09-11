mkdir CMakeBuild
cd CMakeBuild
cmake -D CMAKE_PREFIX_PATH=/opt/homebrew/opt/pytorch/share/cmake ..
cmake --build . --config Release
