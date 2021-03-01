#include <iostream>
#include <math.h>

using namespace std;
void sift_up(int arr[], int pos){
	while (pos > 1 && arr[int(pos/2)-1] < arr[pos-1]) {
        swap(arr[int(pos/2)-1], arr[pos-1]);
        /*int tmp = arr[int(pos/2)-1];
        arr[int(pos/2)-1] = arr[pos-1];
        arr[pos-1] = tmp;*/

        pos = int(pos/2);
    }
}

int main(){
	int l; cin >> l;
	int arr[l];
	int count = 0;
	while(count < l){
		cin >> arr[count];
		sift_up(arr,count+1);
		count++;
	}

	count = 0;
	while(count < l){
		cout << arr[count] << " ";
		++count;
	}



	

}