#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE*fp;
int j=1,i,k;/*i:第几人 j:总人数 k:指定数*/
int n;/*统计文件个数*/
struct Brithday
{
	int year;
	int month;
	int day;
};
struct Friend
{
	int num;
	char name[20];
	char tel[13];
	int type;/*1：办公类 2：个人类 3：商务类*/
	struct Brithday Brithday;
	char email[20];
	char addr[20];
}friends[15];
int main()
{
	void Date_Input(int i);/*输入信息*/
	void Date_output(int i);/*输出信息*/
	void Insert();/*插入信息*/
	void Delete();/*删除指定记录*/
	void Search();/*按姓名查询*/
	void Xiugai();/*修改信息*/
    void Fwrite();/*写入文件*/
    void Fread();/*读取文件*/
	void Mean();/*主菜单*/
	void Lei_search();/*按类别查询*/
    Fread();
	do
	{
	char s;
	E:
	Mean();
	scanf("%s",&s);
	switch(s)
	{
	case '1':
	    system("cls");
        if((fp=fopen("通讯录.text","r+"))==NULL)
        {
            printf("不能打开这个文件！\n");
            return;
        }
        fread(&j,sizeof(int),1,fp);
		if(j>=1)
		{
            for(i=1;i<=j;i++)
            {
                Date_output(i);
                printf("\n");
            }
		}
		else
			printf("没有记录！\n\n");
		break;
    case '2':
        system("cls");
        C:
            printf("请添加记录：\n");
        for(i=j+1;i<15;i++)
        {
            Date_Input(i);
            j++;
			Fwrite();
            printf("\t是否继续插入\n");
            printf("\t\t1:是 \n");
            printf("\t\t2:否\n");
            D:
	        scanf("%d",&k);
	        if(k==1)
	        {
	            goto C;
                printf("\n");
	        }
	        else if(k==2)
               goto E;
            else
            {
                printf("请输入1-2！\n");
                goto D;
            }
        }
	case '3':
	    system("cls");
	    {
	        Insert();
            Fwrite();
	        break;
	    }
	case '4':
	    system("cls");
	    {
	        Xiugai();
            Fwrite();
            break;
	    }
	case '5':
	    system("cls");
	    {
	        printf("\t请选择删除的方式\n");
            printf("\t\t1:删除指定条数 \n");
            printf("\t\t2:全部删除\n");
            F:
	        scanf("%d",&k);
	        if(k==1)
	        {
                Delete();
	            Fwrite();
	            printf("删除成功！\n");
                printf("\n");
                break;
	        }
	        else if(k==2)
            {
                R:
                printf("\t\t\t是否确认删除\n\t\t\t1.是\n\t\t\t2.否\n");
                int s=0;
                scanf("%d",&s);
                if(s==1)
                {
                    j=0;Fwrite();
                    printf("删除成功！\n");
                    break;
                }
                else if(s==2)
                    break;
                else
                    goto R;
                break;
            }
            else
            {
                printf("请输入1-2！\n");
                goto F;
            }
	       break;
	    }
	case '6':
	    system("cls");
	    {
	        B:
	        printf("\t请输入查询的方式\n");
            printf("\t\t1:按姓名查询 \n");
            printf("\t\t2:按类别查询\n");
	        scanf("%d",&k);
	        if(k==1)
	        {
                Search();
                printf("\n");
                break;
	        }
	        else if(k==2)
            {
                Lei_search();
                printf("\n");
                break;
            }
            else
            {
                printf("请输入1-2！\n");
                goto B;
            }

	       break;
	    }
	case '7':
	    {
	        printf("按任意键退出！");
	        Fwrite();
	        goto A;
	    }
	default:printf("输入错误！\n");
	}

	}while(6);
	A:
	return 0;
}


void Mean()/*主菜单*/
{
	printf("\n\t主菜单功能选择：\n");
	printf("\t1：显示所有记录\n");
	printf("\t2：添加\n");
	printf("\t3：插入\n");
	printf("\t4：修改\n");
	printf("\t5：删除\n");
	printf("\t6：查询\n");
	printf("\t7：保存并退出\n");
}

