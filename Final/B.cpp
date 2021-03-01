#include <iostream>
#include <vector>

using namespace std;
int a;
int b;
vector<int>v;




int main(){
	cin >> a; cin>>b;
	int cnt = 0;
	while(a != b){
		if(a < b){
			a *= 2;
			cnt++;
			v.push_back(a);

		}
		if(a > b){
			a--;
			cnt++;
			v.push_back(a);
		}
		
		
	}
	cout << cnt << endl;
	for(int i : v){
		cout << i << " ";
	}

	

}