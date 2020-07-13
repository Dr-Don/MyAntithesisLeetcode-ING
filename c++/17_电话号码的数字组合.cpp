/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
{2:abc, 3:def, 4:ghi, 5:jkl, 6:mno, 7:pqrs, 8:tuv, 9:wxyz}

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

string map[] = {" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res;

/*回溯法*/
vector<string> letterCombinations(string digits) {
    if (digits == "" || digits.size() == 0) return {};
    backtrack(digits, "", 0); // 在这里递归调用
    return res;
}

/*递归函数*/
void backtrack(string str,string letter,int index){
    if(index == str.size()){  // 递归终止条件，digits读取完成
        res.push_back(letter);
        return;
    }
    char c = str[index]; // 依次读取数字字符串
    int pos = c - '0';  // 转换为数字
    string mapString = map[pos];  //从映射表中得到相应的字符串
    for(int i=0;i<mapString.size();i++){
        backtrack(str, letter + mapString[i], index+1); // 调用下一层递归
    }
}

int main(){
    vector<string> str = letterCombinations("23");
    for(int i = 0;i < str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //system("pause");
}