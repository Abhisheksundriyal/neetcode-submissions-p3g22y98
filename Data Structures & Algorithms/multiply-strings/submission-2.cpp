class Solution {
public:
    vector<int> addVect(vector<int>& A,vector<int>& B) {
    int n=A.size(),m=B.size();
    if(n==0 && m==0)
        return {0};
    if(n==0)
        return B;
    if(m==0)
        return A;

    vector<int> ans;
    int idx=0,carry=0;;
    for(int i=0;i<n;i++)
    {
        int num=0,temp=0;
        if(idx<m)
        {
            num=B[idx];
            idx++;
        }
        temp=num+A[i]+carry;
        ans.push_back(temp%10);
        temp=temp/10;
        carry=temp;
    }
    for(int i=idx;i<m;i++)
    {
        int temp=carry+B[i];
        ans.push_back(temp%10);
        temp=temp/10;
        carry=temp;
    }
    if(carry!=0)
        ans.push_back(carry);
    return ans;
}

string multiply(string num1, string num2) {
    int n=num1.size(),m=num2.size(),x=0;
    vector<int> ans;
    string A;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> V(x,0);
        x++;
        int a=num1[i]-'0',carry=0;
        for(int j=m-1;j>=0;j--)
        {
            int b=num2[j]-'0',temp=(a*b)+carry;
            // cout<<"a: "<<a<<" b: "<<b<<" temp: "<<temp<<"\n";
            V.push_back(temp%10);
            temp=temp/10;
            carry=temp;
        }
        if(carry!=0)
            V.push_back(carry);
        // cout<<"V: ";
        // for(int j=0;j<V.size();j++)
        //     cout<<V[j]<<" ";
        // cout<<"\n";
        ans=addVect(ans,V);
        // cout<<"ans: ";
        // for(int i=0;i<ans.size();i++)
        //     cout<<ans[i]<<" ";
        // cout<<"\n";
    }
    while(ans.size()>1 && ans[ans.size()-1]==0)
        ans.pop_back();
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        A+=(to_string(ans[i]));
    return A;
}
};
