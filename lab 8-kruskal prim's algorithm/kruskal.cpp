#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000;
vector<pair<long long, pair<int, int>>> connections;
int edges, nodes, id[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        id[i] = i;
    }
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void join(int x, int y)
{
    id[root(x)] = id[root(y)];
}

int kruskal(vector<pair<long long, pair<int, int>>> c)
{
    int x, y, weight, minimumWeight = 0;
    for (int i = 0; i < edges; i++)
    {
        x = c[i].second.first;
        y = c[i].second.second;
        weight = c[i].first;
        if (root(x) != root(y))
        {
            minimumWeight += weight;
            join(x, y);
        }
    }
    return minimumWeight;
}

int main()
{
    int x, y, weight;
    init();
    cout << "Enter number of nodes and edges" << endl;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter X, Y and weight of edge:" << endl;
        cin >> x >> y >> weight;
        connections.push_back(make_pair(weight, make_pair(x, y)));
    }
    sort(&connections[0], &connections[edges]);
    int minimumCost = kruskal(connections);
    cout << "The minimum cost is: " << minimumCost;
}