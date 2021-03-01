#include <iostream>
#include <vector>
#include <stdlib.h> 


using namespace std;

int n;


int getAge(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}


int main(){
	
	cin>>n;
	vector<int>g[n];
	int arr[n][n];
	for(int i = 0; i<n;i++){
		int a;cin>>a;
		int b;cin>>b;
		--a;--b;
		g[i].push_back(a);
		g[i].push_back(b);
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			arr[i][j] = getAge(g[i][0],g[j][1],g[j][0],g[i][1]);
		}
	}


	

}