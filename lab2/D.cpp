#include <iostream>

using namespace std;

int main(){

	int n,m;
	cin >> n >> m;
	int arr[n][m];
	for(int i = 0; i<n;i++){
		for(int j = 0; j<m;j++){
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	while(cnt<m){
		int min = 1000;
		int minIndex = 0;
		for(int i = 0; i<m){
			if(arr[i][cnt] < min){
				minIndex = i;
			} 
		}
		int max = -999;
		for(int i = 0; i<n){
			if(arr[cnt][i] > max){
				minIndex = i;
			} 
		}

		cnt++;
	}

}