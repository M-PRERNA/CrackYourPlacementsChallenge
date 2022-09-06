void calc(int ind, int sum, vector<int>&num, vector<int> &result){
    if(ind == -1){
        result.push_back(sum);
        return;
    }
//     take
    int reduce = ind - 1;
    calc(reduce, sum+num[ind], num, result);
//     not take
    calc(reduce, sum, num, result);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> result;
    calc(num.size()-1, 0, num, result);
    
    sort(result.begin(), result.end());
    return result;
}
