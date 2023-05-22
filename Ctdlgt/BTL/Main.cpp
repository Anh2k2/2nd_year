#include<bits/stdc++.h>
#include"Tim_Duong_Di.cpp"
#include"Me_Cung.cpp"
#include"Thuat_Toan.cpp" 
using namespace std;
int main()
{
	//Tim duong di trong do thi co huong 
	graph G;
	G.Out();
	
	//Tim duong di trong me cung 
	MeCung M;
	M.Path();
	
	//Kiem tra tinh lien thong cua do thi vo huong 
	Thuat_Toan T;
	T.Check(); 
}

