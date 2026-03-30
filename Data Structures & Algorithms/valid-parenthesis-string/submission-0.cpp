class Solution {
public:

    bool recur(string& s,int n,int idx,int left) {
        if(idx==n)
        {
            if(left==0)
                return true;
            return false;
        }
        if(left<0)
            return false;
        if(s[idx]=='(')
            return recur(s,n,idx+1,left+1);
        if(s[idx]==')')
            return recur(s,n,idx+1,left-1);
        
        return (recur(s,n,idx+1,left+1) || recur(s,n,idx+1,left-1) || recur(s,n,idx+1,left));
    }

    bool checkValidString(string s) {
        int n=s.length();
        return recur(s,n,0,0);
    }
};
