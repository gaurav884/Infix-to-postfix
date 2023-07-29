
// Online IDE - Code Editor, Compiler, Interpreter

#include <bits/stdc++.h>

using namespace std;

int prec(char a){

   if(a == '^') return 3;

   if(a == '*' || a=='/') return 2;

   if(a== '+' || a=='-') return 1;

   return 0;

}

int main()
{
     
    string s = "((A+B)-C*(D/E))+F";
    
    stack<char> st;
    
    string ans = "";
    
    for(int i=0 ;i<s.size() ;i++){

        if(s[i] == ')'){

            while(st.size() >0 && st.top() != '('){
                ans += st.top();
                st.pop();
            }

            st.pop();

        }
        
        else if(s[i] =='(' || s[i] == '+' || s[i] == '-' || s[i]=='/' || s[i]=='*'){

            if(s[i] == '('){
                st.push(s[i]);
            }
            else{

                while(st.size() > 0 && prec(s[i]) < prec(st.top())){
                    ans += st.top();
                    st.pop();
                }
                
                st.push(s[i]);
            }

        }
        else{
            ans += s[i];
        }

    }

    while(st.size() > 0){
        ans += st.top();
        st.pop();
    }
    
    cout<<ans;
    return 0;
}
