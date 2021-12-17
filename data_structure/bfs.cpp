#include <iostream>

#include <vector>
using namespace std;

vector<int> g[100];
queue<int>q;
int used[100];
int d[100];
int n, m, x, y;

void bfs(int i ){
    q.push(i);
    d[i]=0;
    used[i] = true;
    while (!q.empty()){
        int v = q.front();
        for (int i = 0; i < g[v].size(); ++i) {

            int u = g[v][i];
            if(used[u] == false){
                used[u] = true;
                q.push(u);

                d[u] = d[v] + 1;
            }
        }
        q.pop();
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;

        for (int j = 0; j < n; ++j) {
            used[j] = 0;
            if(j <= i){
                used[j] = 1;
            }
        }
        for (int j = 0; j < n; j++){
            if (used[j] == 0) {
                dfs(j);
                cnt++;
            }
        }

        cout << cnt << endl;


    }

    return 0;
}