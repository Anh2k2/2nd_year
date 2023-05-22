//node code by tichpx@utc.edu.vn  7/2020
#include<bits/stdc++.h>
using namespace std;
#ifndef __node__cpp__
#define __node__cpp__
template <class T>
class node
{
	T elem;
	node<T> *prev,*next;
	public:
		node(T x,node<T> *L=0,node<T> *R=0) {elem=x;prev=L;next=R;}
		T &getelem() {return elem;}
		node<T> *&getprev(){return prev;}
		node<T> *&getnext(){return next;}
		void setelem(T x) {elem=x;}
		void setprev(node<T> *p=nullptr) {prev=p;}
		void setnext(node<T> *p=nullptr) {next=p;}
};
#endif
