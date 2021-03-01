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

    return pi;




}


int period(string pat, string s){
    string s3 = s + pat;
    vector<int>res = prefix_function(s3);
    int ans = res[s3.size()-1] / pat.size();
    return ans;
}

int main(){
	string s; cin >> s;
	vector<int>res = prefix_function(s);
    int k = s.size() - res[s.size()-1];
    string sub = s.substr(0,k);
    cout << period(sub,s);
  


}