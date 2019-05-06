#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<time.h>
#include<cmath>
#include<fstream>
int m;  //最大数
int numofcalculate; //算式数量
int brackets; //是否有括号
int decimal;  //是否有小数
char op[4]={'+','-','*','/'};		  //运算符
int ope;      //用户输入的运算符
void  integer_Cal();
void decimal_Cal();
using namespace std;
ofstream outfile;
int main()
{
	outfile.open("myfile.txt");
	cout<<" ***************** "<<endl;
	cout<<" ①:请输入算式数量: "<<endl;
	cin>>numofcalculate;
	cout<<" ②: 请输入最大数: "<<endl;
	cin>>m;
	cout<<" ③:请输入运算符: "<<endl;
	cout<<" 1代表+ 2代表- 3代表* 4代表/ 其他代表随意:"<<endl;
	cin>>ope;
	cout<<" ④:请选择数字类型: "<<endl;
	cout<<" 1代表整数 2代表小数"<<endl;
	cin>>decimal;
	cout<<" ⑤:请选择是否需要括号 "<<endl;
	cout<<" 1代表不需要括号 2代表需要括号"<<endl;
	cin>>brackets;
	if(decimal==1)
	{
		srand(time(NULL));
		for(int i=0;i<numofcalculate;i++)
		{
			integer_Cal();
		}
	}
	else
	{
		srand(time(NULL));
		for(int i=0;i<numofcalculate;i++)
		{
			decimal_Cal();
		}
	}
	outfile.close();
	cout<<" ************* "<<endl;
	return 0;
}
void integer_Cal()
{
	int a,b,c,d;
	a=(rand()%m)+1;
	b=(rand()%m)+1;
	c=(rand()%m)+1;
	int op1,op2,op3;
	op1=rand()%4;
	op2=rand()%4;
	if(brackets==1)
	{
		if(ope==1)
		{
			cout<<a<<"+"<<b<<"+"<<c<<"="<<endl;
			outfile<<a<<"+"<<b<<"+"<<c<<"="<<endl;
		}
		else if(ope==2)
		{
			cout<<a<<"-"<<b<<"-"<<c<<"="<<endl;
			outfile<<a<<"-"<<b<<"-"<<c<<"="<<endl;
		}
		else if(ope==3)
		{
			cout<<a<<"*"<<b<<"*"<<c<<"="<<endl;
			outfile<<a<<"*"<<b<<"*"<<c<<"="<<endl;
		}
		else if(ope==4)
		{
			cout<<a<<"/"<<b<<"/"<<c<<"="<<endl;
			outfile<<a<<"/"<<b<<"/"<<c<<"="<<endl;
		}
		else
		{
			cout<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;
			outfile<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;
		}
	}
	else
	{
		int k;
		k=rand()%2;
		if(k==0)
		{
			if(ope==1)
			{
				cout<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
				outfile<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
				outfile<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
				outfile<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
				outfile<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
			}
			else
			{
				cout<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
				outfile<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
			}
		}
		else
		{
			if(ope==1)
			{
				cout<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
				outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
				outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
				outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
				outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
			}
			else
			{
				cout<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
				outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
			}
		}
	}
}
void decimal_Cal()
{
	double a,b,c,d;
	a=(double)rand()/RAND_MAX*m+1.0;
	b=(double)rand()/RAND_MAX*m+1.0;
	c=(double)rand()/RAND_MAX*m+1.0;
	int op1,op2;
	op1=rand()%4;
	op2=rand()%4;
	if(brackets==1)
	{
		if(ope==1)
		{
			cout<<a<<"+"<<b<<"+"<<c<<"="<<endl;
			outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
		}
		else if(ope==2)
		{
			cout<<a<<"-"<<b<<"-"<<c<<"="<<endl;
			outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
		}
		else if(ope==3)
		{
			cout<<a<<"*"<<b<<"*"<<c<<"="<<endl;
			outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
		}
		else if(ope==4)
		{
			cout<<a<<"/"<<b<<"/"<<c<<"="<<endl;
			outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
		}
		else
		{
			cout<<a<<op[op1]<<b<<op[op2]<<c<<"="<<endl;
			outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
		}
	}
	else
	{
		int k;
		k=rand()%2;
		if(k==0)
		{
			if(ope==1)
			{
				cout<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
				outfile<<"("<<a<<"+"<<b<<")"<<"+"<<c<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
				outfile<<"("<<a<<"-"<<b<<")"<<"-"<<c<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
				outfile<<"("<<a<<"*"<<b<<")"<<"*"<<c<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
				outfile<<"("<<a<<"/"<<b<<")"<<"/"<<c<<"="<<endl;
			}
			else
			{
				cout<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
				outfile<<"("<<a<<op[op1]<<b<<")"<<op[op2]<<c<<"="<<endl;
			}
		}
		else
		{
			if(ope==1)
			{
				cout<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
				outfile<<a<<"+"<<"("<<b<<"+"<<c<<")"<<"="<<endl;
			}
			else if(ope==2)
			{
				cout<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
				outfile<<a<<"-"<<"("<<b<<"-"<<c<<")"<<"="<<endl;
			}
			else if(ope==3)
			{
				cout<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
				outfile<<a<<"*"<<"("<<b<<"*"<<c<<")"<<"="<<endl;
			}
			else if(ope==4)
			{
				cout<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
				outfile<<a<<"/"<<"("<<b<<"/"<<c<<")"<<"="<<endl;
			}
			else
			{
				cout<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
				outfile<<a<<op[op1]<<"("<<b<<op[op2]<<c<<")"<<"="<<endl;
			}
		}
	}
}
