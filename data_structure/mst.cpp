#include <iostream>
#include <vector>
#include <utility>
#include <set>
// n^2 + n
using namespace std;
const int INF = 1000000000;
const int N = (int) 1e3;
const int MAXN = (int) 1e9;
vector<pair<int, int>> g[N];  //g[i].first  g[i].second  i first vertex .first second vertex .second value between vertices


int main() {
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }

}