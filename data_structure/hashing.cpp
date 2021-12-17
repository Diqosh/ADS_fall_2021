
#include <iostream>

using namespace std;


long long polynomialRollingHash(string const &str) {

    int p = 31;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;


    for (char i : str) {
        hash_val = (hash_val+ (i - 'a' + 1) * power_of_p)% m;
        power_of_p = (power_of_p * p) % m;
    }


    return (hash_val % m + m) % m;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;
    cin >> s;
    cout << polynomialRollingHash(s);
    return 0;
}