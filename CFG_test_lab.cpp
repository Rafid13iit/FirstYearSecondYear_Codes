#include <bits/stdc++.h>
using namespace std;

bool is_acceptable(string s) {
    // initialize stack with start symbol
    stack<char> st;
    st.push('S');
    
    // iterate over each symbol in the input string
    for (int i = 0; i < s.length(); i++) {
        // check if stack is empty
        if (st.empty()) {
            return false;
        }
        
        // get the top symbol from stack
        char top = st.top();
        st.pop();
        
        // check if top symbol is a non-terminal
        if (top == 'S') {
            // replace S with A1B on the stack
            st.push('B');
            st.push('1');
            st.push('A');
        }

        else if (top == 'A') {
            // if input symbol is 0, replace A with 0A on the stack
            if (s[i] == '0') {
                st.push('A');
                st.push('0');
            }
            // if input symbol is epsilon, do nothing
            else if (s[i] == '\0') {
                continue;
            }
            // if input symbol is not 0 or epsilon, the string is not accepted
            else {
                return false;
            }
        }

        else if (top == 'B') {
            // if input symbol is 0, replace B with 0B on the stack
            if (s[i] == '0') {
                st.push('B');
                st.push('0');
            }
            // if input symbol is 1, replace B with 1B on the stack
            else if (s[i] == '1') {
                st.push('B');
                st.push('1');
            }
            // if input symbol is epsilon, do nothing
            else if (s[i] == '\0') {
                continue;
            }
            // if input symbol is not 0, 1 or epsilon, the string is not accepted
            else {
                return false;
            }
        }

        else if (top == s[i]) {
            // if top symbol is a terminal and matches the input symbol,
            // continue to the next symbol in the input string
            continue;
        }

        else {
            // if top symbol is a terminal and does not match the input symbol,
            // the string is not accepted
            return false;
        }
    }
    
    // if stack is empty after processing the input string, the string is accepted
    return st.empty();
}

int main() {
    string s = "001110";
    bool result = is_acceptable(s);
    
    if (result) {
        cout << "String " << s << " is ACCEPTED by the CFG." << endl;
    }

    else {
        cout << "String " << s << " is NOT Accepted by the CFG." << endl;
    }
    
    return 0;
}
