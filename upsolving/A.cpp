#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream> 
#include <string> 
#include <map>
using namespace std;

typedef long long ll;
map<int, int>mp;


std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); ++i)
    {   
        if(mp.count(arr[i]) != 0){ //if exist element arr[i] in map

            mp[arr[i]]++;
            if(mp[arr[i] > n]){
                continue;
            }else{
                ans.push_back(arr[i]);
            }1


        }else
            mp[arr[i]] = 1;
        
    }


  
  return ans;
}


int main() {
    
  string s;
  
  vector<int> v;
  while(cin >> s){
    v.push_back(stoi(s));
  }

  vector<int> vi = deleteNth(v, 2);
  for (int i = 0; i < vi.size(); ++i)
  {
      cout << vi[i] << ' ';
  };

  
}