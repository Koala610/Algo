#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

struct field
{
	string value;
	field *next, *prev;

};

struct fieldInt
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
			return "Error";
		}

	}

	string front(){
		return first->value;
	}

	string back(){
		return last->value;
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

struct Dequeue{

	field *first, *last;

	Dequeue(){
		first = NULL;
	}  //пустой конструктор

	void push_back(string a){
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

	string pop_front(){
		if(first != NULL){
			string v = first->value;
			field *tmp = first;
			first = first->next;
			delete tmp;
			return v;
		}else{
			cout << "Error: queue is empty" << endl;
			return "Error";
		}

	}

	void push_front(string a){
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

	string pop_back(){
		if(first != NULL){
			string v = first->value;
			field *tmp = first;
			first = first->next;
			delete tmp;
			return v;
		}else{
			cout << "Error: queue is empty" << endl;
			return "Error";
		}

	}

	string front(){
		return first->value;
	}

	string back(){
		return last->value;
	}

	bool empty(){
		return first == NULL;
	}

	void free(){
		while(!empty()){
			pop();
		}
	}

	~Dequeue() {
        free (); 
    } 

};

/*struct Stack{
	fieldInt *first, *last;

	Stack(){
		first = NULL;
	}

	void push(int n){

		fieldInt *tmp;
		tmp = new fieldInt();
		tmp->value = n;
		if(first == NULL){
			first = tmp;
			last = first;
		}else{
			last -> next = tmp;
			last = tmp;
		}

	}

	void pop(){

		if(first != NULL){
			int tmpN = last->value;
			fieldInt *tmp = last;
			last = 

		}

	}

};*/

int main(){

	cout << pow(10,6);
	return 0;
}