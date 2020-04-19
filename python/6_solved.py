'''
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N
'''
s = "LEETCODEISHIRING"
numRows = 3
def convert(s,num):
    if num<2:
        return s
    s1 = ""
    n, i, j  = 2*num-2, 0, 0
    while i < num:
        while j < len(s):
            k = j % n
            if k == i or k == n - i:
                s1 = s1 + s[j]
            j+=1
        j = 0
        i+=1
    return s1
print(convert(s,numRows))