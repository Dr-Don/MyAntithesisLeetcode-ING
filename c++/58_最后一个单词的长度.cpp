/*给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。


示例:
输入: "Hello World"
输出: 5*/

#include <iostream>
#include "stdlib.h"
using namespace std;

int lengthOfLastWord(string s) {
    int dst = 0;
    int len = s.size();
    if(s == "") return dst;
    while(s[len-1] == ' '){
        s.erase(len-1,1);
        len--;
    }
    for(int i = len-1; i >= 0; i--){
        if(s[i] == ' '){
            return dst;
        }
        dst += 1;
    }
    return dst;
}

int main(){
    string s = "b  a  ";
    cout<<lengthOfLastWord(s)<<endl;
    //system("pause");
    return 0;
}