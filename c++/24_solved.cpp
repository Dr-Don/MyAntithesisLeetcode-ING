/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
精简的递归！

交换head和next->next，再将next移到前面
终止条件为只剩一个节点或者没有节点
*/
ListNode* swapPairs(ListNode* head) {
    // 1. 终止条件
    if(head == NULL || head->next == NULL){
        return head;
    }
    // 2. 调用单元
    // 节点head和head.next交换
    ListNode *next = head->next;
    // 连接后面交换完成的子链表
    head->next = swapPairs(next->next);
    // 连接head
    next->next = head;
    // 3. 返回值
    // next变成了头结点
    return next;
}