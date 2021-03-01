#include <iostream>

using namespace std;
struct Node{
	int value;
	Node *left,*right = NULL;

	Node(int value){
		left = right = NULL;
		this -> value = value;
	}

};
Node *tree = NULL;

struct binaryTree{
	Node *first = NULL;

	/*Node* add(int a, Node *tmp){
		Node *tmp;
		
		if(first == NULL){
			tmp = new Node(a);
			return tmp;
		}else{
			Node *cur = first; 


			while(1){
				if(cur -> value > tmp -> value){
					if(cur->left == NULL){
						cur -> left = tmp;
						break;
					}else{
						cur = cur -> left;
					}
				}else if(cur -> value < tmp -> value){
					if(cur->right == NULL){
						cur -> right = tmp;
						break;
					}else{
						cur = cur -> right;
					}
				}
			}
		}
		if(first -> value > a){
			tmp = 
		}


	}*/


};

/*Node* insert(Node *v, int a){
	Node *u;
	if(v == NULL){
		u = new Node(a);
		return u;
	}
	
	if(v->value > a){
		u = insert(v->left,a);
		if(v->left == NULL){
			v -> left = u;
		}
	}else if(v->value < a){
		u = insert(v->right,a);
		if(v->right == NULL){
			v -> right = u;
		}
	}
	return u;

}*/
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






int Node_Height(const Node* p){
    int l, r, h = 0;
    if(p != NULL){
        l = Node_Height(p->left);
        r = Node_Height(p->right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}





int main(){
	//binaryTree a;
	int num = -1;
	while(num != 0){
		cin>>num;
		if(num != 0){
			add(num,&tree);
		}else{
			break;
		}
		
	}
	cout << Node_Height(tree);

}