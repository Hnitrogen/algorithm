#include <iostream>

using namespace std;

const int N = 10;
int n ;
char g[N][N];   
bool col[N] , dig[N] , udig[N];     // st[N] --> ��Ǳ����(��֦���������)
// ��������̫������,���û���Ż�(��֦) = =
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
            col[i] = dig[u+i] = udig[n+u-i] = true;         //  ��֦
            g[i][u] = 'Q';
            
            dfs(u+1);           //����һ��
            
            g[i][u] = '.';
            col[i] = dig[u+i] = udig[n+u-i] = false;    // ����
        }
    }
}

int main()
{
    cin >> n ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            g[i][j] = '.';

    dfs(0); // u == n �ݹ���� ���Դ�0��ʼ(ֻҪ�ݹ�n������ҵ���)

    return 0;
}