/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串*/

#include <iostream>
using namespace std;

/*笨方法
int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    if(s.size() == 1) return 1;
    int maxlen = 1, m = 1, i, j;
    for(i = 0;i < s.size() - 1;i++){
        m = 1;
        for(j = 1; j < s.size() - i;j++){
            if(s.substr(i,j).find(s[i + j]) == -1) m++; 
            else break;
        }
        maxlen = max(maxlen,m);
    }
    return maxlen;
}*/

/*滑动窗口
什么是滑动窗口？
其实就是一个队列,比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！
如何移动？
我们只要把队列的左边的元素移出就行了，直到满足题目要求！
一直维持这样的队列，找出队列出现最长的长度时候，求出解！
*/
int lengthOfLongestSubstring(string s) {
    int len = s.size(),ans = 0;
    int *index = new int[128]();
    for(int j = 0,i = 0;j < len;j++){
        cout<<index[s[j]]<<" "<<i<<" "<<j<<endl;
        i = max(index[s[j]],i);
        ans = max(ans, j-i+1);
        index[s[j]] = j+1;
    }
    return ans;
}

int main(){
    string s;
    while(1){
        cin>>s;
        cout<<lengthOfLongestSubstring(s)<<endl;
    }
    return 0;
}