class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=1;
        for(char ch='A';ch<='Z';ch++) {
            int K=k,idx=0;
            for(int i=0;i<s.length();i++) {
                if(s[i]!=ch)
                {
                    if(K>0)
                        K--;
                    else
                    {
                        while(s[idx]==ch)
                            idx++;
                        idx++;
                    }
                    
                }
                ans=max(ans,i-idx+1);
            }
        }
        return ans;
    }
};
