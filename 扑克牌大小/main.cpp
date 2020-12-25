//
//  main.cpp
//  扑克牌大小
//
//  Created by 陶炳志 on 2020/11/18.
//

/*
 扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
 输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
 请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

 基本规则：
 （1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
 （2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
 （3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
 （4）输入的两手牌不会出现相等的情况。

 答案提示：
 （1）除了炸弹和对王之外，其他必须同类型比较。
 （2）输入已经保证合法性，不用检查输入是否是合法的牌。
 （3）输入的顺子已经经过从小到大排序，因此不用再排序了.
 
 输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
 
 输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
 
 输入例子:
 4 4 4 4-joker JOKER
 
 输出例子:
 joker JOKER
 */

#include <iostream>

using namespace std;
string data = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
pair<string, int> control(string str){
    int firstCount = 1;
    string::size_type fIndex = str.find(' ');
    pair<string, int> pair;
    if (fIndex != str.npos) {
        while (fIndex != str.npos) {
            string hhh = str.substr(0,fIndex);
            str = str.substr(fIndex+1);
            fIndex = str.find(' ');
            if (firstCount == 1) {
                pair.first = hhh;
            }
            firstCount++;
        }
        pair.second = firstCount;
    }else{
        pair.first = str;
        pair.second = firstCount;
    }
    return pair;
}

bool compare(pair<string, int> firstPair,pair<string, int> secondPair){
    unsigned long firIndex = data.find(firstPair.first);
    unsigned long secIndex = data.find(secondPair.first);
    return firIndex > secIndex;
}

int main(void) {
    string input,firstHand,secondHand;
    pair<string, int> firstPair,secondPair;
    while (getline(cin, input)) {
        if (input.size() == 0) {
            cout << "ERROR" << endl;
        }
        unsigned long f = input.find('-');
        firstHand = input.substr(0,f);
        secondHand = input.substr(f+1);
        
        firstPair = control(firstHand);
        secondPair = control(secondHand);
        
        //首先如果有王炸,直接最大
        if (firstPair.first == "joker" && firstPair.second == 2) {
            cout << firstHand << endl;
        }else if (secondPair.first == "joker" && secondPair.second == 2) {
            cout << secondHand << endl;
        }else {
            //再次,如果没有炸弹,且两手牌数量不一样,直接error
            if (firstPair.second != 4 && secondPair.second != 4 && firstPair.second != secondPair.second) {
                cout << "ERROR" << endl;
            }else {
                //再然后 如果一方有炸弹 直接大
                if (firstPair.second == 4 && secondPair.second != 4) {
                    cout << firstHand << endl;
                }else if (secondPair.second == 4 && firstPair.second != 4) {
                    cout << secondHand << endl;
                }else {
                    if (compare(firstPair,secondPair)) {
                        cout << firstHand << endl;
                    }else{
                        cout << secondHand << endl;
                    }
                }
            }
        }
    }
    return 0;
}
