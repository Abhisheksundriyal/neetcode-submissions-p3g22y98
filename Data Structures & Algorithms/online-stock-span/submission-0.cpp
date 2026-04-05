class StockSpanner {
public:
    vector<int> nums;
    StockSpanner() {
        nums.resize(0);
    }
    
    int next(int price) {
        int count=0;
        nums.push_back(price);
        for(int i=(int)nums.size()-1;i>=0;i--) {
            if(nums[i]<=price) count++;
            else break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */