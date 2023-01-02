#include"Node.h"
int main()
{
    char SubjectName[10][255];
    struct LinkList* list = (struct LinkList*)malloc(sizeof(struct LinkList));
    InitInterface();
    int j=login();
    if(j)
        menu(SubjectName,list);
    return 0;
}
