// APP 1 from notes
// APP 2
// https://leetcode.com/problems/min-stack/description/
class MinStack {
public:
    stack<long long> s;
    long long cur_min;
    MinStack() {
        cur_min=1e12;
    }
    
    void push(int val) {

        if(val < cur_min)
        {
            // ENCRYPTION FORMULA
            long long newMin=val;
            long long oldMin=cur_min;
            long long toPush=2*newMin-oldMin;
            cur_min=newMin;
            s.push(toPush);
        }
        else
        {
            s.push(val);
        }
        
    }
    
    void pop() {
        if(s.top() < cur_min)   
        {
            // DECRYPTION
            long long pushedEleAtThatPoint=s.top();
            s.pop();

            long long newMinAfterPop=2*cur_min-pushedEleAtThatPoint;
            cur_min=newMinAfterPop;
        }
        else
        {
            s.pop();
        }
    }
    
    int top() {
        if(s.top() < cur_min)
        {
            return cur_min;
        }
        else
        {
            return s.top();
        }
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */