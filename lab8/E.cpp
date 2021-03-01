#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 100001;
vector<int>g[N];
vector<int>g1[N];
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
	int comp_num = 0;

	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			int tmp;cin>>tmp;
			g1[i].push_back(tmp);
		}

	}

	int edges = 0;
	for(int i = 0;i<n;i++){
		int cnt = 0;
		for(int u : g1[i]){

			if(u == 1){
				g[i].push_back(cnt);
				g[cnt].push_back(i);
				edges++;
			}
			cnt++;

		}
	}





	for(int i = 0;i<n;i++){
		if(!was[i]){
			dfs(i,comp_num);
			comp_num++;
		}
	}
	edges = int(edges/2);
	

	if(edges- n + 1 == 0 && comp_num == 1){
		cout << "YES";
	}else{
		cout << "NO" << endl;
	}


}