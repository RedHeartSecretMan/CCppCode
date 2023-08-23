#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int data;					// data域存储权值
	int parent, lchild, rchild; // 双亲与孩子
} HTNode, *HuffmanTree;

void InitHuffmanTree(HuffmanTree H, int weight, int parent, int lchild, int rchild)
{
	H->lchild = lchild;
	H->rchild = rchild;
	H->parent = parent;
	H->data = weight;
}

void CreateHuffmanTree(HuffmanTree &HT, int n, int *W)
{
	// 叶子结点的初始化，相当于n棵树，每颗树只有一个结点，那么最后构造过程总的结点个数为：2*n-1
	// n-1+n = 2*n-1

	HT = (HuffmanTree)malloc((2 * n - 1) * sizeof(HTNode)); // n个叶子结点的哈夫曼树结点是2n-1;
	for (int i = 0; i < n; i++)
	{
		InitHuffmanTree(HT + i, W[i], -1, -1, -1); // 初始化-1
	}
	// 开始寻找最小的两个叶子结点，构造哈夫曼树
	for (int i = n; i < 2 * n - 1; i++)
	{								   // 我们构造n-1个度为2的结点
		int min1 = 65522, min2 = min1; // 这里的两个数分别代表第一小，第二小
		int x1 = -1, x2 = -1;		   // 用来记录下标
		for (int j = 0; j < i; j++)
		{
			if ((HT + j)->parent == -1) //表示叶子结点没有父母
			{
				if ((HT + j)->data < min1)
				{
					min2 = min1;
					min1 = (HT + j)->data;
					x2 = x1;
					x1 = j;
				}
				else if ((HT + j)->data < min2)
				{
					min2 = (HT + j)->data;
					x2 = j;
				}
			}
		}
		// 合并两个叶子，让他们有同一个双亲
		(HT + x1)->parent = i;
		(HT + x2)->parent = i;
		// 然后我们让HT[i]指向这两个孩子，为了后来的逆序哈夫曼编码

		InitHuffmanTree(HT + i, min2 + min1, -1, x1, x2); // 父结点构造
	}
}

void HuffmanTreeCode(HuffmanTree HT, char *str, int n, int path, int &e)
{
	int i = 0, j = 0, m = 0;
	int child = path; // 假设我们现在在叶子结点为child索引的地方，如1

	int parent = (HT + child)->parent; // 获取第一个叶子结点的父节点 的值
	// printf("leafe node is:%d \n",(HT+child)->data);

	// 开始逆序寻找根节点，及生成编码
	for (i = n - 1; parent != -1; i--) // 当前结点不是根结点 ,逆序
		if ((HT + parent)->lchild == child)
		{ // 他的双亲指向的左孩子是不是我们当前遍历的这个叶子
			str[j++] = '0';
			child = parent; // 此时parent！=-1 ，表示还有父节点
			parent = (HT + child)->parent;
		}
		else
		{
			str[j++] = '1'; // 实现编码
			child = parent;
			parent = (HT + child)->parent;
		}
	e = j; // 表示一个叶子结点的编码结束
}

int main()
{
	int i, n;
	int *w, e;

	HuffmanTree HT;
	printf("Node Number:");
	scanf("%d", &n);					// 权值个数
	w = (int *)malloc(n * sizeof(int)); // 权值数组
	printf("Input weights:");
	for (i = 0; i < n; i++) // 录入权值
		scanf("%d", &w[i]);
	CreateHuffmanTree(HT, n, w);
	printf("the first node is:%d\n",HT->data);
	printf("create sussessfully\n");

	char str[n];
	for (int k = 0; k < n; k++)
	{
		HuffmanTreeCode(HT, str, n, k, e);
		for (int j = e - 1; j >= 0; j--)
			printf("%c", str[j]);
		printf("\n");
	}
	free(HT);
	return 0;
}
