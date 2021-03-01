#include <iostream>
#include <vector>

using namespace std;




int main(){
	string s;cin>>s;
	int q; cin >> q;
	int n = s.size();

	long long powers[n+1];
	int p =31;
	powers[1] = p;
	powers[0] = 1;
	long long hash[n+1];
	hash[0] = 0;
	for(int i = 2; i<=n;i++){
		powers[i] = powers[i-1]*p;
		//cout << powers[i] << endl;
	}

	for(int i = 1; i<=n;i++){
		hash[i] = hash[i-1] + (s[i-1] - 'a' +1)*powers[i-1];
		//cout << hash[i] << endl;
	}


	for(int i = 0; i<q;i++){
		int l;cin >>l;
		int r;cin>>r;
		int len = r - l +1;
		l--;

		string subs = s.substr(l,len);
		int m = subs.size();

		long long T = 0;
		for(int j = 0;j<m;j++){
			T+= (subs[j] - 'a' + 1)*powers[j];
			//cout << powers[i] << endl;
		}
		int count = 0;
		for(int k = 0; k <= n-m; k++){
			long long h = hash[k+m] - hash[k];
			//cout << h << ' ' << powers[k] << endl;
			if(h == T*powers[k]){
				count++;
			}
		}
	cout << count << endl;
		

	}

	
}
