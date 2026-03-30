class Solution {
public:

   bool recur(string s,int n,int idx,int leftMin,int leftMax) {
        if(idx==n)
        {
            if(leftMin==0 && (leftMax>=0))
                return true;
            return false;
        }
        
        if(s[idx]=='(')
        {
            leftMin++;
            leftMax++;
        }
        else if(s[idx]==')')
        {
            if(leftMin>0)
                leftMin--;
            leftMax--;
        }
        else
        {
            if(leftMin>0)
                leftMin--;
            leftMax++;
        }
        if(leftMax<0)
            return false;
        
        return recur(s,n,idx+1,leftMin,leftMax);
    }
    

    bool checkValidString(string s) {
        int n=s.length();
        return recur(s,n,0,0,0);
    }
};
