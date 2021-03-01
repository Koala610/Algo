#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int main(){
	string s;cin>>s;
	stack<char>st;
	for(char c : s){
		if(!st.empty() && c == st.top()){
			st.pop();
		}else{
			st.push(c);
		}
		
	}



	if(st.empty()){
		cout << "YES";
	}else{
		cout << "NO";
	}


}




