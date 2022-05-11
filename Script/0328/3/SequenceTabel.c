#include <stdio.h>
#include <stdlib.h>
#define Size 5

// 定义布尔类型false=0与true=1
typedef enum
{
    false,
    true
} bool;

// 定义结构类型SequenceTabel[...]叫ST
typedef struct SequenceTabel
{
    int *head;
    int size;
    int length;
} ST;

/* Init */
ST initST();
/* Length */
int lengthST(ST st);
/* Print */
void dispalyST(ST);
/* Insert */
ST addST(ST st, int idx, int elem);
/* Delete */
ST deleteST(ST st, int idx);
/* LocateElement */
bool findST(ST st, int elem);
/* GetElement */
bool emptyST(ST st);
/* Empty */
int getST(ST st, int idx);
/* Destroy */
bool destroyST(ST st);

ST initST()
{
    ST st;
    /* malloc申请一块连续的指定大小的内存块区域作为数组
    分配成功则返回数组的头指针，否则返回空指针NULL
    calloc(size,sizeof(int))会初始化数组元素为0
    sizeof计算一个int型变量占内存多少单元
    (int *)将指针指向的数据强制转换为整型 */
    st.head = (int *)malloc(Size * sizeof(int));
    if (!st.head)
    {
        printf("没有分配内存");
        exit(0);
    }
    st.size = Size;
    st.length = 0;
    return st;
}

int main()
{
    // 初始化顺序素
    ST st = initST();
    for (int i = 1; i <= Size; i++)
    {
        st.head[i - 1] = i;
        st.length++;
    }

    // 求表长
    int l;
    l = lengthST(st);
    printf("顺序表长%d\n", l);

    // 打印元素
    printf("打印初始化的顺序表\n");
    dispalyST(st);

    // 插入元素
    st = addST(st, 1, 6);
    printf("打印插入元素后的顺序表\n");
    dispalyST(st);

    // 删除元素
    st = deleteST(st, 1);
    printf("打印删除元素后的顺序表\n");
    dispalyST(st);

    // 按值找位
    int e = 9;
    int idx;
    idx = findST(st, e);
    if (idx)
    {
        printf("查询元素%d在的顺序表的序位是%d\n", e, idx);
    }
    else
    {
        printf("查询元素%d不在的顺序表\n", e);
    }

    // 按位找值
    e = getST(st, idx = 4);
    printf("顺序表位序%d的元素是%d\n", idx, e);

    // 判空
    bool flag;
    flag = emptyST(st);
    if (flag)
    {
        printf("顺序表是空的\n");
    }
    else
    {
        printf("顺序表不是空的\n");
    }

    // 销毁
    destroyST(st);

    return 0;
}

int lengthST(ST st)
{
    int e = st.length;
    return e;
}

void dispalyST(ST st)
{
    for (int i = 0; i < st.length; i++)
    {
        int print = st.head[i];
        printf("打印第%d的值是:%d\n", i, print);
    }
    printf("\n");
}

ST addST(ST st, int idx, int elem)
{
    if ((idx < 0) || (idx > st.length + 1))
    {
        printf("插入位置有问题\n");
        return st;
    }
    if (st.length == st.size)
    {
        st.head = (int *)realloc(st.head, (st.size + 1) * sizeof(int));
        if (!st.head)
        {
            printf("没有头指针存储空间分配失败\n");
            return st;
        }
        st.size += 1;
    }
    for (int i = st.length - 1; i >= idx - 1; i--)
    {
        st.head[i + 1] = st.head[i];
    }
    st.head[idx - 1] = elem;
    printf("出入元素%d\n", elem);
    st.length++;
    return st;
}

ST deleteST(ST st, int idx)
{
    if ((idx < 0) || (idx > st.length))
    {
        printf("删除位置有问题\n");
        return st;
    }
    int elem = st.head[idx - 1];
    printf("删除元素%d\n", elem);
    for (int j = idx; j < st.length; j++)
    {
        st.head[j - 1] = st.head[j];
    }
    st.length -= 1;
    st.head = (int *)realloc(st.head, (st.size - 1) * sizeof(int));
    st.size -= 1;
    return st;
}

bool findST(ST st, int elem)
{
    for (int i = 0; i < st.length; i++)
    {
        if (st.head[i] == elem)
        {
            return i + 1;
        }
    }
    return false;
}

int getST(ST st, int idx)
{
    int e = st.head[idx];
    return e;
}

bool emptyST(ST st)
{
    if (st.length == 0)
    {
        return true;
    }
    return false;
}

bool destroyST(ST st)
{
    free(st.head);
    st.head = NULL;
    return true;
}
