int mod = (int) 1e9  + 7;
int f(vector<int> &arr, int k, int i){
    if(i==0){
        if(k==0 && arr[0] == 0) return 2;
        if(k==0 || k == arr[0]) return 1;
        return 0;
        }
    
    int pick=0; int notpick; 
    if(i>-1){
    if(arr[i]<=k) 
        pick = f(arr, k-arr[i], i-1);
    notpick = f(arr, k, i-1);
    }
    return pick+notpick;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int s=0;
    for(auto &it: arr) s+=it;
    if(s-d < 0 || (s-d)%2 !=0) return 0;
    int k = (s-d)/2;
    return f(arr, k, n-1)%mod;
}


