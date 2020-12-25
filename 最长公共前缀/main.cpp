//
//  main.cpp
//  最长公共前缀
//
//  Created by 陶炳志 on 2020/11/25.
//

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    int n = (int)strs.size(), min_str = 201;
    string res = "";
    for (int i = 0; i < n; i++)//得到最短串的长度
        min_str = (strs[i].length() < min_str) ? (int)strs[i].length(): min_str;
    for (int j = 0; j < min_str; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (strs[i][j] == strs[i - 1][j])
                continue;
            else
                return res;
        }
        res += strs[0][j];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    vector<string> inputVector;
    while (getline(cin, input)) {
        if (input.size() == 0) {
            cout << "输入为空" << endl;
            return 0;
        }
        string::size_type fIndex = input.find(' ');
        while (fIndex != input.npos) {
            string hhh = input.substr(0,fIndex);
            inputVector.push_back(hhh);
            input = input.substr(fIndex+1);
            fIndex = input.find(' ');
        }
        cout << longestCommonPrefix(inputVector) << endl;
    }
    return 0;
}
