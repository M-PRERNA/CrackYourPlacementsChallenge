#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    map<int, int> mp;
    for(int it = 0; it<n; it++){
         mp[arr[it]]++;
    }
    int f = floor(n/2);
    for(int i = 0; i<n; i++){
        if(mp[arr[i]] > f) return arr[i];
    }
    
    return -1;
}
