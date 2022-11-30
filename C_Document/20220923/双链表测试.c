#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//˫��ѭ������
typedef struct Dnode {
	int data;
	struct Dnode* next;
	struct Dnode* prior;
} Dnode, *linkList;

//˫������ĳ�ʼ��
void initList(linkList* head) {
	*head = (linkList)malloc(sizeof(Dnode));
	(*head)->next = *head;
	(*head)->prior = *head;
	(*head)->data = 999;
}

//˫������Ĳ���(��������ʵ�ֹ���index���Ϸ������)
void insertIndex(linkList* head, int index, int e) {
	Dnode* node = (Dnode*)malloc(sizeof(Dnode));
	node->data = e;
	node->next = NULL;
	node->prior = NULL;

	Dnode* p = (*head)->next;
	int i = 0;
	while (p->next != (*head) && i < index)
	{
		p = p->next;
		i++;
	}

	node->prior = p->prior;
	p->prior->next = node;
	node->next = p;
	p->prior = node;
	return;
}

//˫�������ɾ��
void deleteIndex(linkList* head, int index, int* e) {
	int i = -1;
	Dnode* p = (*head);
	while (p->next != (*head) && i < index)
	{
		p = p->next;
		i++;
	}
	//�����ﲻ�����������������ִ�е������ʾ��p������ǵ�ǰҪɾ���Ľڵ�
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
}

//˫������ı���
void show(linkList head) {
	if (head->next == head)
	{
		printf("������û��Ԫ��\n");
	}
	else
	{
		printf("��������Ԫ�أ���ʼ����\n");
		Dnode* p = head->next;
		int i = 0;
		while (p != head) {
			printf("�����еĵ�%d��Ԫ����%d\n", i, p->data);
			p = p->next;
			i++;
		}
	}
}

void main() {
	linkList head;
	initList(&head);
	show(head);

	printf("����˫��ѭ������Ĳ���\n");
	insertIndex(&head, 0, 0);
	insertIndex(&head, 1, 1);
	insertIndex(&head, 1, 2);
	show(head);

	for (int i = 5; i < 9; i++)
	{
		insertIndex(&head, i, i);
	}
	show(head);

	printf("����˫��ѭ�������ɾ��\n");
	int res;
	int index = 1;
	deleteIndex(&head, index, &res);
	show(head);
	printf("��ɾ�����ǵ�%d��Ԫ��%d\n", index, res);

}
