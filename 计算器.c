#include "stdio.h"
#include "malloc.h"
#define   MAX_SIZE 15
#define   STACKINCREMENT  10
			
struct stack_char
{
	char *base;
	char *top;
	int stacksize;
};      //字符栈


struct stack_double
{
	double *base;
	double *top;
	int stacksize;
};		//运算数栈







/*********初始化字符栈*******/
void   Initstack_char(struct stack_char *p)
{

	if(p->base)
	
	
	{
		p-> top=p-> base;
		p-> stacksize=MAX_SIZE;
	}
}



/*********初始化数字栈*******/
void   Initstack_double(struct stack_double *p)
{
	
	if(p->base)
	
	
	{
		p-> top=p-> base;
		p-> stacksize=MAX_SIZE;
	}
}


 /*********把字符压栈*******/
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



 /*********把数字压栈*******/
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


	/*********读取字符栈栈头*******/
char Get_top_char(struct stack_char *p)
{
	char e;
	if(p->top!=p->base)   
		e=*(p->top-1); 
	return   e; 
};
	/*********读取数字栈栈头*******/
double Get_top_double(struct stack_double *p)
{
	double e;
	if(p->top!=p->base)   
	e=*(p->top-1); 
	return   e; 
};



/*********计算ab关系*******/
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



/*********读取并删除字符栈栈头*******/
void Pop_char(struct stack_char *p,char *c)
{
	
	if(p-> top!=p-> base)
		*c=*(--p->top);
	//return *c;
};


/*********读取并删除数字栈栈头*******/
void Pop_double(struct stack_double *p,double *c)
{
	
	if(p->top!=p->base)
		*c=*(--p->top);
//	return *c;
};


/*********优先级计算*******/
char Precede(char op1, char op2)  //计算优先级 ， 是关键函数， 利用两个switch， 效率较高——只需用进行两次比较
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



/*********把字符串转化成双精度浮点数*******/
char*  change_str_to_double(struct stack_double *p,char *str)
{

	int  num=0;
	double  num2=0;
	if(*str!='\0'&&(*str>='0'&&*str<='9'))//*str指向的不是字符
	{
		while(*str>='0'&&*str<='9')
		{
		
		num=num*10+(*str-'0');
		str++;
		
		}	//得到整数部分str指向数字的下一位
	
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
	
				}//str指向'.'
				str++;
				while(*str>='0'&&*str<='9')
				{
					str++;
				}//此时str应该是指向一个符号
				num2=num2*0.1;		//得到小数部分
		
			}//if
		else
			num2=0;
		printf("运算数 %lf 入运算数栈---->\n",num+num2);
		Push_double(p,num+num2);
		return  str;//此时str应该指向一个符号。。。。
		
	}//if
	else
		return str;
	
	
}



/*********主函数*******/

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

	printf("*******************计算器***********************\n");

	OPTR=(struct stack_char *)malloc(sizeof(struct stack_char));
	OPND=(struct stack_double *)malloc(sizeof(struct stack_double));
	L=(double *)malloc(MAX_SIZE*sizeof(double));
	M=(char *)malloc(MAX_SIZE*sizeof(char));
	OPTR->base=M;
	OPND->base=L;
	
	Initstack_char(OPTR);
	Initstack_double(OPND);
	Push_char(OPTR,'#');
	
	printf("***********请输入要计算的四则运算***************\n");
	printf("***************运算式以#号结尾******************\n");
	gets(n);
	str=&n[0];
	while((*str!='#'||(Get_top_char(OPTR))!='#')&&*str!='\0')
	{
		    str=change_str_to_double(OPND,str);  //str指向一个符号要么是'\0'要么是+-*/#

			switch(Precede(Get_top_char(OPTR),*str))
			{
				case '<': 
					printf("下一个运算符是%c       \n",*str);
					printf("运算符 %c 的优先级高于栈顶运算符 %c ，入字符栈------>\n",*str,Get_top_char(OPTR));
					Push_char(OPTR,*str);//运算符优先级低的时候，压入字符
					
					str++;
					break;
				case'=':
					
					printf(" %c 的运算级与栈中'('相同，脱括号-------->\n",*str);
					Pop_char(OPTR,&x);
					str++;
					break;
				case'>':
					printf("下一个运算符是%c       \n",*str);
					printf("运算符 %c 的优先级低于栈顶运算符 %c ----->\n",*str,Get_top_char(OPTR));

					Pop_char(OPTR,&theta);
					Pop_double(OPND,&b);
					Pop_double(OPND,&a);
					
					printf("则此时计算 %lf %c %lf-------->\n",a,theta,b); 
					Push_double(OPND,Operate(a,theta,b));
					printf("结果为 %lf ，结果入运算数栈--------->\n\n",Get_top_double(OPND));
					
					break;
			}//switch
		
		

	}//while

	printf("最后运算结果为 %lf \n",Get_top_double(OPND));
	getchar();
		



}//main
