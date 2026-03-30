class PrefixTree {
public:
    
    vector<PrefixTree*> child;
    bool isEnd;
    PrefixTree() {
        isEnd=false;
        for(int i=0;i<26;i++)
            child.push_back(nullptr);
    }
    
    void insert(string word) {
        PrefixTree* node=this;
        for(int i=0;i<word.size();i++)
        {
            if(node->child[word[i]-'a']==nullptr)
                node->child[word[i]-'a']=new PrefixTree();
            node=node->child[word[i]-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        PrefixTree* node=this;
        for(int i=0;i<word.size();i++)
        {
            if(node->child[word[i]-'a']==nullptr)
                return false;
            node=node->child[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node=this;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->child[prefix[i]-'a']==nullptr)
                return false;
            node=node->child[prefix[i]-'a'];
        }
        return true;
    }
};