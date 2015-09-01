#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int find_shortest(map<int, vector<int> > &toward, int src, int dest, int depth, vector<int> visited);

int main()
{
    int n;
    cin >> n;

    for( ; n-- ; )
    {
        map<int, vector<int> > toward;
        vector<int> nodes;

        for(int a, b; cin >> a >> b, a && b; )
        {
            toward[a].push_back(b);

            if(find(nodes.begin(), nodes.end(), a) == nodes.end())
            {
                nodes.push_back(a);
            }

            if(find(nodes.begin(), nodes.end(), b) == nodes.end())
            {
                nodes.push_back(b);
            }
        }

        int sum_all_shortest = 0;

        for(int src_index = 0; src_index < nodes.size(); src_index++)
        {
            int src = nodes[src_index];

            if(toward.find(src) == toward.end())
            {
                continue;
            }

            for(int dest_index = 0; dest_index < nodes.size(); dest_index++)
            {
                int dest = nodes[dest_index];

                // source dngn destination node xleh sama
                if(src == dest) continue;

                // add node pertama sbgai visited node
                vector<int> visited;
                visited.push_back(src);

                int a = find_shortest(toward, src, dest, 1, visited);

                sum_all_shortest += a;
            }
        }

        cout << "Case " << n + 1 << " : " << (float)sum_all_shortest / nodes.size() << " degrees" endl;
    }
}

int find_shortest(map<int, vector<int> > &toward, int src, int dest, int depth, vector<int> visited)
{
    vector<int> each_vec = toward[src];
    int shortest = 1 << 30;

    for(int node_index = 0; node_index < each_vec.size(); node_index++)
    {
        int node = each_vec[node_index];

        // klau dh pernah visit node nie, x perlu lagi nk visit sekali lagi
        if(find(visited.begin(), visited.end(), node) != visited.end())
        {
            continue;
        }
        else if(node == dest)
        {
            return depth;
        }
        else
        {
            visited.push_back(node);

            int ret = find_shortest(toward, node, dest, depth + 1, visited);
            shortest = (ret > 0 && ret < shortest) ? ret : shortest;
        }
    }

    return (shortest == (1 << 30)) ? 0 : shortest;
}
