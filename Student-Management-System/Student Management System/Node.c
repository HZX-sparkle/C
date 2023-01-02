#include "Node.h"
int Sum,Num;
struct Node* PassBound;
int PassSum;
void InitNode(int sum, struct LinkList*list,int num)
{
	Sum = sum;
	Num = num;
	list->head = (struct Node*)malloc(sizeof(struct Node));
	list->tail = (struct Node*)malloc(sizeof(struct Node));
	list->head->next=list->tail;
	list->head->pro = NULL;
	list->tail->next = NULL;
	list->tail->pro =list->head;
}

struct Node* CreateNode(int Id, char* Name, char* Sex, char* Class, float Score[])
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->ID = Id;
	strcpy(temp->NAME, Name);
	strcpy(temp->SEX, Sex);
	strcpy(temp->CLASS, Class);
	for (int i = 0; i < Sum; i++)
		temp->SCORE[i] = Score[i];
	return temp;
}

void ExchangeNode(struct Node* n1, struct Node* n2)
{
	/*Node* temp=n2;
	n2->next = n1;
	n2->pro = n1->pro;
	n1->pro->next = n2;
	n1->pro = n2;
	n1->next = temp->next;
	temp->next->pro = n1;*/
	char name[255];
	char Class[100];
	char sex[4];
	int Id;
	float score[10];
	strcpy(sex, n1->SEX);
	strcpy(name, n1->NAME);
	strcpy(Class, n1->CLASS);
	Id = n1->ID;
	for (int i = 0; i < Sum; i++)
		score[i] = n1->SCORE[i];
	strcpy(n1->NAME, n2->NAME);
	strcpy(n1->CLASS, n2->CLASS);
	strcpy(n1->SEX, n2->SEX);
	n1->ID = n2->ID;
	for (int i = 0; i < Sum; i++)
		n1->SCORE[i]= n2->SCORE[i];
	strcpy( n2->NAME,name);
	strcpy(n2->CLASS,Class );
	strcpy( n2->SEX,sex);
	n2->ID = Id;
	for (int i = 0; i < Sum; i++)
		n2->SCORE[i] = score[i];
}

void push_head(struct LinkList* list, struct Node* temp)
{
	temp->pro = list->head;
	temp->next = list->tail;
	list->tail->pro = temp;
	list->head->next = temp;
	list->head = temp;
}

void SortNode(struct Node* tail, char* Class)
{
	if (strcmp(Class, "ID") == 0)
	{
		for(struct Node* i=tail->pro;i->pro !=NULL;i=i->pro)
			for (struct Node* j = i->pro; j->pro != NULL; j = j->pro)
			{
				if (i->ID > j->ID)
					ExchangeNode(i, j);
			}
	}
	else if (strcmp(Class, "成绩") == 0)
	{
		int score;
		printf("\t\t\t\t\t请输排序成绩编号：");
		scanf("%d", &score);
		score -= 1;
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			for (struct Node* j = i->pro; j ->pro!= NULL; j = j->pro)
			{
				if (i->SCORE[score] < j->SCORE[score])
				{
					ExchangeNode(i, j);
				}
			}
	}
	else if (strcmp(Class, "科目") == 0)
	{
		int score;
		printf("\t\t\t\t\t请输科目编号：");
		scanf("%d", &score);
		score -= 1;
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			for (struct Node* j = i->pro; j->pro != NULL; j = j->pro)
			{
				if (i->SCORE[score] > j->SCORE[score])
				{
					ExchangeNode(i, j);
				}
			}
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
		{
			if (i->SCORE[score] > 60)
			{
				PassBound = i;
				return;
			}
			PassSum++;
		}
	}
}

