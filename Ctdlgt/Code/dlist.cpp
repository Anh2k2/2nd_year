//dlist_iterator code by tichpx@utc.edu.vn  7/2020
#include<bits/stdc++.h>
#include"node.cpp"
using namespace std;
#ifndef __dlist_iterator__cpp__
#define __dlist_iterator__cpp__
template<class T>
class dlist_iterator
{
	node<T> *curr;
	public:
		dlist_iterator(node<T> *c=0){curr=c;}
		node<T> *getcurr() {return curr;}
		dlist_iterator &operator=(dlist_iterator<T> it) {this->curr=it.getcurr(); return *this;}
		bool operator!=(dlist_iterator<T> it) {return curr!=it.getcurr();}
		T &operator*() {return curr->getelem();}
		dlist_iterator operator++(int) {dlist_iterator it=curr;curr=curr->getnext(); return it;}
		dlist_iterator operator++() {curr=curr->getnext(); return curr;}
};
template<class T>
class dlist_reverse_iterator
{
	node<T> *curr;
	public:
		dlist_reverse_iterator(node<T> *c=0){curr=c;}
		node<T> *getcurr() {return curr;}
		dlist_reverse_iterator &operator=(dlist_reverse_iterator<T> it) {this->curr=it.getcurr(); return *this;}
		bool operator!=(dlist_reverse_iterator<T> it) {return curr!=it.getcurr();}
		T &operator*() {return curr->getelem();}
		dlist_reverse_iterator operator++(int) {dlist_reverse_iterator it=curr;curr=curr->getprev(); return it;}
		dlist_reverse_iterator operator++() {curr=curr->getprev(); return curr;}
};
#endif

