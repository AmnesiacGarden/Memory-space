#include "stdio.h"
#include "malloc.h"
#define   MAX_SIZE 15
#define   STACKINCREMENT  10
			
struct stack_char
{
	char *base;
	char *top;
	int stacksize;
};      //�ַ�ջ


struct stack_double
{
	double *base;
	double *top;
	int stacksize;
};		//������ջ







/*********��ʼ���ַ�ջ*******/
void   Initstack_char(struct stack_char *p)
{

	if(p->base)
	
	
	{
		p-> top=p-> base;
		p-> stacksize=MAX_SIZE;
	}
}



/*********��ʼ������ջ*******/
void   Initstack_double(struct stack_double *p)
{
	
	if(p->base)
	
	
	{
		p-> top=p-> base;
		p-> stacksize=MAX_SIZE;
	}
}


 /*********���ַ�ѹջ*******/
void Push_char(struct stack_char *p,char c)
{
	
	if((p->top-p->base)>=p->stacksize)
	{
		p->base=(char *)realloc(p->base,(p->stacksize+STACKINCREMENT)*sizeof(char));
		if(p->base)
		{
			p->top=p->base+p->stacksize;
			p->stacksize+=STACKINCREMENT;
		}
	}
	*p->top++=c;
}



 /*********������ѹջ*******/
void Push_double(struct stack_double *p,double c)
{

	
	if((p->top-p->base)>=p->stacksize)
	{
		p->base=(double *)realloc(p->base,(p->stacksize+STACKINCREMENT)*sizeof(double));
		if(p->base)
		{
		p->top=p->base+p->stacksize;
		p->stacksize+=STACKINCREMENT;
		}
	}
	*p->top++=c;

}


	/*********��ȡ�ַ�ջջͷ*******/
char Get_top_char(struct stack_char *p)
{
	char e;
	if(p->top!=p->base)   
		e=*(p->top-1); 
	return   e; 
};
	/*********��ȡ����ջջͷ*******/
double Get_top_double(struct stack_double *p)
{
	double e;
	if(p->top!=p->base)   
	e=*(p->top-1); 
	return   e; 
};



/*********����ab��ϵ*******/
double   Operate(double a,char theta,double b)  
{ 
	//printf("%lf %c %lf\n",a,theta,b);
      switch(theta)   
	  { 
            case '+':  return   a+b; 
            case '-':  return   a-b; 
            case '*':   return   a*b; 
            case '/':   if(b == 0)
							   return 0;
						   else
							   return a / b; 
            default   :  return   0; 
      }   
}



/*********��ȡ��ɾ���ַ�ջջͷ*******/
void Pop_char(struct stack_char *p,char *c)
{
	
	if(p-> top!=p-> base)
		*c=*(--p->top);
	//return *c;
};


/*********��ȡ��ɾ������ջջͷ*******/
void Pop_double(struct stack_double *p,double *c)
{
	
	if(p->top!=p->base)
		*c=*(--p->top);
//	return *c;
};


/*********���ȼ�����*******/
char Precede(char op1, char op2)  //�������ȼ� �� �ǹؼ������� ��������switch�� Ч�ʽϸߡ���ֻ���ý������αȽ�
{ 
	switch(op1)
	{
		case '+':
			switch(op2)
			{
		case '+':	return '>';
		case '-':	return '>';
		case '*':	return '<';
		case '/':	return '<';
		case '(':	return '<';
		case ')':	return '>';
		case '#':	return '>';
			}
		case '-':
			switch(op2)
			{
		case '+':	return '>';
		case '-':	return '>';
		case '*':	return '<';
		case '/':	return '<';
		case '(':	return '<';
		case ')':	return '>';
		case '#':	return '>';
			}
		case '*':
			switch(op2)
			{
		case '+':	return '>';
		case '-':	return '>';
		case '*':	return '>';
		case '/':	return '>';
		case '(':	return '<';
		case ')':	return '>';
		case '#':	return '>';
			}
		case '/':
			switch(op2)
			{
		case '+':	return '>';
		case '-':	return '>';
		case '*':	return '>';
		case '/':	return '>';
		case '(':	return '<';
		case ')':	return '>';
		case '#':	return '>';
			}
		case '(':
			switch(op2)
			{
		case '+':	return '<';
		case '-':	return '<';
		case '*':	return '<';
		case '/':	return '<';
		case '(':	return '<';
		case ')':	return '=';
		case '#':	return '#';
			}
		case ')':
			switch(op2)
			{
		case '+':	return '<';
		case '-':	return '<';
		case '*':	return '<';
		case '/':	return '<';
		case '(':	return '#';
		case ')':	return '>';
		case '#':	return '>';
			}
		case '#':	
			switch(op2)
			{
		case '+':	return '<';
		case '-':	return '<';
		case '*':	return '<';
		case '/':	return '<';
		case '(':	return '<';
		case ')':	return '#';
		case '#':	return '=';
			}
	}
	return '#';
}



