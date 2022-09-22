#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stunode
{ 
	char no[20];
	char name[10];
	int time;
	char Class[20];
	int basic;
	int pro;
	int selective;
	int humanity;
	int exp;
	int through;
	struct stunode *next;
}STU; //定义链表结点的结构体类型 struct stunode，取别名STU＊／ STU head;／＊定义头结点head＊／
STU head;
STU *findNode(char *no); //根据学号查找存放学生信息的节点
int getIndex(char *no); //根据学号获取存放该学生信息节点的序号
void showMenu(); //显示菜单 
void createList(); //创建学生链表 
void printList(); //打印链表 
void insertAt(); //插入节点 
int findstu(char *no); //查询学号是否重复 
void save(); //保存文件 
void deleteNode(); //删除节点 
void modify(); //修改节点 
void showData(); //根据学号查询节点信息 
void getAverage(); //计算平均值 
void freeList();  //释放链表内存空间 
int get_num(void); //限制稚嫩输入整数 
int main()
{
	int select;
    head.next = NULL;
	while(1)
	{
		showMenu();
		printf("请选择需要的操作：");
		fflush(stdin);
		select=get_num();
		fflush(stdin);// ／＊清除键盘缓冲区＊／
		switch(select) //／＊根据用户选择，调用相应函数完成操作＊／
		{
			case 1:createList();system("pause");break;
			case 2:printList();system("pause");break;
			case 3:insertAt();system("pause");break;
			case 4:deleteNode();system("pause");break;
			case 5:modify();system("pause");break;
			case 6:showData();system("pause");break;
			case 7:getAverage();system("pause");break;
			case 8:save();system("pause");break;
			case 0:freeList();exit(0);
			default:printf("输入错误！\n");system("pause");
		}
	}
	system("pause");
	return 0;
}

//根据学号查找存放学生信息的节点。若找到，则返回该节点的地址，否则返回NULL 
STU* findNode(char *no)
{
	STU *p;  
	p=head.next;
	while(p!=NULL)
	{
		if(strcmp(p->no,no)==0)break;
		p=p->next;
	}
	return p;
}

//判断输入为整数 
int get_num(void)
{
    int input;
    char ch;
    fflush(stdin);
    while(scanf("%d", &input) != 1)
    {
        while((ch = getchar())!= '\n')
        {
        	putchar(ch);
        }
        printf(" 不是数字,请输入数字:\n");
    }
    return input;
}

//／＊函数功能：根据学号获取存放该学生信息节点的序号。若找到，则返回该节点的序号，否则返回0 
int getIndex(char *no)
{
	int index=1;
	STU *p;
	p=head.next;
	while(p!=NULL)
	{
		if(strcmp(p->no,no)==0)break;
		p=p->next;
		index++;
	}
	if(p==NULL)
		return 0;
	else
		return index;
}

//／＊函数功能：显示菜单。＊／
void showMenu()
{
	system("cls");//＊清屏＊／
	printf("********学分管理系统********\n");
	printf("\t1.创建学生信息链表\n");
	printf("\t2.显示所有学生成绩\n");
	printf("\t3.在指定位置插入成绩信息\n");
	printf("\t4.根据学号删除成绩信息\n");
	printf("\t5.根据学号修改成绩\n");
	printf("\t6.根据学号查询成绩\n");
	printf("\t7.计算平均成绩\n");
	printf("\t8.保存信息\n");
	printf("\t0.退出\n");
	printf("****************************\n");
	return;
}

