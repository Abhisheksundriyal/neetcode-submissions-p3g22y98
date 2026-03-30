class Solution {
public:
    bool isValid(vector<string>& V,int i,int j)
{
    int I=i+1,J=j+1,count=0,n=V.size();
    while(I<n && J<n && I>=0 && J>=0)
    {
        if(V[I][J]=='Q')
            return false;
        I++;
        J++;
    }
    I=i-1; J=j-1; count=0;
    while(I<n && J<n && I>=0 && J>=0)
    {
        if(V[I][J]=='Q')
            return false;
        I--;
        J--;
    }
    I=i-1; J=j+1;
    while(I<n && J<n && I>=0 && J>=0)
    {
        if(V[I][J]=='Q')
            return false;
        I--;
        J++;
    }
    I=i+1;
    J=j-1;
    while(I<n && J<n && I>=0 && J>=0)
    {
        if(V[I][J]=='Q')
            return false;
        I++;
        J--;
    }
    return true;
}

void recur(vector<vector<string>>& ans,vector<string>& curr,vector<bool>& col,int n,int idx) {
    if(idx==n)
    {
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(col[i]==false)
        {
            vector<bool> tempCol=col;
            tempCol[i]=true;
            vector<string> temp=curr;
            temp[idx][i]='Q';
            if(isValid(temp,idx,i))
                recur(ans,temp,tempCol,n,idx+1);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> curr(n);
    vector<bool> col(n,false);
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<n;i++)
            curr[i].push_back('.');
    }
    recur(ans,curr,col,n,0);
    return ans;
}
};
