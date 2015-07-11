#include <iostream> // cin, cout
#include <cmath> // hypotf
#include <cfloat> // FLT_MAX

#define EPSILON 0.0000000001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)
    
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        int customer[2], x, y, nearestx, nearesty;
        float min_dist = FLT_MAX; // ;)
        cin >> customer[0] >> customer[1];

        for(x = y = 0; x != 10001 && y != 10001; cin >> x >> y)
        {
            float calc_dist = hypotf(x - customer[0], y - customer[1]);

            if(calc_dist < min_dist)
            {
                nearestx = x, nearesty = y;
                min_dist = calc_dist;
            }
            else if(fabs(calc_dist - min_dist) < EPSILON) // floating number comparison "equal" kena pakai epsilon
            {
                if(y > nearesty || (y == nearesty && x > nearestx)) // checking priority
                {
                    nearestx = x, nearesty = y;
                }
            }
        }

        cout << "Case " << i << ": " << nearestx << " " << nearesty << '\n';
    }
}