void Date_Input(int i)/*信息录入*/
{
	friends[i].num=i;
	printf("第%d条记录\n",i);
	printf("请输入姓名：\n");
	scanf("%s",friends[i].name);
	printf("请输入电话号码\n");
	scanf("%s",friends[i].tel);
	printf("请输入联系人所属类别（输数字（1：办公类 2：个人类 3：商务类））：\n");
	scanf("%d",&friends[i].type);
	printf("请输入生日（年）：\n");
	scanf("%d",&friends[i].Brithday.year);
	printf("请输入生日（月）：\n");
	scanf("%d",&friends[i].Brithday.month);
	printf("请输入生日（日）：\n");
	scanf("%d",&friends[i].Brithday.day);
	printf("请输入e-mail地址：\n");
	scanf("%s",friends[i].email);
	printf("请输入地址：\n");
	scanf("%s",friends[i].addr);
}
void Date_output(int i)/*信息输出*/
{
    printf("第%d条记录\n",i);
   	printf("姓名：%s\n",friends[i].name);
  	printf("电话号码:%s\n",friends[i].tel);
    printf("联系人所属类别（1：办公类 2：个人类 3：商务类）:%d\n",friends[i].type);
    printf("生日：%d/%d/%d\n",friends[i].Brithday.year,friends[i].Brithday.month,friends[i].Brithday.day);
	printf("e-mail：%s\n",friends[i].email);
	printf("地址：%s\n",friends[i].addr);
}

void Insert()/*插入记录函数*/
{
	printf("请输入要插入的位置：第（）位\n");
	scanf("%d",&k);
	for(i=j+1;i>k;i--)
	{
		strcpy(friends[i].name,friends[i-1].name);
		strcpy(friends[i].tel,friends[i-1].tel);
		friends[i].type=friends[i-1].type;
		friends[i].Brithday.year=friends[i-1].Brithday.year;
		friends[i].Brithday.month=friends[i-1].Brithday.month;
		friends[i].Brithday .day=friends[i-1].Brithday.day;
		strcpy(friends[i].email,friends[i-1].email);
		strcpy(friends[i].addr,friends[i-1].addr);
	}
	Date_Input(k);
    j++;
	printf("\n\n");
}

void Delete()/*删除指定记录*/
{
	printf("请输入要删除的位置：第（）位\n");
	scanf("%d",&k);
	for(i=k;i<j;i++)
	{
		       strcpy(friends[i].name,friends[i+1].name);
		strcpy(friends[i].tel,friends[i+1].tel);
		friends[i].type=friends[i+1].type;
		friends[i].Brithday.year=friends[i+1].Brithday.year;
		friends[i].Brithday.month=friends[i+1].Brithday.month;
		friends[i].Brithday .day=friends[i+1].Brithday.day;
		strcpy(friends[i].email,friends[i+1].email);
		strcpy(friends[i].addr,friends[i+1].addr);
	}
	j--;
	printf("\n\n");
}

void Search()/*按姓名查询功能*/
{
	int a=0;
	char names[20];
	printf("请输入要查询的人名：\n");
	scanf("%s",&names);
	for(i=1;i<=j;i++)
	{
		if(strcmp(names,friends[i].name)==0)
		{
			 Date_output(i);
			 a=1;
			 break;
		}
	}
	if(a!=1)
	    printf("没有此记录！\n");
	printf("\n\n");
}

void Lei_search()/*按类别查询*/
{
    struct Friend people[10];
    int b=0;
	int c;
	printf("\t\t请输入要查询的类别\n");
	printf("\t\t\t1:办公类\n");
	printf("\t\t\t2:个人类\n");
	printf("\t\t\t3:商务类\n");
	scanf("%d",&c);
	for(i=1;i<=j;i++)
	{
		if(friends[i].type==c)
		{
            Date_output(i);
            b=1;
		}
	}
   if(b!=1)
	    printf("此类别没有记录！\n");
	printf("\n");
}
void Xiugai()/*修改信息*/
{
	char names[20];
	int m=0;
	printf("请输入要修改的姓名：\n");
	scanf("%s",names);
	for(i=1;i<=j;i++)
	{
		if(strcmp(names,friends[i].name)==0)
		{
		    printf("查找成功，请进行修改：\n");
			 Date_Input(i);
			 break;
		}
		else
        {
            m++;
        }
	}
	if(m==j)
		printf("没有此记录！\n");
	printf("\n\n");
}

void Fwrite()/*写入文件*/
{
     if((fp=fopen("通讯录.text","w+"))==NULL)
        {
            printf("不能打开这个文件！\n");
            return;
        }
    fwrite(&j,sizeof(int),1,fp);
    for(i=1;i<=j;i++)
    {
        fwrite(&friends[i],sizeof(struct Friend),1,fp);
    }
    fclose(fp);
}
void Fread()/*读取文件*/
{
     if((fp=fopen("通讯录.text","r+"))==NULL)
    {
        printf("不能打开这个文件！\n");
        return;
    }
    fread(&j,sizeof(int),1,fp);
   for(i=1;i<=j;i++)
    {
        fread(&friends[i],sizeof(struct Friend),1,fp);
    }
    fclose(fp);
}