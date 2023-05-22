#include<bits/stdc++.h>
#define ll long long
using namespace std;
int _x[]={0 , -1 , 0 , 1};
int _y[]={1 , 0 , -1 , 0};
int so_duong;
class MeCung{
	int n, m;
	int A[100][100];
	vector<pair<int, int>> Toado;
	public:
		void Doc_File(string fn);
		void Write();
		void Print();
		void TRY_MeCung(pair<int, int> bd, pair<int,int> dich);
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
void MeCung::Print(){
	cout<<"\nCach di thu "<<so_duong<<" : ";
	int n = Toado.size();
	for(int i = 0; i < n - 1; i++){
		cout<<"("<<Toado[i].first<<","<<Toado[i].second<<")->";
	}
	cout<<"("<<Toado[n-1].first<<","<<Toado[n-1].second<<")";
}
void MeCung::TRY_MeCung(pair<int, int> bd,pair<int,int> dich){
	queue<pair<int, int>> Q;
	Q.push(bd);
	while(!Q.empty()){	
		pair<int, int> u = Q.front();
		Q.pop();
		Toado.push_back(u);
		bool check = true;
		for(int t=0; t<=3; t++){
			pair<int,int>x;
			x.first = u.first + _x[t];
			x.second = u.second + _y[t];
			if(x == dich){
				cout << "Co duong" << endl;
				return;
			}
			if(A[x.first][x.second] == 0){
				Q.push(x);
				A[x.first][x.second] = 1;
				check = false;				
			}
		}	
		if(check) Toado.pop_back();
	}
}
void MeCung::Path()
{
	pair<int,int> dau, dich;
	int d = 0;
	cout << "\nNhap toa do xuat phat : ";
	cin >> dau.first >> dau.second;
	cout << "\nNhap toa do ket thuc : ";
	cin >> dich.first >> dich.second;

	A[dau.first][dau.second] = 1;
	TRY_MeCung(dau, dich);
	Print();
}
int main()
{
	MeCung M;
	M.Doc_File("input.txt");
	cout<<"ME CUNG"<<endl;
	M.Write();
	M.Path();

}


