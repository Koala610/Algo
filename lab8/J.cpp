#include <iostream>
#include <vector>

using namespace std;
int cnt;
const int N = 100;
int arr[N][N];
int was[N];
vector<int>g[2];
void dfs(int v, int n){
	cnt++;
	was[v] = true;
	for(int i = 0;i<n;i++){
		if(arr[v][i] == 1 && !was[i]){
			if(u == g[1][0]-1 && i == g[0][1]-1){
				return;
			}else{
				dfs(i,n);
			}
			

		}
	}

}

int main(){
	int n;cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			arr[i][j] = 1;
		}
	}

	for(int i = 0;i<2;i++){
		int k;cin>>k;
		int l;cin>>l;
		g[i].push_back(k);
		g[i].push_back(l);
	}
	

}