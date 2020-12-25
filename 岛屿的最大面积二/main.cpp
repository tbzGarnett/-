//
//  main.cpp
//  岛屿的最大面积二
//
//  Created by 陶炳志 on 2020/12/2.
//

/*
 给定一个包含了一些 0 和 1 的非空二维数组 grid 。

 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

  

 示例 1:

 [[0,0,1,0,0,0,0,1,0,0,0,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,1,1,0,1,0,0,0,0,0,0,0,0],
  [0,1,0,0,1,1,0,0,1,0,1,0,0],
  [0,1,0,0,1,1,0,0,1,1,1,0,0],
  [0,0,0,0,0,0,0,0,0,0,1,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

 示例 2:

 [[0,0,0,0,0,0,0,0]]
 对于上面这个给定的矩阵, 返回 0。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/max-area-of-island
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 思路:
 矩阵双循环遍历,如果遇到等于1,递归周边四个值的和,如果是1的话反水为0.防止下次重复统计.
 */

int getArea(vector<vector<int>>&  grid, int i, int j)
{
    //由于坐标每次 +1 ，所以判断是否等于数组长度即可
    if (i == grid.size() || i < 0)
        return 0;
    else if (j == grid[0].size() || j < 0)
        return 0; ;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        return 1 + getArea(grid, i + 1, j) + getArea(grid, i - 1, j ) + getArea(grid, i, j + 1) + getArea(grid, i, j - 1);
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    int area = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                //以此为中心，向四周扩散
                area = getArea(grid, i, j);
                maxArea = maxArea > area ? maxArea : area;
            }
        }
    }
    return maxArea;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
