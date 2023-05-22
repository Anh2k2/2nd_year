#include<bits/stdc++.h>
using namespace std;
#ifndef __Stack__cpp__
#define __Stack__cpp__
template <class T>
class Stack{
	int num, cap;
	T *buff;
	public:
		Stack(){buff = 0; cap=num=0;}
		~Stack(){if(buff) delete []buff; buff = 0;}
		int size(){return num;}
		bool empty(){return num == 0;}
		T &top(){return buff[num-1];}
		void pop(){num--;}
		void push(T x){
			if(num==cap){
				cap = 2*cap+5;
				T *tem= new T[cap];
				for(int i=0; i<num; i++) tem[i]=buff[i];
				if(buff) delete[]buff;
				buff = tem;
			}
			buff[num++]=x;
		}
};
#endif

