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
}STU; //����������Ľṹ������ struct stunode��ȡ����STU���� STU head;��������ͷ���head����
STU head;
STU *findNode(char *no); //����ѧ�Ų��Ҵ��ѧ����Ϣ�Ľڵ�
int getIndex(char *no); //����ѧ�Ż�ȡ��Ÿ�ѧ����Ϣ�ڵ�����
void showMenu(); //��ʾ�˵� 
void createList(); //����ѧ������ 
void printList(); //��ӡ���� 
void insertAt(); //����ڵ� 
int findstu(char *no); //��ѯѧ���Ƿ��ظ� 
void save(); //�����ļ� 
void deleteNode(); //ɾ���ڵ� 
void modify(); //�޸Ľڵ� 
void showData(); //����ѧ�Ų�ѯ�ڵ���Ϣ 
void getAverage(); //����ƽ��ֵ 
void freeList();  //�ͷ������ڴ�ռ� 
int get_num(void); //���������������� 
int main()
{
	int select;
    head.next = NULL;
	while(1)
	{
		showMenu();
		printf("��ѡ����Ҫ�Ĳ�����");
		fflush(stdin);
		select=get_num();
		fflush(stdin);// ����������̻���������
		switch(select) //���������û�ѡ�񣬵�����Ӧ������ɲ�������
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
			default:printf("�������\n");system("pause");
		}
	}
	system("pause");
	return 0;
}

//����ѧ�Ų��Ҵ��ѧ����Ϣ�Ľڵ㡣���ҵ����򷵻ظýڵ�ĵ�ַ�����򷵻�NULL 
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

//�ж�����Ϊ���� 
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
        printf(" ��������,����������:\n");
    }
    return input;
}

//�����������ܣ�����ѧ�Ż�ȡ��Ÿ�ѧ����Ϣ�ڵ����š����ҵ����򷵻ظýڵ����ţ����򷵻�0 
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

//�����������ܣ���ʾ�˵�������
void showMenu()
{
	system("cls");//����������
	printf("********ѧ�ֹ���ϵͳ********\n");
	printf("\t1.����ѧ����Ϣ����\n");
	printf("\t2.��ʾ����ѧ���ɼ�\n");
	printf("\t3.��ָ��λ�ò���ɼ���Ϣ\n");
	printf("\t4.����ѧ��ɾ���ɼ���Ϣ\n");
	printf("\t5.����ѧ���޸ĳɼ�\n");
	printf("\t6.����ѧ�Ų�ѯ�ɼ�\n");
	printf("\t7.����ƽ���ɼ�\n");
	printf("\t8.������Ϣ\n");
	printf("\t0.�˳�\n");
	printf("****************************\n");
	return;
}

