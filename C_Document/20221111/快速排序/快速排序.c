//��������
//����һ������a[p:r],pΪ��һ��Ԫ�أ�rΪ���һ��Ԫ��
// 1.�ֽ�(divide)����һ����a[q]Ϊ��׼������a[p:r]��Ϊ��a[p:q-1]�����е��κ�Ԫ�ض�С��a[q],a[q],a[q+1:r]�������κ�Ԫ�ض�����a[q];
// 2.�ݹ����(conquer)���ݹ���ÿ��������㷨�����������߽�������
// 3.�ϲ�(merge)����Ϊ���߶��ź���󣬲���Ҫִ���κμ��㣻
//����������
//��������1��1,2,4,3,5
//�������1��1,2,3,4,5
//��������2��0,5,1,2,4,8,6,3,7,9
//�������2��0,1,2,3,4,5,6,7,8,9
#include <stdio.h>

int a[100];
int input(int *a);					  //��������
void output(int *a, int n);			  //�������
void swap(int i, int j);			  ////������i��Ԫ�غ͵�j��Ԫ��λ��
void quicksort(int *a, int p, int r); //��������
int partition(int *a, int p, int r);  //���������м���

int main()
{
	int n, p, r;
	//��������
	n = input(a);
	printf("�����������Ϊ:\n");
	output(a, n);
	//���п�������
	p = 0;
	r = n;
	quicksort(a, p, r);
	//�������
	printf("����������Ϊ��\n");
	output(a, n);
	return 0;
}

int input(int *a) //��������Ԫ��
{
	int n, i;
	printf("��������������������а�����Ԫ�ظ���(ע:���һ�ٸ�):\n");
	scanf("%d", &n);
	printf("�����������\n");
	//��������
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return n;
}
void output(int *a, int n) //�������Ϊn������
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void swap(int i, int j) //����
{
	int c;
	c = 0;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}
void quicksort(int *a, int p, int r) //��������
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q);		//���������
		quicksort(a, q + 1, r); //���Ұ�����
	}
}
int partition(int *a, int p, int r) //�ֽ�
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
	//����ע�͵Ĵ��������޸�bug��
	// printf("��ǰ��׼��Ϊ��%d�ĸ�:%d\n", j, a[j]);
	// printf("��ǰ����Ϊ��\n");
	// output(a, r);
	// printf("\n");
	return j;
}
