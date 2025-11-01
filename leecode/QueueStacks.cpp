class MyQueue {
private:
    deque<int> qq;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        qq.push_back(x);
    }
    
    int pop() {
        int val;
        val = qq.front();
        qq.pop_front();
        return val;
    }
    
    int peek() {
        return qq.front();
    }
    
    bool empty() {
        return qq.empty() ? true :false;
    }
};

//https://leetcode.com/problems/implement-queue-using-stacks/