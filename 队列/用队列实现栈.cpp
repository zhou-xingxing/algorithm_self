//����ʵ��ջ
//һ������ 

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            int tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp=q.front();
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
