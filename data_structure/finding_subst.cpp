#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll p = 31;
const int MX = 50001;
ll pows[MX];
int sz;

void find_pow() {
    pows[0] = 1;
    for (int i = 1; i < sz; ++i) {
        pows[i] = pows[i - 1] * p;
    }
}

long long Hash(string const &str) {

    long long hash_val = 0;


    for (int i = 0; i < str.size(); ++i) {
        hash_val += (str[i] - 'a' + 1) * pows[i];
    }
    return hash_val;
}

vector<ll> find_all_hashes(string const &s) {
    vector<ll> h(s.size());
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i) {
        h[i] = h[i-1] + (s[i] - 'a' + 1) * pows[i];
    }
    return h;
}


int main() {

    string s1, s2;
    cin >> s1 >> s2;
    sz = s1.size();
    int sz_2 = s2.size();


    find_pow();
    ll myhash = Hash(s2);
    vector<ll> v = find_all_hashes(s1);
    for (int i = 0; i <= sz - sz_2; ++i) {
        int j = i + sz_2 - 1;
        ll hash_at_i = v[j];
        if(i)
            hash_at_i -= v[i-1];
        if(hash_at_i == myhash * pows[i]){
            cout << i << ' ';
        }
    }

    return 0;
}

