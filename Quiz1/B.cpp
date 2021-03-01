#include <iostream>

using namespace std;
struct Queue
{
	field *first, *last;

	Queue(){
		first = NULL;
	}  //пустой конструктор

	void push(string a){
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

	string pop(){
		if(first != NULL){
			string v = first->value;
			field *tmp = first;
			first = first->next;
			delete tmp;
			return v;
		}else{
			cout << "Error: queue is empty" << endl;
		}
	}

	string front(){
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


	int q; cin >> q;
	Queue queue;
	for(int i = 0; i<q;i++){
		getline()
	}
	//int a[];

}