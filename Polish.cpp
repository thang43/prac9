#include "Polish.h"
#include <iostream>
using namespace std;
Polish::Polish(string s)
{
    string_handle(s); 
    if (this->op.size()!=this->operand.size()-1)
    {
        cout<<"Error";
        exit(-1);
    } 
    if(this->indicator.front()==0||this->indicator.back()==1)
    {
        cout<<"Error";
        exit(-1);
    }
}
void Polish::string_handle(string s)
{
    int start = 0;
    for(int i = 0;i<s.length();i++)
    {
        if((s[i]<'0'||s[i]>'9')&&s[i]!=' '&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/')
        {
            cout<<"Error";
            exit(-1);
        }
        if(s[i]==' '||i==s.length()-1)
        {
            int num = 0;
            if(i==s.length()-1)
            {
                i++;
            }
            for(int j=start;j<i;j++)
            {
                if(s[j]=='+')
                {
                    if(j!=i-1)
                    {
                        cout <<"Error";
                        exit(-1);
                    }
                    else
                    {
                        this->indicator.push(1);
                        this->op.push(s[j]);
                    }     
                }
                else if(s[j]=='-')
                {
                      if(j!=i-1)
                    {
                        cout <<"Error";
                        exit(-1);
                    } 
                     else
                    {
                        this->indicator.push(1);
                        this->op.push(s[j]);
                    }
                }
                else if(s[j]=='*')
                {
                      if(j!=i-1)
                    {
                        cout <<"Error";
                        exit(-1);
                    }
                     else
                    {
                        this->indicator.push(1);
                        this->op.push(s[j]);
                    } 
                }
                else if(s[j]=='/')
                {
                      if(j!=i-1)
                    {
                        cout <<"Error";
                        exit(-1);
                    }
                     else
                    {
                        this->indicator.push(1);
                        this->op.push(s[j]);
                    } 
                }
                else
                {
                    num = num*10+int(s[j]-'0');
                    if(j==i-1)
                    {
                        this->indicator.push(0);
                        this->operand.push(num);
                    }
                }
                start = i+1;
            }
        }
    }
}
int Polish:: take_indicator()
{
    if(this->indicator.empty())
    return -1;
    else{
    int i = this->indicator.front();
    this->indicator.pop();
    return i;
    }
}
char Polish:: take_op()
{
    char t = this->op.front();
    this->op.pop();
    return t;
}
int Polish::take_num()
{
    int i = this->operand.front();
    this->operand.pop();
    return i;
}
int Polish::calculate(int count)
{
    int ti = this->take_indicator();
    if(ti==-1)
    {
        cout <<"=";
        return 0;
    }
    else if(ti==0)
    {
        int i = this->take_num();
        cout <<i;
        return i;
    }
    else 
    {
        char t = this->take_op();
        
        if(t=='+')
        {
            if (count!=0)
            cout<<"(";
            int first = calculate(0);
            cout<<" + ";
            int second = calculate(0);
            if (count!=0)
            cout<<")";
            return first+second;
        }
        if(t=='-')
        {
            if (count!=0)
            cout<<"(";
            int first = calculate(0);
            cout<<" - ";
            int second = calculate(0);
            if (count!=0)
            cout<<")";
            return first-second;
        }
        if(t=='*')
        {
            
             int first = calculate(1);
            cout<<" * ";
            int second = calculate(1);
            return first*second;
        }
        if(t=='/')
        {
            
            int first = calculate(1);
            cout<<" / ";
            int second = calculate(1);
            if(second == 0)
            {
                cout<<"Error";
                exit(-1);
            }  
            return first/second;
        }
    }
}