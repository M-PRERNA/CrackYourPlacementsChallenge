bool f(vector<int> &arr, int k, int i){
    if(arr[i] == k || k==0)  return 1;

    int pick=0; int notpick = 0;
    if(i>-1){
    if(arr[i]<k) 
        pick = f(arr, k-arr[i], i-1);
    notpick = f(arr, k, i-1);
    }
    
    if(pick || notpick) return 1;
    else return 0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(arr, k, n-1); // returns 1 if there is a subset equal to the sum and 0 if not
}
