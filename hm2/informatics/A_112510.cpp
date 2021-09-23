#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
pair<string, int> item;

bool my_funct(pair<string, int> s1, pair<string, int> s2){
    if(s1.second == s2.second){
        return s1.first < s1.first;
    }else{
        return s1.second < s2.second;
    }
}

bool is_in_vector(vector<pair<string, int>> &v, string &item) {
    for (auto &i: v) { if (i.first == item) return true; }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<pair<string, int>> v;
    string s;
    while (cin >> s) {
        for (auto &i: v) {
            if (i.first == s) {
                i.second += 1;
                break;
            }
        }
        if(!is_in_vector(v, s)) v.push_back(make_pair(s, 1));
    }
    sort(v.begin(), v.end());
    ofstream f;
    f.open("output.txt");
    for (auto &i: v) {
        f <<  i.first + " " + to_string(i.second) + '\n';
    }

    return 0;
}

