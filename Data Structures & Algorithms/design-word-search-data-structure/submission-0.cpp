class WordDictionary {
public:

    vector<WordDictionary*> V;
    bool isEnd;

    WordDictionary() {
        for(int i=0;i<26;i++)
            V.push_back(nullptr);
        isEnd=false;
    }
    
    void addWord(string word) {
        WordDictionary* node=this;
        for(int i=0;i<word.size();i++)
        {
           if(node->V[word[i]-'a']==nullptr)
           {
                WordDictionary* newNode=new WordDictionary();
                node->V[word[i]-'a']=newNode;
           }
           node=node->V[word[i]-'a'];
        }
        node->isEnd=true;
    }
    
    bool recur(WordDictionary* node,string& word,int idx) {

        if (!node) return false;

    if (idx == word.size()) {
        return node->isEnd;
    }

    if (word[idx] == '.') {
        for (int i = 0; i < 26; ++i) {
            if (recur(node->V[i], word, idx + 1)) {
                return true;
            }
        }
    } else {
        int ch = word[idx] - 'a';
        return recur(node->V[ch], word, idx + 1);
    }

    return false;
    }

    bool search(string word) {
        WordDictionary* node=this;
        return recur(node,word,0);
    }
};