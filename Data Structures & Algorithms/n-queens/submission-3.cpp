class Solution {
public:
    vector<vector<string>> ans;
unordered_set<int> posDisg;
unordered_set<int> negDiag;
unordered_set<int> col;

void recur(int idx,int n,vector<string>& curr) {
    // cout<<"idx: "<<idx<<"\n";
    if(idx==n)
    {
        // cout<<"hello world\n";
        ans.push_back(curr);
        return;
    }
    string temp(n,'.');
    for(int i=0;i<n;i++)
    {
        
        if(col.find(i)==col.end() && posDisg.find(idx+i)==posDisg.end()
             && negDiag.find(idx-i)==negDiag.end())
        {
            col.insert(i);
            posDisg.insert(idx+i);
            negDiag.insert(idx-i);
            temp[i]='Q';
            // cout<<"temp: "<<temp<<"\n";
            curr.push_back(temp);

            recur(idx+1,n,curr);

            col.erase(i);
            posDisg.erase(idx+i);
            negDiag.erase(idx-i);
            temp[i]='.';
            curr.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> curr;
    recur(0,n,curr);
    return ans;
}
};
