#include <iostream>

using namespace std;

int main(){
	int n;cin>>n;
	int arr[n][n];
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int cur,x,y,z; 
	int min = 3001;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i!=j){
				for(int k = 0; k<n;++k){
					if(k!=i && k!= j && (cur=arr[i][j]+arr[j][k]+arr[k][i]) < min){
						min = cur; x = i; y = j; z = k;

					}
				}

			}
			
		}
	}
	cout << x +1 << " " << y+1 << " " << z+1;


}