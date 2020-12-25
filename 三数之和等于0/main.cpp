//
//  main.cpp
//  三数之和等于0
//
//  Created by 陶炳志 on 2020/11/30.
//

/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

  

 示例：

 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/3sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
vector<vector<int>> threeSum(vector<int> nums) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1]) {
           continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}
 */
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = (int)nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < N - 2; i++) {
            // prune
            if (nums[i] > 0) { // smaller already > 0, a + b + c cannot be 0
                return res;
            }

            int target = -nums[i];
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue; // skip dup
            }

            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                auto sum = nums[j] + nums[k];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    //这里可以减少循环次数,当添加一对解后,左指针直接快进到第一个不相等的下标,右指针同理.
                    int m = j;
                    while (m < k && nums[m] == nums[j]) {
                        m++;
                    }
                    j = m;

                    int n = k;
                    while (n > j && nums[n] == nums[k]) {
                       n--;
                    }
                    k = n;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }
int main() {
    // insert code here...
//    string input;
//    vector<int> nums;
//    while (getline(cin, input)) {
//        if (input.length() == 0) {
//            cout << "ERROR" << endl;
//        }
//        unsigned long fIndex = input.find(',');
//        while (fIndex != input.npos) {
//            int num = stoi(input.substr(0,fIndex));
//            nums.push_back(num);
//            input = input.substr(fIndex + 1);
//            fIndex = input.find(',');
//        }
//        nums.push_back(stoi(input));
//        vector<vector<int>> result = threeSum(nums);
//    }
//    vector<int> nums = [-1,0,1,2,-1,-4,-2,-3,3,0,4];
    
//    threeSum(nums);
    return 0;
}
