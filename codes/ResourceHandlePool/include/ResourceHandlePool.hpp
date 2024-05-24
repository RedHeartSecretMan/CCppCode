#ifndef RESOURCE_HANDLE_POOL_HPP
#define RESOURCE_HANDLE_POOL_HPP

#include <condition_variable>
#include <mutex>
#include <queue>

// 资源类型模板定义
template<typename ResourceType>

// 资源句柄池类定义
class ResourceHandlePool {
public:
    // 定义公有成员函数
    // 构造函数：用给定的一组资源初始化资源池
    ResourceHandlePool(std::queue<ResourceType> initial_resources)
        : resource_queue_(std::move(initial_resources)) {}

    // 获取资源：从池中获取一个资源
    ResourceType acquire() {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_var_.wait(lock, [this]() { return !resource_queue_.empty(); });

        ResourceType resource = resource_queue_.front();
        resource_queue_.pop();
        return resource;
    }

    // 释放资源：将资源释放回池中
    void release(ResourceType resource) {
        std::lock_guard<std::mutex> lock(mutex_);
        resource_queue_.push(std::move(resource));
        cond_var_.notify_one();
    }

private:
    // 定义私有成员变量
    // 资源队列
    std::queue<ResourceType> resource_queue_;
    // 互斥锁
    std::mutex mutex_;
    // 条件变量
    std::condition_variable cond_var_;
};

#endif
