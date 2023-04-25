class SmallestInfiniteSet {
public:    
    bool temp[1001];
    SmallestInfiniteSet() {
        for(int i=0; i<1001; i++)
        {
            temp[i] = 1;
        }
    }
    
    int popSmallest() {
        int i = 1;
        while(temp[i]!=1)
        {
            i++;
        }
        temp[i] = 0;
        return i;
    }
    
    void addBack(int num) {
        temp[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
