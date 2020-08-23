//用栈实现队列
//一个输入栈，一个输出栈 


class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out_stack.empty()){
            int tmp;
            while(!in_stack.empty()){
                tmp=in_stack.top();
                in_stack.pop();
                out_stack.push(tmp);
            }
        }
        int tmp=out_stack.top();
        out_stack.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(out_stack.empty()){
            int tmp;
            while(!in_stack.empty()){
                tmp=in_stack.top();
                in_stack.pop();
                out_stack.push(tmp);
            }
        }
        int tmp=out_stack.top();
        return tmp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in_stack.empty()&&out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
