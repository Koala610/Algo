#include <iostream>
using namespace std;
struct Node{
	int data[3];
	int index;
	Node *left,*right;
	Node(){

	}
	Node(int month,int day,int year){
		data[0] = month;
		data[1] = day;
		data[2] = year;
	}

};
int count = 0;
struct Date{
	Node *first;
	Date(){
		first = NULL;
	}

	void add(int month,int day,int year){
		Node *tmp = new Node(month,day,year);
		if(first == NULL){
			first = tmp;
			first -> left = NULL;
			first -> right = NULL;
			first -> index = 0;
		}else{
			Node *cur = first; 
			while(1){
				if(cur -> right != NULL){
					cur = cur -> right;
				}else{
					cur -> right = tmp;
					cur -> right -> right = NULL;
					count++;
					cur -> right -> index = count;
					break;

				}
			}
		}
	}
	Node* get(int i){
		Node *cur = first;
		while(1){
			if(cur->index!=i){
				cur = cur -> right;
			}else{
				return cur;
			}
		}

	}

	void swap(Node* a, Node* b){
		int data1[3];
		data1[0] = b -> data[0];
		data1[1] = b -> data[1];
		data1[2] = b -> data[2];


		b -> data[0] = a -> data[0];
		a -> data[0] = data1[0];
		b -> data[1] = a -> data[1];
		a -> data[1] = data1[1];
		b -> data[2] = a -> data[2];
		a -> data[2] = data1[2];
		




	}

	void print(Node* cur){
		if(cur == NULL){
			return;
		}
		cout << cur ->data[0] << " " << cur->data[1] << " " << cur->data[2] << endl;
		print(cur->right);

		}


	void sort(){
		int l = 0;
		int r = count;
		bool isWorking = true; 

		while(isWorking){
			isWorking = false;
			Node* cur =  first;
			for(int i = l;i<r;i++){
				int trig = 0;
				if((cur -> data[2] > cur -> right -> data[2]) ){
					trig = 1;
					
				}else if(cur -> data[2] == cur -> right -> data[2]){
					if(cur -> data[1] > cur -> right -> data[1]){
						trig = 1;
					}else if((cur -> data[1] == cur -> right -> data[1]) &&(cur -> data[0] > cur -> right -> data[0])){
						trig = 1;
					}
				}
				if(trig == 1){
					swap(cur,cur->right);
					isWorking = true;
				}
				cur = cur -> right;
			}
			r--;
		}
	}
};






int main(){
	Date d;
	int n; cin >>n;
	for(int i = 0; i<n;i++){
		int month;cin >> month;
		int day;cin >>day;
		int year;cin >>year;
		d.add(month,day,year);
	}
	d.sort();
	d.print(d.first);

}