#include <iostream>
using namespace std;
/*
结构体计算要遵循字节对齐原则
结构体默认的字节对齐一般满足三个准则
1) 结构体变量的首地址能够被其最宽基本类型成员的大小所整除
2) 结构体每个成员相对于结构体首地址的偏移量（offset）都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节（internal adding）
3) 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在最末一个成员之后加上填充字节（trailing padding）字节对齐
*/
typedef struct TNode {
    bool bool_1;    // 1
    int int_1;      // 4
    float float_1;  // 4
    double double_1;// 8
} TNode;

int main(int argc, char const *argv[]) {
    /* code */
    TNode a;
    cout << sizeof(a) << endl;
    bool bool_2;
    cout << sizeof(bool_2) << endl;
    int int_2;
    cout << sizeof(int_2) << endl;
    float float_2;
    cout << sizeof(int_2) << endl;
    double double_2;
    cout << sizeof(double_2) << endl;
    return 0;
}
