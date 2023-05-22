#include<bits/stdc++.h>
using namespace std;
template <class Keys, class T> 
class Node
{ 
private: 
    Keys key;  
    T elem; 
    Node<Keys,T> *parent; 
    Node<Keys,T> *left; 
    Node<Keys,T> *right;  
public: 
    Node()
	{  
        parent = NULL; 
        left = NULL; 
        right = NULL;  
    }  
    ~Node()
	{  
        parent = NULL; 
        left = NULL; 
        right = NULL;  
    }  
    Node<Keys,T> *getParent() { return parent;} 
    Node<Keys,T> *getLeft() { return left;} 
    Node<Keys,T> *getRight() { return right;} 
    void setLeft(Node<Keys,T>* p){ left = p;} 
    void setRight(Node<Keys,T>* p) {right = p;} 
    void setParent(Node<Keys,T>* p) {parent= p;} 
    int hasLeft() { return left!=NULL; } 
    int hasRight() { return right!=NULL;} 
    T& getElem(){ return elem;} 
    void setElem(T e) { elem =e;} 
    Keys getKey(){ return key;} 
    void setKey(Keys k){ key = k; } 
}; 

template <class Keys, class T> 
class BSTree
{ 
private: 
    Node<Keys,T> *root; 
    long count;  
    void inOrder(Node<Keys,T>*,Node<Keys,T>*&first,int  &kt); 
    void remove(Node<Keys,T>*&); 
public: 
    BSTree(); 
    Node<Keys,T> *getRoot(); 
    int size(); 
    int isEmpty(); 
    int isInternal(Node<Keys,T>*); 
    int isExternal(Node<Keys,T>*); 
    int isRoot(Node<Keys,T>*); 
    void preOrder(Node<Keys,T>*); 
    void inOrder(Node<Keys,T>*); 
    void postOrder(Node<Keys,T>*); 
    Node<Keys,T>*search(Keys, Node<Keys,T>*); 
    Node<Keys,T>* insert(Keys, T);  
    void remove(Keys); 
}; 
//------------------ Cai dat cac phuong thuc -------------- 
template <class Keys, class T> 
BSTree<Keys,T>::BSTree() 
{ 
    root = NULL; 
    count=0; 
} 
template <class Keys, class T> 
Node<Keys,T>* BSTree<Keys,T>::getRoot() 
{ 
    return root; 
} 
template <class Keys, class T> 
int BSTree<Keys,T>::size() 
{ 
    return count; 
} 
template <class Keys, class T>
int BSTree<Keys,T>::isEmpty() 
{ 
    return root==NULL; 
} 
template <class Keys, class T> 
int BSTree<Keys,T>::isInternal(Node<Keys,T>* p) 
{ 
    return p->hasLeft()||p->hasRight(); 
} 
template <class Keys, class T> 
int BSTree<Keys,T>::isExternal(Node<Keys,T>*p) 
{ 
    if(!p->hasLeft() && !p->hasRight()) return 1; 
    else return 0; 
} 
template <class Keys, class T> 
int BSTree<Keys,T>::isRoot(Node<Keys,T>* p) 
{ 
    if(p->getParent()==NULL) return 1; 
    else return 0; 
} 
template <class Keys, class T> 
void BSTree<Keys,T>::preOrder(Node<Keys,T>*p) 
{ 
    if(p!=NULL)
	{ 
        cout<<p->getElem()<<""; 
        preOrder(p->getLeft()); 
        preOrder(p->getRight()); 
    } 
} 
template <class Keys, class T> 
void BSTree<Keys,T>::inOrder(Node<Keys,T>*p) 
{ 
    if(p!=NULL)
	{ 
        inOrder(p->getLeft()); 
        cout<<p->getElem()<<""; 
        inOrder(p->getRight()); 
    } 
} 
template <class Keys, class T> 
void BSTree<Keys,T>::postOrder(Node<Keys,T>*p) 
{ 
    if(p!=NULL)
	{ 
        postOrder(p->getLeft()); 
        postOrder(p->getRight()); 
        cout<<p->getElem()<<"";  
    } 
} 
template <class Keys, class T> 
Node<Keys,T>* BSTree<Keys,T>::search(Keys key, Node<Keys,T>*  p) 
{ 
    if(p!=NULL)
	{ 
        if(p->getKey()>key) return search(key,p->getLeft()); 
        else if(p->getKey()<key) 
            return search(key,p->getRight()); 
        else return p; 
    } 
    else return NULL; 
} 
template <class Keys, class T> 
Node<Keys,T>* BSTree<Keys,T>::insert(Keys key, T elem)
{ 
    Node<Keys, T>*p; 
    Node<Keys, T>*q = new Node<Keys, T>(); 
    q->setKey(key); 
    q->setElem(elem); 
    if(root==NULL)
	{ 
        root = q; 
        count++; 
    } 
    else{ 
        p = root; 
        while(p != NULL)
		{ 
            if(key< p->getKey()) 
                if(p->getLeft()==NULL)
				{
                	q->setParent(p); 
                    p->setLeft(q); 
                    count++; 
                    p = NULL; //dat p = NULL de ket thuc 
                } 
                else 
                    p = p->getLeft(); 
                else 
                    if(key> p->getKey()) // nam ben cay con ben phai 
                        if(p->getRight()== NULL)
						{ 
                            q->setParent(p); 
                            p->setRight(q); 
                            count++; 
                            p = NULL; 
                        } 
                        else 
                            p = p->getRight(); 
                else
				 { 
                    delete q; 
                    p=NULL; 
                } 
        } 
    } 
    return q;  
} 
template <class Keys, class T> 
void BSTree<Keys,T>::inOrder(Node<Keys,T> *p, Node<Keys,T>  *&first, int &kt) 
{ 
    if(p!=NULL && kt!=1) 
    {
        inOrder(p->getLeft(),first, kt); 
        if(kt==0) 
        { 
            first = p; 
            kt=1; 
        } 
    } 
} 
template <class Keys, class T> 
void BSTree<Keys,T>::remove(Node<Keys,T> *&v) 
{ 
    Node<Keys,T> *p; 
    if (!v->hasLeft() && !v->hasRight())
    { 
        p=v->getParent(); 
        if(p!=NULL) 
            if(v == p->getLeft()) 
                p->setLeft(NULL); 
            else p->setRight(NULL);  
            else v = NULL;  
    } 
    if(v->hasLeft() && !v->hasRight()) 
    { 
        p=v->getParent(); 
        v->getLeft()->setParent(p); 
        if(p->getLeft()==v) p->setLeft(v->getLeft()); 
        else p->setRight(v->getLeft()); 
    } 
    if((!v->hasLeft()) && v->hasRight()) 
    { 
        p=v->getParent(); 
        v->getRight()->setParent(p); 
        if(p->getLeft()==v) p->setLeft(v->getRight()); 
        else p->setRight(v->getRight()); 
    } 
    delete v; 
} 
template <class Keys, class T> 
void BSTree<Keys,T>::remove(Keys key) 
{ 
    Node<Keys,T>*v = search(key, root); 
    if(v==NULL) return; 
    if(v->hasLeft()&& v->hasLeft())  //Co ca hai con 
	{ 
        Node<Keys,T> *first; 
        int kt=0; 
        inOrder(v->getRight(), first, kt); 
        v->setKey(first->getKey()); 
        v->setElem(first->getElem()); 
        remove(first); 
    } 
    else 
        remove(v); 
        count--; 
} 

int main()
{ 
    BSTree<int,char*> tree; 
    Node<int,char*> *p; 
   
    tree.insert(100,"  100-1  "); 
    tree.insert(70,"  70a  "); 
    tree.insert(150,"  150x  "); 
    tree.insert(120,"  120-y  "); 
    
    cout<<"Duyet cay theo thu tu truoc:  "; 
    tree.preOrder(tree.getRoot());  
    cout<<"\nDuyet cay theo thu tu giua:  "; 
    tree.inOrder(tree.getRoot());  
    cout<<"\nDuyet cay theo thu tu sau:  "; 
    tree.postOrder(tree.getRoot());     
    cout<<"\n"; 
    
    p = tree.search(120, tree.getRoot()); 
    if(p!=NULL) 
        cout<<"Tim thay khoa 120, Co gia tri "<<p->getElem(); 
	else cout<<"Khong tim thay khoa 120."; 
  
    tree.remove(120); 
    tree.remove(70);  
    cout<<"\nDuyet cay theo thu tu giua: "; 
    tree.inOrder(tree.getRoot()); 
    return 0; 
}

 

