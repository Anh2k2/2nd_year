#include<bits/stdc++.h>
#ifndef __Thuat_Toan__cpp__
#define __Thuat_Toan__cpp__
using namespace std;
map<int, bool>Dau;
pair<int, int> P[100];
class Thuat_Toan{
	int n, m;
    Queue<int> S;
	public:
		void LoadFile(string fn);
		void BFS();
		void Write();
		void Check();
};
void Thuat_Toan::Check(){
	cout<<"\n\nCac duong cua do thi vo huong\n";      
	LoadFile("file.txt");
	for(int i=0; i<m; i++)                            
		cout<<P[i].first <<" " <<P[i].second<<endl;   
	S.push(1);                                        
	BFS();                                            
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
void Thuat_Toan::BFS(){
	while(!S.empty()){                                
		int u = S.front();                          
		S.pop();                                      
		Dau[u]= true;                                 
		for(int i=0; i<m; i++){                       
			if(u == P[i].first) {                     
				if(Dau[ P[i].second ] == false){      
					S.push(P[i].second);              
					Dau[P[i].second] = true;          
				}
			}
			else if(u == P[i].second) {               
				if(Dau [P[i].first ] == false){      
					S.push(P[i].first);               
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


