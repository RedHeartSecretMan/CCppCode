#include <stdio.h>
#include <stdlib.h>


// 找到奇次数的数
int main()
{
    int arr[] = {1,1,2,2,3,3,3,4,4,4,4};
    int eor = 0;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        eor ^= arr[i];
    }
    printf("%d\n", eor); 
    return 0;
}
