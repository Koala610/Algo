#include <iostream>
const int N = 60000;
int n,m;
int arr[N][N];
int cur;
using namespace std;

void rev(int x, int y){
	int tmp = arr[x][y];
	arr[x][y] = arr[y][x];
	arr[y][x] = tmp;
}

void move(int x, int y){
	if(arr[x][y] == 1){
		cur = y;
	}
}

void count(){
	
}

int main(){
	cin>>n;
	cin>>m;
	

	for(int i = 0; i<m, i++){
		int k;int l;
		cin >> k >> l;--k;--l;
		arr[k][l] = 1;
	}

	count();


	
	
}