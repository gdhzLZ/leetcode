/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* end =  head;
        do{
            if(first != NULL)
                first = first->next;
            if(end != NULL)
                end = end->next;
            if(end != NULL)
                end = end->next;
        }while(first != end && end != NULL && first != NULL);
        if(end == NULL || first == NULL) return NULL;
        end = head;
        while(end != first)
            end = end->next,first = first->next;
        return first;
            
    }
};