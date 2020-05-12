/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return 0;

    int res[num1.size() + num2.size()];
    for(int i = num1.size() - 1;i >= 0;i--){
        for(int j = num2.size() - 1;j >= 0;j++){
            int sum = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
            res[i + j + 1] = sum % 10;
            res[i + j] += sum/10;
        }
    }

    string result = "";
    for(int i = 0;i < res.size() - 1;i++){
        if(i == 0 && res[i] == 0) continue;
        result.push_back(res[i]);
    }
    return result;
}

int main(){
    string num1;
    string num2;
    while(1){
        if(num1 == "#") break;
        cin>>num1>>num2;
        cout<<multiply(num1,num2)<<endl;
    }
    return 0;
}