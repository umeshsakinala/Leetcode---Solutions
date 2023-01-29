class LFUCache {
private:
    struct Data {
        int value;
        int freq;
    };
    
    unordered_map<int, Data> store;
    multimap<int, int> frequencies;
    const int m_capacity;
    int currentSize = 0;

public:
    LFUCache(int capacity)
        :m_capacity(capacity)
    {
    }
    
    int get(int key) {
        if (store.find(key) == store.end()) {
            return -1;
        }

        markHit(key);
        return store[key].value;
    }
    
    void put(int key, int value) {
        if (0 == m_capacity) { 
            return;
        }

        if (store.find(key) == store.end()) {
            if (currentSize == m_capacity) {
                evict();
            } else {
                currentSize++;
            }

            store[key] = {value, 1};
            frequencies.insert({1, key});
        } else {
            store[key].value = value;
            markHit(key);
        }
    }

private:
    void evict() {
        while (true) {
            auto highest = frequencies.begin();
            int actualFreq = store[highest->second].freq;
            if (actualFreq == highest->first) {
                store.erase(highest->second);
                frequencies.erase(highest);
                break;
            }
            
            frequencies.erase(highest);
        }
    }

    void markHit(int key) {
        store[key].freq++;
        frequencies.insert({store[key].freq, key});
    }
};
