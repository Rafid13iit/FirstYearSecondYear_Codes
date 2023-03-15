#include <bits/stdc++.h>
using namespace std;

bool is_acceptable(string s) {
    stack<char> st;
    st.push('S');
    
    for (int i = 0; i < s.length(); i++) {

        if (st.empty()) {
            return false;
        }
        
        char top = st.top();
        st.pop();
        
        if (top == 'S') {

            st.push('B');
            st.push('1');
            st.push('A');

            i--;
        }

        else if (top == 'A') {
    
            if (s[i] == '0') {
                st.push('A');
            }

            else if (s[i] == '1'){
                st.pop();
                continue;
            }

            else{
                return false;
            }
        }

        else if (top == 'B') {

            if (s[i] == '0') {
                st.push('B');
            }
  
            else if (s[i] == '1') {
                st.push('B');
            }

            else {
                return false;
            }
        }

        else {
            return false;
        }
    }
    
    if(st.top() == 'B'){
        return true;
    }

    else{
        return false;
    }
}

int main() {
    string s;
    cin >> s;
    
    bool result = is_acceptable(s);
    
    if (result) {
        cout << "String " << s << " is ACCEPTED by the CFG." << endl;
    }

    else {
        cout << "String " << s << " is NOT Accepted by the CFG." << endl;
    }
    
    return 0;
}
