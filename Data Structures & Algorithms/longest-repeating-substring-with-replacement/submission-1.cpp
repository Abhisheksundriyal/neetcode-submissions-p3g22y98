class Solution {
public:
    bool isPossible(vector<int>& cnt,int k) {
        int sum=0;
        for(int i=0;i<26;i++)
            sum+=cnt[i];
        for(int i=0;i<26;i++)
        {
            int temp=sum-cnt[i];
            if(temp<=k)
                return true;
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0);
        int n=s.size(),idx=0,ans=0;
        for(int i=0;i<n;i++)
        {
            cnt[s[i]-'A']++;
            while(!isPossible(cnt,k))
            {
                cnt[s[idx]-'A']--;
                idx++;
            }
            ans=max(ans,(i-idx+1));
        }
        return ans;
    }
};
