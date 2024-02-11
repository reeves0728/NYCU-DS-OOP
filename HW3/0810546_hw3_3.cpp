#include <iostream>
#include <queue>
#define MAXN 200
using namespace std;

int g[MAXN][MAXN];
int color[MAXN];

int main()
{
    int n, m, u, v;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                g[i][j] = 0;
            }
            color[i] = -1;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool BICOLORABLE = true;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int nxt = 0; nxt < n; nxt++)
            {
                if (g[now][nxt] == 0)
                    continue;
                if (color[nxt] != -1)
                {
                    if (color[nxt] != color[now])
                        continue;
                    else
                    {
                        BICOLORABLE = false;
                        break;
                    }
                }
                else
                {
                    color[nxt] = color[now] ^ 1;
                    q.push(nxt);
                }
            }
            if (!BICOLORABLE)
                break;
        }
        if (!BICOLORABLE)
            cout << "NOT BICOLORABLE.\n";
        else
            cout << "BICOLORABLE.\n";
    }
}