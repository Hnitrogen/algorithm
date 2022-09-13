#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int,int> PII;

const int N = 110;
int g[N][N] , m , n ;
int  dist[N][N];
PII q[N*N];

int dx[4] = {-1,0,1,0} , dy[4]={0,1,0,-1};  
void bfs(int sx , int sy)
{
    int hh = 0 , tt = 0;    // 因为后面加入一个点所以 tt = 0 
    q[0]={sx,sy};
    dist[sx][sy] = 0 ;

    while(hh <= tt)
    {
        PII t = q[hh++];

        for(int i = 0 ; i < 4 ; i++)
        {
            int a = t.x + dx[i] , b = t.y + dy[i];  // 遍历四个方向
            if(a >= 0 && a < n && b >= 0 && b < m && dist[a][b] == -1 && g[a][b] == 0)  // 出界 | 是否被遍历 | 是否可以走
            {
                dist[a][b] = dist[t.x][t.y] + 1;
                q[++tt] = {a,b};
            }
        }
    }
}

int main()
{
    memset(dist,-1,sizeof dist);

    cin >> n >> m ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            scanf("%d",&g[i][j]);
        
    bfs(0,0);

    cout << dist[n-1][m-1] << endl;

    return 0;
}