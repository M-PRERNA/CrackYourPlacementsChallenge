#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    map<int, int> mp;
    for(int it = 0; it<arr.size(); it++){
         mp[arr[it]]++;
    }
    vector<int> result;
    map<int, bool> visited;
    int f = floor(arr.size()/3);
    for(int i = 0; i<arr.size(); i++){
        if(mp[arr[i]] > f) {
            if(!visited[arr[i]]){
                result.push_back(arr[i]);
                visited[arr[i]] = true;
            }
    }
    }
   return result;
}
