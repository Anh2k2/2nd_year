#include<bits/stdc++.h>
#include"Stack.cpp"
#ifndef __Tim_Duong_Di__cpp__
#define __Tim_Duong_Di__cpp__ 
using namespace std;
class graph{
	int n;
 	int A[100][100];
	public:
	void LoadFile(string fn);
 	int DFS(int s, int f);
 	void inkq(int*, int, int);
 	void Out();
};
void graph:: Out(){
	int f, s;
	LoadFile("du_lieu.txt");
	cout<<"Ma tran bieu dien do thi co huong"<<endl;
	for(int i=0; i<=n; i++)
		A[0][i]=A[i][0]=i;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++)
			cout<<A[i][j]<<" ";
		cout<<"\n";
	}
	cout << "\nNhap dinh xuat phat s :";
	cin >> s;
	cout << "Nhap dinh ket thuc f : ";
	cin >> f;
	if (DFS(s, f));
	else cout << "Khong co duong di tu " << s <<  " den " << f;
}
void graph::inkq(int* sign, int s, int f){
 	if (sign[f] == s) cout << "\n" << s << "->" << f;
 	else
 	{
  	inkq(sign, s, sign[f]);
  	cout << "->" << f;
 	}
}
int graph::DFS(int s, int f){
	Stack<int>S;
 	int* sign = new int[n + 2];
 	int u, v, i;
 	for (i = 1; i <= n; i++) sign[i] = 0;
 	S.push(s);
 	sign[s] = 1;
 	while (!S.empty())
 	{
  		u = S.top();
  		S.pop();
  		for (v = 1; v <= n; v++)
		if (A[u][v] == 1 && sign[v] == 0)
   		{
    		S.push(v);
    		sign[v] = u;
    		if (v == f) { inkq(sign, s, f); return 1; }
   		}	
 	}
 return 0;
}
void graph::LoadFile(string fn){
	ifstream f(fn);
	f >> n;
 	for (int i = 1; i <= n; i++)
  	for (int j = 1; j <= n; j++)
  	{
   		int t;
   		f >> t;
   		A[i][j] = t;
  	}
}
#endif
