class TrieNode {
    public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.resize(26,nullptr);
        isEnd=false;
    }
    void insert(string s) {
        TrieNode* node=this;
        int n=s.size();
        for(int i=0;i<n;i++) {
            int idx=s[i]-'a';
            if(node->children[idx]==nullptr) 
                node->children[idx]=new TrieNode();
            node=node->children[idx];
        }
        node->isEnd=true;
    }
};
class Solution {
public:
    vector<int> dp;
    int solve(string& s,int index,int n,TrieNode* node) {
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
        TrieNode* root=node;
        int ans=1+solve(s,index+1,n,root);
        for(int i=index;i<n;i++) {
            int idx=s[i]-'a';
            if(node->children[idx]==nullptr)
                break;
            node=node->children[idx];
            if(node->isEnd) {
                ans=min(ans,solve(s,i+1,n,root));
            }
        }
        if(!node->isEnd) ans=min(ans,n-1-index+1);
        return dp[index]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* node=new TrieNode();
        dp.resize(s.size(),-1);
        for(int i=0;i<dictionary.size();i++) 
            node->insert(dictionary[i]);
        
        return solve(s,0,s.size(),node);
    }
};