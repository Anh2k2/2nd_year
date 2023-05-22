#include<bits/stdc++.h>
using namespace std;
template<class T>

class node{
	public:
		T elem;
		node<T> *L,*R;		//1 node se co node trai va node phai
		node(){
			L=R=NULL;
		}
};

template<class T>
class BinaryTree{
	private:
		node<T> *far;
		int leaf = 0;
		long long sum = 0;
		
	public:
		BinaryTree(){
			far=NULL;
		}
		node<T> *createNode(T x){		//luu lai gia tri cua return vao bien cuc bo : them * truoc tren ham
			node<T> *newNode = new node<T>; 	// khoi tao node co con tro L = R = 0
			
			newNode->elem = x;			//gan gia tri x cho elem
			newNode->L = newNode->R = NULL;
			return newNode;	
		}
		long long getSum(){
			return sum;
		}
		int getLeaf(){
			return leaf;
		}
		node<T> *getNode(){
			return far;
		}
		//7,2,4,1,3,9,10,5,6,8
		void insertNode(T x){
			node<T> *newNode = createNode(x); //khoi tao node moi
			
			if(far != NULL){
				node<T> *temp = far;		// chay tren cac node khi duyet, luon bat dau tu goc, co the hieu temp la mui ten
				node<T> *farCurr = NULL;  //	la node cha khi duyet (luon thay doi theo temp)
				while(temp!=NULL){		// do duong tu goc cho den vi tri node cha cua node can them
					
					farCurr = temp;
					if(temp->elem > newNode->elem){	
//						cout<<"temp->elem: "<<temp->elem<<" "; //7 - 7 - 7 2 - 7 4 - 7 - 7 - 9
						temp = temp->L;		// tro den node con ben trai == NULL
					}
					else{
						temp=temp->R;
					}
//					cout<<farCurr->elem<<" ";				
				}
				if(farCurr->elem > newNode->elem){
					farCurr->L = newNode;
				}
				else{
					farCurr->R = newNode;
				}
			}
			else{
				far = newNode;
			}
		}
		void preOrder(node<T>* far){
			if(far!=NULL){
				if(far->L == NULL && far->R == NULL){
					leaf++;
				}
				cout<<far->elem<<" ";
				preOrder(far->L);
				preOrder(far->R);
			}
		}
		void inOrder(node<T>* far){
			if(far!=NULL){
				inOrder(far->L);
				cout<<far->elem<<" ";
				inOrder(far->R);
			}
		}
		void postOrder(node<T>* far){
			if(far!=NULL){
				postOrder(far->L);
				postOrder(far->R);
				cout<<far->elem<<" ";
			}
		}
		node<T> *find(node<T> *far, T x){
			if(far || far->elem ==x) return far;
			return find(x<far->elem ? far->L : far->R, x);
		}
		
		
		
		bool isLeaf(node<T>* curr) {
		    return (curr->L == nullptr && curr->R == nullptr);
		}
		
	//						  2 
	//					   /     \
	//					 7        9
	//	   		      /    \     / 
	//  		     1     6    8
	//                    / \
	//                   3   5
	//                        \   
	//                         11	
		void rootToLeafPaths(node<T>* far, vector<int> &path){
			if (far == nullptr) {
		        return; 
		    }
		    path.push_back(far->elem);
		    if (isLeaf(far)){     		//neu khong tim thay node con nua ->
		    	cout<<endl;
		    	long long s = 0;
		    	int i=0;
		        for (int data: path) {
		            s = s + data*pow(10,i);
		            i++;
		            cout<<data<<"   ";
		        }
		        sum+=s;
		    }
		 
		    rootToLeafPaths(far->L, path);
		    rootToLeafPaths(far->R, path);
		 
		    path.pop_back();
		}
		void rootToLeafPaths(node<T>* far){
			vector<int> path;
		    rootToLeafPaths(far, path);
		}
		
		void check(int a, node<T>* far, vector<int> &path, int &i){
			
			if (far == nullptr) {
		        return;
		    }
		    path.push_back(far->elem);
		    if (isLeaf(far)){
			     		//neu khong tim thay node con nua ->
		    	long long s = 0;
		        for (int data: path) {
		            s += data;
		        }
				if(s==a){
					i++;
					for (int data: path) {
		            	cout<<data<<"  ";
		        	}
		        	cout<<endl;
				}
		    }
		    
		    check(a,far->L, path,i);
		    check(a,far->R, path,i);
		 	
		    path.pop_back();
		    
		}
		void check(int a){
			vector<int> path;
			int i=0;
			check(a, far, path, i);
			if(i==0){
				cout<<"false";
			}
		}
		
};



int main(){
	

	
	BinaryTree<int> BT;
	for(int x:{2,7,6,1,3,9,5,11,8}){
		BT.insertNode(x);
	}
	
	cout<<"\nTien  thu tu: "; BT.preOrder(BT.getNode());
//	cout<<"\nTrung thu tu: "; BT.inOrder(BT.getNode());
//	cout<<"\nHau   thu tu: "; BT.postOrder(BT.getNode());
	cout<<"\nSo duong di tu goc den la: ";
	cout<<BT.getLeaf();
	BT.rootToLeafPaths(BT.getNode());
	cout<<"\nTong cac duong di la: ";
	cout<<BT.getSum();
	
	int a;cout<<"\nNhap vao so a: ";cin>>a;
	BT.check(a);
	
}

