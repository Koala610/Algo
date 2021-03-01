#include <iostream>
#include <cmath>
using namespace std;
struct field
{
	string value;
	field *next;

};

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
			return "";
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
	Queue queue;
	Queue queue1;.
	string input;
	getline(cin,input);
	for(int i = 0;i < input.length();i++){
		queue.push(i);
	}
	
	for(int i = 0;i < input.length();i++){
		}

}