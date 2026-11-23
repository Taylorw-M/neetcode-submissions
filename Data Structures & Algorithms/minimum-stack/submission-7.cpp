class MinStack {
private:
    stack<int> s;
    stack<int> minimums;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);

        if (minimums.empty() || val <= minimums.top()) {
            minimums.push(val);
        }
    }

    void pop() {
        if (s.top() == minimums.top()) {
            minimums.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minimums.top();
    }
};