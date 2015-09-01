#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;

    for(cin >> n; n--; )
    {
        float a,b,c,d, at, bt, ct, dt;
        int status = 1, count = 0;

        cin >> a >> b >> c >> d;

        at = a, bt = b, ct = c , dt = d;

        b = (b / 60) * 12;
        d = (d / 60) * 12;

        for(int i = 0; status; a++, i++)
        {
            if(!i && a == c)
            {
                if(b < d && b < a && d > a) // 9 40 9 50
                {
                    count++;
                    break;
                }
                else if(b > d && b < a) count++;
            }
            else if(i && a == c)
            {
                if(d > c) count++;
                break;
            }
            else if(a >= 12) a = 0;
            else if(!i && b < a) count++;
            else if(i) count++;
        }

        printf("%.2d:%.2d %.2d:%.2d %d\n", (int)at, (int)bt, (int)ct, (int)dt, count);
    }
}
