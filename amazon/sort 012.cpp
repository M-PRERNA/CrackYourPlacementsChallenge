#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   map<int, int> mp;
   for(int it = 0; it<n; it++){
       mp[arr[it]]++;
   }
    int i, j;
//     cout<<mp[0];
//     cout<<mp[1];
//     cout<<mp[2];
//    for 0
    for(i = 0; i<mp[0]; i++) {arr[i] = 0;}
//     for 1
    for(j = i; j<i+mp[1]; j++) {arr[j] = 1;}
    
//     for 2
    for(int k = j; k<j+mp[2]; k++) {arr[k] = 2;}
}
