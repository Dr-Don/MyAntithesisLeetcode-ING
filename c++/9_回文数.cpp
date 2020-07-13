/*判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数*/
#include <iostream>
#include <limits.h>
using namespace std;

#define INT_MIN     (-2147483647 - 1) // minimum (signed) int value
#define INT_MAX       2147483647    // maximum (signed) int value

bool IsPalind(int x){
    if (x < 0) return false;
    int res = x;
    int rev = 0;
    while(x!=0){
        int pop = x % 10;
        x/=10;
        if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)){
            return false;
        }
        if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)){
            return false;
        }
        rev = rev * 10 + pop;
    }
    if(rev == res){
        return true;  
    }
    return false;
}

int main(){
    int x;
    while(x){
        cin>>x;
        if(x == 0){
            break;
        }
        cout << IsPalind(x) << endl;
    }
    return 0;
}