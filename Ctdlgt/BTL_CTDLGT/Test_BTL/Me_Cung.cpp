#include<bits/stdc++.h>
#include"Stack.cpp"
#ifndef __Me_Cung__cpp__
#define __Me_Cung__cpp__ 
using namespace std;
#define Toado Stack<pair<int,int> >
#define H first
#define C second
int hh[] = { 0, -1, 0, 1 };
int hc[] = { 1, 0, -1, 0 };
class Mecung
{
	int n, m;
	int A[100][100];
	int d;
	public:
		void LoadFile(string fn);
		void Write();
		void Print(Toado x, int k);
		void TRY_MeCung(Toado x, int k, pair<int, int> f);
		void Path();
};
void Mecung::LoadFile(string fn)
{
	ifstream f(fn);
	f >> n >> m;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			f >> A[i][j];
	f.close();
	for(int i = 0; i<=n+1; i++) 
		A[i][0] = A[i][m+1] = 1;
	for(int j = 0; j<=m+1; j++)
		A[0][j] = A[n+1][j] = 1;
}
void Mecung::Write()
{
	for(int i = 0; i <= n+1; i++)
	{
		for(int j = 0; j <= m+1; j++)
			cout << A[i][j] <<" ";
		cout << "\n";
	}
}
void Mecung::Print(Toado x, int k)
{
	Toado y;
	cout<<"\nCach di thu "<<d+1<<" : ";
	for(int i = 1; i <= k; i++){
		y.push(x.top());
		x.pop();
	}
	for(int i = 1; i < k; i++){
		cout << "(" << y.top().H << "," << y.top().C << ")->";
		x.push(y.top());
		y.pop();
	}
	cout<<"(" << y.top().H << "," << y.top().C << ")";
	x.push(y.top());
	d++;
}
void Mecung::TRY_MeCung(Toado x, int k, pair<int, int> f)
{
	if (x.top() == f) Print(x, k);
	else
	{
		for(int t = 0; t <= 3; t++)
		{
			pair<int, int> tt;
			tt.H = x.top().H + hh[t];
	   		tt.C = x.top().C + hc[t];
	   		x.push(tt);
		   	if (A[x.top().H][x.top().C] == 0)
		   	{
		    	A[x.top().H][x.top().C] = 1; //tien
		    	TRY_MeCung(x, k + 1, f);
		    	A[x.top().H][x.top().C] = 0; //lui
		   	}
		   	x.pop();
	  	}
	}
}
void Mecung::Path()
{
	pair<int, int> s, f;
	d = 0;
	LoadFile("input.txt");
	cout<<"\n\nMe cung"<<endl;
	Write();
	cout << "\nNhap toa do xuat phat : ";
	cin >> s.H >> s.C;
	cout << "Nhap toa do ket thuc : ";
	cin >> f.H >> f.C;
	Toado x;
	x.push(s);
	A[s.H][s.C] = 1;
	TRY_MeCung(x, 1, f);
	if (d == 0) cout << "Khong co duong di";
	else cout << "\nCo so duong di la " << d;
}
#endif 
//int main()
//{
////	graph G;
////	G.Out();
//	
//	Mecung M;
//	M.Path();
//
//}
