#include <iostream>
#include <vector>
#include <queue>
const int N = (int)1e5 +5;
const int inf = (int)1e9;

using namespace std;

queue<int> q;
vector<int> g[N];
int d[N];
int start, end;
vector<int> a[N];

void bfs(int v) {
    for (int i = 0; i < 1000; i++) {
        d[i] = inf;
    }
    q.push(v);
    d[v] = 0;
    a[start].push_back(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
    for (int i = 0; i < (int)g[v].size(); i++) {
        int c = g[v][i];
        if (d[c] == inf) {
            q.push(c);
            a[start].push_back(c);
            d[c] = d[v] + 1;
      }
    }
  }
}