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
        ListNode* start=head;
        ListNode* temp=new ListNode(-1);
        temp->next=head;
        ListNode* pre=temp;

        for (int i=1; i<left && start!=NULL; i++)
        {
            start=start->next;
            pre=pre->next;
        }

        ListNode* cur=start;
        ListNode* prev=NULL;
        ListNode* forw=NULL;

        for(int i=1; i<=right-left+1 && cur!=NULL; i++)
        {
            forw=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forw;
        }
        pre->next=prev;
        start->next=cur;
        return temp->next;
    }
};