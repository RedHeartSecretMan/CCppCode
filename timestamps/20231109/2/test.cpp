#include <iostream>

// 定义一个函数，接收一个整数参数并将其加倍（值传递）
void doubleValueByValue(int x) {
    x *= 2;
}

// 定义一个函数，接收一个整数指针参数并将其加倍（指针传递）
void doubleValueByPointer(int *x) {
    if (x != nullptr) {
        *x *= 2;
    }
}

// 定义一个函数，接收一个整数引用参数并将其加倍（引用传递）
void doubleValueByReference(int &x) {
    x *= 2;
}

int main() {
    int num1 = 5;
    int num2 = 5;
    int num3 = 5;

    std::cout << "Original values:" << std::endl;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    std::cout << "num3: " << num3 << std::endl;

    // 使用值传递
    doubleValueByValue(num1);
    // 使用指针传递
    doubleValueByPointer(&num2);
    // 使用引用传递
    doubleValueByReference(num3);

    std::cout << "After function calls:" << std::endl;
    std::cout << "num1 (Value): " << num1 << std::endl;    // 应该仍然是 5
    std::cout << "num2 (Pointer): " << num2 << std::endl;  // 应该是 10
    std::cout << "num3 (Reference): " << num3 << std::endl;// 应该是 10

    return 0;
}
