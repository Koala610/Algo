#include <iostream>

using namespace std;
const int N = 101;
int cnt;
bool was[N][N];
char arr[N][N];
void dfs(int vx,int vy,int m, int n){
	if(was[vx][vy])return;
	if(arr[vx][vy]== '.') return;
	if(vx < 0 || vx >= m || vy < 0 || vy >= n)return;
	was[vx][vy] = true;

	dfs(vx-1, vy,m,n);

	dfs(vx+1, vy,m,n);
	dfs(vx, vy-1,m,n);
	dfs(vx, vy+1,m,n);

	
}

int main(){
	int m;cin>>m;
	int n;cin>>n;
	
	
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	int res = 0;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(!was[i][j] && arr[i][j] == '#'){

				dfs(i,j,m,n);
				res++;
			}
		}
	}

	cout << res;

	



	

}
