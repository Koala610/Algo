#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n_container;
	string s_container;
	int minFirst;
	int minIndex;
	vector<pair<int,string> >v;
	vector<pair<int,string> >v1;
	while(cin){
		cin>> n_container;
		cin >> s_container;
		v.push_back(make_pair(n_container,s_container));

	}
	v.pop_back();

	while(v.size()> 0){
		minFirst = v[0].first;
		minIndex = 0;
		for(int i =0; i<v.size();i++){
			if(v[i].first < minFirst){
				minFirst = v[i].first;
				minIndex = i;
			}
		}
		v1.push_back(make_pair(v[minIndex].first,v[minIndex].second));
		v.erase(v.begin()+minIndex);
	}
	for(int i =0; i<v1.size();i++){
		cout << v1[i].first << " " << v1[i].second << endl;
	}
}