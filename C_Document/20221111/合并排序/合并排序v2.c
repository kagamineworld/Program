//�ϲ�����(Mergesort)
//����������
//��������:54,24,50,46,84,49,20,60
//�������:20,24,46,49,50,54,60,84

#include <stdio.h>
#include <windows.h>

int a[100];
int input(int *a);							//��������
void output(int *a, int n);					//�������
void mergesort(int *data, int p, int r);	//�ϲ�����
void merge(int *data, int p, int q, int r); //ʵ�־���ĺϲ��㷨

int main()
{
	int n;
	//��������
	n = input(a);
	printf("�����������Ϊ:\n");
	output(a, n);
	//���кϲ�����
	mergesort(a, 0, n - 1);
	//�������
	printf("����������Ϊ��\n");
	output(a, n);
	system("pause");
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
void mergesort(int *data, int p, int r) //�ϲ�����dataΪ��Ҫ��������飬pΪ��ʼ�ĵ�һ��Ԫ�ص�λ�ã�rΪ���һ��Ԫ�ص�λ��
{
	int temp;  //��ʱ��ŷָ�λ�ú�
	if (p < r) //ֻ��һ�����޼�¼ʱ��������
	{
		temp = (int)((p + r) / 2);	  //��data����ֳ�����
		mergesort(data, p, temp);	  //�ݹ���������
		mergesort(data, temp + 1, r); //�ݹ���������
		merge(data, p, temp, r);	  //�ϲ�����
	}
}

void merge(int *data, int p, int q, int r) //ʵ�־���ĺϲ��㷨
{
	int left_n, right_n, i, j, k; // left_nΪ�������ĳ��ȣ�right_nΪ�Ұ�����ĳ���
	left_n = q - p + 1;			  //������鳤�ȵļ���
	right_n = r - q;			  //�Ұ����鳤�ȵļ���
	int left[left_n];			  //�����������
	int right[right_n];			  //�����Ұ�����
	for (i = 0; i < left_n; i++)  //�������鸳ֵ
		left[i] = data[p + i];
	for (j = 0; j < right_n; j++) //�������鸳ֵ
		right[j] = data[q + 1 + j];
	i = j = 0;						  //��ʼ��i��j
	k = p;							  //������¼�Ѿ����뵽��λ�ã���ֹwhile�Ƚϵ�ʱ������ظ��Ƚϵ�����
	while (i < left_n && j < right_n) //������Ԫ��ֵ�����Ƚϣ����ϲ���data����
	{
		if (left[i] <= right[j])
			data[k++] = left[i++]; //û��¼���data��λ��k�ͻ��Լ�1��iΪ��¼left�����Ѿ��Ƚϵ�λ��
		else
			data[k++] = right[j++]; // j��¼right�����Ѿ��Ƚϵ�λ��
	}
	for (i; i < left_n; i++)  //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ���data����
		data[k++] = left[i];  //ʣ��ĵ����Ǹ���������һ�������Կ���ֱ��¼��
	for (j; j < right_n; j++) //�����������Ԫ��ʣ�࣬��ʣ��Ԫ�غϲ���data����
		data[k++] = right[j];
}
