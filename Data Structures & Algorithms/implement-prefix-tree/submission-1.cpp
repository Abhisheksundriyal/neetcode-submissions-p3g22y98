
class PrefixTree {
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode () {
            for(int i=0;i<26;i++)
                children.push_back(nullptr);
            isEnd=false;
        }
    };
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i]-'a';
            if(node->children[idx]==nullptr)
            {
                TrieNode* temp = new TrieNode;
                node->children[idx]=temp;
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            int idx=word[i]-'a';
            if(node->children[idx]==nullptr)
                return false;
            node=node->children[idx];
        }
        return (node->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++)
        {
            int idx=prefix[i]-'a';
            if(node->children[idx]==nullptr)
                return false;
            node=node->children[idx];
        }
        return true;
    }
};
