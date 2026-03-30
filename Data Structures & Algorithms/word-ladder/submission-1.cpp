class Solution {
public:
    unordered_map<string,vector<string>> graph;
unordered_set<string> VIS;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    VIS.insert(beginWord);
    int count=0,ans=1;
    queue<string> que;
    que.push(beginWord);
    for(int i=0;i<wordList.size();i++)
    {
        // cout<<"wordList[i]: "<<wordList[i]<<"\n";
        if(wordList[i]==endWord)
            count++;
        string temp=wordList[i];
        for(int j=0;j<temp.size();j++)
        {
            temp[j]='*';
            graph[temp].push_back(wordList[i]);
            temp=wordList[i];
        }
    }
    // cout<<"count: "<<count<<"\n";
    if(count==0)
        return 0;
    // printmap();
    while(!que.empty()) {
        queue<string> newQue;
        while(!que.empty())
        {
            string node=que.front();
            if(node==endWord)
                return ans;
            que.pop();
            for(int i=0;i<node.size();i++)
            {
                string temp=node;
                temp[i]='*';
                // vector<string>& V=graph[temp];
                for(int j=0;j<graph[temp].size();j++)
                {
                    if(VIS.find(graph[temp][j])==VIS.end())
                    {
                        VIS.insert(graph[temp][j]);
                        newQue.push(graph[temp][j]);
                    }
                }
            }
        }
        ans++;
        que=newQue;
    }
    return 0;
}
};
