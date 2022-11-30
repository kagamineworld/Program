#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int datatype;
#define maxsize 2
typedef struct dnode
{
    datatype data[maxsize];
    struct dnode *prior, *next;
    /* data */
} Dnode, *linkList;

//双向链表的初始化
void initList(linkList* head) {
	*head = (linkList)malloc(sizeof(Dnode));
	(*head)->next = *head;
	(*head)->prior = *head;
	(*head)->data[0] = 999;
    (*head)->data[1] = 999;
}

void insertIndex(linkList* head, int e,int f) {
	Dnode* node = (Dnode*)malloc(sizeof(Dnode));
	node->data[0] = e;
    node->data[1] = f;
	node->next = NULL;
	node->prior = NULL;

	Dnode* p = (*head)->next;
	int i = 0;
	while (p->next != (*head))
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

//双向链表的遍历
void show(linkList head) {
	if (head->next == head)
	{

	}
	else
	{
		printf("链表中有元素，开始遍历\n");
		Dnode* p = head->next;
		int i = 0;
		while (p != head) {
			printf("链表中的众数是%d它的重数是%d\n", p->data[0], p->data[1]);
			p = p->next;
			i++;
		}
	}
}

int main()
{
    linkList head;
	initList(&head);
	show(head);
    int s[7]={1,2,2,2,3,3,5};
    int i,j,a,b;

    for ( i = 0; i < 7; i++)
    {
        a=s[i];
        b = 0;
        if(i > 0&&s[i]==s[i-1])
            continue;
        else
        {
            for ( j = i; j < (7); j++)
            {
                if (a == s[j])
                    b++;
                else
                    continue;
            }
        }
        if (b <= 1)
            continue;
        else
        {
            insertIndex(&head, a, b);
        }
    }
    show(head);
    return 0;
} 
