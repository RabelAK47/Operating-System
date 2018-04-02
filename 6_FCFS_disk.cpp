#include "bits/stdc++.h"
using namespace std;

int main()
{
    freopen("FCFS_disk_input.txt", "r", stdin);
    int num_io, initial_block, sum  = 0;
    scanf("%d %d", &num_io, &initial_block);

    int io_block[10000], ans[10000];
    for(int i = 0; i < num_io; i++)
    {
        scanf("%d", &io_block[i]);
    }

    for(int i = 0; i < num_io; i++)
    {
        ans[i] = abs(initial_block-io_block[i]);
        initial_block = io_block[i];
    }

    printf("\nEach Difference\t");
    for(int i = 0; i < num_io; i++)
    {
        printf("%d ", ans[i]);
        sum += ans[i];
    }
    printf("\n");
    printf("Average Waiting Time %d\n", sum/num_io);

}

/*
8 53
98 183 37 122 14 124 65 67
*/
