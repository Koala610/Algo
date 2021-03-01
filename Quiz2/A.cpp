#include <iostream>

using namespace std;
void sift_down(int arr[], int pos, int len){
	int max;
	int l = 2 * pos + 1;
	int r = 2 * pos + 2;
	if(r < len && arr[r] > arr[l])max = r;
	else max = l;
	if(max < len && arr[max] >arr[pos]){
		swap(arr[max],arr[pos]);
		sift_down(arr,max,len);
	}
}

int shift_up(int arr[], int pos){
    while (pos > 1 && arr[int(pos/2)-1] < arr[pos-1]) {
        swap(arr[int(pos/2)-1], arr[pos-1]);
        /*int tmp = arr[int(pos/2)-1];
        arr[int(pos/2)-1] = arr[pos-1];
        arr[pos-1] = tmp;*/

        pos = int(pos/2);
    }
}
int main(){
	int n, x; cin>>n; cin>>x;
	long long res = 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		shift_up(arr,i+1);

	}
	
	for (int i = 0; i < x; i++) {
		sift_down(arr,0,n);
		res += arr[0];
		arr[0]--;
		
		
	}
	cout << res;
}


	