#include <iostream>

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

void pyramid(int arr[]){
	build_heap(arr,curLen);
	while(curLen != 0){
		swap(arr[curLen-1],arr[0]);
		curLen--;
		sift_down(arr,1);
	}

}
void bubble_sort(int arr[], int len){
	int l = 0;
	int r = len-2;
	bool isWorking  = true;
	while(isWorking){
		isWorking = false;
		for(int i = l;i<r;i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				isWorking = true;
			}
		}
		r--;
	}

}

int main(){
	int n; cin >> n;
	int arr[n];
	for(int  i = 0; i<n;i++){
		cin >> arr[i];
	}
	curLen = 3;
	pyramid(arr);
	long long fMax = arr[2];
	long long sMax = arr[1];
	long long tMax = arr[0];
	for(int  i = 0; i<n;i++){
		long long res;
		if(i == 0 || i ==1){
			cout << -1 << endl;
		}else if(i == 2){
			res = fMax * sMax * tMax;
			cout << res << endl;
		}
		else{
			/*int tmp[i+1];
			for(int j = 0;j<i+1;j++){
				tmp[j] = arr[j];
				
			}*/
			if(arr[i]>fMax){
				tMax = sMax;
				sMax = fMax;
				fMax = arr[i];
			}else if(arr[i]> sMax){
				tMax = sMax;
				sMax = arr[i];
			}else if(arr[i] >tMax){
				tMax = arr[i];
			}


			
			res = fMax * sMax * tMax;
			cout << res << endl;

		}
	}
}