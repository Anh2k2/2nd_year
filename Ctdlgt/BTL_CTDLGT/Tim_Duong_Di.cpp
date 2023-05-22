#include<bits/stdc++.h>
#include"Queue.cpp"
#ifndef __Tim_Duong_Di__cpp__
#define __Tim_Duong_Di__cpp__
using namespace std;
class graph{
	int n;
	int a[100][100];
	public:
	    void LoadFile(string fn); 
	    int BFS(int s, int f);
		void inkq(int*, int, int);
		void Out(); 
}; 
void graph::Out(){
	int f, s;                                           
	LoadFile("du_lieu.txt");
	cout<<"Ma tran bieu dien do thi co huong"<<endl;    
	for(int i=0;i<=n;i++){                              
		a[0][i]=a[i][0]=i;                             
	}
	for(int i=0;i<=n;i++){                             
		for(int j=0;j<=n;j++){                          
			cout<<a[i][j]<<" ";	                        
		} 
		cout<<"\n";                                    
	} 
	cout<<"Nhap dinh xuat phat s: ";                  
	cin>>s;                                           
	cout<<"Nhap dinh ket thuc f: ";                    
	cin>>f;                                            
	if(BFS(s,f));                                       
	else cout<<"Khong co duong di tu "<<s<<" den " << f;
} 
void graph::inkq(int* sign, int s, int f){
	if(sign[f]==s) cout<<"Co duong di la: "<<s<<"->"<<f;              
	else{                             
		inkq(sign,s,sign[f]);               
		cout<<"->"<<f;                      
	}
} 
int graph::BFS(int s, int f){
	Queue<int>Q;                              
	int* sign=new int[n+2];                  
	int u, v, i;                              
	for(i=1;i<=n;i++){                        
		sign[i]=0;                            
	}              
	Q.push(s);                                
	sign[s]=1;                                
	while(!Q.empty()){                       
		u=Q.front();                          
		Q.pop();                              
		for(v=1;v<=n;v++)                     
			if(sign[v]==0 && a[u][v]==1){     
				Q.push(v);                    
				sign[v]=u;                    
			    if (v == f){                  
			    	inkq(sign, s, f);         
					return 1;                 
			    }	
		    }
	} 
	return 0;                                 
} 

void graph::LoadFile(string fn){
	ifstream f(fn);                           
	f>>n;                                     
    for(int i=1;i<=n;i++)                    
    for(int j=1;j<=n;j++){                    
    	int t;                                
		f>>t;                                 
		a[i][j]=t;                            
	}
}
#endif






