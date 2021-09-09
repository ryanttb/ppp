#include <stdio.h>

int main()
{
    int i = 0;

    while (i < 100) {

        int sq = i*i;
        printf("%d\t%d\n", i, sq);
        ++i;
    }

    return 0;
}
