#include <iostream>
#include <sstream>
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
			cerr << "Error: queue is empty";
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



int main(){

	Queue players[2];
	string input1, input2;
	int stepNum = 0;
	getline(cin,input1);
	getline(cin,input2);
	bool isGood = true;
	while((input1.find(" ") != string::npos) && (input2.find(" ") != string::npos)){
		input1.erase(input1.begin()+input1.find(" "));
		input2.erase(input2.begin()+input2.find(" "));

	}
	for(int i = 0; i<input1.size();i++){
		/*stringstream ss(input1);
		int tmpNum1 = 0;
		input1[i] >> tmpNum1;
		stringstream ss1(input2);
		int tmpNum2 = 0;*/
		//input2[i] >> tmpNum2;
		players[0].push(input1.substr(i,1));
		players[1].push(input2.substr(i,1));

	}
	//(players[0].empty() == false) || (players[1].empty() == false)
	//while((players[0].empty() != 1) || (players[1].empty() != 1))
	//for(int i = 0;i<5;i++)
	bool isWorking = true;
	while(isWorking == true){ 
		if(((players[0].front()== "0") && (players[1].front() == "9")) || ((players[1].front()=="0")&&(players[0].front() == "9"))){

			if(players[0].front() == "0"){
				players[0].push(players[0].front());
				players[0].push(players[1].front());
			}
			else if(players[1].front() == "0"){
				players[1].push(players[0].front());
				players[1].push(players[1].front());
			}
			players[0].pop();
			players[1].pop();
			stepNum++; 
		}
		else{
			if(players[0].front()>players[1].front()){

				players[0].push(players[0].front());
				players[0].push(players[1].front());

			}
			else if(players[0].front()<players[1].front()){

				players[1].push(players[0].front());
				players[1].push(players[1].front());
						

			}
			players[0].pop();
			players[1].pop();
			stepNum++; 

		}
				
		if((players[0].empty() == 1) || (players[1].empty() == 1)){
			isWorking = false;
		}
				

		if(stepNum > 1000000){
					cout << "botva" << endl;
					isWorking = false;
					isGood = false;
		}
	}
	//players[0].free();
	if(isGood == true){
		if(players[0].empty() == 0){
			cout << "first " << stepNum;
		}else{
			cout << "second " << stepNum;
		}
	}
	//cout << "fdhjfgj" << endl;
	//cout << "First " << players[0].empty() << " Second " << players[1].empty()<< " " << stepNum << endl;

	


	//cout << players[0].front() << " " << players[1].front() << endl;
}