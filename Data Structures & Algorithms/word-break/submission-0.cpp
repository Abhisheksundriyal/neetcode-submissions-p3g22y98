class Solution {
public:
    unordered_map<string,bool> myMap;

bool wordBreak(string s, vector<string>& wordDict) {
    
    if(s.length()==0)
        return true;
    for(int i=0;i<wordDict.size();i++)
    {
        if(wordDict[i].length()<=s.length())
        {
            int count=0,idx=0;
            for(int j=0;j<wordDict[i].length();j++)
            {
                if(s[idx]!=wordDict[i][j])
                {
                    count++;
                    break;
                }
                idx++;
            }
            if(count==0)
            {
                string newString;
                for(int j=idx;j<s.length();j++)
                    newString.push_back(s[j]);
                if(myMap.find(newString)==myMap.end())
                    myMap[newString]=wordBreak(newString,wordDict);
                if(myMap[newString])
                    return true;
            }
        }
    }


    return false;
}
};
