/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb
*/

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

class Solution {
public:
    /* 我的暴力解法，是对的但是超时 */
    string longestPalindrome(string s) {
        int n = s.size();
        int leftMin = 0;
        int lenMax = 0;
        if(n == 1) return s;
        if(n == 0) return "";
        for(int i = 0;i < n;i++){
            for (int j = n - 1; j > i; j--) {
                if(s[i] == s[j]){
                    int left = i;
                    int right = j;
                    while(s[left] == s[right] && left < right){
                        left++;
                        right--;
                    }
                    if(s[left] != s[right]) continue;
                    if(abs(left-right) == 1 || left == right){
                        if(lenMax < j-i+1){
                            lenMax = j-i+1;
                            leftMin = i;
                        }
                    }
                }
            }
        }
        if(lenMax > 0) return s.substr(leftMin,lenMax);
        return string(1,s[0]);
    }

    /* 马拉车算法 */
    string preProcess(string s){
        int n = s.size();
        if (n == 0) return "^$";
        string res = "^";
        for (int i = 0; i < n; i++)
            res += "#" + string(1,s[i]);
        res += "#$";
        return res;
    }

    string longestPalindrome(string s) {
        string str = preProcess(s);
        int n = str.size();
        int P[n];
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            if (R > i) P[i] = min(R - i, P[i_mirror]);// 防止超出 R
            else P[i] = 0;// 等于 R 的情况

            // 中心扩展法
            while (str[i + 1 + P[i]] == str[i - 1 - P[i]]) {
                P[i]++;
            }

            // 判断是否需要更新 R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // 找出 P 的最大值
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2; //最开始讲的求原字符串下标
        return s.substr(start, maxLen);
    }
};