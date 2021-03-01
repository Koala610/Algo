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

void build_heap(int arr[],int l) {
	int start = (l / 2) -1;
	for(int i = start;i >= 0; i--){
		sift_down(arr,i+1);
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
	build_heap(arr,l);
	

	count = 0;
	while(count < l){
		cout << arr[count] << " ";
		++count;
	}



	

}
