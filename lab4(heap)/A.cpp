#include <iostream>
#include <math.h>

using namespace std;
int shift_up(int arr[], int pos){
	while (pos > 1 && arr[int(pos/2)-1] < arr[pos-1]) {
        swap(arr[int(pos/2)-1], arr[pos-1]);
        /*int tmp = arr[int(pos/2)-1];
        arr[int(pos/2)-1] = arr[pos-1];
        arr[pos-1] = tmp;*/

        pos = int(pos/2);
    }
    return pos;
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
	int pos[n];
	while(count < n){
		int i; cin >> i;;
		int val; cin >> val;
		arr[i-1] += val; 
		++count;
		cout << shift_up(arr,i) << endl;
	}
	count = 0;
	while(count < l){
		cout << arr[count] << " ";
		++count;
	}



	

}