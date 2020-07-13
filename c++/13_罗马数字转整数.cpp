/*罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。*/

#include <iostream>

using namespace std;

 int romanToInt(string s) {
     int des = 0;
     char pre;
     int i = 0;
     for(int i = 0;i < s.size();i++){
        switch (s[i])
        {
        case 'I':
            des += 1;
            break;
        case 'V':
            des += 5;
            if(pre == 'I') des -= 2;
            break;
        case 'X':
            des += 10;
            if(pre == 'I') des -= 2;
            break;
        case 'L':
            des += 50;
            if(pre == 'X') des -= 20;
            break;
        case 'C':
            des += 100;
            if(pre == 'X') des -= 20;
            break;
        case 'D':
            des += 500;
            if(pre == 'C') des -= 200;
            break;
        case 'M':
            des += 1000;
            if(pre == 'C') des -= 200;
            break;
        default:
            break;
        }
        pre = s[i];
     }
     return des;
}

int main(){
    string x;
    while(1){
        cin>>x;
        if(x == "#"){
            break;
        }
        cout << romanToInt(x) << endl;
    }
    return 0;
}
