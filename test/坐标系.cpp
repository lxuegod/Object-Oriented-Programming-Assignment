#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point() {}   //默认构造函数
    float x;     //x坐标
    float y;     //y坐标
};

int main()
{
    Point* p = new Point[41];
    int num = 0;
    for (float i = -10; i <= 10; i += 0.5)
    {
        p[num].x = i;
        p[num].y = 2*i;
        cout <<"(" <<fixed << setprecision(1)<< p[num].x << "," << p[num].y<<")" << endl;
        num++;
    }
    delete[] p;
    return 0;
}