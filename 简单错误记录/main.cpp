//
//  main.cpp
//  华为机考题
//
//  Created by 陶炳志 on 2020/11/17.
//

/*
 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
 处理:
 1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
 2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
 3.输入的文件可能带路径，记录文件名称不能带路径

 一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

     文件路径为windows格式

     如：E:\V1R2\product\fpgadrive.c 1325
 
 将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1

     结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

     如果超过8条记录，则只输出前8条记录.

     如果文件名的长度超过16个字符，则只输出后16个字符
 
 输入例子:
 E:\V1R2\product\fpgadrive.c 1325
 
 输出例子:
 fpgadrive.c 1325 1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare (pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
int main(void) {
    string input,file;
    vector<pair<string, int>> errors;
    while(getline(cin, input)) {
        if(input.size() == 0) break;
        unsigned long f = input.rfind('\\');
        file = input.substr(f+1);
        errors.push_back(make_pair(file, 1));
        for(int i = 0; i < (errors.size() - 1); i++) {
            if(errors[i].first == file) {
                errors[i].second ++ ;
                errors.pop_back();
                break;
            }
        }
    }
    stable_sort(errors.begin(),errors.end(),compare);
    int idx = 0;
    while(idx < 8 && idx < errors.size()){
        string temp = errors[idx].first;
        unsigned long t = temp.find(' ');
        if(t > 16) {
            errors[idx].first.erase(0, t-16);
        }
        cout << errors[idx].first << ' ' << errors[idx].second << endl;
        idx++;
    }
}
