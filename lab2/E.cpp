#include <iostream>
#include <set>

using namespace std;

int main(){

	int n; cin >> n;
	set<int>members;
	for(int i = 0; i<n;i++){
		int inp; cin >> inp;
		members.insert(inp);
	}

	members.erase(*members.rbegin());
	cout << *members.rbegin();

}