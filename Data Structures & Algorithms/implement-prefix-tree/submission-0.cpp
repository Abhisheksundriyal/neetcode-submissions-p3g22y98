class PrefixTree {
public:
    vector<PrefixTree*> CH;
    bool isEnd;

    PrefixTree() {
        for(char ch='a';ch<='z';ch++)
            CH.push_back(nullptr);
        isEnd=false;
    }
    
    void insert(string word) {
        PrefixTree* node = this;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(node->CH[ch-'a']==nullptr)
            {
                PrefixTree* newNode=new PrefixTree;
                node->CH[ch-'a']=newNode;
            }
            node=node->CH[ch-'a'];
            if(i==word.size()-1)
                node->isEnd=true;
        }
    }
    
    bool search(string word) {
       PrefixTree* node = this;
       for(int i=0;i<word.size();i++) {
            char ch=word[i];
            if(node->CH[ch-'a']==nullptr)
                return false;
            node=node->CH[ch-'a'];
       }
       return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
       for(int i=0;i<prefix.size();i++) {
            char ch=prefix[i];
            if(node->CH[ch-'a']==nullptr)
                return false;
            node=node->CH[ch-'a'];
       }
       return true;
    }
};
