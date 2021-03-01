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
	string s; cin >> s;
	int n = s.size();
   /* vector<int>v = prefix_function(s);
    int count = 0;
    for(int i = 0;i<n;i++){
        if(v[i]!=0){
            string subs = s.substr(0,i+1);
            if(2*v[i] == subs.size()){
                count++;
            }

        }
        cout << v[i] << endl;
    }*/
	int pw[n+1];
	int h[n+1];
	int p = 31;
	pw[0] = 1;
    pw[1] = p;
    h[0] = 0;

    //Создаем степени prime number
    for(int i = 2; i<= n ;i++){
    	pw[i] = pw[i-1]*p;
    }

    //Хэшируем 
    for(int i = 1; i<=n;i++){
    	h[i] = h[i-1] + (s[i-1] - 'a' + 1) * pw[i-1];
        //cout << h[i] << endl;
    }
   
    // a + b + c = s ; a+c=b+c => a=b => a + a + c = s  =>  
    for(int i =1; 2*i<n; i++){
        if(h[i] * pw[i] == h[2*i] - h[i]){
            count++;
        }
    }

    cout<<  count;


  


}