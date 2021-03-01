#include <iostream>

using namespace std;
struct field
{
	int value;
	field *next;

};

struct Queue
{
	field *first, *last;

	Queue(){
		first = NULL;
	}  //пустой конструктор

	void push(int a){
		field *tmp;
		tmp = new field();
		tmp->value = a; //tmp.value = a
		if(first == NULL){
			first = tmp;
			last = first;
		}else{
			last->next = tmp;
			last = tmp;
		}

	}

	int pop(){
		if(first != NULL){
			int v = first->value;
			field *tmp = first;
			first = first->next;
			delete tmp;
			return v;
		}else{
			cout << "Error: queue is empty" << endl;
		}
	}

	int front(){
		return first->value;
	}

	bool empty(){
		return first == NULL;
	}

	void free(){
		while(!empty()){
			pop();
		}
	}

	~Queue() {
        free (); 
    } //деструктор


};

int main(){
	int n; cin >> n;
	int q; cin >> q;
	int a[n];
	Queue queue[q];
	int l1,r1,l2,r2;
	for(int i = 0; i<n;i++){
		cin >> a[i];
	}
	for(int i = 0; i<q;i++){
		cin >> l1 >> r1 >> l2 >> r2;
		for(int j = 0; j<n; j++){
			if((l1 <= a[j]) && (a[j] <=r1)){
				queue[i].push(j);
				cout << j << endl;
			}else if(((l2<=a[j])&&(a[j]<=r2))){
				queue[i].push(j);
				cout << j << endl;
			}
		}
		l1,r1,l2,r2 = 0;
	}
	for(int i = 0; i<q;i++){
		cout << queue[i].last -> value << endl;
	}


	//int a[];

}