struct Node* findNode(struct Node* tail, char* Name, int Id, char* Class, int case_1)
{
	if (case_1 == 0)
	{
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			if (Id == i->ID)
				return i;
	}
	else if (case_1 == 1)
	{
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			if (Id == i->ID)
			{
				Print(i);
				return NULL;
			}
		printf("\t\t\t\t\t\t未找到，请输入正确ID\n");
	}
	else if (case_1 == 3)
	{
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			if (strcmp(Class, i->CLASS) == 0)
			{
				Print(i);
			}
	}
	else if (case_1 == 2)
	{
		for (struct Node* i = tail->pro; i->pro != NULL; i = i->pro)
			if (strcmp(Name, i->NAME) == 0)
			{
				Print(i);
			}
	}
	return NULL;
}

int VaryNode(struct Node* node, char* Class)
{
	if (strcmp(Class, "学号") == 0)
	{
		printf("\t\t\t\t\t请输入学号：");
		scanf("%d", &node->ID);
        return 1;
	}
	else if (strcmp(Class, "姓名") == 0)
	{
		memset(node->NAME, 0, sizeof(node->NAME));
		printf("\t\t\t\t\t请输入姓名：");
			scanf("%s", node->NAME);
	}
    else if(strcmp(Class, "性别")==0)
	{
		memset(node->SEX, 0, sizeof(node->SEX));
		printf("\t\t\t\t\t请输入性别：");
		scanf("%s", node->SEX);
        return 1;
	}
    else if(strcmp(Class, "班级")==0)
	{
		memset(node->CLASS, 0, sizeof(node->CLASS));
		printf("\t\t\t\t\t请输入新的班级：");
		scanf("%s", node->CLASS);
        return 1;
	}
    else if (strcmp(Class, "成绩") == 0)
	{
		int score;
		printf("\t\t\t\t\t请输入学科编号：");
		scanf("%d", &score);
		score -= 1;
		printf("\t\t\t\t\t请输入学科分数：");
		scanf("%f", &node->SCORE[score]);
        return 1;
	}
    else if (strcmp(Class, "删除") == 0)
	{
		DeleteNode(node);
        return 1;
	}
    else return 0;
}

void DeleteNode(struct Node* node)
{
	node->pro->next = node->next;
	node->next->pro = node->pro;
	free(node);
	node = NULL;
}

void Print(struct Node* node)
{
	printf("\t\t\t\tID：%d 姓名：%s 性别：%s 班级：%s ", node->ID, node->NAME, node->SEX, node->CLASS);
	for (int i = 0; i < Sum; i++)
		printf("\t\t\t\t%4lf ", node->SCORE[i]);
	printf("\n");
}

void AllPrint(struct Node*tail, char  SubjectName[][255])
{
	printf("\t\t\t________________________________________");
	for (int i = 0; i < Sum; i++)
		printf("________");
	printf("\n");
	char a[4] = { "ID" }, b[5] = { "姓名" }, c[5] = { "性别" }, d[5] = { "班级" };
	printf("\t\t\t|%8s|%8s|%8s|%8s",a,b,c,d);
	
	for (int i = 0; i < Sum; i++)
		printf("|%8s", SubjectName[i]);
	printf("|\n");
	for (struct Node* node = tail->pro; node->pro != NULL; node = node->pro)
	{
		printf("\t\t\t|%8d|%8s|%8s|%8s", node->ID, node->NAME, node->SEX, node->CLASS);
		for (int i = 0; i < Sum; i++)
	    printf("|%8.1lf", node->SCORE[i]);
		printf("|\n");
	}
	printf("\t\t\t________________________________________");
	for (int i = 0; i < Sum; i++)
		printf("________");
	printf("\n");
}

