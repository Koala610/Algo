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
	string s;cin>>s;
	vector<int>res = prefix_function(s);
	for(int i = 0;i< (int)res.size();i++){
		cout << res[i] << " ";
	}
	

  


}