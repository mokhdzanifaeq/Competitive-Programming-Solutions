#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    char str[8][5] = { "MMM", "GMM", "MGM", "MMG", "MGG", "GMG", "GGM", "GGG" };

    for(cin >> n, cin.ignore(); n-- ; )
    {
        int count[8] = {0};

        char input[200], *substr;
        cin.getline(input, 200);

        for(int piece = strlen(input) / 3, i = 0; i < piece; i++)
        {
            substr = &input[i * 3];

            for(int z = 0; z < 8; z++)
            {
                if(str[z][0] == substr[0] && str[z][1] == substr[1] && str[z][2] == substr[2])
                {
                    count[z]++;
                    break;
                }
            }
        }

        for(int i = 0; i < 8; i++)
        {
            cout << count[i];
        }

        cout << endl;
    }
}
