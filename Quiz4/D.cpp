#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 100000;
vector<int>g[N];
bool was[N];
int comp[N];
vector<int>order;

void dfs(int v, int comp_num){
	was[v] = true;
	comp[v] = comp_num;

	for(int u: g[v]){
		if(!was[u]){
			dfs(u,comp_num);
		}
	}
	order.push_back(v);

}




void topological_sort(int n, int comp_num) {
	for (int i=0; i<n; ++i)
		was[i] = false;
	order.clear();
	for (int i=0; i<n; ++i)
		if (!was[i])
			dfs (i,comp_num);
	reverse (order.begin(), order.end());
}



int main(){
	int n;cin>>n;
	int m; cin>>m;
	int comp_num = 0;
	for(int i=0;i<m;i++){
		int k;cin>>k;
		int l;cin>>l;
		--k;
		--l;
		g[k].push_back(l);

	}

	for(int i = 0;i<n;i++){
		if(!was[i]){
			dfs(i,comp_num);
			comp_num++;
		}
	}
		
	topological_sort(n,comp_num);

	for(int u : order){
		cout << u  + 1 << " ";
	}


	


}