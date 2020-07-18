/*
给定一个二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。
 
示例：

输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	/* 解法一：使用已建立的next指针，在当前层时,把下一层第一个节点用dummy记录下来,然后遍历当前层的时候,
	把下面一层串起来,当前层遍历完,通过dummy可以开始下一层的遍历(同样重复上述, 
	将dummy记录下下层第一个节点,然后遍历该层, 并把下面一层串起来)
	太牛了*/
	Node* connect(Node* root) {
		Node* curr = root;
		Node* dummy = new Node;
		while (curr) { // 处理完一层
			Node* tail = dummy;
			while (curr) { // 遍历当前层的节点，处理下一层
				if (curr->left) { // 下一层
					tail->next = curr->left;
					tail = tail->next;
				}
				if (curr->right) { // 下一层
					tail->next = curr->right;
					tail = tail->next;
				}
				curr = curr->next;
			}
			curr = dummy->next; // 指向下一层的开始，继续
			if (tail == dummy) break;
		}
		return root;
	}
};