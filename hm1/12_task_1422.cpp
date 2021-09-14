#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    int max = a >= b ? a : b;
    int min = a < b ? a : b;
    while(max % min != 0){
        c = max;
        max = min;
        min = c % max;
    }
    return min;

}

int lcm(int a, int b){

    return (a / gcd(a, b)) * b;
}

int main(){
    int a,b;cin >> a>> b;
    cout << lcm(a,b);

    return 0;
}
