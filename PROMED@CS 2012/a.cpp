#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int validate_input(char input[])
{
    int bool_zul[30] = {0}, len = strlen(input);

    for(int i = 0; i < len; i++)
    {
    	int index = input[i] - 'A';

        // 1. check jika setiap characters dlm string 'input' mengandungi bukan uppercase character (A-Z)
        // 2. check jika character dh wujud dalam array -> O(1) performance
        if(!isupper(input[i]) || bool_zul[index] == 1)
        {
            return 0;
        }
        else bool_zul[index] = 1;
    }

    return len > 2 && len < 27;
}

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)
    
    int n;
    char input[1000];
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        cin.getline(input, 1000);
        cout << "Case #" << i << ": " << (validate_input(input) ? "VALID" : "INVALID") << '\n';
    }
}