/*********���ַ���ת����˫���ȸ�����*******/
char*  change_str_to_double(struct stack_double *p,char *str)
{

	int  num=0;
	double  num2=0;
	if(*str!='\0'&&(*str>='0'&&*str<='9'))//*strָ��Ĳ����ַ�
	{
		while(*str>='0'&&*str<='9')
		{
		
		num=num*10+(*str-'0');
		str++;
		
		}	//�õ���������strָ�����ֵ���һλ
	
		if(*str=='.')
			{
				str++;
				while(*str>='0'&&*str<='9')
				{
					str++;
				}
				str--;
				while(*str!='.')
				{

					num2=num2*0.1+(*str-'0');
					str--;
	
				}//strָ��'.'
				str++;
				while(*str>='0'&&*str<='9')
				{
					str++;
				}//��ʱstrӦ����ָ��һ������
				num2=num2*0.1;		//�õ�С������
		
			}//if
		else
			num2=0;
		printf("������ %lf ��������ջ---->\n",num+num2);
		Push_double(p,num+num2);
		return  str;//��ʱstrӦ��ָ��һ�����š�������
		
	}//if
	else
		return str;
	
	
}



/*********������*******/

void main()
{
	struct stack_char *OPTR;
	struct stack_double *OPND;
	double *L;
	char *M;
	char x,theta;
	double a,b;
	char n[100];
	char *str;

	printf("*******************������***********************\n");

	OPTR=(struct stack_char *)malloc(sizeof(struct stack_char));
	OPND=(struct stack_double *)malloc(sizeof(struct stack_double));
	L=(double *)malloc(MAX_SIZE*sizeof(double));
	M=(char *)malloc(MAX_SIZE*sizeof(char));
	OPTR->base=M;
	OPND->base=L;
	
	Initstack_char(OPTR);
	Initstack_double(OPND);
	Push_char(OPTR,'#');
	
	printf("***********������Ҫ�������������***************\n");
	printf("***************����ʽ��#�Ž�β******************\n");
	gets(n);
	str=&n[0];
	while((*str!='#'||(Get_top_char(OPTR))!='#')&&*str!='\0')
	{
		    str=change_str_to_double(OPND,str);  //strָ��һ������Ҫô��'\0'Ҫô��+-*/#

			switch(Precede(Get_top_char(OPTR),*str))
			{
				case '<': 
					printf("��һ���������%c       \n",*str);
					printf("����� %c �����ȼ�����ջ������� %c �����ַ�ջ------>\n",*str,Get_top_char(OPTR));
					Push_char(OPTR,*str);//��������ȼ��͵�ʱ��ѹ���ַ�
					
					str++;
					break;
				case'=':
					
					printf(" %c �����㼶��ջ��'('��ͬ��������-------->\n",*str);
					Pop_char(OPTR,&x);
					str++;
					break;
				case'>':
					printf("��һ���������%c       \n",*str);
					printf("����� %c �����ȼ�����ջ������� %c ----->\n",*str,Get_top_char(OPTR));

					Pop_char(OPTR,&theta);
					Pop_double(OPND,&b);
					Pop_double(OPND,&a);
					
					printf("���ʱ���� %lf %c %lf-------->\n",a,theta,b); 
					Push_double(OPND,Operate(a,theta,b));
					printf("���Ϊ %lf �������������ջ--------->\n\n",Get_top_double(OPND));
					
					break;
			}//switch
		
		

	}//while

	printf("���������Ϊ %lf \n",Get_top_double(OPND));
	getchar();
		



}//main
