#include <iostream>

using namespace std;

int main(){
	int n;cin>>n;
	int m;cin>>m;
	int arr[n][n];
	for(int i = 0; i<n;i++){
		for(int j = 0; j<n;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i<m;i++){
		int k;cin>>k;
		int l;cin>>l;
		int o;cin>>o;
		--k;--l;--o;
		if(arr[k][l] == 1 && arr[k][l] == arr[l][o] && arr[l][o] == arr[o][k]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
}