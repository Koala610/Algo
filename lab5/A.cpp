#include <iostream>

using namespace std;

int main(){
	string s; cin >> s;
	string t; cin >>t;
	int n = s.size();
    int m = t.size();
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
    //Хэшируем функции в t
    int T = 0;
    for(int i = 0; i <m;i++){
    	T+= (t[i] - 'a' + 1) * pw[i];
        cout << T << endl;

    }
    

    for (int i = 0; i <= n - m; i++) {
        int hash = h[i + m] - h[i]; // hash[l,r) * p^i
        if (hash == T * pw[i]) {
            //cout << i << " ";
        }
    }

  


}