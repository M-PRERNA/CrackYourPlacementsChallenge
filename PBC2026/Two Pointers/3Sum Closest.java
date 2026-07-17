class Solution {
    public int threeSumClosest(int[] nums, int target) {
        
        int closestSum = Integer.MAX_VALUE;
        int closestAbsDiff = Integer.MAX_VALUE;
        int n = nums.length;
        Arrays.sort(nums);

        for(int i = 0; i<n; i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                
                int sum = nums[i] + nums[left] + nums[right];
                // System.out.println("target: "+ target + "sum: "+ sum + " closest sum: "+ closestSum+ " absolute diff:" + Math.abs(target-sum));
                //update closest value
                if(Math.abs(target - sum) < closestAbsDiff){
                    
                    closestAbsDiff = Math.abs(target - sum);
                    closestSum = sum;
                    // System.out.println("target: "+ target + "sum: "+ sum +" closest sum: "+ closestSum+  " absolute diff:" + Math.abs(target-sum));
                }

                if(sum == target){

                    return sum;

                }
                
                if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            
        }
        return closestSum;
    }

}
