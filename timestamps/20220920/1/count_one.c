#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// 位移法
int displace_count_1(uint32_t x){
    int count=0;
    while(x){
        if(x&0x1)
            ++count;
        x=(x>>1);
    }
    return count;
}


// 去1法
int leave_one_count_1(uint32_t x){
    int count = 0;
    while(x){
        x = x & (x-1);
        count++;
    }
    return count;
}


// 分治法
int divide_count_1(uint32_t n ){  
    n = (n&0x55555555) + ((n>>1)&0x55555555);  
    n = (n&0x33333333) + ((n>>2)&0x33333333);  
    n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);  
    n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff);  
    n = (n&0x0000ffff) + ((n>>16)&0x0000ffff);
    return n;  
}


int main(){
    uint32_t x = 128, y = 128, z = 128;
    x = displace_count_1(x);
    printf("%d\n", x);
    y = leave_one_count_1(y);
    printf("%d\n", y);
    z = leave_one_count_1(z);
    printf("%d\n", z);
}