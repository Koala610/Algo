#include <iostream>
#include <vector>

using namespace std;

int main(){
	string line = "";
	string commands[6] = {"push","pop","back","size","clear","exit"};
	vector<int> v;
	int lastNum;
	while(line!="exit"){
		cin >> line;
		int det = 0;
		for(int i = 0; i<6;i++){
			if(line == commands[i]){
				det = i;
			}
		}
		switch(det){
			case 0:   //push
				int num;
				cin >> num;
				v.push_back(num);
				cout << "ok" << endl;
				break;
			case 1: //pop
				if (!v.empty()){
					lastNum = v[v.size()-1];
					v.pop_back();
					cout << lastNum << endl;
				}
				else{
					cout << "error" << endl;
				}
				break;
			case 2:  //back
				if (!v.empty()){
					lastNum = v[v.size()-1];
					cout << lastNum << endl;
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


		}
	}
}