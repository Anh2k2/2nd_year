#include<bits/stdc++.h>
#include"Stack.cpp"
#define ll long long
using namespace std;
int _x[]={0 , -1 , 0 , 1};
int _y[]={1 , 0 , -1 , 0};
int so_duong;
class MeCung{
	int n, m;
	int A[100][100];
	public:
		void Doc_File(string fn);
		void Write();
		void Printf(Stack<pair<int,int> >Toado, int k);
		void TRY_MeCung(Stack<pair<int,int> > Toado, int k, pair<int,int> dich);
		void Path();
};
void MeCung :: Doc_File(string fn){
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
void MeCung :: Write(){
	for(int i = 0; i<= n+1; i++){
		for(int j=0; j<= m+1; j++)
			cout<< A[i][j] <<" ";
		cout<<"\n";
	}
}
void MeCung::Printf(Stack<pair<int, int> >Toado, int k){
	cout<<"\nCach di thu "<<so_duong<<" : ";
	Stack<pair<int, int> >T,Q;
	T = Toado;
	for(int i=1; i<k; i++){
		Q.push(T.top());
		T.pop();
	}
	for(int i=1; i<k-1; i++){
		cout<<"("<<Q.top().second<<","<<Q.top().first<<")->";
		Q.pop();
	}
	cout<<"("<<Q.top().second<<","<<Q.top().first<<")";
}
void MeCung::TRY_MeCung(Stack<pair<int,int> > Toado, int k, pair<int,int> dich){
	if(Toado.top() == dich){
		so_duong++;
		Printf(Toado, k);
		return;
	}
//	while(!Toado.empty()){
	
	for(int t=0; t<=3; t++){
		pair<int,int>x;
		x.first = Toado.top().first + _x[t];
		x.second = Toado.top().second + _y[t];
		Toado.push(x);
		if(A[Toado.top().first][Toado.top().second] == 0){
			A[Toado.top().first][Toado.top().second] =1;
			TRY_MeCung(Toado, k+1, dich);
			A[Toado.top().first][Toado.top().second] =0;
			
		}
		Toado.pop();
	}
//}
}
void MeCung::Path()
{
	pair<int,int> dau, dich;
	int d = 0;
	cout << "\nNhap toa do xuat phat : ";
	cin >> dau.first >> dau.first;
	cout << "\nNhap toa do ket thuc : ";
	cin >> dich.first >> dich.second;
	Stack<pair<int,int> > x;
	x.push(dau);
	A[dau.first][dau.second] = 1;
	TRY_MeCung(x, 1, dich);
	if (d == 0) cout << "Khong co duong di";
	else cout << "\nCo so duong di la " << d;
}
int main()
{
	MeCung M;
	M.Doc_File("input.txt");
	cout<<"ME CUNG"<<endl;
	M.Write();
	M.Path();

}


