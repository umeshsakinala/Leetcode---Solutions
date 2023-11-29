class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> count = n;
        return count.count();
    }
};