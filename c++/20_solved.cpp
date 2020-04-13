/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。*/
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    if(s == "") return true;
    stack<char> stack;
    for(int i = 0;i< s.size();i++){
        switch (s[i])
        {
        case '(':
            stack.push(')');
            break;
        case '{':
            stack.push('}');
            break;
        case '[':
            stack.push(']');
            break;                
        default:
            if(stack.size() == 0 || s[i] != stack.top()) return false;
            stack.pop();
        }
    }
    if(stack.size() == 0) return true;
    return false;
}

int main(){
    string x;
    while(1){
        cin>>x;
        if(x == "#"){
            break;
        }
        cout << isValid(x) << endl;
    }
    return 0;
}