#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    char str[200002];
    scanf("%s", str + 1);

    int ret = 0;
    for (int idx = N; idx >= 2; idx -= 2)
    {
        if (str[idx] == str[idx-1])
            continue;

        if (str[idx] == 'G' && ret % 2 == 1)
            ++ret;

        if (str[idx] == 'H' && ret % 2 == 0)
            ++ret;
    }

    printf("%d\n", ret);

    return 0;
}