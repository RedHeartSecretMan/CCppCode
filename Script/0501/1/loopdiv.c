#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float loopdiv(int a, int b, int m, char *mode);

int main()
{   
    clock_t start, finish;
    double  duration; 
    int a = 2;
    int b = 2;
    int m = 1e9;
    char *mode = "for";
    float c;
    start = clock(); 
    c = loopdiv(a, b, m, mode);
    finish = clock();  
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("运行总时间%f秒\n", duration); 
    return 0;
}

float loopdiv(int a, int b, int m, char *mode)
{
    float c;
    int i = 0;
    if(strcmp(mode, "for")==0)
    {
        for(i=0; i < m; i++)
        {
            c = a / b;
        }
    }
    else
    {
        while(i<m)
        {
            c = a / b;
            i++;
        }
    }
    return c;
}