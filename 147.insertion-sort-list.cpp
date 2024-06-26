/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        sort(nodes.begin(), nodes.end(), [](ListNode* n1, ListNode* n2){return n1->val < n2->val;});
        
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = nullptr;
        return nodes[0];
    }
};
// @lc code=end

