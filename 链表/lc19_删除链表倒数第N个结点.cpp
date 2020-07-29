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
    //双指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        //增加头结点，方便在只有一个结点的情况下删除该结点
        ListNode * tmp=new ListNode(0);
        tmp->next=head;
        head=tmp;
        ListNode *first,*second;
        first=second=head;
        for(int i=0;i<=n;i++){
            second=second->next;
        }
        while(second){
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return head->next;
    }
};
