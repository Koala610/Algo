#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>  
using namespace std;
struct Node{
	int value;
	Node *left,*right = NULL;
	Node(int key){
		left = right = NULL;
		this -> value = key;
	}

};

struct binaryTree{
	Node *first;
	binaryTree(){
		first = NULL;
	}

	/*void add(int a){
		Node *tmp;
		tmp = new Node();
		tmp -> value = a;
		if(first == NULL){
			first = tmp;
			first -> left = NULL;
			first -> right = NULL;
			count++;
		}else{
			Node *cur = first; 

			while(1){
				if(cur -> value > tmp -> value){
					if(cur->left == NULL){
						cur -> left = tmp;
						count++;
						break;
					}else{
						cur = cur -> left;
					}
				}else if(cur -> value < tmp -> value){
					if(cur->right == NULL){
						cur -> right = tmp;
						count++;
						break;
					}else{
						cur = cur -> right;
					}
				}
			}
		}

	}*/
};
vector<int>v;
int n = 0;
int Node_Height(const Node* p){
    int l, r, h = 0;
    if(p != NULL){
        l = Node_Height(p->left);
        r = Node_Height(p->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}
int count(Node *tmp){
	if(tmp ==NULL){
		return 0;
	}
	if(abs(Node_Height(tmp->left)-Node_Height(tmp->right))>1){
		n++;
	}
	return count(tmp->right) + count(tmp->left) + 1;
}





void add(int a,Node **t){
	if((*t) == NULL){
		(*t) = new Node(a);
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if(a>(*t)->value){
		add(a,&(*t)->right);
	}else if(a<(*t)->value){
		add(a,&(*t)->left);
	}

}







int main(){
	binaryTree a;
	int num;
	while(1){
		cin>>num;
		if(num != 0){
			add(num,&a.first);
		}else{
			break;
		}
		
	}

	count(a.first);
	/*sort(v.begin(),v.end());
	for(vector<int>::iterator itr = v.begin();itr!=v.end();++itr){
		cout << *itr << endl;
	}*/
	if(n==0){
		cout << "YES";
	}else{
		cout << "NO";
	}
}