void save()
{
	STU *p;
	p=head.next;
	FILE *fp = fopen("D:\\学分管理系统.txt","w");
	fprintf(fp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t%s\t%s\t%s\n","学号","姓名","班级","入学时间","基础课","专业课","选修课","人文课","实验课");
	while (p!=NULL)
	{
		fprintf(fp,"%-16s\t%-16s\t%-16s\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->Class,p->time,p->basic,p->pro,p->selective,p->humanity,p->exp);
		p=p->next;
	}
	printf("保存成功!\n");
	fclose(fp);
}

//／＊函数功能：创建存储n个学生信息的链表。／
void createList()
{
	int i,n;
	STU *p,*tail;
	if(head.next!=NULL)
	{
		printf("学生成绩链表已经创建！\n");
		return;
	}
	tail=&head; //＊初始建立链表tail指向头结点head＊／
	printf("请输入学生个数：");
	fflush(stdin);
	n = get_num();
	for(i=1;i<=n;i++)
	{
		p=(STU *)malloc(sizeof(STU)); //／＊新建一个结点＊／
		if(p==NULL)
		{
			printf("建立链表时内存分配失败！\n");
			return;
		}
		printf("请输入第%d个学生的信息:\n",i);
		printf("学号:");
		fflush(stdin);
		gets(p->no);
		while(findstu(p->no)==1)
		{
	   		 printf("学号重复，请重新输入：");
        	 gets(p->no);
		}
		printf("姓名:");
		fflush(stdin);
		gets(p->name);
		printf("班级:");
		gets(p->Class);
		printf("入学时间(必须为2015年到2019年):");
		p->time = get_num();
		while(p->time>2019||p->time<2015)
		{
			printf("日期必须为2015年到2019年，请重新输入:");
			p->time = get_num();
		}
		printf("基础课学分:");
		p->basic = get_num();
		while(p->basic<0||p->basic>100)
		{
			printf("学分必须大于等于0，小于等于100，请重新输入：");
			p->basic = get_num();
		}
		printf("专业课学分:");
		p->pro = get_num();
		while(p->pro<0||p->pro>100)
		{
			printf("学分必须大于等于0，小于等于100，请重新输入：");
			p->pro = get_num();
		}
		printf("选修课学分:");
		p->selective = get_num();
		while(p->selective<0||p->selective>100)
		{
			printf("学分必须大于等于0，小于等于100，请重新输入：");
			p->selective = get_num();
		}
		printf("人文课学分:");
		p->humanity = get_num();
		while(p->humanity<0||p->humanity>100)
		{
			printf("学分必须大于等于0，小于等于100，请重新输入：");
			p->humanity = get_num();
		}
		printf("实验课学分:");
		p->exp = get_num();
		while(p->exp<0||p->exp>100)
		{
			printf("学分必须大于等于0，小于等于100，请重新输入：");
			p->exp = get_num();
		}
		if(p->basic>=50&&p->pro>=50&&p->selective>=24&&p->humanity>=8&&p->exp>=20)
		{
			p->through=1;
		}
		else
		{
			p->through=0;
		}
		//／＊将结点添加到链表的尾部＊／
		tail->next=p;
		p->next=NULL;
		tail=p;
	}
	
	return;
	
}

//／＊函数功能：输出链表中存储的所有学生信息。＊／
void printList()
{
	FILE *fp=fopen("D:\\学分管理系统_可以毕业人数.txt","w");
	STU *p;
	int count=0;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表\n");
		return;
	}
	p=head.next; //／＊指针变量p指向第一个结点＊／
	printf("学号\t\t姓名\t\t班级\t\t\t入学时间\t基础课\t专业课\t选修课\t人文课\t实验课\n");
	fprintf(fp,"%s\n","毕业生名单：");
	fprintf(fp,"%s\t\t%s\n","学号","姓名");
	while(p!=NULL)
	{
		printf("%-16s%-8s\t%-8s\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->Class,p->time,p->basic,p->pro,p->selective,p->humanity,p->exp);
		if(p->through==1)
		{
			count++;
			fprintf(fp,"%-16s\t%s\n",p->no,p->name);
		}
		p=p->next; //／＊指针变量p指向下一个结点＊／
	}
	printf("可以毕业人数为：%d\n",count);
	fprintf(fp,"%s%d","可以毕业人数为：",count);
	fclose(fp);
	return;
}

//／＊函数功能：在指定位置插入一个学生的信息。＊／
void insertAt()
{
	int n,i,j;
	STU *pnew,*p;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表！\n");
		return;
	}
	printf("请输入要插入的位置\n");
	n=get_num();
	if(n<1)
	{
		printf("插入位置不能小于1！\n");
		return;
	}
	p=&head;
	for(i=1;i<=n-1;i++) //循环结束后，p指向第n-1个节点 
	{
		if(p==NULL)break;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("插入位置太大！\n");
		return;
	}
	pnew=(STU*)malloc(sizeof(STU)); //新建节点
	if(pnew==NULL)
	{
		printf("动态内存分配失败！");
		return;
	} 
	printf("请输入学生学号、姓名、班级、入学时间、基础课学分、专业课学分、选修课学分、人文课学分和实验课学分：\n");
	printf("学号:");
	fflush(stdin);
	gets(pnew->no);
	while(findstu(pnew->no)==1)
	{
		 printf("学号重复，请重新输入：");
       	 gets(pnew->no);
	}
	printf("姓名:");
	fflush(stdin);
	gets(pnew->name);
	printf("班级:");
	fflush(stdin);
	gets(pnew->Class);
	printf("入学时间(必须为2015年到2019年):");
	pnew->time = get_num();
	while(pnew->time>2019||pnew->time<2015)
	{
		printf("日期必须为2015到2019年，请重新输入:");
		pnew->time = get_num();
	}
	printf("基础课学分:");
	pnew->basic = get_num();
	while(pnew->basic<0||pnew->basic>100)
	{
		printf("学分必须大于等于0，小于等于100，请重新输入：");
		pnew->basic = get_num();
	}
	printf("专业课学分:");
	pnew->pro = get_num();
	while(pnew->pro<0||pnew->pro>100)
	{
		printf("学分必须大于等于0，小于等于100，请重新输入：");
		pnew->pro = get_num();
	}
	printf("选修课学分:");
	pnew->selective = get_num();
	while(pnew->selective<0||pnew->selective>100)
	{
		printf("学分必须大于等于0，小于等于100，请重新输入：");
		pnew->selective = get_num();
	}
	printf("人文课学分:");
	pnew->humanity = get_num();
	while(pnew->humanity<0||pnew->humanity>100)
	{
		printf("学分必须大于等于0，小于等于100，请重新输入：");
		pnew->humanity = get_num();
	}
	printf("实验课学分:");
	pnew->exp = get_num();
	while(pnew->exp<0||pnew->exp>100)
	{
		printf("学分必须大于等于0，小于等于100，请重新输入：");
		pnew->exp = get_num();
	}
	if(pnew->basic>=50&&pnew->pro>=50&&pnew->selective>=24&&pnew->humanity>=8&&pnew->exp>=20)
	{
		pnew->through=1;
	}
	else
	{
		pnew->through=0;
	}
	pnew->next=p->next; //将p所指节点的next赋给新节点的next
	p->next=pnew; //将新节点的地址赋给p所指节点的next
	printf("插入成功！\n");
	return; 
}

//函数功能：在链表中删除指定学号的学生信息。
void deleteNode()
{
	int n,i;
	char no[20],select;
	STU *p,*pre;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表！\n");
		return;
	}
	printf("请输入要删除的学号；\n");
	gets(no);
	n=getIndex(no);//删除 
	if(n==0) //若n为0表示要删除的学生不存在 
	{
		printf("学生信息不存在！\n");
		return;
	}
	pre=&head; //指针变量pre指向头节点
	for(i=1;i<=n-1;i++)
	{
		pre=pre->next;
	} 
	p=pre->next;
	printf("该学生的学号、姓名和成绩为：\n");
	printf("学号\t\t姓名\t\t基础课\t专业课\t选修课\t人文课\t实验课\n");
	printf("%-16s%-8s\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->basic,p->pro,p->selective,p->humanity,p->exp);
	fflush(stdin);
	printf("是否确认删除(Y/N)?");
	select=getchar();
	if(select=='Y'||select=='y')
	{
		pre->next=p->next; //／＊将p所指向的结点从链表中删除。／
		free(p);
		printf("删除成功！\n");
	}
	else
		printf("删除取消！\n");
	return;
} 
//／＊函数功能：根据学号修改学生的成绩。＊／
void modify()
{
	STU *p;
	char no[20];
	int i;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表！\n");
		return;
	}
	printf("请输入需要修改的学生学号：\n");
	gets(no);
	p=findNode(no); //／＊查找no对应的结点地址＊／
	if(p==NULL)
	{
		printf("学生信息不存在\n");
		return;
	}
	printf("该学生的姓名和成绩为：\n");
	printf("姓名\t\t基础课\t专业课\t选修课\t人文课\t实验课\n");
	printf("%-8s\t%d\t%d\t%d\t%d\t%d\n",p->name,p->basic,p->pro,p->selective,p->humanity,p->exp);
	printf("请输入修改后的成绩\n输入1修改基础课\n输入2修改专业课\n输入3修改选修课\n输入4修改人文课\n输入5修改实验课\n输入其他数字取消修改：\n");
	i=get_num();
	switch(i)
		{
			case 1:printf("基础课学分:");p->basic = get_num();while(p->basic<0||p->basic>100){
					printf("学分必须大于等于0，小于等于100，请重新输入：");
					p->basic = get_num();
					
			}	
			printf("修改成功！\n");
			break;
			case 2:printf("专业课学分:");p->pro = get_num();while(p->pro<0||p->pro>100){
					printf("学分必须大于等于0，小于等于100，请重新输入：");
					p->pro = get_num();		
			}
			printf("修改成功！\n");
			break;
			case 3:printf("选修课学分:");p->selective = get_num();while(p->selective<0||p->selective>100){
					printf("学分必须大于等于0，小于等于100，请重新输入：");
					p->selective = get_num();
			}
			printf("修改成功！\n");
			break;
			case 4:printf("人文课学分:");p->humanity = get_num();while(p->humanity<0||p->humanity>100){
					printf("学分必须大于等于0，小于等于100，请重新输入：");
					p->humanity = get_num();
					
			}
			printf("修改成功！\n");
			break;
			case 5:printf("实验学分:");p->exp = get_num();while(p->exp<0||p->exp>100){
					printf("学分必须大于等于0，小于等于100，请重新输入：");
					p->exp = get_num();
					
			}
			printf("修改成功！\n");
			break;
			default:printf("退出成功！\n");break;
		}
	if(p->basic>=50&&p->pro>=50&&p->selective>=24&&p->humanity>=8&&p->exp>=20)
	{
		p->through=1;
	}
	else
	{
		p->through=0;
	}	
	return;
}

