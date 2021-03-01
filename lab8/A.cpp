#include <iostream>

using namespace std;

int main(){
	int n;cin>>n;
	int arr[n][n];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int color[n];
	for(int i = 0; i<n; i++){
		cin>>color[i];
	}
	int cnt = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(color[i]!=color[j] && arr[i][j] == 1){
				cnt++;
			}
		}
	}
	cout << (int)cnt / 2;

}