/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *res = NULL;
    ListNode *ptr,*p;
    while(p1 != NULL || p2 != NULL){        
        ptr = new ListNode(0);
        if(p1 == NULL){
            ptr->val = p2->val;
            p2 = p2->next;
        }
        else if(p2 == NULL){
            ptr->val = p1->val;
            p1 = p1->next;
        }
        else{
            if(p1->val >= p2->val){
                ptr->val = p2->val;
                p2 = p2->next;
            }
            else if(p1->val <= p2->val){
                ptr->val = p1->val;
                p1 = p1->next;
            }
        }
        ptr->next = NULL;
        if(res == NULL){
            res = ptr;
            p = res;
        }
        else{
            p->next = ptr;
            p = ptr;
        }
    }
    return res;
}

int main(){
    ListNode l1(1);
    ListNode l2(1);
    ListNode *p = &l1;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(4);
    p = &l2;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    ListNode *res = mergeTwoLists(&l1,&l2);
    p = res;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    p = NULL;
    delete p,res;
    //system("pause");
    return 0; 
}