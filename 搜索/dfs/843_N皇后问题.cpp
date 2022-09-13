#include <iostream>

using namespace std;

const int N = 10;
int n ;
char g[N][N];   
bool col[N] , dig[N] , udig[N];     // st[N] --> 标记变多了(剪枝条件变多了)
// 暴力搜索太暴力了,如果没有优化(剪枝) = =
void dfs(int u)
{
    if(n == u) 
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout << g[i][j] ;
            cout << endl;
        }
        cout << endl ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!col[i] && !dig[u+i] && !udig[n+u-i])
        {
            col[i] = dig[u+i] = udig[n+u-i] = true;         //  剪枝
            g[i][u] = 'Q';
            
            dfs(u+1);           //找下一层
            
            g[i][u] = '.';
            col[i] = dig[u+i] = udig[n+u-i] = false;    // 回溯
        }
    }
}

int main()
{
    cin >> n ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            g[i][j] = '.';

    dfs(0); // u == n 递归出口 所以从0开始(只要递归n层就能找到解)

    return 0;
}