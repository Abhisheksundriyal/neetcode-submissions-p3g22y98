class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int large=-1;
        for(int i=(int)arr.size()-1;i>=0;i--) {
            int temp=large;
            large=max(large,arr[i]);
            arr[i]=temp;
            
        }
        return arr;
    }
};