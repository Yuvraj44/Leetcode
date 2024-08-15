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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=new ListNode(0);
        temp->next=head;

        ListNode* start=head;
        ListNode* pre=temp;
        for(int i=1; i<left && start!=NULL; i++)
        {
            start=start->next;
            pre=pre->next;
        }
        
        ListNode* cur=start;
        ListNode* prev=pre;
        ListNode* forward=NULL;
        for(int i=1; i<=right-left+1 && cur!=NULL ; i++)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
        }
        
        pre->next=prev;
        start->next=cur;

        return temp->next;

    }
};