#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int n;
int main(){
	cin>> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		int a;cin>>a;
		arr[i] = a;
	}

	int sum = 0;
	int max = -1;

	for(int i = 0 ;i<n;i++){
		int tmp = abs(arr[i]);
		arr[i] = tmp;
		if(max < tmp){
			max = tmp;
		}
		
	}
	int counts[max+1];
	for(int i = 0 ; i<max+1;i++){
		counts[i] = 0;
	}

	for(int i = 0 ; i<n;i++){
		counts[arr[i]]++;
	}

	int gen[sum+1];
	gen[0] = 0;
	for(int i = 1;i<sum+1;i++){
		gen[i] = -1;
	}

	for(int i = 1; i < max+1;i++){
		for(int j = 0; j < sum+1; j++){
			if(gen[j]>= 0){
				gen[j] = counts[i];
			}else if(j-i >= 0 && gen[j-i] > 0){
				gen[j] = gen[j-1] - 1;
			}
		}
	}

	int res = sum;


	for(int i = 0; i < (sum +1)/2 + 1;i++){
		if(gen[i]>= 0 && res > abs(sum - 2*i))res = abs(sum - 2 * i);
	}

	cout << res;


	

}