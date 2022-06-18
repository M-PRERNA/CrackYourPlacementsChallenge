#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
//     kadanes
    long long s = 0;
    long long maxi = 0;
    for( int i=0; i< n; i++){
        if (s+arr[i] < 0) s = 0;
        else{
            s += arr[i]; 
            if (s>maxi) maxi = s;
        }
    }
    return maxi;
}
