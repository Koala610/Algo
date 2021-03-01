#include <iostream>
#include <math.h>

using namespace std;

int curLen = 0;
void sift_down(int arr[], int pos){
	int max;
	int cur = pos-1;
	int l = 2 * cur + 1;
	int r = 2 * cur + 2;
	if(r < curLen && arr[r] > arr[l])max = r;
	else max = l;
	if(max < curLen && arr[max] >arr[cur]){
		swap(arr[max],arr[cur]);
		sift_down(arr,max+1);
		}
}
void printArr(int arr[]){
	for(int i = 0; i < curLen;i++){
		cout << arr[i] << " ";

	}
	cout << endl;
}
void printArr(int arr[], int len){
	for(int i = 0; i < len;i++){
		cout << arr[i] << " ";

	}
	cout << endl;
}
void build_heap(int arr[],int l) {
	int start = (l / 2) -1;
	for(int i = start;i >= 0; i--){
		sift_down(arr,i+1);
	}
}

void pyramid(int arr[]){
	build_heap(arr,curLen);
	while(curLen != 0){
		swap(arr[curLen-1],arr[0]);
		curLen--;
		sift_down(arr,1);
	}

}


int main(){
	int l; cin >> l;
	int arr[l];
	int count = 0;
	while(count < l){
		cin >> arr[count];
		count++;
		
		//sift_down(arr,count+1,count);
		
	}
	curLen = l;
	pyramid(arr);
	printArr(arr,l);
	
	



	

}
