#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{ 
//   time complexity is O(nlogn) space complexity is O(n)
    vector<int> temp;
    int count = 1;
    temp.push_back(arr[0]);
    for (int i = 1; i<n; i++){
        if(arr[i]>temp.back()) {
            temp.push_back(arr[i]);
            count++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
//             we subtract the temp.begin() because without it an iterator is returned which is of no use to us
//          returns the first element larger than a[i]
            temp[ind] = arr[i]; //replace it with arr[i]
        }
    }
    return count;
}
