#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define TRUE    1
#define FALSE   0
#define ERROR   0
#define OVERFlow    -2

typedef struct student{
    char    sno[11];
    char    name[25];
    int     sex;
    char    birthday[8];
    char    telephone[11];
}studentInfo;

typedef struct studentLinkList{
    studentInfo             stu;
    struct studentLinkList  *next;
}studentLink;



studentLink *newDataBase();
int newDataBase2(studentLink **head);//这样也可以实现正确的头结点申请 
int addRecord(studentLink **head);
int deleteRecord(studentLink **head);
int selectRecord(studentLink **head);
int printList(studentLink **head);
int quit(studentLink **head);



int main(){
	
    char ch='^';
    studentLink *dataBase=NULL;//数据链表头结点，可以当做数据库的名称
    printf ( "a.新建数据档案\n" );
	printf ( "b.添加数据\n" );
	printf ( "c.删除数据\n" );
	printf ( "d.对输入的数据进行查询\n" );
	printf ( "e.退出\n" );    
	
    while(ch!='$'){
        char c=0;
	    printf ("\n请输入选项：");
        scanf("%c",&c);
		switch(c){
			case 'a':
                dataBase=newDataBase();break;//显示输入示例
			case 'b':
				addRecord(&dataBase);break;
			case 'c':
				deleteRecord(&dataBase);break;
			case 'd':
				selectRecord(&dataBase);break;
			case 'e':
				quit(&dataBase);break;
			case 'f':
                printList(&dataBase);break;
			default :
                printf("Invalid Input\n");break;
		}
        ch=getchar();
    }
    return 0;        
}

studentLink *newDataBase(){
    studentLink *p,*head;    
    head=(studentLink *)malloc(sizeof(studentLink));
    p=head;
    p->next=NULL;
    printf("succeed created!\n");
    return head;
}

int newDataBase2(studentLink **head){
    studentLink *p;    
    *head=(studentLink *)malloc(sizeof(studentLink));
    p=*head;
    p->next=NULL;
    printf("succeed created!\n");
    return TRUE;
}

int addRecord(studentLink **head){
    studentLink *newStudentInfo;
    if((*head)!=NULL){
        newStudentInfo=(studentLink *)malloc(sizeof(studentLink));
        if(newStudentInfo!=NULL){
            printf("input student infomation:");
            scanf("%s",newStudentInfo->stu.sno);
            scanf("%s",newStudentInfo->stu.name);
            scanf("%d",&(newStudentInfo->stu.sex));
            scanf("%s",newStudentInfo->stu.birthday);
            scanf("%s",newStudentInfo->stu.telephone);
            newStudentInfo->next=(*head)->next;
            (*head)->next=newStudentInfo; 
            return TRUE;
        }
        else{
            return OVERFlow;    
        }
    }
    else{
        return FALSE;
    }
}

int deleteRecord(studentLink **head){
        
}

int selectRecord(studentLink **head){
        
}

int quit(studentLink **head){
	studentLink *p,*q;
	if((p=q=(*head))!=NULL)
	while(p){
			q=p;
			p=p->next;
			free(q);
	}
	*head=NULL;
}

int printList(studentLink **head){
    studentLink *p=NULL;
    if((p=*head)!=NULL)
	while(p->next!=NULL){
        p=p->next;
        printf("%s\n",p->stu.name);
    }

    //当输入两条记录时，以下程序可以正确运行
    /* 
		printf("%s\n",p->stu.name);
		p=p->next;
		printf("%s\n",p->stu.name);
		p=p->next;
	*/
        
    return TRUE;
}
