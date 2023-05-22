#include<bits/stdc++.h>
using namespace std;

class dayso{
	private:
		int n;
		float *a;
	public:
		dayso();
		dayso(int);
		~dayso();
		void nhap();
		void in();
		void them();
};

dayso::dayso(){
	n =0;
	a = NULL;
}

dayso::dayso(int m){
	n=m;
	a = new float [n];
}

dayso::~dayso(){
	delete []a;
}

void dayso::nhap(){
	for (int i=0;i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}

void dayso::in(){
	cout<<"Day so la: ";
	for (int i=0;i<n;i++){
		cout<<a[i]<<setw(10);
	}
}

void dayso::them(){
	int h;
	float k;
	cout<<endl<<"Nhap so can them vao day la: ";
	cin>>k;
	cout<<"Can them vao vi tri: ";
	cin>>h;
	for (int i=n-1;i>=h;i++){
			a[i+1]=a[i];
		}
		a[h]=k;
		n++;
	cout<<"Day so la: ";
	for (int i=0;i<n+1;i++){
		cout<<a[i]<<setw(10);
	}
}

int main(){
	int m,h;
	float k;
	cout<<"Nhap so phan tu: ";
	cin>>m;
	dayso t(m);
	t.nhap();
	cout<<setprecision(1)<<fixed;
	t.in();
	t.them();
}

