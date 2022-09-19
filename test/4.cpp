#include <iostream>
#include <iomanip>
using namespace std;
int* YangHuiData(int n) {
	int *a = new int[n*n]; //指针a指向new动态分配的长度为(n*n)*sizeof(int)的内存空间 

	//完成杨辉三角形的计算，没有显示的位置填0 
	int i, j;
	for (i = 0; i<n*n; i++) {
		a[i] = 0;			//填0操作		
	}
	a[0] = 1;
	a[n] = 1;
	a[n + 1] = 1;
	for (i = 2; i<n; i++) {
		a[i*n] = 1;
		a[i*n + i] = 1;
		for (j = 1; j<i; j++) {
			a[i*n + j] = a[(i - 1)*n + j - 1] + a[(i - 1)*n + j]; //通过a[i*n+j]来访问第(i*n+j)个数据,根据杨辉三角的特性求值
		}
	}
	return a;
}
void YangHuiShow(int *a, int n) {
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n - i - 1; j++)
			cout << setw(3) << " ";//前导空格，为单个数据的一半宽度  
		for (j = 0; j <= i; j++)
			cout << setw(6) << a[i*n + j];
		cout << endl;
	}
}

int main() {
	int n;
	cout << "请输入行数:"<<endl;
	cin >> n;
	int *pData = YangHuiData(n);
	YangHuiShow(pData, n);
	return 0;
}