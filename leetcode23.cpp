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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        else return mergeLists(lists,0,lists.size()-1);
    }
    ListNode* mergeLists(vector<ListNode*> lists,int start,int end){
        if(start == end)
            return lists[start];
        else if(end-start == 1){
            return mergeBinary(lists,lists[start],lists[end]);
        }
        else{
            int mid = (start+end)/2;
            ListNode* l1 = mergeLists(lists,start,mid);
            ListNode* l2 = mergeLists(lists,mid+1,end);
            return mergeBinary(lists,l1,l2);
        }
    }
    ListNode* mergeBinary(vector<ListNode*> lists,ListNode* start,ListNode* end){
        ListNode* p1 = start;
        ListNode* p2 = end;
        ListNode* ans = new ListNode(-1);
        ListNode* p3 = ans;
        
        while(p1 != NULL && p2 != NULL){
            if(p1->val > p2->val){
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
            else{
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
        }
        while(p1 != NULL){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next; 
        }
        while(p2 != NULL){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next; 
        }
        p3 = ans;
        ans = ans->next;
        delete p3;
        return ans;
    }

};