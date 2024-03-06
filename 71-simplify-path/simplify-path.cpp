class Solution {
public:
    string simplifyPath(string path) {
     stack<string> st;
        for(int i = 0; i < path.size(); ++i) 
        {
            if(path[i] == '/') 
            continue;
            
            string temp;
            while(i < path.size() && path[i] != '/') 
                temp += path[i++];
                
            
            if(temp == ".") 
            continue;
            else if(temp == "..") 
            {
                if(!st.empty()) 
                st.pop();
            }
            else
            st.push(temp);
        }
        if(st.empty())
        return "/";
        
        path = "";
        while(!st.empty()) {
            path = "/" + st.top() + path;
            st.pop();
        }
        
        return path;
        }
};
 