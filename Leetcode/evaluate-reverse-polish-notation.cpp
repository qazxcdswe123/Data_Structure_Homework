class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int length = tokens.size();
        for (int i = 0; i < length; i++)
        {
            string& token = tokens[i];
            if (isNumber(token))
            {
                stk.push(stoi(token));
            }
            else
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(token[0])
                {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
