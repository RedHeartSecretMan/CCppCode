#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a11 = 3;

bool abc(int a11) {
    a11 = 5;
    printf("输出结果%d\n", a11);
    return a11;
}

int main() {
    int a = 2000;
    int *b = &a;
    int c[5] = {0, 1, 2, 3, 4};
    int *d = &c[0];
    int *e = d;
    int *p = (int *) malloc(5 * sizeof(int));
    int **q = &p;
    int *y = *q;
    int z = **q;
    int a1 = 1;
    int *p1 = &a1;
    float *p11 = (float *) p1;
    char r[] = "wanghao";
    char rr[6] = "wang";
    abc(a11);

    printf("输出结果%d,%p,%d,%p,%d,%p,%p\n", a, &a, *b, b, c[1], d, e);
    printf("输出结果%d,%p,%p,%p,%d\n", *p, p, q, y, z);
    printf("输出结果%p,%f,%d\n", p11, *p11, a11);
    printf("输出结果%d\n", a11);
    printf("输出结果%s,%s\n", r, rr);

    bool t1, t2 = 0;
    int t3 = true;

    printf("输出结果%d,%d,%d\n", t1, t2 = 3, t3);

    int *ddd;
    int ccc[2] = {1, 2};
    ddd = &ccc[0];
    ddd++;

    printf("输出结果%p,%d\n", ddd, *ddd);
    printf("输出结果%p,%d,%d\n", ddd, *ddd, (*ddd)++);

    int aa1[2] = {1, 2};
    int *ppp = &aa1[0];
    int aa2 = *(ppp - 1);
    int aa3 = *(ppp + 1);
    printf("输出结果%d,%d,%d,%d\n", aa1[1], aa2, aa3, *ppp++);
}
