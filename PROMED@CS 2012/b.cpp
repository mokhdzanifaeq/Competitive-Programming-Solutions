#include <iostream>
#include <cstring>
#define MAX 100000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)
    
    int n, len;
    char input[MAX];

    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        cin.getline(input, MAX);
        len = strlen(input);

        if(len >= 101 && len <= 65534)
        {
            int count_block = 0, state = 0;

            for(int z = 0; z < len; z++)
            {
                if(input[z] == '1' && state == 0)
                {
                    count_block++;
                    state++;
                }
                else if(input[z] == '0')
                {
                    state = 0;
                }
            }

            cout << "Case #" << i << ": " << count_block << '\n';
        }
        else
        {
            cout << "Case #" << i << ": -1" << '\n';
        }
    }
}
