//
//  main.cpp
//  删数二
//
//  Created by 陶炳志 on 2020/11/18.
//
/*
 有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
 
 每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。
 
 一行输出最后一个被删掉的数的原始下标位置。
 
 输入:
 8
 输出:
 6
 
 
 0,1,2,3,4,5,6,7
 
 0,1,3,4,6,7
 
 1,3,6,7
 
 3,6
 
 6
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int input;
    vector<int> arr;
    while (cin >> input) {
        if (input > 1000) {
            input = 1000;
        }
        for (int i = 0; i<input; i++) {
            if ((i+1)%3 != 0) {
                arr.push_back(i);
            }
        }
        int temp = input%3;
        while (arr.size() > 2) {
            int index = 0;
            for (vector<int>::iterator it=arr.begin(); it!=arr.end();) {
                if ((index+1+temp)%(3) == 0) {
                    it = arr.erase(it);
                }else{
                    ++it;
                }
                index++;
            }
            temp = (index+temp)%3;
        }
        if (arr.size() == 1) {
            cout<<arr[0]<<endl;
        }else{
            if (temp == 1) {
                cout<<arr[0]<<endl;
            }else{
                cout<<arr[1]<<endl;
            }
        }
        arr.clear();
    }
    return 0;
}
