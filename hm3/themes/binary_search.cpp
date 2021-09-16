#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll binary_search(vector<ll> &arr, ll item){
    ll left = 0, right = arr.size();
    while (left <= right){
        ll middle = (left + right)/2;

        if(arr[middle] == item) {
            return middle;
        }

        if(arr[middle] > item) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }

    }

    return -1;


}


int main(){
   vector<ll> a;

    for (int i = 1; i < 10; ++i) {
        a.push_back(i);
    }
    cout << binary_search(a, 9);
   return 0;
}
