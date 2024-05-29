#include <iostream>

// 基类模板
template<typename T>
class Animal {
public:
    void sound() {
        static_cast<T *>(this)->makeSound();// 静态多态
    }
};

// 派生类模板
class Dog : public Animal<Dog> {
public:
    void makeSound() {
        std::cout << "Dog barks" << std::endl;
    }
};


void heap_mode() {
    Dog *dog = new Dog();
    dog->sound();// Output: Dog barks
    delete dog;
}

void stack_mode() {
    Dog dog;
    dog.sound();// Output: Dog barks
}


int main() {
    // 栈模式
    stack_mode();

    // 堆模式
    heap_mode();

    return 0;
}
