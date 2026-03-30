class Solution {
public:
    unordered_map<char,vector<char>> mp;
    unordered_map<char,int> VIS;
    string ans;
    void dfs(char ch,bool& exist) {
        VIS[ch]=1;
        for(int i=0;i<mp[ch].size();i++)
        {
            if(VIS[mp[ch][i]]==0)
                dfs(mp[ch][i],exist);
            else if(VIS[mp[ch][i]]==1)
                exist=false;
        }
        VIS[ch]=2;
        ans.push_back(ch);
    }
    void isValid(string& s1,string& s2,int& ans) {
        int count=0;
        for(int i=0;i<min(s1.size(),s2.size());i++)
        {
            if(s1[i]!=s2[i])
            {
                count=1;
                break;
            }
        }
        if(count==0)
        {
            if(s2.size()<s1.size())
                ans=1;
            else if(s2.size()>s1.size())
                ans=2;
            else
                ans=3;
        }
        else
            ans=4;
    }
    string foreignDictionary(vector<string>& words) {
        bool exist=true;
        for(int i=0;i<words.size()-1;i++)
        {
            int ans;
            isValid(words[i],words[i+1],ans);
            if(ans==1)
                return "";
            else if(ans==4)
            {
                for(int j=0;j<min(words[i].size(),words[i+1].size());j++)
                {
                    if(words[i][j]!=words[i+1][j])
                    {
                        char ch1=words[i][j],ch2=words[i+1][j];
                        mp[ch1].push_back(ch2);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(!VIS[words[i][j]])
                    dfs(words[i][j],exist);
            }
        }
        if(!exist)
            return "";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
