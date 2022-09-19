#include <iostream>
using namespace std;
class Student
{
public:
    void print();
    string id;
    string name;
    string like;
    Student();
    ~Student();
};

void Student::print()
{
    cout<<"学号为："<<id<<" 姓名为："<<name<<" 爱好为："<<like<<endl;
}

Student::Student()
{
    cout<<"调用默认构造函数"<<endl;
}

Student::~Student()
{
    cout<<"调用析构函数"<<endl;
}

int main(){
    Student * students = new Student[4];
    students[0].id = "20200601";
    students[0].name = "张三";
    students[0].like = "学习";
    students[1].id = "20200602";
    students[1].name = "李四";
    students[1].like = "睡觉";
    students[2].id = "20200603";
    students[2].name = "王二";
    students[2].like = "打球";
    students[3].id = "20200604";
    students[3].name = "麻子";
    students[3].like = "看书";
    for(int i = 0; i < 4; i++){
       students[i].print();
    }
    delete [] students;
    return 0;
}