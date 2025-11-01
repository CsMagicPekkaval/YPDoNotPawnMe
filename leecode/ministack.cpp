class MinStack {
private:
    vector<pair<int,int>> ms;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min = getMin();
        if (ms.empty() or min > val) {
            min = val;
        }
        ms.push_back({val, min});        
    }
    
    void pop() {
        ms.pop_back();
    }
    
    int top() 
    {
        return ms.back().first;
    }
    
    int getMin() 
    {
        if (ms.empty())
        {
            return -1;
        }
        
        return ms.back().second;
    }
};
//https://leetcode.com/problems/min-stack/