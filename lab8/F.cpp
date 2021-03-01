#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 500;
vector<int>g[N];
int g1[N][N];
bool was[N];
int comp[N];
int ind[N];
bool isPossible = true;

int dfs(int v, int comp_num, int indicator){
	was[v] = true;
	comp[v] = comp_num;
	ind[v] = indicator;

	for(int u: g[v]){
		if(!was[u]){
			dfs(u,comp_num, indicator* (-1));
		}
	}
	return 0;

}

int main(){
	int n;cin>>n;
	int m; cin>>m;
	int comp_num = 0;

	for(int i = 0; i<m;i++){
		int k;cin>>k;
		int l;cin>>l;
		--k;--l;
		g[k].push_back(l);
		g[l].push_back(k);
		g1[k][l] = g1[l][k] = 1;
	}



	/*for(int i = 0 ; i<n;i++){
		for(int j = 0; j<n;j++){
			cout << g1[i][j] << " ";
			if(j == n-1){
				cout << endl;
			}
		}
	}*/

	for(int i = 0;i<n;i++){
		if(!was[i]){
			dfs(i,comp_num,1);
			comp_num++;
		}
	}

	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){
			if(ind[i] == ind[j] && g1[i][j] != 0){
				isPossible = false;
			}
		}
	}



	vector<int>res[comp_num];

	for(int i = 0;i<n;i++){
		res[comp[i]].push_back(i+1);
	}

	if(isPossible){
		cout << "YES" << endl;
		for(int i = 0; i<n;i++){
			if(ind[i] == 1){
				cout << i + 1 << endl;
			}
		}
	}else{
		cout << "NO";
	}

	

}
