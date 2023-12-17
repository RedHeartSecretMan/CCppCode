#include <stdio.h>

typedef struct Lnode {
    int a;
    struct Lnode *next;
} Lnode1, *Lp;

int main() {
    // 定义了4个结点
    struct Lnode node0;
    Lnode1 node1;
    Lnode1 node2;
    Lnode1 node3;

    // 定义了4个指向结点的指针
    Lp p0 = &node0;// p1指向第1个结点
    Lp p1 = &node1;// p1指向第1个结点
    Lp p2 = &node2;// p2指向第2个结点
    Lp p3 = &node3;// p3指向第3个结点
    Lp p4;
    printf("node address is\n%p,%p\n%p,%p\n%p,%p\n%p,%p\n", p0, &node0, p1, &node1, p2, &node2, p3, &node3);
    printf("node2 address is  %p\n", &node2);
    printf("node2.next is     %p\n", node2.next);

    printf("p2:      %p\n", p2);// 查看p2指向的结点的地址，也就是node2的地址
    printf("p2+1:    %p\n", p2 + 1);
    printf("p2->next:%p\n", p2 = p2->next);

    return 0;
}
