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
    //˫ָ��
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        //����ͷ��㣬������ֻ��һ�����������ɾ���ý��
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
