#include <iostream>

using namespace std;
const int N = 1001;
int arr[N][N];
bool was[N][N];
int cnt = 0;
int m,n;
void kill(int vx,int vy){
	cnt++;
	arr[vx][vy] = 2;

	if(vx < m - 1 && arr[vx+1][vy] == 1)arr[vx+1][vy] = 2; 
	if(vx > 0 && arr[vx-1][vy] == 1)arr[vx-1][vy] = 2;
	if(vy > 0 && arr[vx][vy-1] == 1)arr[vx][vy-1] = 2;
	if(vy < n-1 && arr[vx][vy+1] == 1)arr[vx][vy+1] = 2;
	
	
	
	

}


void show_matrix(){
	cout << endl;
	for(int i = 0;i<m;i++){

		for(int j = 0;j<n;j++){
			cout << arr[i][j] << " ";
			if(j == n-1){
				cout << endl;
			}
		}
	}
	cout << endl;
}

bool check(){
	for(int i = 0;i<m;i++){

		for(int j = 0;j<n;j++){
			if(arr[i][j] == 1)return true;
		}
	}
	return false;

}


bool check_around(int vx, int vy){
	if(vx < m - 1 && arr[vx+1][vy] == 1)return true;
	if(vx > 0 && arr[vx-1][vy] == 1)return true;
	if(vy > 0 && arr[vx][vy-1] == 1)return true;
	if(vy < n-1 && arr[vx][vy+1] == 1)return true;
	return false;
}

int main(){
	cin>>m;
	cin>>n;
	
	for(int i = 0; i<m;i++){
		for(int j = 0; j<n;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i<m;i++){
		for(int j = 0; j<n;j++){
			if(arr[i][j] == 2 && check_around(i,j)){
				kill(i,j);
					
			}

				
		}
	}

	if(!check()){n
		cout << cnt;
	}else{
		cout << -1;
	}
	
	
	
}