void menu(char SubjectName[][255], struct LinkList* list)
{
	system("cls");
	int n;
	int sum = 0;
	int num = 0;
	while (1)
	{
		Draw();
		printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
		printf("\t\t\t\t   │              学生信息管理系统              │\n");
		printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
		printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 1. 创建信息                    2. 信息管理 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 3. 信息查询                    4. 信息排序 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 5. 写入信息                    6. 读取信息 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 7. 退出程序                                │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
		if (Sum != 0)
		{
			printf("\t\t\t\t\t\t  学科序号:\n");
			printf("\t\t\t\t\t");
			for (int i = 0; i < Sum; i++)
				printf("%d.%s\t", i + 1, SubjectName[i]);
			printf("\n");
		}
		printf("\t\t\t\t\t\t  请您选择(1-7):");
		scanf("%d", &n);
		switch (n)
		{
		case 1: {
			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息创建功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			printf("\t\t\t\t\t\t请输入课程数量:");
			scanf("%d", &sum);
			char xing[] = { "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " };
			char a[] = {    "----------------------------------------------------------------------------------------------------------------------- " };
			for (int i = 0; i < strlen(xing); i++)
			{
				printf("%c", xing[i]);
				Sleep(5);
			}
			printf("\t\t\t\t按顺序写出课程名称（如，高等数学  线性代数；则第一个是高等数学，的二个是线性代数）:\n");
			printf("\t\t\t\t\t\t");
			for (int i = 0; i < sum; i++)
				scanf("%s", SubjectName[i]);
			for (int i = 0; i < strlen(xing); i++)
			{
				printf("%c", xing[i]);
				Sleep(5);
			}
			printf("\t\t\t\t\t\t\t请输入学生总人数:");
			scanf("%d", &num);
			InitNode(sum, list,num);
			for (int i = 0; i < strlen(xing); i++)
			{
				printf("%c", xing[i]);
				Sleep(5);
			}
			printf("\t\t\t\t\t\t按顺序输入学生ID，姓名，性别，班级，以及各科成绩：\n");
			for (int i = 0; i < strlen(a); i++)
			{
				printf("%c", a[i]);
				Sleep(3);
			}
            printf("\n");
			for (int j = 0; j < num; j++)
			{
				printf("\t\t\t\t\t\t");
				int id;
				char name[255], sex[4], class_[100];
				float score[10];
				scanf("%d%s%s%s", &id, name, sex, class_);
				for (int i = 0; i < sum; i++)
					scanf("%f", &score[i]);
				struct Node* temp = CreateNode(id, name, sex, class_, score);
				push_head(list, temp);
				for (int i = 0; i < strlen(a); i++)
				{
					printf("%c", a[i]);
					Sleep(3);
				}
                printf("\n");
			}
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息修改功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			AllPrint(list->tail, SubjectName);
			printf("\t\t\t\t\t请输入要修改学生的ID:");
			int id;
			scanf("%d", &id);
			struct Node* temp = findNode(list->tail, NULL, id, NULL, 0);
			char Class[255];
			printf("\t\t\t\t\t请输入修改的属性(如果需要删除，请输入“删除”)：");
			scanf("%s", Class);
            while (VaryNode(temp, Class) == 0) {
                printf("\t\t\t\t\t没有此选项，请重新输入:");
                scanf("%s", Class);
            }
			system("pause");
			system("cls");
			break;
		}
		case 3: {

			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息查询功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
			printf("\t\t\t\t   │                                            │\n");
			printf("\t\t\t\t   │ 1. ID查询                      2. 姓名查询 │\n");
			printf("\t\t\t\t   │                                            │\n");
			printf("\t\t\t\t   │ 3. 班级查询                    4. 全部信息 │\n");
			printf("\t\t\t\t   │                                            │\n");
			printf("\t\t\t\t   │ 5. 及格信息                                │\n");
			printf("\t\t\t\t   │                                            │\n");
			printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
			/*printf("*1.ID查询*\n");
			printf("*2.姓名查询\n");
			printf("*3.班级查询\n");
			printf("*4.打印全部信息\n");
			printf("*5.查询及格信息\n");*/
			int m;
			printf("\t\t\t\t\t\t  请您选择(1-5):");
			scanf("%d", &m);
			switch (m)
			{
			case 1: {//ID查询
				system("cls");
				printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				printf("\t\t\t\t   │              学生信息查询功能              │\n");
				printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				int id;
				printf("\t\t\t\t\t\t请输入学生ID:");
				scanf("%d", &id);
				findNode(list->tail, NULL, id, NULL, m);
				break;
			}
			case 2: {//姓名查询
				system("cls");
				printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				printf("\t\t\t\t   │              学生信息查询功能              │\n");
				printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				char name[255];
				printf("\t\t\t\t\t\t请输入学生姓名:");
				scanf("%s", name);
				findNode(list->tail, name, 0, NULL, m);
				break;
			}
			case 3: {//班级查询
				system("cls");
				printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				printf("\t\t\t\t   │              学生信息查询功能              │\n");
				printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				char Class[100];
				printf("\t\t\t\t\t\t请输入学生班级:");
				scanf("%s", Class);
				findNode(list->tail, NULL, 0, Class, m);
				break;
			}
			case 4: {//全部信息
				system("cls");
				printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				printf("\t\t\t\t   │              学生信息查询功能              │\n");
				printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				AllPrint(list->tail, SubjectName);
				break;
			}
			case 5: {//及格信息
				PassBound = NULL;
				PassSum = 0;
				system("cls");
				printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
				printf("\t\t\t\t   │              学生信息查询功能              │\n");
				printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
				printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
				printf("\t\t\t\t   │                                            │\n");
				printf("\t\t\t\t   │ 1. 不及格人数                  2. 及格人数 │\n");
				printf("\t\t\t\t   │                                            │\n");
				printf("\t\t\t\t   │ 3. 显示不及格人数                          │\n");
				printf("\t\t\t\t   │                                            │\n");
				printf("\t\t\t\t   │ 5. 显示及格人数                            │\n");
				printf("\t\t\t\t   │                                            │\n");
				printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
				printf("\t\t\t\t\t\t  请您选择(1-5):");
				/*printf("*1.打印不及格人数\n");
				printf("*2.打印及格人数\n");
				printf("*3.显示不及格人数\n");
				printf("*4.显示及格人数\n");*/
				char temp[10] = { "科目" };
				int k = 0;
				scanf("%d", &k);
				SortNode(list->tail,temp);
				
				switch (k)
				{
				case 1: {
					for (struct Node* i = PassBound->next; i->next != NULL; i = i->next)
						Print(i);
					break;
				}
				case 2: {
					for (struct Node* i = PassBound; i->pro != NULL; i = i->pro)
						Print(i);
					break;
				}
				case 3: {
					printf("%d\n", PassSum);
					break;
				}
				case 4: {
					printf("%d\n", Num-PassSum);
					break;
				}
				}
				break;
			}
			}
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息排序功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			printf("\t\t\t\t\t请输入选择排序方式（ID，成绩）:");
			char Class[255];
			scanf("%s", Class);
			SortNode(list->tail, Class);
			AllPrint(list->tail, SubjectName);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息写入功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			fwriteS(list->tail, SubjectName);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			system("cls");
			printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
			printf("\t\t\t\t   │              学生信息读取功能              │\n");
			printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
			char FileName[500];
			printf("\t\t\t\t\t\t请输入文件名称:");
			scanf("%s", FileName);
			freadS(FileName, list, SubjectName);
			system("pause");
			system("cls");
			break;
		}
		case 7: {
            exit(0);
		}
		
		}
	}
}

