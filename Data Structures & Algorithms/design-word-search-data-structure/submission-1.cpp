class WordDictionary {
    struct trie{
        vector<trie*> children;
        bool isEnd;
        trie() {
            for(int i=0;i<26;i++)
                children.push_back(nullptr);
            isEnd=false;
        }
    };
    trie* root;
public:
    WordDictionary() {
        root = new trie;
    }
    
    void addWord(string word) {
        trie* node=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i]-'a';
            if(node->children[idx]==nullptr)
            {
                trie* temp = new trie;
                node->children[idx]=temp;
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }

    bool search2(string& word,int idx,trie* node) {
        if(node==nullptr)
            return false;
         if(idx==word.size())
            return (node->isEnd);
        if(word[idx]!='.')
        {
            node=node->children[word[idx]-'a'];
            return search2(word,idx+1,node);
        }
        for(int i=0;i<26;i++)
        {
            trie* temp=node->children[i];
            if(search2(word,idx+1,temp))
                return true;
        }
        return false;
    }
    
    bool search(string word) {
        return (search2(word,0,root));
    }
};
