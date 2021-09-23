#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
pair<string, int> item;

bool my_funct(pair<string, int> &p1, pair<string, int> &p2){
    if(p1.second!=p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

bool is_in_vector(vector<pair<string, int>> &v, string &item) {
    for (auto &i: v) { if (i.first == item) return true; }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<pair<string, int>> v;
    string a;
    while (cin >> a) {
        transform(a.begin(), a.end(), a.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        string s = "";
        for(char &i : a){
            if (97 <= i && i <= 122){
                s += i;
            }
        }
        for (auto &i: v) {
            if (i.first == s) {
                i.second += 1;
                break;
            }
        }
        if(!is_in_vector(v, s)) v.push_back(make_pair(s, 1));
    }
    sort(v.begin(), v.end(), my_funct);
    ofstream f;
    f.open("output.txt");
    for (auto &i: v) {
        f  <<  i.first + " " + to_string(i.second) + '\n';
    }

    return 0;
}
