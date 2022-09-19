#include <iostream>
using namespace std;
class myException
{
public:
    myException(){ }
    ~myException(){ }
    const char *showReason()
   {  return "myException异常"; }
};
class Demo
{
public:
   Demo()
   { cout<<"构造Demo. "<<endl; }
   ~Demo()
   { cout<<"析构Demo. "<<endl; }
};
int main()
{  cout<<"在main函数中"<<endl;
    try
   {    Demo d;
         throw myException();
    }
    catch(myException e)
    { cout<<"在catch异常处理程序中"<<endl;
      cout<<"捕获到myException类型异常: ";
      cout<<e.showReason()<<endl;
     }
     catch(char* str)
     {  cout<<"捕获字符异常"<<endl;  }
cout<<"回到main函数,从这里开始恢复执行" <<endl;  }