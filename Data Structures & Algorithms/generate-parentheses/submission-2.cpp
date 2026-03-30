class Solution {
public:

    void recur(string curr,int open,int close,int n,vector<string>& ans) {
        if(curr.size()==(2*n))
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
            recur(curr+"(",open+1,close,n,ans);
        if(open>close)
            recur(curr+")",open,close+1,n,ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur("",0,0,n,ans);
        return ans;
    }
};
