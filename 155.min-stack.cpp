/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack()
    {
    }

    void push(int val)
    {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if(minStack.top() == mainStack.top())
        {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top()
    {
        return mainStack.top();
    }

    int getMin()
    {
        return minStack.top();
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
// @lc code=end
