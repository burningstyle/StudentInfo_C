#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"

#define TRUE    1
#define FALSE   0
#define ERROR   0
#define OVERFlow    -2

#define LENGTH_SNO      11
#define LENGTH_NAME     25
#define LENGTH_BIRTHDAY 8
#define LENGTH_TELEPHONE    11

//-----------------------------------------------------------------结构体数据定义
typedef struct student{
    char    sno[LENGTH_SNO];
    char    name[LENGTH_NAME];
    int     sex;
    char    birthday[LENGTH_BIRTHDAY];
    char    telephone[LENGTH_TELEPHONE];
}studentInfo;

typedef struct studentLinkList{
    studentInfo             stu;
    struct studentLinkList  *next;
}studentLink;

//-----------------------------------------------------------------函数声明
//创建数据库
studentLink *newDataBase();
studentLink *newDataBaseFromFile(FILE *f); //通过导入文件建立数据库
int newDataBase2(studentLink **head);//这样也可以实现正确的头结点申请
//选择，添加，删除,清空
int addRecord(studentLink **head);
studentLink *selectRecord(studentLink **head);
int deleteRecord(studentLink **head,studentLink *selectedInfo);//以head为头结点的链表中删除p结点
int clear(studentLink **head);
//输出链表中的所有元素
int printList(studentLink **head);
//快捷对结构体进行赋值与输出
int inputStudentInfo(studentInfo *elem);
int printStudentInfo(studentInfo elem);
//数据输出到文件
int outputToFile(studentLink **head,FILE *f);



//-----------------------------------------------------------------主函数
int main(){

    char ch='^';
    studentLink *dataBase=NULL;//数据链表头结点，可以当做数据库的名称

    while(ch!='$'){
        char c=0;
		printf ( "=============================\n" );
		if(dataBase==NULL){
			printf ( "a.新建数据档案\n" );
		}else{
			printf ( "b.添加数据\n" );
			printf ( "c.删除数据\n" );
			printf ( "d.数据查询\n" );
			printf ( "e.清除数据库\n" );
			printf ( "q.退出程序\n" );
		}
		printf ( "\n=============================\n" );
		
		
	    printf ("\n请输入选项：");
        scanf("%c",&ch);
		switch(ch){
			case 'a':
                dataBase=newDataBase();break;//显示输入示例
			case 'b':
				addRecord(&dataBase);break;
			case 'c':
				deleteRecord(&dataBase,selectRecord(&dataBase));break;
			case 'd':
				printStudentInfo((selectRecord(&dataBase))->stu);break;
			case 'e':
				clear(&dataBase);break;
			case 'f':
				printList(&dataBase);system("pause");break;
			case 'q':
				clear(&dataBase);exit(0);break;
			default :
                printf("Invalid Input\n");break;
		}
       ch=getchar();
    }
    return 0;        
}

//-----------------------------------------------------------------自定义函数的实现
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

int deleteRecord(studentLink **head,studentLink *selectedInfo){
    studentLink *p,*q;
	if((p=(*head))!=NULL && (q=selectedInfo)!=NULL)
	while(p->next!=q) p=p->next;
	p->next=q->next;
	free(q);
	selectedInfo=NULL;
}

//数据查询，并返回该记录的指针 
studentLink *selectRecord(studentLink **head){
    char    ch='0';
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
        studentLink *p=NULL;
		char    input_sno[LENGTH_SNO];
		scanf("%s",input_sno);
        if((p=*head)!=NULL)
        while(p->next!=NULL){
            p=p->next;
            if(strcmp(p->stu.sno,input_sno)==0){
				return p;
			}
        }
    }

	else if(strcmp(tempSelectName,name_name)==0){
		studentLink *p=NULL;
		char    input_name[LENGTH_NAME];
		scanf("%s",input_name);
        if((p=*head)!=NULL)
        while(p->next!=NULL){
            p=p->next;
            if(strcmp(p->stu.name,input_name)==0){
				return p;
			}
        }
	}
	else if(strcmp(tempSelectName,sex_name)==0){
		studentLink *p=NULL;
		int    input_sex;
		scanf("%d",&input_sex);
        if((p=*head)!=NULL)
        while(p->next!=NULL){
            p=p->next;
            if(p->stu.sex==input_sex){
				return p;
			}
        }
	}
	else if(strcmp(tempSelectName,birthday_name)==0){
		studentLink *p=NULL;
		char    input_birthday[LENGTH_BIRTHDAY];
		scanf("%s",input_birthday);
        if((p=*head)!=NULL)
        while(p->next!=NULL){
            p=p->next;
            if(strcmp(p->stu.birthday,input_birthday)==0){
				return p;
			}
        }
	}
	else if(strcmp(tempSelectName,telephone_name)==0){
		studentLink *p=NULL;
		char    input_telephone[LENGTH_TELEPHONE];
		scanf("%s",input_telephone);
        if((p=*head)!=NULL)
        while(p->next!=NULL){
            p=p->next;
            if(strcmp(p->stu.telephone,input_telephone)==0){
				return p;
			}
        }
	}
	ch=getchar();
	system("pause");
}

int clear(studentLink **head){
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
	printf("\n");
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
	printf("\n");
}
