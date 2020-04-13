/*给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"*/

#include <iostream>
#include <stdlib.h>
using namespace std;

string addBinary(string a, string b) {
    int lenA = a.size();
    int lenB = b.size();
    while(lenA < lenB){
        a = '0' + a;
        lenA++;
    }
    while(lenA > lenB){
        b = '0' + b;
        lenB++;
    }
    for(int i = lenA - 1;i > 0;i--){
        a[i] = a[i] - '0' + b[i];
        if(a[i] >= '2'){
            a[i] = (a[i] - '0') % 2 + '0';
            a[i-1] = a[i-1] + 1;
        }
    }
    a[0] = a[0] - '0' + b[0];
    if(a[0] >= '2'){
        a[0] = (a[0] - '0') % 2 + '0';
        a = '1' + a;
    }
    return a;
}

int main(){
    string a = "1010", b = "1011";
    cout<<addBinary(a,b)<<endl;
    //system("pause");
    return 0;
}