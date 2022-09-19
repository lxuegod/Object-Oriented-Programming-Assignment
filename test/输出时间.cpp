// #include <iostream>
// using namespace std;
// class Clock
// {
// public:
//     Clock(int H, int M, int S)
//     {
//         Hour = H;
//         Minute = M;
//         Second = S;
//     }
//     void ShowTime();
// private:
//     int Hour, Minute, Second;
// };
// void Clock::ShowTime()
// {
//     cout<<this->Hour<<":"<<this->Minute<<":"<<this->Second<<endl;
// }
// int main(){
//     Clock c(17, 8 ,20);
//     c.ShowTime();
//     return 0;
// }

// #include <iostream>
// #include <time.h>
// using namespace std;
// int main(){
//     time_t t = time(NULL);
//     tm * _tm = localtime(&t);
//     int hh = _tm->tm_hour;
//     int mm = _tm->tm_min;
//     int ss = _tm->tm_sec;
//     printf("%02d:%02d:%02d", hh, mm, ss);
//     return 0;
// }

#include <iostream>
#include <time.h>
using namespace std;
int main(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%H:%M:%S",localtime(&timep) );
    cout << tmp << endl;
    return 0;
}