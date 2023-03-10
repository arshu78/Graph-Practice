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
    vector<int> tp;
    long long int size; 
    Solution(ListNode* head) {
        ListNode* temp=head;
        size=0;
        while(temp!=NULL)
        {
            tp.push_back(temp->val);
            temp=temp->next;
            size++;
        }
    }
    
    int getRandom() {
        long long int index=rand() % size;
        return tp[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */