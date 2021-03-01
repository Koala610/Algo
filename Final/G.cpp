#include <iostream>
#include <set>

using namespace std;


int n;


int main(){
	cin>>n;
	set<string>st;
	for(int i = 0; i<n;i++){
		char c;cin>>c;
		string s;cin>>s;
		int ns = int(s.size());
		if(c == '+'){
			st.insert(s);
		}else if(c == '?'){
			int cnt = 0;
			for(string ss : st){

				if(ss.substr(0,ns) == s){
					cnt++;
				}
			}
			cout << cnt << endl;
		}else if(c == '-'){
			st.erase(s);
		}

	}
	

}