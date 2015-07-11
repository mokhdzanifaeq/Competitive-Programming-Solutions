#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        char input[10];
        int z, input_int[50], min_score = 101, max_score = -1, largest_gap = -1, gap, loop;

        cin >> loop;
        cin.ignore();

        for(z = 0; z < loop; z++)
        {
            cin >> input_int[z];
        }

        sort(input_int, input_int + loop);

        for(int z = 1; z < loop; z++)
        {
            gap = input_int[z] - input_int[z-1];
            if(largest_gap < gap) largest_gap = gap;
        }

        cout << "Class " << i << endl << "Max " << input_int[loop-1] << ", Min " << input_int[0] << ", Largest gap " << largest_gap << endl;
    }
}
