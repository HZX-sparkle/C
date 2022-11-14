#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* createList(int data[], int n);
void freelst(struct node* h);
void printlst(struct node* h);
int main()
{
	struct node* header = NULL;
	int* data, n, i;
	scanf("%d", &n);
	data = (int*)malloc(n * sizeof(int));
	if (!data)return 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", data + i);
		getchar();
	}
	header = (struct node*)createList(data, n);
	printlst(header);
	freelst(header);
	free(data);
	return 0;
}
void freelst(struct node* h)
{
	struct node* p = h->next;
	while (p)
	{
		h->next = p->next;
		free(p);
		p = h->next;
	}
	free(h);
}
void printlst(struct node* h)
{
	struct node* p = h->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
struct node* createList(int data[], int n)
{
	struct node *h = NULL, *p = NULL, *ptail = NULL;
	for (int j = 0; j < n; j++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->next = NULL;
		p->data = data[j];
		if (j == 0)
		{
			h = (struct node*)malloc(sizeof(struct node));
			h->next = p;
		}
		else
		{
			ptail->next = p;
		}
		ptail = p;
	}

	return h;
}