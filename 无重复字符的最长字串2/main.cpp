//
//  main.cpp
//  无重复字符的最长字串2
//
//  Created by 陶炳志 on 2020/12/1.
//

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

  

 示例 1:

 输入: s = "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:

 输入: s = "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 示例 3:

 输入: s = "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 示例 4:

 输入: s = ""
 输出: 0
  

 提示：

 0 <= s.length <= 5 * 104
 s 由英文字母、数字、符号和空格组成

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;
/*
 1.滑动窗口，保证每个窗口里字母都是唯一的
 2.使用 vector<int> m 来记录一个字母如果后面出现重复时，i 应该调整到的新位置
   所以每次更新的时候都会保存 j + 1 ，即字母后面的位置
 3.j 表示子串的最后一个字母，计算子串长度为 j - i + 1
 */
int lengthOfLongestSubstring(string s) {
    vector<int> m(128, 0);
    int ans = 0;
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
        i = max(i, m[s[j]]);
        m[s[j]] = j + 1;
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    while (cin >> input) {
        cout << lengthOfLongestSubstring(input) << endl;
    }
    return 0;
}
