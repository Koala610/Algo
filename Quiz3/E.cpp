#include <iostream>

#include <vector>
using namespace std;
vector<int> prefix_function(string s){
	int n = (int)s.size();
	vector<int>pi (n);
	pi[0] = 0;

	int i = 1;
	int j =0;
	while(i != n){
		if(s[i]==s[j]){
			pi[i] = j+1;
			i++;j++;
		}else if(j ==0){
			pi[i] = 0;
			i++;
		}else{
			j = pi[j-1];
		}
	}

	/*for(int i = 1;i<n;i++){
		int j = pi[i-j];
		while(j>0 && s[i] != s[j]){
			j = pi[j-1];
		}
		if(s[i] == s[j]) ++j;
		pi[i] = j;

	}*/
	return pi;




}

int main(){
	string s;cin >>s;
	vector<int>v = prefix_function(s);
	if(v[v.size()-1] != 0){
		int count = 0;
		for(int i = 0;i<v.size();i++){
			if(v[i]==v[v.size()-1]){
				count++;
			}
		}
		if(count >1){
			cout << s.substr(0,v[v.size()-1]);
		}else{
			cout << "Just a legend";
		}

	}else{
		cout << "Just a legend";
	}
	/*if(v[v.size()-1] != 0){
		string subs1 = s.substr(0,v[v.size()-1]);
		bool isFound = false;
		for(int i = v[v.size()-1]-1; i<=mid;i++){
			string subs2 = s.substr(i,v[v.size()-1]);
			if(subs1 == subs2){
				cout << subs1;
				isFound = true;
				break;
			}

		}
		if(!isFound){
			cout << "Just a legend";
		}

	}else{
		cout << "Just a legend";
	}*/
	

	
}
