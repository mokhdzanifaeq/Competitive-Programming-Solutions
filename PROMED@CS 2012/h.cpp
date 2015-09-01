#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int isvowel(char input)
{
    switch(input)
    {
        case 'a': case 'e': case 'i':
        case 'o': case 'u': case 'A':
        case 'E': case 'I': case 'O':
        case 'U':
            return 1;
        default:
            return 0;
    }
}

int main()
{
    int n;
    char first[1000], second[1000];

    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        scanf("%s %s", first, second);
        int nFirst = strlen(first), nSecond = strlen(second), z, cond;

        if(cond = (nFirst == nSecond))
        {
            for(z = 0; z < nFirst; z++)
            {
                if(isvowel(first[z]) != isvowel(second[z]))
                {
                    cond = 0;
                    break;
                }
            }
        }

        cout << "Case #" << i << ": " << (cond ? "same" : "different") << '\n';
    }
}
