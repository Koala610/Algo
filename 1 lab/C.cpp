#include <iostream>
#include <vector>

using namespace std;

int main(){
	string line = "";
	string commands[9] = {"push_back","pop_front","front","size","clear","exit","push_front","pop_back","back"};
	vector<int> v;
	int firstNum;
	int lastNum;
	while(line!="exit"){
		cin >> line;
		int det = 0;
		for(int i = 0; i<9;i++){
			if(line == commands[i]){
				det = i;
			}
		}
		switch(det){

			case 0:   //push_back
				if(v.size()<100){
					int num;
					cin >> num;
					v.push_back(num);
					cout << "ok" << endl;
				}
					break;
			case 1: //pop
				if (!v.empty()){
					firstNum = v[0];
					v.erase(v.begin());
					cout << firstNum << endl;
				}
				else{
					cout << "error" << endl;
				}
				break;
			case 2:  //front
				if (!v.empty()){
					firstNum = v[0];
					cout << firstNum << endl;
				}
				else{
					cout << "error" << endl;
				}
				break;
			case 3:  //size
				cout << v.size() << endl;
				break;
			case 4:  //clear
				v.clear();
				cout << "ok" << endl;
				break;
			case 5:  //exit
				cout << "bye" << endl;
				break;
			case 6:
				if(v.size()<100){
					int num;
					cin >> num;
					v.insert(v.begin(),num);
					cout << "ok" << endl;
				}
				break;

			case 7:
				if (!v.empty()){
					lastNum = v[v.size()-1];
					v.pop_back();
					cout << lastNum << endl;

				}
				else{
					cout << "error" << endl;
				}
				break;

			case 8:
				if (!v.empty()){
					lastNum = v[v.size()-1];
					cout << lastNum << endl;
				}
				else{
					cout << "error" << endl;
				}
				break;





		}
	}
}