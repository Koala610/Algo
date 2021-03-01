#include <iostream>

using namespace std;


int binarySearch(int arr[],int size, int key){
	int left = 0;
	int right = size;
	int mid = 0;
	bool isWorking =true;
	int cnt = 0;
	while(isWorking){
		cnt++;
		mid = (left+right)/2;
		if(key<arr[mid]){
			right = mid - 1;
		}
		else if(key > arr[mid]){
			left = mid + 1;
		}
		else{
			return cnt;
		}

		if(left > right){
			return -1;
		}
	}
	return -1;


}


int main(){

	int key; cin >> key;
	int cnt = 0;
	int m = 1;
	while(m < key){
	    m = m *2;
	    cnt += 1;
	}
	cout << cnt;
}