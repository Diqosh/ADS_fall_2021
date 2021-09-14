#include <iostream>

using namespace std;

int main(){
    int a;cin >> a;
    for(int i = 2;i*i < a  + 1;i++){
        if(a % i == 0){
            cout << "composite";
            return 0;
        }
    }
    cout << "prime";


    return 0;
}