void save()
{
	STU *p;
	p=head.next;
	FILE *fp = fopen("D:\\ѧ�ֹ���ϵͳ.txt","w");
	fprintf(fp,"%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t%s\t%s\t%s\n","ѧ��","����","�༶","��ѧʱ��","������","רҵ��","ѡ�޿�","���Ŀ�","ʵ���");
	while (p!=NULL)
	{
		fprintf(fp,"%-16s\t%-16s\t%-16s\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->Class,p->time,p->basic,p->pro,p->selective,p->humanity,p->exp);
		p=p->next;
	}
	printf("����ɹ�!\n");
	fclose(fp);
}

//�����������ܣ������洢n��ѧ����Ϣ��������
void createList()
{
	int i,n;
	STU *p,*tail;
	if(head.next!=NULL)
	{
		printf("ѧ���ɼ������Ѿ�������\n");
		return;
	}
	tail=&head; //����ʼ��������tailָ��ͷ���head����
	printf("������ѧ��������");
	fflush(stdin);
	n = get_num();
	for(i=1;i<=n;i++)
	{
		p=(STU *)malloc(sizeof(STU)); //�����½�һ����㣪��
		if(p==NULL)
		{
			printf("��������ʱ�ڴ����ʧ�ܣ�\n");
			return;
		}
		printf("�������%d��ѧ������Ϣ:\n",i);
		printf("ѧ��:");
		fflush(stdin);
		gets(p->no);
		while(findstu(p->no)==1)
		{
	   		 printf("ѧ���ظ������������룺");
        	 gets(p->no);
		}
		printf("����:");
		fflush(stdin);
		gets(p->name);
		printf("�༶:");
		gets(p->Class);
		printf("��ѧʱ��(����Ϊ2015�굽2019��):");
		p->time = get_num();
		while(p->time>2019||p->time<2015)
		{
			printf("���ڱ���Ϊ2015�굽2019�꣬����������:");
			p->time = get_num();
		}
		printf("������ѧ��:");
		p->basic = get_num();
		while(p->basic<0||p->basic>100)
		{
			printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
			p->basic = get_num();
		}
		printf("רҵ��ѧ��:");
		p->pro = get_num();
		while(p->pro<0||p->pro>100)
		{
			printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
			p->pro = get_num();
		}
		printf("ѡ�޿�ѧ��:");
		p->selective = get_num();
		while(p->selective<0||p->selective>100)
		{
			printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
			p->selective = get_num();
		}
		printf("���Ŀ�ѧ��:");
		p->humanity = get_num();
		while(p->humanity<0||p->humanity>100)
		{
			printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
			p->humanity = get_num();
		}
		printf("ʵ���ѧ��:");
		p->exp = get_num();
		while(p->exp<0||p->exp>100)
		{
			printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
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
		//�����������ӵ������β������
		tail->next=p;
		p->next=NULL;
		tail=p;
	}
	
	return;
	
}

//�����������ܣ���������д洢������ѧ����Ϣ������
void printList()
{
	FILE *fp=fopen("D:\\ѧ�ֹ���ϵͳ_���Ա�ҵ����.txt","w");
	STU *p;
	int count=0;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	p=head.next; //����ָ�����pָ���һ����㣪��
	printf("ѧ��\t\t����\t\t�༶\t\t\t��ѧʱ��\t������\tרҵ��\tѡ�޿�\t���Ŀ�\tʵ���\n");
	fprintf(fp,"%s\n","��ҵ��������");
	fprintf(fp,"%s\t\t%s\n","ѧ��","����");
	while(p!=NULL)
	{
		printf("%-16s%-8s\t%-8s\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->Class,p->time,p->basic,p->pro,p->selective,p->humanity,p->exp);
		if(p->through==1)
		{
			count++;
			fprintf(fp,"%-16s\t%s\n",p->no,p->name);
		}
		p=p->next; //����ָ�����pָ����һ����㣪��
	}
	printf("���Ա�ҵ����Ϊ��%d\n",count);
	fprintf(fp,"%s%d","���Ա�ҵ����Ϊ��",count);
	fclose(fp);
	return;
}

//�����������ܣ���ָ��λ�ò���һ��ѧ������Ϣ������
void insertAt()
{
	int n,i,j;
	STU *pnew,*p;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	printf("������Ҫ�����λ��\n");
	n=get_num();
	if(n<1)
	{
		printf("����λ�ò���С��1��\n");
		return;
	}
	p=&head;
	for(i=1;i<=n-1;i++) //ѭ��������pָ���n-1���ڵ� 
	{
		if(p==NULL)break;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("����λ��̫��\n");
		return;
	}
	pnew=(STU*)malloc(sizeof(STU)); //�½��ڵ�
	if(pnew==NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�");
		return;
	} 
	printf("������ѧ��ѧ�š��������༶����ѧʱ�䡢������ѧ�֡�רҵ��ѧ�֡�ѡ�޿�ѧ�֡����Ŀ�ѧ�ֺ�ʵ���ѧ�֣�\n");
	printf("ѧ��:");
	fflush(stdin);
	gets(pnew->no);
	while(findstu(pnew->no)==1)
	{
		 printf("ѧ���ظ������������룺");
       	 gets(pnew->no);
	}
	printf("����:");
	fflush(stdin);
	gets(pnew->name);
	printf("�༶:");
	fflush(stdin);
	gets(pnew->Class);
	printf("��ѧʱ��(����Ϊ2015�굽2019��):");
	pnew->time = get_num();
	while(pnew->time>2019||pnew->time<2015)
	{
		printf("���ڱ���Ϊ2015��2019�꣬����������:");
		pnew->time = get_num();
	}
	printf("������ѧ��:");
	pnew->basic = get_num();
	while(pnew->basic<0||pnew->basic>100)
	{
		printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
		pnew->basic = get_num();
	}
	printf("רҵ��ѧ��:");
	pnew->pro = get_num();
	while(pnew->pro<0||pnew->pro>100)
	{
		printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
		pnew->pro = get_num();
	}
	printf("ѡ�޿�ѧ��:");
	pnew->selective = get_num();
	while(pnew->selective<0||pnew->selective>100)
	{
		printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
		pnew->selective = get_num();
	}
	printf("���Ŀ�ѧ��:");
	pnew->humanity = get_num();
	while(pnew->humanity<0||pnew->humanity>100)
	{
		printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
		pnew->humanity = get_num();
	}
	printf("ʵ���ѧ��:");
	pnew->exp = get_num();
	while(pnew->exp<0||pnew->exp>100)
	{
		printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
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
	pnew->next=p->next; //��p��ָ�ڵ��next�����½ڵ��next
	p->next=pnew; //���½ڵ�ĵ�ַ����p��ָ�ڵ��next
	printf("����ɹ���\n");
	return; 
}

//�������ܣ���������ɾ��ָ��ѧ�ŵ�ѧ����Ϣ��
void deleteNode()
{
	int n,i;
	char no[20],select;
	STU *p,*pre;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	printf("������Ҫɾ����ѧ�ţ�\n");
	gets(no);
	n=getIndex(no);//ɾ�� 
	if(n==0) //��nΪ0��ʾҪɾ����ѧ�������� 
	{
		printf("ѧ����Ϣ�����ڣ�\n");
		return;
	}
	pre=&head; //ָ�����preָ��ͷ�ڵ�
	for(i=1;i<=n-1;i++)
	{
		pre=pre->next;
	} 
	p=pre->next;
	printf("��ѧ����ѧ�š������ͳɼ�Ϊ��\n");
	printf("ѧ��\t\t����\t\t������\tרҵ��\tѡ�޿�\t���Ŀ�\tʵ���\n");
	printf("%-16s%-8s\t%d\t%d\t%d\t%d\t%d\n",p->no,p->name,p->basic,p->pro,p->selective,p->humanity,p->exp);
	fflush(stdin);
	printf("�Ƿ�ȷ��ɾ��(Y/N)?");
	select=getchar();
	if(select=='Y'||select=='y')
	{
		pre->next=p->next; //������p��ָ��Ľ���������ɾ������
		free(p);
		printf("ɾ���ɹ���\n");
	}
	else
		printf("ɾ��ȡ����\n");
	return;
} 
//�����������ܣ�����ѧ���޸�ѧ���ĳɼ�������
void modify()
{
	STU *p;
	char no[20];
	int i;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
	gets(no);
	p=findNode(no); //��������no��Ӧ�Ľ���ַ����
	if(p==NULL)
	{
		printf("ѧ����Ϣ������\n");
		return;
	}
	printf("��ѧ���������ͳɼ�Ϊ��\n");
	printf("����\t\t������\tרҵ��\tѡ�޿�\t���Ŀ�\tʵ���\n");
	printf("%-8s\t%d\t%d\t%d\t%d\t%d\n",p->name,p->basic,p->pro,p->selective,p->humanity,p->exp);
	printf("�������޸ĺ�ĳɼ�\n����1�޸Ļ�����\n����2�޸�רҵ��\n����3�޸�ѡ�޿�\n����4�޸����Ŀ�\n����5�޸�ʵ���\n������������ȡ���޸ģ�\n");
	i=get_num();
	switch(i)
		{
			case 1:printf("������ѧ��:");p->basic = get_num();while(p->basic<0||p->basic>100){
					printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
					p->basic = get_num();
					
			}	
			printf("�޸ĳɹ���\n");
			break;
			case 2:printf("רҵ��ѧ��:");p->pro = get_num();while(p->pro<0||p->pro>100){
					printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
					p->pro = get_num();		
			}
			printf("�޸ĳɹ���\n");
			break;
			case 3:printf("ѡ�޿�ѧ��:");p->selective = get_num();while(p->selective<0||p->selective>100){
					printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
					p->selective = get_num();
			}
			printf("�޸ĳɹ���\n");
			break;
			case 4:printf("���Ŀ�ѧ��:");p->humanity = get_num();while(p->humanity<0||p->humanity>100){
					printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
					p->humanity = get_num();
					
			}
			printf("�޸ĳɹ���\n");
			break;
			case 5:printf("ʵ��ѧ��:");p->exp = get_num();while(p->exp<0||p->exp>100){
					printf("ѧ�ֱ�����ڵ���0��С�ڵ���100�����������룺");
					p->exp = get_num();
					
			}
			printf("�޸ĳɹ���\n");
			break;
			default:printf("�˳��ɹ���\n");break;
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

//�����������ܣ�����ѧ�����һ��ѧ���ɼ���Ϣ������
void showData()
{
	char no[20];
	STU *p;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	printf("��������Ҫ��ѯ��ѧ�ţ�\n");
	gets(no);
	p=findNode(no); //�������ҡ���
	if(p==NULL)
		printf("ѧ����Ϣ�����ڣ�\n");
	else
	{
		printf("ѧ��\t\t����\t\t�༶\t������\tרҵ��\tѡ�޿�\t���Ŀ�\tʵ���\n");
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

//��.�������ܣ��������ѧ����ƽ���ɼ�����
void getAverage()
{
	FILE *fp=fopen("D:\\ѧ�ֹ���ϵͳ_ƽ����.txt","w");
	double avg_basic=0,avg_pro=0,avg_selective=0,avg_humanity=0,avg_exp=0; //����avg���ƽ���ɼ�����
	int count=0; //����count ���ѧ����������
	STU *p;
	if(head.next==NULL)
	{
		printf("δ����ѧ���ɼ�����\n");
		return;
	}
	p=head.next; //pָ���һ���ڵ� 
	while(p!=NULL) //������p��ΪNULLʱ����
	{
		count++; //����ѧ��������1����
		avg_basic+=p->basic;
		avg_pro+=p->pro;
		avg_selective+=p->selective;
		avg_humanity+=p->humanity;
		avg_exp+=p->exp;
		 //������ѧ���ɼ��ۼӵ�avg�У���
		p=p->next; //����pָ����һ����㣪��
	}
	avg_basic/=count; //��������ƽ���ɼ�����
	avg_pro/=count;
	avg_selective/=count;
	avg_humanity/=count;
	avg_exp/=count; 
	printf("ƽ���ɼ�Ϊ��\n");
	printf("������\tרҵ��\tѡ�޿�\t���Ŀ�\tʵ���\n");
	printf("%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",avg_basic,avg_pro,avg_selective,avg_humanity,avg_exp);
	fprintf(fp,"%s\t%s\t%s\t%s\t%s\n","������","רҵ��","ѡ�޿�","���Ŀ�","ʵ���");
	fprintf(fp,"%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",avg_basic,avg_pro,avg_selective,avg_humanity,avg_exp);
	fclose(fp);
	return;
}

//�����������ܣ��ͷ����������д��ѧ����Ϣ�Ľ�㡣����
void freeList()
{
	STU *p;
	p=head.next; //�����ӵ�һ����㿪ʼ�ͷţ���
	while(p!=NULL) //����ѭ���ͷ�������ÿ�����Ŀռ䣪��
	{
		head.next=p->next;
		free(p); //�����ͷ�pָ��Ľ��ռ䣪��
		p=head.next; //����ָ�����pָ����һ�����ͷŵĽ�㣪��
	}
	return;
}