void fwriteS(struct Node* tail, char SubjectName[][255])
{
	printf("\t\t\t\t请输入文件名称（默认无此文件新建,形式如“学生信息表.dat”）\n");
	char FileName[500];
	printf("\t\t\t\t\t\t");
	scanf("%s", FileName);
	FILE *fp=fopen(FileName, "wb");
	fwrite(&Sum, sizeof(int), 1, fp);
	fwrite(&Num, sizeof(int), 1, fp);
	/*fprintf(fp,"\t%d", Sum);
	fprintf(fp, "\t%d", Num);*/
	for (int i = 0; i < Sum; i++)
		fwrite(SubjectName[i], sizeof(SubjectName[i]), 1, fp);
		/*fprintf(fp,"\t%s", SubjectName[i]);
	fprintf(fp, "\n");*/
	for (struct Node* node = tail->pro; node->pro != NULL; node = node->pro)
	{
		fwrite(node, sizeof(struct Node), 1, fp);
		/*fprintf(fp, "\t%d\t%s\t%s\t%s", node->ID, node->NAME, node->SEX, node->CLASS);
		for (int i = 0; i < Sum; i++)
			fprintf(fp, "\t%.1f", node->SCORE[i]);
		fprintf(fp, "\n");*/
	}
	fclose(fp);
}

