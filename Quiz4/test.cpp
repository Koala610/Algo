#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ,m; cin >> n >> m; int a[n][m];int b[n][m];
    queue <int> q;
    for (int i = 0; i < n;  i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            b[i][j] = 0;
            if (a[i][j] == 2){
                q.push(i); q.push(j);
            }
        }
    }
    int x, y;
    while (!q.empty())
    {
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        if (x > 0 && a[x - 1][y] == 1){
            a[x - 1][y] = 2;
            q.push(x-1);q.push(y);
            b[x-1][y] = b[x][y] + 1;
        }
        if (x < n-1 && a[x + 1][y] == 1){
            a[x + 1][y] = 2;
            q.push(x+1);q.push(y);
            b[x+1][y] = b[x][y] + 1;
        } if (y > 0 && a[x][y - 1] == 1){
            a[x][y - 1] = 2;
            q.push(x);q.push(y - 1);
            b[x][y-1] = b[x][y] + 1;
        } if (y < m - 1 && a[x][y + 1] == 1){
            a[x][y + 1] = 2;
            q.push(x);q.push(y + 1);
            b[x][y+1] = b[x][y] + 1;
        }
    }
    for (int i = 0; i < n;  i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == 1) {
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    cout<<b[x][y]<<"\n";
    return 0;
}