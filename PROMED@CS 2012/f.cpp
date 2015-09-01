#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        int ppl, inputppl, voucher, child = 0, adult = 0, senior = 0;
        cin >> ppl;

        for( ; ppl-- ; )
        {
            cin >> inputppl;

            if(inputppl >= 3 && inputppl <= 11) child++;
            else if(inputppl >= 12 && inputppl <= 59) adult++;
            else if(inputppl >= 60) senior++;
        }

        cin >> voucher;

        if(voucher)
        {
            if(adult >= child && voucher >= child)
                child -= child;
            else if(child >= adult && voucher >= child)
                child -= adult;
            else if(adult >= child && voucher <= child)
                child -= voucher;
        }

        printf("Case #%i: RM%.2f\n", i, (float)((child + senior) * 110 + adult * 140));
    }
}