void freadS(char* FileName, struct LinkList* list,char SubjectName[][255])
{
	FILE* fp = fopen(FileName, "rb");
	if (fp == NULL)
	{
		printf("\t\t\t\t\t\t不存在该文件\n");
		return;
	}
	printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
	printf("\t\t\t\t   │                                            │\n");
	printf("\t\t\t\t   │ 1. 完全读取                  2. 当前表合并 │\n");
	printf("\t\t\t\t   │                                            │\n");
	printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
	printf("\t\t\t\t\t\t  请您选择(1-2):");
	/*printf("*1.完全读取新表\n");
	printf("*2.与当前表合并\n");*/
	int m=1;
	scanf("%d", &m);
	int sum = 0,num=0;
	fread(&sum, sizeof(int), 1, fp);
	fread(&num, sizeof(int), 1, fp);
	
	/*fscanf(fp, "\t%d", &sum);
	fscanf(fp, "\t%d", &num);*/
	if (m == 2)
	{
		if (Sum == 0)
		{
			printf("\t\t\t\t\t当前不存在信息，无法合并，请选择完全读取新表\n");
			return;
		}
		if (sum != Sum)
		{
			printf("\t\t\t\t\t\t格式不符，无法合并\n");
			return;
		}
		Num += num;
		char tempSubName[10][255];
		for (int i = 0; i < sum; i++)
		{
			/*fscanf(fp, "\t%s", tempSubName[i]);*/
			fread(tempSubName[i], 255, 1, fp);
			if (strcmp(tempSubName[i], SubjectName[i]) != 0)
			{
				printf("\t\t\t\t\t\t科目不符，无法合并\n");
				return;
			}
		}
		/*fscanf(fp, "\n");*/
		for (int j = 0; j < num; j++)
		{
			struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
			fread(temp, sizeof(struct Node), 1, fp);
			/*struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
			fscanf(fp, "\t%d\t%s\t%s\t%s", &temp->ID, temp->NAME, temp->SEX, temp->CLASS);
			for (int i = 0; i < Sum; i++)
				fscanf(fp, "\t%f", &temp->SCORE[i]);
			fscanf(fp, "\n");*/
			push_head(list, temp);
		}
		printf("\t\t\t\t\t\t合并成功\n");
	}
	if (m == 1)
	{
		for (int i = 0; i < sum; i++)
			fread(SubjectName[i], 255, 1, fp);
			/*fscanf(fp, "\t%s", SubjectName[i]);*/
		/*fscanf(fp, "\n");*/
		InitNode(sum, list, num);
		for (int j = 0; j < num; j++)
		{
			struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
			fread(temp, sizeof(struct Node), 1, fp);
			/*printf( "\t%d\t%s\t%s\t%s", temp->ID, temp->NAME, temp->SEX, temp->CLASS);*/
			/*struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
			fscanf(fp, "\t%d\t%s\t%s\t%s", &temp->ID, temp->NAME, temp->SEX, temp->CLASS);
			for (int i = 0; i < Sum; i++)
				fscanf(fp, "\t%f", &temp->SCORE[i]);
			fscanf(fp, "\n");*/
			push_head(list, temp);
		}
		printf("读取成功\n");
	}
}

