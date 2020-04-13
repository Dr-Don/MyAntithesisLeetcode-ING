/*实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int strStr(string haystack, string needle) {
        int res = -1;
        int i, j;
        if(needle == "") return 0;
        for(i = 0;i < haystack.size();i++){
            for(j = 0;j < needle.size();j++){
                if(needle[j] != haystack[i + j]) break;
                if(j == needle.size() - 1) return res = i;
            }
        }
        return res;
}

int main(){
    string hay = "mississippi";
    string need = "issip";
    cout <<strStr(hay,need) << endl;
    //system("pause");
    return 0;
}