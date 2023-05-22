#include<bits/stdc++.h>
using namespace std;
#ifndef __Graph__cpp__
#define __Graph__cpp__ 
template<class G> 
class Graph{
	private:
		int nV ;                 
		int nE ;                 
		int type ;               
		int mtk[100][100];     
	public:
		void Nhap(){
			int dd, dc;
			for(int i=1;i<=G.nV;i++)
				for(int j=1;j<=nV;j++)
					G.mtk[i][j]=0;
			for(int k=1;k<=G.nE;k++)
				G.mtk[dd][dc]=1;
				if(G.type==0)
					G.mtk[dd][dc]=1; 	 
		}
		void Xuat(){
			for(int i=1;i<=G.nV;i++)
				for(int j=1;j<=G.nV;j++)
					G.mtk[i][j]; 
		}	 
}; 
#endif 

