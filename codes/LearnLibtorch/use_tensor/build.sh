mkdir build
cd build
cmake -D CMAKE_PREFIX_PATH=/opt/homebrew/opt/pytorch/share/cmake ..
cmake --build . --config Release  # 具有跨平台一致性，不用管底层的构建系统（如 Make、Ninja、MSBuild 等）
