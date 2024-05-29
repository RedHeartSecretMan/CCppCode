#include <iostream>

class Animal {
public:
    virtual void sound() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Dog barks" << std::endl;
    }
};

void makeSound(Animal *animal) {
    animal->sound();
}

void heap_mode() {
    Dog *dog = new Dog();
    makeSound(dog);// Output: Dog barks
    delete dog;
}

void stack_mode() {
    Dog dog;
    makeSound(&dog);// Output: Dog barks
}

int main() {
    // 栈模式
    stack_mode();

    // 堆模式
    heap_mode();

    return 0;
}
