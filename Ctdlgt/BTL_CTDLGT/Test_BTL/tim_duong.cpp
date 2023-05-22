#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
#include"Queue.cpp"
using namespace std;
#define Toado pair <int,int>
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
		void Print(Toado* x, int k);
		void TRY(Toado* x, int k, Toado f);
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
void Mecung::Print(Toado* x, int k)
{
	cout<<"\nCach di thu "<<d+1<<" : ";
	for(int i = 1; i < k; i++)
		cout << "(" << x[i].H << "," << x[i].C << ")->";
	cout<<"(" << x[k].H << "," << x[k].C << ")";
	d++;
}
void Mecung::TRY(Toado* x, int k, Toado f)
{
	if (x[k] == f) Print(x, k);
	else
	{
		for(int t = 0; t <= 3; t++)
		{
			x[k + 1].H = x[k].H + hh[t];
	   		x[k + 1].C = x[k].C + hc[t];
		   	if (A[x[k + 1].H][x[k + 1].C] == 0)
		   	{
		    	A[x[k + 1].H][x[k + 1].C] = 1; //tien
		    	TRY(x, k + 1, f);
		    	A[x[k + 1].H][x[k + 1].C] = 0; //lui
		   	}
	  	}
	}
}
void Mecung::Path()
{
	Toado s, f;
	d = 0;
	cout << "\nNhap toa do xuat phat : ";
	cin >> s.H >> s.C;
	cout << "Nhap toa do ket thuc : ";
	cin >> f.H >> f.C;
	Toado* x = new Toado[n*m+5];
	x[1] = s;
	A[s.H][s.C] = 1;
	TRY(x, 1, f);
	if (d == 0) cout << "Khong co duong di";
	else cout << "\nCo so duong di la " << d;
}
int main()
{
	Mecung M;
	M.LoadFile("input.txt");
	cout << "ME CUNG \n";
	M.Write();
	M.Path();
}
