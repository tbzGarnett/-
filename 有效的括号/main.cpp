//
//  main.cpp
//  有效的括号
//
//  Created by 陶炳志 on 2020/11/26.
//

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。

 示例 1:

 输入: "()"
 输出: true
 示例 2:

 输入: "()[]{}"
 输出: true
 示例 3:

 输入: "(]"
 输出: false
 示例 4:

 输入: "([)]"
 输出: false
 示例 5:

 输入: "{[]}"
 输出: true

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
        // 第三种情况 是遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
        // 第二种情况 遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
        else if (st.empty() || st.top() != s[i]) return false;
        else st.pop(); // st.top() == s[i]
    }
    // 第一种情况 此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    return st.empty();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    while (cin >> input) {
        cout << isValid(input) << endl;
    }
    return 0;
}
