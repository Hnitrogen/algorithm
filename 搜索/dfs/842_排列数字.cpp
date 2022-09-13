#include <iostream>

using namespace std;

const int N = 10;
int path[N] , n;    
bool st[N];     // 标记

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0 ; i < n ; i++)    cout << path[i] << ' ';
        puts("");
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!st[i])  
        {
            st[i] = true;
            path[u] = i ;
            dfs(u+1);       // 向下一层递归
            st[i] = false;  // 恢复现场    
        }
    }
}
int main()
{
    cin >> n ;

    dfs(0);

    return 0;
}