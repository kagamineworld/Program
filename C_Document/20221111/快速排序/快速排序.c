//快速排序
//输入一个数组a[p:r],p为第一个元素，r为最后一个元素
// 1.分解(divide)：以一个数a[q]为基准将数组a[p:r]分为，a[p:q-1]：其中的任何元素都小于a[q],a[q],a[q+1:r]：其中任何元素都大于a[q];
// 2.递归求解(conquer)：递归调用快速排序算法，对左右两边进行排序；
// 3.合并(merge)：因为两边都排好序后，不需要执行任何计算；
//试验样例：
//输入数组1：1,2,4,3,5
//输出数组1：1,2,3,4,5
//输入数组2；0,5,1,2,4,8,6,3,7,9
//输出数组2：0,1,2,3,4,5,6,7,8,9
#include <stdio.h>

int a[100];
int input(int *a);					  //输入数组
void output(int *a, int n);			  //输出数组
void swap(int i, int j);			  ////交换第i个元素和第j个元素位置
void quicksort(int *a, int p, int r); //快速排序
int partition(int *a, int p, int r);  //从两边向中间走

int main()
{
	int n, p, r;
	//输入数组
	n = input(a);
	printf("你输入的数组为:\n");
	output(a, n);
	//进行快速排序
	p = 0;
	r = n;
	quicksort(a, p, r);
	//输出数组
	printf("排序后的数组为：\n");
	output(a, n);
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
void swap(int i, int j) //交换
{
	int c;
	c = 0;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}
void quicksort(int *a, int p, int r) //快速排序
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q);		//对左半排序
		quicksort(a, q + 1, r); //对右半排序
	}
}
int partition(int *a, int p, int r) //分解
{
	int i = p;
	int j = r;
	int x = a[p];
	while (1)
	{
		while (a[++i] < x && i < r)
			;
		while (a[--j] > x)
			;
		if (i > j)
			break;
		swap(i, j);
	}
	a[p] = a[j];
	a[j] = x;
	//以下注释的代码用于修改bug：
	// printf("当前基准数为第%d的个:%d\n", j, a[j]);
	// printf("当前数组为：\n");
	// output(a, r);
	// printf("\n");
	return j;
}
