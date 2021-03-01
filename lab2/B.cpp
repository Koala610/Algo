#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	int max = -1;
	int ind = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] > max){
			max = arr[i];
			ind = i+1;
		}
	}
	cout << ind;
}