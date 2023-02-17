#include<stdio.h>

int search_num(int (*p)[3], int *r, int *c, int k){
	//定位行和列，
	int x= 0;//0行
	int y = *c - 1;//最右边的列
	while (x<*r&&y>=0){
		if (p[x][y]>k){//比较最右上角元素
			y--;//最右上角的元素大，就划去一列
		}
		else if(p[x][y] < k){
			x++;//最右上角的元素小划去一行
		}
		else {
			*r = x;
			*c = y;
			return 1;
		}
	}
}

int main(){
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 5;
	int r = 3;
	int c = 3;
	// &r &c  两个功能：1，传入参数 2，带回值
	int ret=search_num(arr, &r, &c, k);
	//返回1说明找到了
	if (ret == 1){
		printf("找到了,下标是%d，%d", r, c);
	}
	else printf("没找到");
	return 0;
}