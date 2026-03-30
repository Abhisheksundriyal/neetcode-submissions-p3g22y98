class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> myMap;
        int large=0,count=0;
        for(int i=0;i<tasks.size();i++)
        {
            myMap[tasks[i]]++;
            large=max(large,myMap[tasks[i]]);
        }
        for(char ch='A';ch<='Z';ch++)
        {
            if(myMap[ch]==large)
                count++;
        }
        return max((int)tasks.size(),(((large-1)*(n+1))+count));
    }
};
