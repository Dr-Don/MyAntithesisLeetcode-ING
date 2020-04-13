/*给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> dst;
    int len = digits.size();
    int plu = 0;
    int num = digits[len - 1] + 1;
    if(num == 10){
        plu = 1;
        num = 0;
    }
    /*关键点，末尾没有进位，就不用遍历向量*/
    else{
        dst = digits;
        dst[len-1]++;
        return dst;
    }
    dst.push_back(num);
    for(int i = len-2;i >= 0;i--){
        num = digits[i];
        num = num + plu;
        if(num == 10){
            num = 0;
            plu = 1;
        }
        else{
            plu = 0;
        }
        dst.insert(dst.begin(),num);
    }
    if(dst[0] == 0 && digits[0] != 0){
        dst.insert(dst.begin(),1);
    }
    return dst;
}

int main(){
    int num[4] = {0};
    vector<int> nums(num,num+1);
    vector<int> res = plusOne(nums);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    //system("pause");
    return 0;
} 