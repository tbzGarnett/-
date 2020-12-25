//
//  main.cpp
//  链表中倒数第k个节点
//
//  Created by 陶炳志 on 2020/12/14.
//

/*
 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

  

 示例：

 给定一个链表: 1->2->3->4->5, 和 k = 2.

 返回链表 4->5.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 题解思路:快慢指针
 就是先来一个链表,循环k次,指向next;
 然后再来一个循环(count-k),即while(cur),然后head指向next.
 因为是要输出倒数第k个节点
 所以先循环k次,然后while剩下的节点直到null.
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; i ++) cur = cur->next;
        while(cur) {
            cur = cur->next;  //快指针
            head = head->next;  //慢指针
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
