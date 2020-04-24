/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/*动态规划
这个方法真的是绝妙*/
vector<string> generateParenthesis(int n) {
    if(n == 0) return {};
    vector<vector<string>> dp(n+1);
    dp[0].push_back("");

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < i;j++){
            for(string &str1:dp[j]){
                for(string &str2:dp[i-j-1]){
                    dp[i].push_back("(" + str2 + ")" + str1);
                }
            }
        }
    }
    return dp[n];
}

int main(){
    vector<string> des = generateParenthesis(3);
    for(int i = 0;i < des.size();i++){
        cout<<des[i]<<endl;
    }
    system("pause");
    return 0;
}