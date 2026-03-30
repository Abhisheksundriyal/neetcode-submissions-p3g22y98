class Solution {
public:

    vector<string> solve(vector<string>& A,vector<string>& B) {
        vector<string> ans;
        if(B.size()==0)
            return A;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                string temp=A[i]+B[j];
                ans.push_back(temp);
            }
                
        }
        return ans;
    }

    vector<string> recur(string& digits,int n,int idx,unordered_map<char,string>& myMap) {
        vector<string> A,B,ans;
        if(idx==n)
            return ans;
        int m=myMap[digits[idx]].size();
        for(int i=0;i<m;i++)
        {
            string temp;
            temp.push_back(myMap[digits[idx]][i]);
            A.push_back(temp);
        }
        B=recur(digits,n,idx+1,myMap);
        ans=solve(A,B);
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> myMap;
        myMap['2']="abc";
        myMap['3']="def";
        myMap['4']="ghi";
        myMap['5']="jkl";
        myMap['6']="mno";
        myMap['7']="pqrs";
        myMap['8']="tuv";
        myMap['9']="wxyz";
        int n=digits.size();
        // vector<string> ans;
        return recur(digits,n,0,myMap);
    }
};
