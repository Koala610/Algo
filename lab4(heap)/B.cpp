#include <iostream>
#include <math.h>

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
	}else{
		cout << pos + 1 << endl;
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
}

int main(){
	int l; cin >> l;
	int arr[l];
	int count = 0;
	while(count < l){
		cin >> arr[count];
		count++;
	}
	count = 0;
	int n; cin >> n;
	while(count < n){
		int i; cin >> i;;
		int val; cin >> val;
		arr[i-1] -= val; 
		++count;
		int len = sizeof(arr)/sizeof(arr[0]);
		sift_down(arr,i-1,len);
	}
	count = 0;
	while(count < l){
		cout << arr[count] << " ";
		++count;
	}



	

}
/*

#include <iostream>
#include <math.h>

using namespace std;
int sift_down(int arr[], int pos, int len){
	int cur = pos - 1;
	int max = 0;
	int l = 0;
	int r = 0;
	while(max < len && arr[max] > arr[cur]){
		l = 2 * cur + 1;
		r = 2 * cur + 2;
		if(r < len && arr[r] > arr[l])max = r;
		else max = l;
		swap(arr[max],arr[cur]);
		cur = max;
	}
	return cur+1;
	
	
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
    cout << pos << endl;
}

int main(){
	int l; cin >> l;
	int arr[l];
	int count = 0;
	while(count < l){
		cin >> arr[count];
		count++;
	}
	count = 0;
	int n; cin >> n;
	while(count < n){
		int i; cin >> i;;
		int val; cin >> val;
		arr[i-1] -= val; 
		++count;
		int len = sizeof(arr)/sizeof(arr[0]);
		cout << sift_down(arr,i,len) << endl;
	}
	count = 0;
	while(count < l){
		cout << arr[count] << " ";
		++count;
	}



	

}*/