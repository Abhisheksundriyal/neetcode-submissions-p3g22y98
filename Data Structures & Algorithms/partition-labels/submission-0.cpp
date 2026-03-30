class Solution {
public:

    bool check(vector<int>& total,vector<int>& cnt) {
        for(int i=0;i<26;i++) {
            if(cnt[i]>0 && cnt[i]!=total[i])
                return false;
        }
        return true;
    }

    vector<int> partitionLabels(string s) {
        vector<int> total(26,0),cnt(26,0);
        int n=s.length(),idx=0,count=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
            total[s[i]-'a']++;
        for(int i=0;i<n;i++)
        {
            if(check(total,cnt) && count>0)
            {
                ans.push_back(count);
                for(int j=0;j<26;j++)
                    cnt[j]=0;
                count=0;
            }
            cnt[s[i]-'a']++;
            count++;
        }
        if(count>0)
            ans.push_back(count);
        return ans;
    }
};
