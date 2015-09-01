#include <iostream> // cin, cout
#include <map> // map<> container
#include <cstdlib> // qsort, malloc
#include <cfloat> // FLT_MAX
#include <cmath> // hypotf
#include <algorithm> // swap

#define endl '\n' // for performance, as 'endl' flush the stream, so we ended up with serious performance issue
#define MIN_SHORTEST(X,Y) ((X.dist) < (Y.dist)) ? (X) : (Y) // for finding min distance Coordinate struct

using namespace std;

/* For holding coordinate and state code */
typedef struct coordinate
{
    int x, y, code;
    char state;
}
Coordinate;

/* For holding shortest distance, with their first and second node */
typedef struct shortest
{
    Coordinate first, second;
    float dist;
}
Shortest;

/* Used by qsort, for sorting by X coordinate */
int cmp_x(const void *aptr, const void *bptr)
{
    int a = ((Coordinate *)aptr)->x, b = ((Coordinate *)bptr)->x;
    return (a > b) - (a < b);
}

/* Used by qsort, for sorting by Y coordinate */
int cmp_y(const void *aptr, const void *bptr)
{
    int a = ((Coordinate *)aptr)->y, b = ((Coordinate *)bptr)->y;
    return (a > b) - (a < b);
}

Shortest bruteforce(Coordinate P[], int start, int end)
{
    Shortest s;
    s.dist = FLT_MAX;

    for(int i = start; i <= end; i++)
        for(int j = i+1; j <= end; j++)
        {
            // if same state, then ignore this loop
            if(P[i].state == P[j].state) continue;

            float calc_dist = hypotf(P[i].x - P[j].x, P[i].y - P[j].y);

            if(calc_dist < s.dist)
            {
                s.first = P[i], s.second = P[j];
                s.dist = calc_dist;
            }
        }

    return s;
}

Shortest stripClosest(Coordinate strip[], int size, float d)
{
    Shortest s;
    s.dist = d;

    qsort(strip, size, sizeof(Coordinate), cmp_y);

    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size && (strip[i].y - strip[j].y) < s.dist; j++)
        {
            // if same state, then ignore this loop
            if(strip[i].state == strip[j].state) continue;

            float calc_dist = hypotf(strip[i].x - strip[j].x, strip[i].y - strip[j].y);

            if(calc_dist < s.dist)
            {
                s.first = strip[i], s.second = strip[j];
                s.dist = calc_dist;
            }
        }

    return s;
}

Shortest closest(Coordinate P[], int start, int end)
{
    int size_segment = (end - start) + 1;

    // this is base case for recursive call
    // if size of left or right segment is below or eq to 10, then use bruteforce approach
    if(size_segment <= 10)
        return bruteforce(P, start, end);

    // get the midpoint of array, so its easier to cut array to half later
    int mid = (start + end) / 2;

    Shortest dl, dr, d, strip_short;

    // find shortest pair of point inside left and right segment recursively
    // this involving cut the array into half, and solve it using divide & conquer approach
    dl = closest(P, start, mid);
    dr = closest(P, mid+1, end);

    // find minimum shortest pair of point between left and right
    d = MIN_SHORTEST(dl, dr);

    // use heap as storage, i dont know why i choosed this method instead storing it inside stack
    Coordinate *strip = (Coordinate *)malloc(sizeof(Coordinate) * size_segment);

    int j = 0;

    // so how if the shortest pair of point isn't inside left || right half?
    // maybe its the pair that cut the midpoint?
    // so here we're finding points thats have lower distance than current min (left || right) distance
    for(int i = start; i <= end; i++)
        if(abs(P[i].x - P[mid].x) < d.dist)
            strip[j++] = P[i];

    strip_short = stripClosest(strip, j, d.dist);

    // free the heap, to avoid memory leak problem
    free(strip);

    // hackkk :(
    return (d.dist != strip_short.dist) ? MIN_SHORTEST(d, strip_short) : d;
}

/* Declared as global var, cuz i'm paranoid at storing large array inside stack :( */
Coordinate uni[100000];

int main()
{
    ios_base::sync_with_stdio(0); // tq asdacap :)

    int T; // number of test cases
    cin >> T;
    cin.ignore();

    for(int i = 1; i <= T; i++)
    {
        int N; // number of universities
        cin >> N;
        cin.ignore();

        map<char, int> state_count;

        for(int z = 0; z < N; z++)
        {
            uni[z].code = z+1; // university code is using array index+1

            cin >> uni[z].x >> uni[z].y >> uni[z].state;
            state_count[uni[z].state]++; // for counting number of universities in each states
        }

        if(state_count.size() <= 1) // if only 1 state available in input, then return "NO SOLUTION"
        {
            cout << "Case #" << i << ": NO SOLUTION" << endl;
        }
        else
        {
            // C standard func is still gold to use ;)
            // O(n log n) worst case for quick sort algorithm
            qsort(uni, N, sizeof(Coordinate), cmp_x);

            // here is the magic :)
            // return Shortest s, containing all infos we needed
            Shortest s = closest(uni, 0, N-1);

            // sorting output, first one must lower than second one
            if(s.first.state > s.second.state)
            {
                swap(s.first, s.second);
            }

            cout << "Case #" << i << ": "
                 << s.first.code << " " << s.first.state << " "
                 << s.second.code << " " << s.second.state << endl;
        }
    }
}
