#include <bits/stdc++.h>
#include <chrono>
#include <cassert>
#include <typeinfo>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int N = (int)1e5 + 5;

int vn = 1;
int to[N][26];
int cnt[N];
// vn = vertex number, intially root exist 
// to[v][c] is index of vertex that is next to v by letter c
// cnt[v] = number of strings passed vertex v of trie

void add(string &s) {
    int n = s.length();
    int v = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i] - 'a'; // [0,26)
        if (to[v][c] == 0) { // if no transition
            to[v][c] = ++vn;
        }
        v = to[v][c]; // do transition
        cnt[v]++;
    }
}

int find(string &t) {
    int m = t.length();
    int v = 1;
    for (int i= 0; i < m; i++) {
        char c = t[i] - 'a';
        if (to[v][c] == 0)
            return 0;
        v = to[v][c];
    }
    return cnt[v];
}

int a;
int b;
vector<int>v;




int main(){
    cin >> a; cin>>b;
    int cnt = 0;
    while(a != b){
        if(a < b){
            a *= 2;
            cnt++;
            v.push_back(a);

        }
        if(a > b){
            a--;
            cnt++;
            v.push_back(a);
        }
        
        
    }
    cout << cnt << endl;
    for(int i : v){
        cout << i << " ";
    }

    

}