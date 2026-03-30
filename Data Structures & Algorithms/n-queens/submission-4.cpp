class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> col,posDiag,negDiag;
    void recur(int n,int i,vector<string>& curr) {
        if(i==n)
        {
            ans.push_back(curr);
            return;
        }
        string temp(n,'.');
        for(int j=0;j<n;j++)
        {
            if(col.find(j)==col.end() && 
                posDiag.find(i+j)==posDiag.end() &&
                negDiag.find(i-j)==negDiag.end())
            {
                temp[j]='Q';
                col.insert(j);
                posDiag.insert(i+j);
                negDiag.insert(i-j);
                curr.push_back(temp);
                recur(n,i+1,curr);
                temp[j]='.';
                col.erase(j);
                posDiag.erase(i+j);
                negDiag.erase(i-j);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr;
        recur(n,0,curr);
        return ans;
    }
};
