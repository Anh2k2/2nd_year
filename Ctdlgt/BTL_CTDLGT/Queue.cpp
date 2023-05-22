#include<bits/stdc++.h>
using namespace std;
#ifndef __Queue__cpp__
#define __Queue__cpp__
template<class T>
class Queue
{
	T *buff;
	int num, cap, F, L;
	public: 
	    Queue() {                        
		    buff=0;
			num=cap=0;
			F=L=0;
		} 
	    ~Queue() {
		    if(buff) delete[]buff; 
			buff=0;
		}
		bool empty() { return num==0; }
		int size() { return num; } 
		T &front() { return buff[F]; }
		T &back() { 
		    return L==0?buff[cap-1]:buff[L-1];
		}
		void pop() { 
		    F=(F+1)%cap; 
			num--;
		} 
		void push(T x)
		{
			if(num==cap){
				int newcap=cap*2+2;
				T *tem=new T[newcap];
				for(int i=F,j=0;i<F+cap;i++,j++) 
				    tem[j]=buff[i%cap];
				if(buff) delete[]buff;
				buff=tem;
				F=0;
				L=cap;
				cap=newcap; 
			} 
			buff[L]=x;
			L=(L+1)%cap;
			num++; 
		} 	
};
#endif 


