class Solution {
public:
    bool isCollision(stack<int>& myStac,int num) {
        if(myStac.empty()) return false;
        if(num<0 && myStac.top()>0) return true;
        return false;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStac;
        int n=asteroids.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            bool flag=1;
            while(isCollision(myStac,asteroids[i])) {
                int temp=myStac.top();
                myStac.pop();
                if(abs(temp)>abs(asteroids[i]))
                    asteroids[i]=temp;
                else if(abs(temp) == abs(asteroids[i])){
                    flag=0;
                    break;
                }
            }
            if(flag)
                myStac.push(asteroids[i]);
        }
        while(!myStac.empty()) {
            ans.push_back(myStac.top());
            myStac.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};