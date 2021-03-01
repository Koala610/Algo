#include <iostream>
#include <vector>
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

	void add(int a){
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

	}
};
int cc = 0;
int n = 0;
int count(Node *tmp){
	if(tmp ==NULL){
		return 0;
	}
	if(tmp->left!=NULL && tmp->right!=NULL){
		cc++;
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
	int n;cin >> n;
	for(int i = 0; i<n;i++){
		int tmp; cin>> tmp;
		add(tmp,&a.first);
	}
	count(a.first);
	cout << cc;
}


	