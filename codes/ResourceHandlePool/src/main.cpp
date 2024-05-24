#include "ResourceHandlePool.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>


// 定义资源类
class Resource {
public:
    Resource(const std::string &name) : name_(name) {}

    std::string getName() const {
        return name_;
    }

private:
    const std::string name_;
};


// 定义资源使用函数
void useResource(ResourceHandlePool<Resource> &resource_handle_pool, int thread_id, std::mutex &cout_mutex) {
    Resource resource = resource_handle_pool.acquire();

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Thread " << thread_id << " acquired: " << resource.getName() << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Thread " << thread_id << " releasing: " << resource.getName() << std::endl;
    }

    resource_handle_pool.release(std::move(resource));
}

int main() {
    // 初始化资源句柄池
    std::queue<Resource> initial_resources;
    for (int i = 0; i < 5; ++i) {
        initial_resources.push(Resource("Resource" + std::to_string(i)));
    }

    ResourceHandlePool<Resource> resource_handle_pool(std::move(initial_resources));

    // 创建多个线程来使用资源
    std::mutex cout_mutex;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(useResource, std::ref(resource_handle_pool), i, std::ref(cout_mutex));
    }

    // 主线程等待子线程结束
    for (auto &thread: threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::cout << "All threads have completed." << std::endl;
    return 0;
}
