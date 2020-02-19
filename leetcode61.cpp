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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int length = 0;
        ListNode* p = head;
        while(p!=NULL){
            length++;
            p = p->next;
        }
        k = k%length;
        if(k==0) return head;
        p = head;
        while(k&&p!=NULL){
            p = p->next;
            k--;
        }
        ListNode* p1 = head;
        while(p->next !=NULL){
            p1=p1->next;
            p=p->next;
        }
        ListNode* head1 = p1->next;
        p1->next = NULL;
        p->next = head;
        return head1;
    }
};