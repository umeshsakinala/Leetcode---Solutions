/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function(root) {
    let modes=[];
    let currentCount = 0;
    let maxCount = 0;
    let currentVal = null;

    const inOrderTraversal = (node) => {
        if(node === null) {
            return ;
        }

        inOrderTraversal(node.left)
        if(node.val === currentVal) {
            currentCount++;
        }
        else {
            currentVal = node.val;
            currentCount = 1;
        }

        if(currentCount > maxCount) {
            maxCount = currentCount;
            modes = [currentVal]
        }
        else if(currentCount === maxCount) {
            modes.push(currentVal)
        }
        
        inOrderTraversal(node.right)
    }
    inOrderTraversal(root)
    return modes;
};