//
//  main.cpp
//  数独
//
//  Created by 陶炳志 on 2020/11/27.
//

/*
 数独是一个我们都非常熟悉的经典游戏，运用计算机我们可以很快地解开数独难题，现在有一些简单的数独题目，请编写一个程序求解。
 如有多解，输出一个解

 输入描述:
 输入9行，每行为空格隔开的9个数字，为0的地方就是需要填充的。

 输出描述:
 输出九行，每行九个空格隔开的数字，为解出的答案。
 */

#include <iostream>
using namespace std;

int nums[9][9];
bool flag=false;

bool check(int n,int key)
{
    for(int i=0;i<9;i++)
    {

        int j=n/9;
        if(nums[j][i]==key) return false;
    }
    for(int i=0;i<9;i++)
    {
        int j=n%9;
        if(nums[i][j]==key) return false;
    }

    int x=n/9/3*3;
    int y=n%9/3*3;

    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(nums[i][j]==key) return false;
        }
    }
    return true;
}

void dfs(int n)
{
    if(n>80)
    {
        flag = true;
        return ;
    }

    if(nums[n/9][n%9]!=0)
    {
        dfs(n+1);
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(check(n,i)==true)
            {
                nums[n/9][n%9]=i;
                dfs(n+1);
                if(flag==true) return ;
                nums[n/9][n%9] = 0;

            }
        }
    }
    return ;
}


int main()
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>nums[i][j];
        }
    }
    dfs(0);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<nums[i][j]<<" ";
            if(j==8) cout<<endl;
        }
    }

}

