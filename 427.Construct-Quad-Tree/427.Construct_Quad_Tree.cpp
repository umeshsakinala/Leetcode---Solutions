/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        return build(grid, 0, 0, n);
    }
    
    Node* build(vector<vector<int>>& grid, int i, int j, int n) {
        if(n == 1) return new Node(grid[i][j], true);
        Node* res = new Node(0, false, 
                            build(grid, i, j, n / 2),
                            build(grid, i, j + n / 2, n / 2),
                            build(grid, i + n / 2, j, n / 2),
                            build(grid, i + n / 2, j + n / 2, n / 2));
        if(
            res->topLeft->isLeaf && 
            res->topRight->isLeaf && 
            res->bottomLeft->isLeaf && 
            res->bottomRight->isLeaf && 
            res->topLeft->val == res->topRight->val && 
            res->topLeft->val == res->bottomLeft->val && 
            res->topLeft->val == res->bottomRight->val
        ) {
            res->val = res->topLeft->val;
            res->isLeaf = true;
            delete res->topLeft;
            delete res->topRight;
            delete res->bottomLeft;
            delete res->bottomRight;
            res->topLeft = NULL;
            res->topRight = NULL;
            res->bottomLeft = NULL;
            res->bottomRight = NULL;
        }
        return res;
    }
};
