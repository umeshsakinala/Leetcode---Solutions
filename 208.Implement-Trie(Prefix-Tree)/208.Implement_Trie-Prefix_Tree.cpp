class Node {
    public:
    Node* links[26];
    bool flag = false;
};
Node* root;
class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->links[word[i] - 'a'])
            {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->links[word[i]-'a'])
            {
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(!node->links[prefix[i]-'a'])
            {
                return false;
            }
            node=node->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
