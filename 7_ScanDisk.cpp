#include "bits/stdc++.h"
using namespace std;

int num_io, initial_block, moving, sum = 0;
int io_blocks[10000], head_loc;;

void display_toZero()
{
    for(int i = head_loc; i >= 0; i--)
    {
        printf("%d ", io_blocks[i]);
    }
    printf("0 ");
    for(int i = head_loc+1; i < num_io; i++)
    {
        printf("%d ", io_blocks[i]);
    }
    printf("199\n");
}

void display_to199()
{
    for(int i = head_loc; i < num_io; i++)
    {
        printf("%d ", io_blocks[i]);
    }
    printf("199 ");
    for(int i = head_loc-1; i >= 0; i--)
    {
        printf("%d ", io_blocks[i]);
    }
    printf("0\n");
}

int main()
{
    freopen("scan_disk_input.txt", "r", stdin);
    scanf("%d %d %d", &num_io, &initial_block, &moving);

    io_blocks[0] = initial_block;
    num_io++;
    for(int i = 1; i < num_io; i++)
    {
        scanf("%d", &io_blocks[i]);
    }

    sort(io_blocks, io_blocks + num_io);


    for(int i = 0; i < num_io; i++)
    {
        if(io_blocks[i] == initial_block)
        {
            head_loc = i;
            break;
        }
    }

    printf("Output\n");
    if(moving == 0)
    {
        display_toZero();
    }

    else if(moving == 199)
    {
        display_to199();
    }
}

/*
8 53 0
14 37 65 67 98 122 124 183
*/

/*
8 53 199
14 37 65 67 98 122 124 183
*/
