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
        //记住要比较的是a->next b->next
        while(b->next){
            if(a->next->val!=b->next->val){
                a=a->next;
                b=b->next;
            }
            else{
                //不要忘记先判断b->next是否为空
                while(b->next && a->next->val==b->next->val){
                    b=b->next;
                }
                a->next=b->next;
                //时刻注意判断指针是否为空
                if(b->next){
                    b=b->next;
                }
                
            }
        }
        //此处注意不能直接返回head，因为head也有可能是应该删除的点
        return tmp->next;
    }
};
