#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 函数声明 */
int iadd(int b);

/* 定义全局变量 */
int i = 0;
int n = 10;
int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
  /* 定义局部变量 */
  int b1 = 0;
  int b2 = 9;

  iadd(b1);
  iadd(b2);

  typedef struct
  {
    // 每个字节存储一个字符
    char ch[64];
    // 串的实际长度
    int length;
  } SString;
  SString rr;
  const char a[] = "wang";
  strcpy(rr.ch, a);
  printf("%s,%s\n", rr.ch, a);  
  return 0;
}

int iadd(int b)
{
  /* while 循环执行 */
  while (i <= n - 1 && (A[i] != b))
  {
    i++;
  }

  /* printf 输出 */
  printf("%d\n", i);
  return i;
}