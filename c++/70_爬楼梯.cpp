/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶*/

#include <iostream>
using namespace std;

int climbStairs(int n) {
    int res;
    int num1 = 1;
    int num2 = 2;
    if(n == 1) return num1;
    if(n == 2) return num2;
    for(int i = 3;i <= n;i++){
            res = num1 + num2;
            num1 = num2;
            num2 = res;
    }
    return res;
}

int main(){
    int x;
    while(x){
        cin>>x;
        cout<<climbStairs(x)<<endl;
    }
    return 0;
}