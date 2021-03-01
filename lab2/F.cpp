#include <iostream>

using namespace std;

int main(){

	int n; cin >> n;
	int arr[n];
	int max = -1;
	int min = 99999;
	for(int i = 0; i<n;i++){
		int inp; cin >> inp;
		if(inp > max){
			max = inp;
		}
		if(inp < min){
			min = inp;
		}
		arr[i] = inp;
	}
	for(int i = 0; i<n;i++){
		if(arr[i] == max){
			arr[i] = min;
		}

	}
	for(int i = 0; i<n;i++){
		cout << arr[i] <<  ' ';
	}

	
}