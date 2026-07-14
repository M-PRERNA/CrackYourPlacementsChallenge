class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;

        while(left<right){
            
            while(left<s.length() && !Character.isLetterOrDigit(s.charAt(left)) ){
                left++;
            }
            
            while(right>=0 && !Character.isLetterOrDigit(s.charAt(right))){
                right--;
            }

            if (left >= right) {
                break;
            }
            char a = Character.toLowerCase(s.charAt(left));
            char b = Character.toLowerCase(s.charAt(right));

            if(a != b){
                return false;
            }

            //move pointer
            left++;
            right--;
        }


        return true;

    }
}
