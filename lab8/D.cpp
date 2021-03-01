#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 100001;
vector<int>g[N];
bool was[N];
int comp[N];

int dfs(int v, int comp_num){
	was[v] = true;
	comp[v] = comp_num;

	for(int u: g[v]){
		if(!was[u]){
			dfs(u,comp_num);
		}
	}
	return 0;

}

int main(){
	int n;cin>>n;
	int m; cin>>m;
	int comp_num = 1;

	for(int i=0;i<m;i++){
		int k;cin>>k;
		int l;cin>>l;
		--k;
		--l;
		g[k].push_back(l);
		g[l].push_back(k);

	}

	for(int i = 0;i<n;i++){
		if(!was[i]){
			dfs(i,comp_num);
			comp_num++;
		}
	}

	vector<int>res[comp_num-1];

	for(int i = 0;i<n;i++){
		res[comp[i]-1].push_back(i+1);
	}



	cout << comp_num-1 << endl;

	for(int i = 0;i<comp_num-1;i++){
		cout << res[i].size() << endl;
		for(int p : res[i]){
			cout << p << " ";
		}
		cout << endl;
	}


}