# ResourceHandlePool

This project demonstrates a generic resource handle pool using templates and condition variables in C++. The resource pool can be used to manage any type of resources in a thread-safe manner.

## Project Structure

```sh
ResourceHandlePool/
├── include/
│ └── ResourceHandlePool.hpp
├── src/
│ └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Building the Project

1. Navigate to the project directory:

```sh
cd ResourceHandlePool
mkdir build
cd build
cmake ..
make
```

### 运行示例

构建并运行项目时，将看到多个线程在获取和释放资源的输出，类似如下：

```sh
./ResourceHandlePool
Thread 0 acquired: Resource0
Thread 1 acquired: Resource1
Thread 2 acquired: Resource2
Thread 3 acquired: Resource3
Thread 4 acquired: Resource4
Thread 0 releasing: Resource0
Thread 1 releasing: Resource1
Thread 5 acquired: Resource0
Thread 2 releasing: Resource2
Thread 3 releasing: Resource3
Thread 4 releasing: Resource4
Thread 7 acquired: Resource2
Thread 6 acquired: Resource1
Thread 8 acquired: Resource3
Thread 9 acquired: Resource4
Thread 5 releasing: Resource0
Thread 8 releasing: Resource3
Thread 7 releasing: Resource2
Thread 6 releasing: Resource1
Thread 9 releasing: Resource4
...
```
