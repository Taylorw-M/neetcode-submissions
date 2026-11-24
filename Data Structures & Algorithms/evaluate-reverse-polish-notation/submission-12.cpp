class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const string& str : tokens){
            int sum = 0;
            if(str == "+"){
                    sum += s.top();
                    s.pop();
                    sum += s.top();
                    s.pop();
                    s.push(sum);
                    continue;
            } else if(str == "-"){
                    int operand1 = s.top();
                    s.pop();
                    int operand2 = s.top();
                    s.pop();
                    sum = operand2 - operand1;
                    s.push(sum);
                    continue;    
            } else if(str == "*"){
                    int operand1 = s.top();
                    s.pop();
                    int operand2 = s.top();
                    s.pop();
                    sum = operand2 * operand1;
                    s.push(sum);
                    continue; 
            } else if(str == "/"){
                    int operand1 = s.top();
                    s.pop();
                    int operand2 = s.top();
                    s.pop();
                    if(operand1 != 0){
                    sum = operand2 / operand1;
                    s.push(sum);
                    }
                    continue; 
            } else{
                s.push(stoi(str));
            }
        }
        if(s.empty()){
            return 0;
        }
        return s.top();
    }
};
