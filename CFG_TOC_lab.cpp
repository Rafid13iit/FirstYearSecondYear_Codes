/*
the CFG is :

S -> A1B
A -> 0A | ε
B -> 0B | 1B | ε

*/

#include <bits/stdc++.h>
using namespace std;

bool is_acceptable_leftMost(string s) {
    stack<char> st;
    st.push('S');

    cout << endl << "The Left Most Derivation is : " << endl << endl;

    char top;

    for (int i = 0; i < s.length(); i++) {

        if (st.empty()) {
            return false;
        }

        top = st.top();
        st.pop();

        if (top == 'S') {

            st.push('B');
            st.push('1');
            st.push('A');

            cout << "S -> A1B" << endl;

            i--;
        }

        else if (top == 'A') {

            if (s[i] == '0') {
                st.push('A');

                cout << "A -> 0A" << endl;
            }

            else if (s[i] == '1'){
                st.pop();

                cout << "A -> ε" << endl << "1" << endl;

                continue;
            }

            else{
                return false;
            }
        }

        else if (top == 'B') {

            if (s[i] == '0') {
                st.push('B');

                cout << "B -> 0B" << endl;
            }

            else if (s[i] == '1') {
                st.push('B');

                cout << "B -> 1B" << endl;
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
        cout << "B -> ε" << endl;

        return true;
    }

    else{
        return false;
    }
}


bool is_acceptable_rightMost(string s) {

    int index = -1;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '1'){
            index = i;
            break;
        }
    }
    
    if (index == -1) return false;

    else {
        stack<char> st;
        st.push('S');

        cout << endl << "The Right Most Derivation is : " << endl << endl;

        char top;

        for (int i = index+1; i < s.length(); i++) {

            if (st.empty()) {
                return false;
            }

            top = st.top();
            st.pop();

            if (top == 'S') {

                st.push('A');
                st.push('1');
                st.push('B');

                cout << "S -> A1B" << endl;

                i--;
            }

            else if (top == 'B') {

                if (s[i] == '0') {
                    st.push('B');

                    cout << "B -> 0B" << endl;
                }

                else if (s[i] == '1') {
                    st.push('B');

                    cout << "B -> 1B" << endl;
                }

                else {
                    return false;
                }
            }

            else {
                return false;
            }
        }

        cout << "B -> ε" << endl << "1" << endl;

        st.pop();
        st.pop();
        top = st.top();

        for (int i = 0; i < index; i++){

            if (top == 'A') {

                if (s[i] == '0') {
                    st.push('A');

                    cout << "A -> 0A" << endl;
                }

                else{
                    return false;
                }
            }

        }

        if(st.top() == 'A'){
            cout << "A -> ε"<< endl;

            return true;
        }

        else{
            return false;
        }
    }
}


int main() {
    string s;
    cout << "Enter the string containing 0 and 1 : ";
    cin >> s;

    bool result_lestMost = is_acceptable_leftMost(s);

    if (result_lestMost) {
        cout << endl << "String " << s << " is ACCEPTED by the CFG." << endl;
    }

    else {
        cout << endl << "String " << s << " is NOT Accepted by the CFG." << endl;
    }




    bool result_rightMost = is_acceptable_rightMost(s);

    if (result_rightMost) {
        cout << endl << "String " << s << " is ACCEPTED by the CFG." << endl;
    }

    else {
        cout << endl << "String " << s << " is NOT Accepted by the CFG." << endl;
    }

    return 0;
}
