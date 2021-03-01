#include <iostream>
#include <math.h>

using namespace std;
void sift_down(int arr[], int pos, int len){
	int max;
	int cur = pos - 1;
	int l = 2 * cur + 1;
	int r = 2 * cur + 2;
	if(r < len && arr[r] > arr[l])max = r;
	else max = l;
	if(max < len && arr[max] >arr[cur]){
		swap(arr[max],arr[cur]);
		sift_down(arr,max+1,len);
	}else{
		cout << pos  << " ";
	}
}
	
	/*int endVal = 0;
	while ((pos > 1 && arr[pos-1] < arr[2*pos-1]) || (pos > 1 && arr[pos-1] < arr[2*pos])) {
		if(arr[2*pos-1] >= arr[2*pos]){
			swap(arr[2*pos-1], arr[pos-1]);
			endVal =2*pos-1;
		}else{
			swap(arr[2*pos], arr[pos-1]);
			endVal =2*pos;
		}
		//int val = arr[2*pos-1]>arr[2*pos] ? arr[2*pos-1] : arr[2*pos];
		int index = arr[2*pos-1]>arr[2*pos] ? 2*pos-1 : 2*pos;
		cout << pos << endl;
		swap(arr[index],arr[pos-1]);
		pos  = index+1;
    }
    cout << pos << endl;*/

void extract_max(int arr[], int len){
	if(len == 1){
		return;
	}
	int tmp = arr[0];
	arr[0] = arr[len-1];
	--len;
	sift_down(arr,1,len);
	cout << tmp << endl;
	extract_max(arr,len);

}

int main(){
	int l; cin >> l;
	int arr[l];
	int count = 0;
	while(count < l){
		cin >> arr[count];
		count++;
	}
	int len = sizeof(arr)/ sizeof(arr[0]);
	extract_max(arr,len);


	

}