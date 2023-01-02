#pragma once
#ifndef NODE
#define NODE
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<Windows.h>
#include <conio.h>
struct Node
{
	int ID;
	float SCORE[10] ;
	char NAME[255];
	char SEX[4];
	char CLASS[100];
	struct Node* next;
	struct Node* pro;
};
struct LinkList
{
	struct Node* head;
	struct Node* tail;
	int Size ;
};
void InitNode(int sum, struct LinkList *list,int num);
struct Node* CreateNode(int Id,char* Name,char* Sex,char *Class,float Score[]);
void ExchangeNode(struct Node* n1, struct Node* n2);
void push_head(struct LinkList* list, struct Node* temp);
void SortNode(struct Node* tail, char* Class);
struct Node* findNode(struct Node* tail, char* Name, int Id, char* Class, int case_1);
int VaryNode(struct Node* node,char* Class);
void DeleteNode(struct Node* node);
void Print(struct Node* node);
void AllPrint(struct Node* tail,char SubjectName[][255]);
void menu(char SubjectName[][255], struct LinkList* list);
void fwriteS(struct Node* tail, char SubjectName[][255]);
void freadS(char* FileName, struct LinkList* listchar,char SubjectName[][255]);
int islogin(char* UserName,char*UserWord,char *tempUserName,char *tempUserWord,int times);
int login();
void Draw();
void InitInterface();
#endif // !NODE
