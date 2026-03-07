#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, turns, direction;
    node() {}
    node(int _x, int _y, int _turns, int _direction)
    {
        x = _x;
        y = _y;
        turns = _turns;
        direction = _direction;
    }
};

// 记录每个位置在每个方向上的最小转弯次数
int minTurns[101][101][4];
char maze[101][101];
int m, n, k;

// 方向定义：0-上，1-下，2-左，3-右
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> m >> n;
        
        // 初始化迷宫和转弯次数数组
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
                for (int d = 0; d < 4; d++)
                {
                    minTurns[i][j][d] = INT_MAX;
                }
            }
        }
        
        int x1, y1, x2, y2;
        cin >> k >> x1 >> y1 >> x2 >> y2;
        
        // 转换为0-based索引
        x1--; y1--; x2--; y2--;
        
        queue<node> q;
        
        // 从起点开始，可以向四个方向出发，初始转弯次数为0
        for (int d = 0; d < 4; d++)
        {
            q.push(node(x1, y1, 0, d));
            minTurns[y1][x1][d] = 0;
        }
        
        bool found = false;
        
        while (!q.empty() && !found)
        {
            node current = q.front();
            q.pop();
            
            // 如果到达终点
            if (current.x == x2 && current.y == y2 && current.turns <= k)
            {
                found = true;
                break;
            }
            
            // 如果转弯次数已经超过限制，跳过
            if (current.turns > k)
            {
                continue;
            }
            
            // 尝试四个方向
            for (int d = 0; d < 4; d++)
            {
                int nx = current.x + dx[d];
                int ny = current.y + dy[d];
                
                // 检查边界和障碍
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || maze[ny][nx] == '*')
                {
                    continue;
                }
                
                // 计算新的转弯次数
                int newTurns = current.turns;
                if (current.direction != d)
                {
                    newTurns++;
                }
                
                // 如果这个状态更好（转弯次数更少），则更新
                if (newTurns < minTurns[ny][nx][d] && newTurns <= k)
                {
                    minTurns[ny][nx][d] = newTurns;
                    q.push(node(nx, ny, newTurns, d));
                }
            }
        }
        
        if (found)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    
    return 0;
}