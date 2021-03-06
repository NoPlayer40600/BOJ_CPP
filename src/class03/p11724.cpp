#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

int main(void)
{
    std::map<int, std::vector<int> *> graph;
    int n = 0, v = 0;
    scanf("%d %d", &n, &v);
    for (int loop = 1; loop <= n; loop++)
        graph.insert(std::make_pair(loop, new std::vector<int>()));
    for (int loop = 0, a = 0, b = 0; loop < v; loop++)
    {
        scanf("%d %d", &a, &b);
        bool af = false, bf = false;
        for (auto it : graph)
            if (it.first == a)
            {
                it.second->push_back(b);
                af = true;
            }
            else if (it.first == b)
            {
                it.second->push_back(a);
                bf = true;
            }
            else if (af && bf == true)
                break;
    }
    std::vector<int> visited;
    std::queue<int> queued;
    int c = 0;
    for (int loop = 1; loop <= n; loop++)
    {
        if (std::find(visited.begin(), visited.end(), loop) != visited.end())
            continue;
        queued.push(loop);
        while (!queued.empty())
        {
            int node = queued.front();
            queued.pop();
            if (std::find(visited.begin(), visited.end(), node) == visited.end())
            {
                visited.push_back(node);
                std::vector<int> *list = graph.find(node)->second;
                for (auto it : *list)
                    queued.push(it);
            }
        }
        c++;
    }
    printf("%d\n", c);
}