class Solution {
public:
    unordered_map<string,vector<string>> mp;
    unordered_set<string> mySet;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        bool exist=false;
        queue<string> que;
        wordList.push_back(beginWord);
        mySet.insert(beginWord);
        que.push(beginWord);
        for(int i=0;i<wordList.size();i++)
        {
            string temp=wordList[i];
            for(int j=0;j<temp.size();j++)
            {
                char ch=temp[j];
                temp[j]='*';
                mp[temp].push_back(wordList[i]);
                temp[j]=ch;
            }
        }
        while(!que.empty() && !exist)
        {
            ans++;
            queue<string> newQue;
            while(!que.empty())
            {
                string temp=que.front();
                if(temp==endWord)
                {
                    exist=true;
                    break;
                }
                que.pop();
                mySet.insert(temp);
                for(int i=0;i<temp.size();i++)
                {
                    char ch=temp[i];
                    temp[i]='*';
                    for(int j=0;j<mp[temp].size();j++)
                    {
                        string temp2=mp[temp][j];
                        if(mySet.find(temp2)==mySet.end())
                            newQue.push(temp2);
                    }
                    temp[i]=ch;
                }
            }
            que=newQue;
        }
        if(exist)
            return ans;
        return 0;
    }
};
