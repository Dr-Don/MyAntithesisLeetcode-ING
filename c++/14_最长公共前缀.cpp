/*编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。*/

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
        string res;
        if(strs.size() == 0) return "";
        res = strs[0];
        for(int i = 0; i< strs.size();i++){
            while(strs[i].substr(0, res.size()) != res){
                res = res.substr(0, res.size() - 1);
                if(res == "") return res;
            }
        }
        return res;
}

int main(){
    string str[] = {"flower","flow","flight"};
    vector<string> strs(str,str+3);
    cout <<longestCommonPrefix(strs) << endl;
    return 0;
}