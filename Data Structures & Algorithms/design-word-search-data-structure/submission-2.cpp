class WordDictionary {
public:
    vector<WordDictionary*> child;
    bool isEnd;
    WordDictionary() {
        for(int i=0;i<26;i++)
            child.push_back(nullptr);
        isEnd=false;
    }
    
    void addWord(string word) {
        WordDictionary* node=this;
        for(int i=0;i<word.size();i++)
        {
            if(node->child[word[i]-'a']==nullptr)
                node->child[word[i]-'a']=new WordDictionary();
            node=node->child[word[i]-'a'];
        }
        node->isEnd=true;
    }

    bool recur(WordDictionary* node,string& word,int idx) {

        if(!node)
            return false;
        if(idx==word.size())
            return node->isEnd;

        if(word[idx]=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(recur(node->child[i],word,idx+1))
                    return true;
            }
            return false;
        }
        return recur(node->child[word[idx]-'a'],word,idx+1);
    }
    
    bool search(string word) {
        WordDictionary* node=this;
        return recur(node,word,0);
    }
};
