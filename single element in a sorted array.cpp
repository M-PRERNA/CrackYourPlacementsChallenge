int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int i = 0;
    while(i<n){
        if(arr[i] == arr[i+1]) i = i+2;
        else {
           break;
        }
        
    }
    return arr[i];   
}
