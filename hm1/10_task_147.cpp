#include <iostream>

using namespace std;

int main(){
    int a,b,c;cin >> a >> b;
    int max = a >= b ? a : b;
    int min = a < b ? a : b;

    while(max % min != 0){
        c = max;
        max = min;
        min = c % max;
    }
    cout << min;

    return 0;
}