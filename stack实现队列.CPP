/***使用两个stack之间的出入来实现

class MyQueue {
    stack<int> val;
    stack<int> inverse_val;
public:
    /** Initialize your data structure here. */
    MyQueue():val(),inverse_val() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {

        val.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=val.top();
        while(!val.empty())
        {
            res=val.top();
            val.pop();
            inverse_val.push(res);
        }
        //reverse to val
        inverse_val.pop();
        while(!inverse_val.empty())
        {
            val.push(inverse_val.top());
            inverse_val.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res=val.top();
        while(!val.empty())
        {
            res=val.top();
            val.pop();
            inverse_val.push(res);
        }
        while(!inverse_val.empty())
        {
            val.push(inverse_val.top());
            inverse_val.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(val.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/version 2/
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>instack;
     stack<int>outstack;
    MyQueue() {
     
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        checkOutstack();
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        checkOutstack();
        return outstack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return instack.empty() && outstack.empty();
    }
private: void checkOutstack()
{
    if (outstack.empty())
    {
        while (!instack.empty())
      { 
        outstack.push(instack.top());
        instack.pop();
      }
    }
}
};
