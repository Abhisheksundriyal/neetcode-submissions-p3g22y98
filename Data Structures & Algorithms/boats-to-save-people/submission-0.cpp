class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0,curr=0,n=people.size();
        if(n==1) return 1;
        sort(people.begin(),people.end());
        // cout<<"people: ";
        // for(int i=0;i<n;i++) cout<<people[i]<<" ";
        // cout<<"\n";
        int l=0,r=n-1;
        while(l<=r) {
            if(l==r) {
                ans++;
                break;
            }
            if(people[l]+people[r]<=limit) {
                ans++;
                l++;
                r--;
            }
            else {
                ans++;
                r--;
            }
        }
        return ans;
    }
};