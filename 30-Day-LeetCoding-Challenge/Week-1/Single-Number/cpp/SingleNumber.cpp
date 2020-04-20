class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int v = 0;
        for (auto t: nums) v ^= t;
        return v;
    }
};