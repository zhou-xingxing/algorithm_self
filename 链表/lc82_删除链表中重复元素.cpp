class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode * tmp= new ListNode;
        tmp->next=head;
        ListNode * a, * b;
        a=tmp;
        b=head;
        //��סҪ�Ƚϵ���a->next b->next
        while(b->next){
            if(a->next->val!=b->next->val){
                a=a->next;
                b=b->next;
            }
            else{
                //��Ҫ�������ж�b->next�Ƿ�Ϊ��
                while(b->next && a->next->val==b->next->val){
                    b=b->next;
                }
                a->next=b->next;
                //ʱ��ע���ж�ָ���Ƿ�Ϊ��
                if(b->next){
                    b=b->next;
                }
                
            }
        }
        //�˴�ע�ⲻ��ֱ�ӷ���head����ΪheadҲ�п�����Ӧ��ɾ���ĵ�
        return tmp->next;
    }
};