//／＊函数功能：根据学号输出一个学生成绩信息。＊／
void showData()
{
	char no[20];
	STU *p;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表！\n");
		return;
	}
	printf("请输入需要查询的学号：\n");
	gets(no);
	p=findNode(no); //／·查找·／
	if(p==NULL)
		printf("学生信息不存在！\n");
	else
	{
		printf("学号\t\t姓名\t\t班级\t基础课\t专业课\t选修课\t人文课\t实验课\n");
		printf("%-16s%-8s\t%s\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->Class,p->basic,p->pro,p->selective,p->humanity,p->exp);
		
	}
	return;
}

int findstu(char *no)
{
	STU *p;
	p=head.next;
	while(p!=NULL)
	{
		if(strcmp(p->no,no)==0)
		{
			return 1;
			break;
		}
		p=p->next;
	}
	return 0;
}

//／.函数功能：输出所有学生的平均成绩。／
void getAverage()
{
	FILE *fp=fopen("D:\\学分管理系统_平均分.txt","w");
	double avg_basic=0,avg_pro=0,avg_selective=0,avg_humanity=0,avg_exp=0; //／＊avg存放平均成绩＊／
	int count=0; //／＊count 存放学生个数＊／
	STU *p;
	if(head.next==NULL)
	{
		printf("未创建学生成绩链表！\n");
		return;
	}
	p=head.next; //p指向第一个节点 
	while(p!=NULL) //／＊当p不为NULL时＊／
	{
		count++; //／＊学生人数加1＊／
		avg_basic+=p->basic;
		avg_pro+=p->pro;
		avg_selective+=p->selective;
		avg_humanity+=p->humanity;
		avg_exp+=p->exp;
		 //／＊将学生成绩累加到avg中＊／
		p=p->next; //／＊p指向下一个结点＊／
	}
	avg_basic/=count; //／＊计算平均成绩＊／
	avg_pro/=count;
	avg_selective/=count;
	avg_humanity/=count;
	avg_exp/=count; 
	printf("平均成绩为：\n");
	printf("基础课\t专业课\t选修课\t人文课\t实验课\n");
	printf("%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",avg_basic,avg_pro,avg_selective,avg_humanity,avg_exp);
	fprintf(fp,"%s\t%s\t%s\t%s\t%s\n","基础课","专业课","选修课","人文课","实验课");
	fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",avg_basic,avg_pro,avg_selective,avg_humanity,avg_exp);
	fclose(fp);
	return;
}

//／＊函数功能：释放链表中所有存放学生信息的结点。＊／
void freeList()
{
	STU *p;
	p=head.next; //／＊从第一个结点开始释放＊／
	while(p!=NULL) //／＊循环释放链表中每个结点的空间＊／
	{
		head.next=p->next;
		free(p); //／＊释放p指向的结点空间＊／
		p=head.next; //／＊指针变量p指向下一个待释放的结点＊／
	}
	return;
}



