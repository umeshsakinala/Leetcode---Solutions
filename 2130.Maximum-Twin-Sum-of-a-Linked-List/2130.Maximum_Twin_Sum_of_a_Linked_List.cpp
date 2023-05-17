/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* p = head;
        int sum = 0;
        int prev_sum = 0;
        vector<int> arr;
        while(p)
        {
            arr.push_back(p->val);
            p = p->next;
        }
        for(int j=0; j<arr.size(); j++)
        {
            sum = arr[j] + arr[arr.size()-1-j];
            if(prev_sum > sum)
            {
                sum = prev_sum;
            }
            prev_sum = sum;
        }
        return sum;
    }
};
