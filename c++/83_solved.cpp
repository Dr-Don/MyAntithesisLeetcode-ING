/*给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(1);
    ListNode* p = res;
    ListNode* ptr;
    if(head == NULL) return head;
    p->val = head->val;
    p->next = NULL;
    int pre = head->val;
    head = head->next;
    while(head != NULL){
        if(head->val != pre){
            ptr = new ListNode(1);
            ptr->val = head->val;
            p->next = ptr;
            p = p->next;
        }
        pre = head->val;
        head = head->next;
    }
    return res;
}

 int main(){
     ListNode *head;
    ListNode *p = head;
    p->val = 1;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    ListNode *res = deleteDuplicates(head);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
    p = NULL;
    res = NULL;
    delete p,res;
    //system("pause");
    return 0; 
}