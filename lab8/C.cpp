#include <iostream>

using namespace std;
int cnt;
const int N = 100;
int arr[N][N];
int was[N];

int dfs(int v, int n){
	cnt++;
	was[v] = true;
	for(int i = 0;i<n;i++){
		if(arr[v][i] == 1 && !was[i]){
			dfs(i,n);
		}
	}
	return 0;

}

int main(){
	int n;cin>>n;
	int s;cin>>s;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	dfs(s-1,n);

	cout << cnt;

}