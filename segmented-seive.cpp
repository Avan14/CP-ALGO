#include <iostream>
#include <vector>
using namespace std;

bool seive[100001];

void segemnted_seive(int l, int r)
{
    for (int i = 2; i < 100001; i++)
    {
        seive[i] = 1;
    }
    for (int i = 2; i * i < 100001; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j < 100001; j += i)
            {
                seive[j] = 0;
            }
        }
    }
    int size = r - l + 1;
    int dummy[100001];
    for (int i = 0; i < size; i++)
    {
        dummy[i] = 1;
    }
    for (int i = 2; i * i <= r; i++)
    {
        if (seive[i])
        {
            int initial = (l / i) * i;
            if (initial < l)
            {
                initial += i;
            }
            initial = max(i * i, initial);
            for (int j = initial - l; i < size; j += i)
            {
                dummy[j] = 0;
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}