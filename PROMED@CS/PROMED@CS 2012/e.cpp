#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)
    
    int n;
    char input[1000];

    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        int len, num_array[100], nArray = 0, cond = 1;
        cin >> len;

        cin.getline(input, 1000);

        char *tok = strtok(input, " ");

        while(tok)
        {
            num_array[nArray++] = strtol(tok, NULL, 10);
            tok = strtok(NULL, " ");
        }

        cout << "Case #" << i << ": |";

        for(int l = 0; cond ; )
        {
            for(int z = 0; cond && z < nArray; z++)
            {
                for(int x = 0; cond && x < num_array[z]; x++)
                {
                    cout << (!(z % 2) ? '_' : ' ');

                    if(++l >= len)
                    {
                        cond = 0;
                    }
                }
            }
        }

        cout << "|\n";
    }
}
