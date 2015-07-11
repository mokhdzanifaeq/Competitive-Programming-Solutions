#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)
    
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        int input, even = 0, odd = 0, mixed = 0;

        for(cin >> input, pow(input, 3); input > 0; input /= 10)
        {
            int num = (input % 10) % 2;

            if((even && num) || (odd && !num))
            {
                mixed++;
                break;
            }

            !num ? even++ : odd++;
        }

        cout << "Case #" << i << ": " << (mixed ? "MIXED" : (odd ? "ODD" : "EVEN")) << '\n';
    }
}
