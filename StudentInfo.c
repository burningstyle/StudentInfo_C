#include "stdio.h"
#include "string.h"
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
int newDataBase2(studentLink **head);//����Ҳ����ʵ����ȷ��ͷ������� 
int addRecord(studentLink **head);
int deleteRecord(studentLink **head);
int selectRecord(studentLink **head);
int printList(studentLink **head);
int quit(studentLink **head);
int printStudentInfo(studentInfo elem);
int inputStudentInfo(studentInfo *elem);


int main(){

    char ch='^';
    studentLink *dataBase=NULL;//��������ͷ��㣬���Ե������ݿ������
    

    while(ch!='$'){
        char c=0;
		printf ( "=============================\n" );
		if(dataBase==NULL){
			printf ( "a.�½����ݵ���\n" );
		}else{
			printf ( "b.�������\n" );
			printf ( "c.ɾ������\n" );
			printf ( "d.���ݲ�ѯ\n" );
			printf ( "e.������ݿ�\n" );
			printf ( "q.�˳�����\n" );
		}
		printf ( "\n=============================\n" );
		
		
	    printf ("\n������ѡ�");
        scanf("%c",&ch);
		switch(ch){
			case 'a':
                dataBase=newDataBase();break;//��ʾ����ʾ��
			case 'b':
				addRecord(&dataBase);break;
			case 'c':
				deleteRecord(&dataBase);break;
			case 'd':
				selectRecord(&dataBase);break;
			case 'e':
				quit(&dataBase);break;
			case 'f':
				printList(&dataBase);system("pause");break;
			case 'q':
				quit(&dataBase);exit(0);break;
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
            printf("input student infomation:\n");
			inputStudentInfo(&(newStudentInfo->stu));
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
	char ch='0';
	char    sno_name[15]="sno";
    char    name_name[15]="name";
    char    sex_name[15]="sex";
    char    birthday_name[15]="birthday";
    char    telephone_name[15]="telephone";
	char    tempSelectName[15]="";
	printf ( "=============================\n" );
	printf ( "1.sno\n" );
	printf ( "2.name\n" );
	printf ( "3.sex\n" );
	printf ( "4.birthday\n" );
	printf ( "5.telephone\n" );        
	printf ( "\n=============================\n" );
	scanf("%s",tempSelectName);
	if(strcmp(tempSelectName,sno_name)==0){
		printf("%s\n",sno_name);
	}else if(strcmp(tempSelectName,name_name)){
		
	}else if(strcmp(tempSelectName,sex_name)){
		
	}else if(strcmp(tempSelectName,birthday_name)){
		
	}else if(strcmp(tempSelectName,telephone_name)){
		
	}
	ch=getchar();
	system("pause");
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
      //  printf("%s\n",p->stu.name);
		printStudentInfo(p->stu);
    }

        
    return TRUE;
}
int printStudentInfo(studentInfo elem){
	printf("sno:%s\n",elem.sno);
	printf("name:%s\n",elem.name);
	printf("sex:%d\n",elem.sex);
	printf("birthday:%s\n",elem.birthday);
	printf("telephone:%s\n",elem.telephone);
}

int inputStudentInfo(studentInfo *elem){
	printf("sno:");
	scanf("%s",elem->sno);
	printf("name:");
	scanf("%s",elem->name);
	printf("sex:");
	scanf("%d",&(elem->sex));
	printf("birthday:");
	scanf("%s",elem->birthday);
	printf("telephone:");
	scanf("%s",elem->telephone);
}
