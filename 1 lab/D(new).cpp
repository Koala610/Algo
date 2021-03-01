#include <iostream>
#include <sstream>

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

struct X
{
	field *first, *last, *prev ;

	Queue(){
		first = NULL;
	}  //пустой конструктор
};

int main(){
	Queue gradesList[3];  // создаем массив из 3 очередей: 9,10,10 классы
	while(1){
		string input;
		string surname;
		int num = 0;
		string stNum;
		getline(cin,input);

		if(input.size() == 0){
			break;
		} // если строка пустая, то выход
		surname = input.substr(input.find(" ") + 1); //  с помощью подстроки, выносим Фамилию в отдельную переменную
		stNum = input.substr(0,2);
		stringstream stToInt(stNum);
		stToInt >> num;
		num -= 9;
		 // берём номер класса и отнимаем 9, чтобы добавить в соответствующую очередь
		gradesList[num].push(surname);

	}
	/*for(int i = 0; i< 3; i++){
		while(!gradesList[i].empty()){
			cout << i+9 << " " << gradesList[i].pop() << endl;
		}
	}*/

	return 0;
}