mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/pytorch/share/cmake ..
cmake --build . --config Release
