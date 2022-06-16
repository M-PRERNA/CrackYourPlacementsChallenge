
int  f(int i, int j, string &s, string &t){
//     base case
    if(i<0) return j+1;
    if(j<0) return i+1;
//     represent as indexes
    
//     do all stuffs
//     1 if equal : do nothing just move one step back
    int ins = 0, del=0, rep=0;
    if(s[i] == t[j]) return 0+f(i-1, j-1, s, t);
//     2 if not equal : del, replace, ins
    ins = 1 + f(i, j-1, s, t);
    del = 1 + f(i-1, j, s, t);
    rep = 1 + f(i-1, j-1, s, t);
    
//     return the minimum of all stuffs
    return min(ins, min(rep, del));
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    
    return f(n-1, m-1, str1, str2);
//     return the min no of ops required to convert str1[0 to n-1] to str 2[0 to m-1]
//     ops:
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
//     note that these ops are hypothetical as we do not have to return the changed or cnverted string
 
}
