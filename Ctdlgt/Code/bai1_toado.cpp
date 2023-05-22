#include<bits/stdc++.h>

using namespace std;

class toado{
	private:
		float x , y;
	public:
		toado();
		toado(float , float);
		~toado();
		void nhap();
		void in(){
			cout<<"("<<x<<","<<y<<")  ";
		}
};

toado::toado(){
	x = 0;
	y = 0;
}
// phai lay a va b vi ko dc trung voi ten 
toado::toado(float a , float b){
	x = a;
	y = b;
}
toado::~toado(){
	
}

void toado::nhap(){
	cout<<"hoanh do la: ";
	cin>>x;
	cout<<"tung do la: ";
	cin>>y;
}

void nhaptoado(toado *a , int n){
	for (int i=0;i<n;i++){
		cout<<"nhap toa diem thu "<<i+1<<" la:"<<endl;
		a[i].nhap();
	}
}

void hienthi (toado *a , int n){
	cout<<setprecision(1)<<fixed;
	for (int i=0;i<n;i++){
		a[i].in();
	}
}

int main(){
	int n;
	cout<<"nhap so diem:";
	cin>>n;
	toado *a = new toado[n];
	nhaptoado(a,n);
	cout<<"Cau tu khong doi: toa do cac diem la:"<<endl;
	hienthi(a,n);
	cout<<endl<<"Cau tu co doi: toa do diem la: "<<endl;
	toado b(3,5);
	b.in();
}