int islogin(char* UserName, char* UserWord, char* tempUserName, char* tempUserWord,int times)
{
	int i;
	char shutdown[] = { "系统将于%d秒后关闭..." };
	while (!(strcmp(UserName, tempUserName) == 0 && strcmp(UserWord, tempUserWord) == 0))
	{
		times++;	//密码输入错误 times++
		if (times > 3)
		{
			printf("\n\n\n\n\t\t\t\t账号或密码输入错误累计达到%d次，系统将于3秒后关闭", times);
			Sleep(1000);
			system("cls");
			for (i = 0; i < 3; i++)
			{
				printf(shutdown, 3 - i);
				Sleep(1000);
				system("cls");
			}
			exit(0);
		}
		printf("\n\n\n\n\t\t\t\t账号或密码输入错误,你还有%d次登录机会，按任意键重新登录...", 4 - times);
		_getch();
		return 0;
		system("cls");
	}
	return 1;
	//return 0;
}

int login()
{
	char xing[] = { "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " };
	int i;
	FILE* fp = fopen("账户数据.dat", "rb");
	if (fp == NULL)
	{
		Draw();
		for (i = 0; i < strlen(xing); i++)
		{
			printf("%c", xing[i]);
			Sleep(10);
		}
		FILE* fp1 = fopen("账户数据.dat", "wb");
		char UserWord[255], UserName[255];
		printf("\n\n\t\t\t\t\t\t由于没有检测到账户数据，请输入要创建的账户与密码:\n\n\n\n\t\t\t\t\t\t账号:");
		scanf("%s", UserName);
		printf("\n\n\t\t\t\t\t\t密码:");
		scanf("%s", UserWord);
		fwrite(UserName, sizeof(UserName), 1, fp1);
		fwrite(UserWord, sizeof(UserWord), 1, fp1); 
		fclose(fp1);
		system("cls");
	}
	 fp = fopen("账户数据.dat", "rb");
	Draw();
	for (i = 0; i < strlen(xing); i++)
	{
		printf("%c", xing[i]);
		Sleep(10);
	}
	char UserWord[255], UserName[255];
	fread(UserName, sizeof(UserName), 1, fp);
	fread(UserWord, sizeof(UserWord), 1, fp);
	/*printf("%s   %s", UserName, UserWord);*/
	fclose(fp);
	do
	{
		char tempUserWord[255], tempUserName[255];
		printf("\n\n\t\t\t\t\t\t请输入您的账号密码:\n\n\n\n\t\t\t\t\t\t账号:");
		scanf("%s", tempUserName);
		printf("\n\n\t\t\t\t\t\t密码:");
		scanf("%s", tempUserWord);
		int times = 0;
		i = islogin( UserName,UserWord, tempUserName, tempUserWord,times);
		times++;
	} while (!i);
	return i;

}

void Draw()
{
	printf("\n");
	printf("\t\t\t\t\t( ゜- ゜)つロ--------ロ~(￣▽￣)~* \n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t╭ ? % ╮                   ╭ ```╮  \n");
	printf("\t\t\t\t\t(@^o^@) 学生信息管理系统 (⌒:⌒)\n");
	printf("\t\t\t\t\t(~):(~)                  (~)v(~) \n");
	printf("\n\n\n");
}

void InitInterface()
{
	int i;
	char heihei[] = { "即将进入学生管理系统..." };

	SetConsoleTitle((LPCSTR) L"Student Management System");//修改窗口标题
	system("color f0");//设置颜色
	printf("欢迎使用本系统！\n");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t");

	for (i = 0; i < strlen(heihei); i++)
	{
		printf("%c", heihei[i]);
		Sleep(10);
	}
	system("CLS");
	Draw();
	system("cls");
}

