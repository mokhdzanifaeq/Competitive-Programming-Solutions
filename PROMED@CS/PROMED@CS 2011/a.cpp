#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, len;

    for(cin >> n; n-- ; )
    {
        char each[100];

        cin.ignore(); // ignore newline after inserting num of test cases

        while(true)
        {
            cin.getline(each, 100, ' ');

            len = strlen(each);

            if(len == 1 && each[0] == ';')
                break;

            while(len--)
                cout << '*';

            cout << endl;
        }
    }
}
