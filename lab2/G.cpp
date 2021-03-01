#include <iostream>

using namespace std;


int binarySearch(int arr[],int size, int key){
	int left = 0;
	int right = size;
	int mid = 0;
	bool isWorking =true;
	while(isWorking){
		mid = (left+right)/2;
		if(key<arr[mid]){
			right = mid - 1;
		}
		else if(key > arr[mid]){
			left = mid + 1;
		}
		else{
			return mid;
		}

		if(left > right){
			return -1;
		}
	}
	return -1;


}


int main(){

	int n,k; cin >> n; cin >>k;
	int arr[n];
	int size = n-1;
	for(int i = 0; i<n;i++){
		int inp; cin >> inp;
		arr[i] = inp;
	}
	for(int i = 0; i < k; i++){
		int inp; cin >> inp;
		int index = binarySearch(arr,size,inp);
		if(index >= 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;

}