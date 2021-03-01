#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	int needed;
	cin >> needed;
	for(int i = 0;i<n;i++){
		if(arr[i] == needed){
			cout << i+1 << " ";
		}
	}
}