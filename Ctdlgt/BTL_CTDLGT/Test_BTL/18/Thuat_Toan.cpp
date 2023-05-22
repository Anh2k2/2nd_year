#include<bits/stdc++.h>
#ifndef __Thuat_Toan__cpp__
#define __Thuat_Toan__cpp__ 
#define ll long long
using namespace std;
map<int, bool>Dau;
pair<int, int> P[100];
class Thuat_Toan{
	int n, m;
	stack<int> Q;
	public:
		void LoadFile(string fn);
		void DFS();
		void Write();
		void Out();
};
void Thuat_Toan::Out(){
	cout<<"\n\nCac duong cua do thi vo huong\n";
	LoadFile("file.txt");
	for(int i=0; i<m; i++)
		cout<<P[i].first <<" " <<P[i].second<<endl;
	Q.push(1);
	DFS();
	Write();
}
void Thuat_Toan::LoadFile(string fn){
	ifstream f(fn);
	f >> n >> m;
	int i=0;
	while(i<m){
		f >> P[i].first >> P[i].second;
		i++;
	}
	
}
void Thuat_Toan::DFS(){
	while(!Q.empty()){
		int u = Q.top();
		Q.pop();
		Dau[u]= true;
		for(int i=0; i<m; i++){
			if(u == P[i].first) {
				if(Dau[ P[i].second ] == false){
					Q.push(P[i].second);
					Dau[P[i].second] = true;
				}
			}
			else if(u == P[i].second) {
				if(Dau [P[i].first ] == false){
					Q.push(P[i].first);
				Dau[P[i].first] = true;
				}
			}
		}
	}
}
void Thuat_Toan::Write(){
	for(int i=1; i<=n; i++){
		if(Dau[i] == false){
			cout<<"=> DO THI KHONG LIEN THONG";
			return ;
		}
	}
	cout<<"=> DO THI CO LIEN THONG";
}
#endif

