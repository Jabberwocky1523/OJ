#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        int edge[n][n][2], distance[n], visit[n], p[n];
        for (int i = 0; i < n; i++)
        {
            distance[i] = p[i] = INT_MAX;
            visit[i] = 0;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    edge[i][j][k] = INT_MAX;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, d, p;
            cin >> u >> v >> d >> p;
            u--, v--;
            if (d < edge[u][v][0])
            {
                edge[u][v][0] = edge[v][u][0] = d, edge[u][v][1] = edge[v][u][1] = p;
            }
            else if (d == edge[u][v][0])
            {
                if (p < edge[u][v][1])
                {
                    edge[u][v][1] = edge[v][u][1] = p;
                }
            }
        }
        int s, t, sumd = 0, sump = 0;
        cin >> s >> t;
        s--, t--;
        visit[s] = 1;
        for (int i = 0; i < n; i++)
        {
            if (edge[s][i][0] != -1 && !visit[i])
            {

                if (edge[s][i][0] < distance[i])
                {
                    distance[i] = edge[s][i][0];
                    p[i] = edge[s][i][1];
                }
                else if (distance[i] == edge[s][i][0])
                {
                    if (edge[s][i][1] < p[i])
                    {
                        p[i] = edge[s][i][1];
                    }
                }
            }
        }
        int temp = n;
        while (temp != 1)
        {
            /* code */
            int index = -1, min = INT_MAX, pmin = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (!visit[i])
                {
                    if (distance[i] < min)
                    {
                        min = distance[i], index = i, pmin = p[i];
                    }
                    else if (distance[i] == min)
                    {
                        if (p[i] < pmin)
                            index = i, pmin = p[i];
                    }
                }
            }
            // for (int i = 0; i < n; i++)
            // {
            //     cout << distance[i] << " ";
            // }
            // cout << endl;
            if (index == t)
            {
                break;
            }
            visit[index] = 1;
            temp--;
            for (int i = 0; i < n; i++)
            {
                if (edge[index][i][0] != INT_MAX && !visit[i])
                {
                    if (distance[index] + edge[index][i][0] < distance[i])
                    {
                        distance[i] = distance[index] + edge[index][i][0];
                        p[i] = p[index] + edge[index][i][1];
                    }
                    else if (distance[i] == distance[index] + edge[index][i][0])
                    {
                        if (p[index] + edge[index][i][1] < p[i])
                        {
                            p[i] = p[index] + edge[index][i][1];
                        }
                    }
                }
            }
        }
        cout << distance[t] << " " << p[t] << endl;
    }

    return 0;
}