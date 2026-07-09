class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    maxSlidingWindow(nums, k) {
        const st = [];
    const ans = [];
    let l = 0;

    for (let i = 0; i < nums.length; i++) {
        st.push(nums[i]);
        st.sort((a, b) => a - b);

        while (st.length > k) {
            const idx = st.indexOf(nums[l]);
            st.splice(idx, 1);
            l++;
        }

        if (st.length === k) {
            ans.push(st[st.length - 1]); // largest element
        }
    }

    return ans;
    }
}
