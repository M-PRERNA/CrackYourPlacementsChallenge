class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> triplets = new ArrayList<>();
        Arrays.sort(nums);

        for(int i = 0; i< n-2; i++){
            if(nums[i]>0) break; //optimisation addition
            //if a no starts with positive, 
            //it can never have a triplet with nos on its right that add up to zero
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            
            while(left<right){
                int leftValue = nums[left];
                int rightValue = nums[right];
                int sum = leftValue+rightValue;

                if(sum == target){
                    List<Integer> triplet = new ArrayList<>();
                    // triplet.add(nums[i]);
                    // triplet.add(leftValue);
                    // triplet.add(rightValue);

                    triplets.add(Arrays.asList(nums[i], leftValue, rightValue));
                    
                    //skipping duplicates
                    while(left<right && nums[left] == leftValue) left++;
                    while(left <right && nums[right] == rightValue) right--;

                }

                else if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
            }
        }

        return triplets;
    }
}
