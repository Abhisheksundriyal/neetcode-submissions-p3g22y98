class Solution {
    max(a,b) {
        if(a>b) return a;
        return b;
    }
    maxProfit(prices) {
        const n=prices.length;
        let ans=0;
        const arr=[];
        arr.length=n;
        arr[n-1]=prices[n-1];
        for(let i=n-2;i>=0;i--) {
            arr[i]=this.max(arr[i+1],prices[i]);
        }
        console.log(arr);
        for(let i=0;i<n-1;i++) {
            if(arr[i+1]>prices[i]) {
                let profit=arr[i+1]-prices[i];
                if(profit>ans) ans=profit;
            }
        }
        return ans;
    }
}
