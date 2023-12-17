#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREATEMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int status;
typedef struct stack {
    int *base;
    int *top;
    int stacksize;
} sqstack;

// 传入顺序栈的引用参数初始化
status initstack(sqstack &s) {
    s.base = (int *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!s.base)
        exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

// 入栈
status push(sqstack &s, int e) {
    // 栈满
    if (s.top - s.base >= s.stacksize) {
        s.base = (int *) realloc(s.base, (s.stacksize + STACKINCREATEMENT) * sizeof(int));

        if (!s.base)
            exit(OVERFLOW);

        s.top = s.base + s.stacksize;
        s.stacksize = s.stacksize + STACKINCREATEMENT;
    }

    *s.top = e;
    s.top++;
    return OK;
}

// 出栈
status pop(sqstack &s, int &e) {
    // 栈空
    if (s.base == s.top)
        return ERROR;

    // 取出栈顶元素
    e = *(s.top - 1);
    // 指针top减一
    s.top--;
    return OK;
}

// 获取栈顶元素
status gettop(sqstack &s, int &e) {
    if (s.base == s.top)
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

// 打印栈中数据元素
status printstack(sqstack s) {
    if (s.base == s.top) {
        printf("空栈\n");
        return ERROR;
    } else
        printf("栈的内容为:");

    for (s.base; s.base != s.top; s.base++) {
        printf("%d  ", *s.base);
    }

    return OK;
}

int main() {
    sqstack s;
    int x = 1;
    initstack(s);

    while (1) {
        printf("请输入要进行的操作:\n");
        printf(" 1.进栈\n 2.出栈\n 3.获取栈顶元素\n 4.打印\n 0.退出\n");
        scanf("%d", &x);
        if (x == 0)
            break;
        switch (x) {
            case 0:
                free(s.base);
                s.base = NULL;
                break;
            case 1:
                int pushnumber;
                printf("请输入要进栈的元素:");
                scanf("%d", &pushnumber);
                if (push(s, pushnumber))
                    printf("进栈成功\n");
                else
                    printf("进栈失败\n");
                break;
            case 2:
                int e;
                if (pop(s, e))
                    printf("元素%d出栈\n", e);
                else
                    printf("出栈失败\n");
                break;
            case 3:
                if (gettop(s, e))
                    printf("栈顶元素是:%d\n", e);
                else
                    printf("获取栈顶元素失败\n");
                break;
            case 4:
                if (printstack(s))
                    printf("打印完毕\n");
                break;
            default:
                printf("您进行了误操作，请重试\n");
                break;
        }
    }
    return 1;
}