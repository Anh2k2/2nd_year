/*
Lap chuong trinh nhap toa do cac dinh cua 1 tam giac bky trong mp.
Tinh dien tich va chu vi cua tam giac do.In kq len man hinh. 
*/
//Lap trinh cau truc 
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
void Nhap(Diem &A,char ten)
{
	cout<<"Nhap diem "<<ten<<" : ";
	cin>>A.x>>A.y; 
} 
double kc(Diem A,Diem B)
{
	A.x-=B.x; A.y-=B.y;
	return sqrt(A.x*A.x+A.y*A.y); 
} 
double dt(Diem A,Diem B)
{
	return A.x*B.y-A.y*B.x; 
}

//typedef double Ham(Diem A,Diem B)'
double fun(Diem A,Diem B,Diem C,double f(Diem,Diem))
{
	return f(A,B)+f(B,C)+f(C,A); 
} 
int main()
{
	Diem A,B,C;
	Nhap(A,'A');Nhap(B,'B'); Nhap(C,'C'); 
	cout<<"Chu vi "<<fun(A,B,C,kc);
	cout<<"\nDien tich "<<fabs(fun(A,B,C,dt))/2; 
	
} 
