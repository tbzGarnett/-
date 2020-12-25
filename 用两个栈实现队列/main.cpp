//
//  main.cpp
//  用两个栈实现队列
//
//  Created by 陶炳志 on 2020/12/9.
//

/*
 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

  

 示例 1：

 输入：
 ["CQueue","appendTail","deleteHead","deleteHead"]
 [[],[3],[],[]]
 输出：[null,null,3,-1]
 示例 2：

 输入：
 ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
 [[],[],[5],[2],[],[]]
 输出：[null,-1,null,null,5,2]
 提示：

 1 <= values <= 10000
 最多会对 appendTail、deleteHead 进行 10000 次调用

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <stack>
using namespace std;

class CQueue {
private:
    stack<int> stack1, stack2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        // 明确一点，题目要求queue弹出的元素，是stack1最下面的元素，也是stack2最上面的元素
        int res = 0;
        if(!stack2.empty())
        {
            // 如果stack2不是空的，那么其最上面的元素就是要被弹出的
            res = stack2.top();
            stack2.pop();
        }
        else if(!stack1.empty())
        {
            // 如果stack2已经空了，把stack1的元素压过去，然后弹出stack2最上面的元素
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            res = stack2.top();
            stack2.pop();
        }
        else return -1; // 如果stack1和2都是空的，返回-1
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
