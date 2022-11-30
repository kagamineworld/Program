//合并排序(Mergesort)
//试验样例：
//输入数组:54,24,50,46,84,49,20,60
//输出数组:20,24,46,49,50,54,60,84

#include <stdio.h>
#include <windows.h>

int a[100];
int input(int *a);							//输入数组
void output(int *a, int n);					//输出数组
void mergesort(int *data, int p, int r);	//合并排序
void merge(int *data, int p, int q, int r); //实现具体的合并算法

int main()
{
	int n;
	//输入数组
	n = input(a);
	printf("你输入的数组为:\n");
	output(a, n);
	//进行合并排序
	mergesort(a, 0, n - 1);
	//输出数组
	printf("排序后的数组为：\n");
	output(a, n);
	system("pause");
	return 0;
}
int input(int *a) //输入数组元素
{
	int n, i;
	printf("请输入你想排序的序列中包含的元素个数(注:最多一百个):\n");
	scanf("%d", &n);
	printf("请输入该序列\n");
	//输入序列
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return n;
}
void output(int *a, int n) //输出长度为n的数组
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void mergesort(int *data, int p, int r) //合并排序，data为需要排序的数组，p为起始的第一个元素的位置，r为最后一个元素的位置
{
	int temp;  //临时存放分割位置号
	if (p < r) //只有一个或无记录时不须排序
	{
		temp = (int)((p + r) / 2);	  //将data数组分成两半
		mergesort(data, p, temp);	  //递归拆分左数组
		mergesort(data, temp + 1, r); //递归拆分右数组
		merge(data, p, temp, r);	  //合并数组
	}
}

void merge(int *data, int p, int q, int r) //实现具体的合并算法
{
	int left_n, right_n, i, j, k; // left_n为左半数组的长度，right_n为右半数组的长度
	left_n = q - p + 1;			  //左半数组长度的计算
	right_n = r - q;			  //右半数组长度的计算
	int left[left_n];			  //声明左半数组
	int right[right_n];			  //声明右半数组
	for (i = 0; i < left_n; i++)  //对左数组赋值
		left[i] = data[p + i];
	for (j = 0; j < right_n; j++) //对右数组赋值
		right[j] = data[q + 1 + j];
	i = j = 0;						  //初始化i、j
	k = p;							  //用来记录已经输入到的位置，防止while比较的时候出现重复比较的问题
	while (i < left_n && j < right_n) //将数组元素值两两比较，并合并到data数组
	{
		if (left[i] <= right[j])
			data[k++] = left[i++]; //没次录入后data的位置k就会自加1，i为记录left数组已经比较的位置
		else
			data[k++] = right[j++]; // j记录right数组已经比较的位置
	}
	for (i; i < left_n; i++)  //如果左数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = left[i];  //剩余的单独那个就是最大的一个，所以可以直接录入
	for (j; j < right_n; j++) //如果右数组有元素剩余，则将剩余元素合并到data数组
		data[k++] = right[j];
}
