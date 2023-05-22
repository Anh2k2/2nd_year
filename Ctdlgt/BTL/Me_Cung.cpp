#include<bits/stdc++.h>
#include"Queue.cpp"
#ifndef __Me_Cung__cpp_
#define __Me_Cung__cpp_ 
#define H first
#define C second 
using namespace std;
int hh[]={0 , -1 , 0 , 1};
int hc[]={1 , 0 , -1 , 0};
class MeCung{
	int n, m;
	int a[100][100];
	int d;
	vector<pair<int, int>> Toado;
	public:
		void LoadFile(string fn);
		void Write();
		void Print();
		void Try_MeCung(pair<int, int> bd, pair<int,int> f);
		void Path();
};
void MeCung :: LoadFile(string fn){
	ifstream f(fn);
	f >> n >> m;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
				f >> a[i][j];
		}
	}	
	f.close();
	for(int i = 0; i<=n+1; i++){
		a[i][0] = a[i][m+1] = 1;
	}
	for(int j = 0; j<=m+1; j++){
		a[0][j] = a[n+1][j] = 1;
	}		
}
void MeCung :: Write(){
	for(int i = 0; i<= n+1; i++){
		for(int j=0; j<= m+1; j++){
			cout<< a[i][j] <<" ";
		}
		cout<<"\n";
	}
}
void MeCung::Try_MeCung(pair<int, int> bd,pair<int,int> f){
	queue<pair<int, int>> Q;
	Q.push(bd);
	while(!Q.empty()){	
		pair<int, int> u = Q.front();
		Q.pop();
		Toado.push_back(u);
		bool check = true;
		for(int t=0; t<=3; t++){
			pair<int,int>x;
			x.H = u.H + hh[t];
			x.C = u.C + hc[t];
			if(x == f){
				cout << "Co duong di." << endl;
				return;
			} 
			if(a[x.H][x.C] == 0){
				Q.push(x);
				a[x.H][x.C] = 1;
				check = false;				
			}
		}	
		if(check) Toado.pop_back();
	}
}
void MeCung::Print(){
	cout<<"Cach di "<<d+1<<":";
	int n = Toado.size();
	for(int i = 0; i < n - 1; i++){
		cout<<"("<<Toado[i].H<<","<<Toado[i].C<<")->";
	}
	cout<<"("<<Toado[n-1].H<<","<<Toado[n-1].C<<")";	
}
void MeCung::Path()
{
	pair<int,int> s, f;
	d=0; 
	LoadFile("input.txt");
	cout<<"\n\nMe Cung"<<endl;
	Write();
	cout<<"(0 la duong - 1 la tuong)";
	cout<< "\nNhap toa do xuat phat : ";
	cin >> s.H >> s.C;
	cout << "Nhap toa do ket thuc : ";
	cin >> f.H >> f.C;
	a[s.H][s.C] = 1;
	Try_MeCung(s, f);
	Print();	
}
#endif 



