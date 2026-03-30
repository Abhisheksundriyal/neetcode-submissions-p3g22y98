class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    unordered_map<string,vector<string>> myMap;
    queue<string> myQue;
    unordered_set<string> mySet;
    myQue.push(beginWord);
    mySet.insert(beginWord);
    int count=0,n=beginWord.size(),ans=1;
    for(int i=0;i<wordList.size();i++)
    {
        if(wordList[i]==endWord)
        {
            count=1;
            break;
        }
    }
    if(endWord.length()==0 || count==0)
        return 0;

    for(int i=0;i<wordList.size();i++)
    {
        string temp=wordList[i];
        for(int j=0;j<n;j++)
        {
            temp[j]='*';
            myMap[temp].push_back(wordList[i]);
            temp=wordList[i];
        }
    }

    // for(auto itr=myMap.begin();itr!=myMap.end();++itr)
    // {
    //     pair<string,vector<string>> temp=(*itr);
    //     cout<<temp.first<<" : ";
    //     for(int i=0;i<temp.second.size();i++)
    //         cout<<temp.second[i]<<" ";
    //     cout<<"\n";
    // }

    while(!myQue.empty())
    {
        queue<string> newQue;
        while(!myQue.empty())
        {
            string t=myQue.front(),temp=t;
            if(t==endWord)
                return ans;
            myQue.pop();
            for(int i=0;i<n;i++)
            {
                temp[i]='*';
                vector<string> V=myMap[temp];
                for(int j=0;j<V.size();j++)
                {
                    string next=V[j];
                    if(mySet.find(V[j])==mySet.end())
                    {
                        mySet.insert(V[j]);
                        newQue.push(V[j]);
                    }
                }
                temp=t;
            }
        }
        myQue=newQue;
        ans++;
    }
    return 0;
}
};
