class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size(),count=0,idx=0;
        vector<int> occ(26),ans;
        for(int i=0;i<n;i++)
            occ[s[i]-'a']=i;
        for(int i=0;i<n;i++)
        {
            count++;
            idx=max(idx,occ[s[i]-'a']);
            if(i==idx)
            {
                ans.push_back(count);
                count=0;
            }
        }
        return ans;
    }
};
