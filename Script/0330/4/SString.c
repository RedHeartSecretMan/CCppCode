#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    // 每个字节存储一个字符
    char ch[64];
    // 串的实际长度
    int length;
} SString;

int BFIndex(SString sm, SString sp)
{
    int i = 0; // 主串的匹配起始位置
    int j = 0; // 模式串的匹配起始位置

    while (i < sm.length && j < sp.length)
    {
        if (sm.ch[i] == sp.ch[j])
        {
            ++i; // 当前字符匹配成功，两者均往后走一个位置
            ++j;
        }
        else
        {
            i = i - j + 1; // 每次未匹配成功时i回退到原来i的后一位置
            j = 0;         // 模式串每次未匹配成功时回退到0位置
        }
    }
    if (j >= sp.length) // 条件满足说明j走过了模式串的所有字符
    {
        return i - j;
    }
    return -1;
}

void GetNext(SString sp, int *next)
{
    int i = 1;
    int j = 0;
    next[0] = -1;
    next[1] = 0;

    while (i < sp.length)
    {
        if (j == -1 || sp.ch[i] == sp.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int KMPIndex(SString sm, SString sp)
{
    int i = 0;
    int j = 0;
    int *next = (int *)malloc(sizeof(int) * sp.length);
    GetNext(sp, next);
    while (i < sm.length && j < sp.length)
    {
        if (j == -1 || sm.ch[i] == sp.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= sp.length)
    {
        return i - j;
    }
    return -1;
}

int main()
{
    SString sm;
    char MainStr[] = "i am wanghao";
    strcpy(sm.ch, MainStr);
    sm.length = strlen(MainStr);

    SString sp;
    char PatternStr[] = "wang";
    strcpy(sp.ch, PatternStr);
    sp.length = strlen(PatternStr);

    int Postion1 = BFIndex(sm, sp);
    int Postion2 = KMPIndex(sm, sp);
    printf("匹配位置 = %d,%d\n", Postion1, Postion2);

    return 0;
}
