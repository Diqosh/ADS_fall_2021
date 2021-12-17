#include <iostream>
#include <vector>
#include <utility>
// n^2 + n
using namespace std;
const int INF = 1000000000;
const int N = (int)1e3;
const int MAXN =(int)1e9;
vector<pair<int,int>> g[N];  //g[i].first  g[i].second  i first vertex .first second vertex .second value between vertices


int main() {
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;y--;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }

    vector<int> d(n, MAXN);
    d[s] = 0;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if(!u[j] && (v == -1 || d[j] < d[v])) v = j;
        }
        if(d[v] == MAXN) break;
        u[v] = true;
        for (int j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first;
            int len  = g[v][j].second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
            }
        }
    }
    for (int i = 0; i < d.size(); ++i) {
        cout << i + 1 << ' '  << d[i]<< endl;
    }

}

