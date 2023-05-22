//Tam giac lap trinh huong doi tuong 
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> Diem;
#define x first
#define y second
double kc(Diem A,Diem B)
{
	double u=A.x-B.x,v=A.y-B.y;
	return sqrt(u*u+v*v); 
} 

class TG
{
	Diem A,B,C;
	public:

void Nhap(){
	cout<<"Diem A: ";cin>>A.x>>A.y; 
	cout<<"Diem B: ";cin>>B.x>>B.y; 
	cout<<"Diem C: ";cin>>C.x>>C.y; 
}	 

double CV(){
	return kc(A,B)+kc(A,C)+kc(C,B); 
}

double DT(){
	return fabs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y))/2; 
} 

};
int main()
{
	TG t;
	t.Nhap();
	cout<<"Chu vi tam giac "<<t.CV();
	cout<<"\nDien tich tam giac "<<t.DT(); 
		
}

