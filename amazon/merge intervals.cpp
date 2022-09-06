
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // stack<vector<int>> s;
        // for(int i = 0; i<=intervals.size(); i++){
        //     s.push(intervals[i]);
        // }
        // // cout<<s.top();
        // vector<vector<int>> result;
        // while(!s.empty()){
        //     vector<int> curr = s.top();
        //     s.pop();
        //     vector<int> t = s.top();
        //     if(curr[0]>t[0] && curr[0]<t[1]){
        //         s.pop();
        //         cout<<curr[0];
        //         s.push( [t[0],  max( t[1], curr[1] )]);
        //     }
        //     else{
        //         result.push_back(curr);
        //         s.pop();
        //     }
        // }
        // return result;
        
        vector<vector<int>> result;
        
        if(intervals.size() == 0){
            return result;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        
        for(auto it : intervals){
            if(it[0]<=temp[1]){
                temp[1] = max(temp[1], it[1]);
            }
            else{
                result.push_back(temp);
                temp = it;
            }
        }
        
        result.push_back(temp);
        return result;
    }
};
