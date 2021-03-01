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

int main(){
	int n, x; cin>>n; cin>>x;
	long long res = 0;
	int arr[n];
	curLen = n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	
	for (int i = 0; i < x; i++) {
		sift_down(arr,1);
		res += arr[0];
		arr[0]--;
		
		
	}
	cout << res;
}


	