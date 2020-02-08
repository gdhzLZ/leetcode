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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last = head;
        ListNode* left = head;
        ListNode* right = head;
        for(int i = 0 ; i < n ; i++){
            right = right->next;
        }
        while(right != NULL){
            right = right -> next;
            last = left;
            left = left -> next;
        }
        if(left == head){
            head = head->next;
            return head;
        }
        else{

        
            last->next = left ->next;
            return head;
        }
    }
};