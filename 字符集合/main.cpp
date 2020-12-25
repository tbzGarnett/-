//
//  main.cpp
//  字符集合
//
//  Created by 陶炳志 on 2020/11/27.
//

/*
 输入一个字符串，求出该字符串包含的字符集合

 输入描述:
 每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。

 输出描述:
 每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。

 输入例子1:
 abcqweracb

 输出例子1:
 abcqwer
 */

#include <iostream>
using namespace std;

int arr[256];
char ans[100];

int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    while (cin >> input) {
        int size = (int)input.size();
        int ans_index = 0;
        for (int i = 0; i<size; i++) {
            int hash = (int) input[i];
            if (arr[hash] == 0) {
                arr[hash] = 1;
                ans[ans_index] = input[i];
                ans_index++;
            }
        }
        int length = (int)strlen(ans);
        for (int j = 0; j<length; j++) {
            cout << ans[j];
        }
        cout << endl;
    }
    return 0;
}
