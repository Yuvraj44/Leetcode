class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> s;
        for(int i=0; i<tokens.size(); i++)
        {
            s.push(tokens[i]);
            if(s.top()=="+")
            {
                s.pop();
                int n2=stoi(s.top());
                s.pop();
                int n1=stoi(s.top());
                s.pop();
                int cal=n1+n2;
                s.push(to_string(cal));

            }
            else if(s.top()=="-")
            {
                s.pop();
                int n2=stoi(s.top());
                s.pop();
                int n1=stoi(s.top());
                s.pop();
                int cal=n1-n2;
                s.push(to_string(cal));

            }
            else if(s.top()=="*")
            {
                s.pop();
                int n2=stoi(s.top());
                s.pop();
                int n1=stoi(s.top());
                s.pop();
                int cal=n1*n2;
                s.push(to_string(cal));

            }
            else if(s.top()=="/")
            {
                s.pop();
                int n2=stoi(s.top());
                s.pop();
                int n1=stoi(s.top());
                s.pop();
                int cal=n1/n2;
                s.push(to_string(cal));

            }
            cout<<s.top()<<" ";
        }
        return stoi(s.top());
    }
};