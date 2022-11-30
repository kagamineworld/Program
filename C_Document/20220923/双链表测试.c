#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//双向循环链表
typedef struct Dnode {
	int data;
	struct Dnode* next;
	struct Dnode* prior;
} Dnode, *linkList;

//双向链表的初始化
void initList(linkList* head) {
	*head = (linkList)malloc(sizeof(Dnode));
	(*head)->next = *head;
	(*head)->prior = *head;
	(*head)->data = 999;
}

//双向链表的插入(在这里有实现关于index不合法的情况)
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

//双向链表的删除
void deleteIndex(linkList* head, int index, int* e) {
	int i = -1;
	Dnode* p = (*head);
	while (p->next != (*head) && i < index)
	{
		p = p->next;
		i++;
	}
	//在这里不考虑其他情况，程序执行到这里表示：p代表的是当前要删除的节点
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
}

//双向链表的遍历
void show(linkList head) {
	if (head->next == head)
	{
		printf("链表中没有元素\n");
	}
	else
	{
		printf("链表中有元素，开始遍历\n");
		Dnode* p = head->next;
		int i = 0;
		while (p != head) {
			printf("链表中的第%d个元素是%d\n", i, p->data);
			p = p->next;
			i++;
		}
	}
}

void main() {
	linkList head;
	initList(&head);
	show(head);

	printf("测试双向循环链表的插入\n");
	insertIndex(&head, 0, 0);
	insertIndex(&head, 1, 1);
	insertIndex(&head, 1, 2);
	show(head);

	for (int i = 5; i < 9; i++)
	{
		insertIndex(&head, i, i);
	}
	show(head);

	printf("测试双向循环链表的删除\n");
	int res;
	int index = 1;
	deleteIndex(&head, index, &res);
	show(head);
	printf("被删除的是第%d个元素%d\n", index, res);

}
