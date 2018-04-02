#include "bits/stdc++.h"
using namespace std;

int num_io, init_head, io_blocks[10000];


int find_min(int num)
{
    int mini = INT_MAX, ind;
    for(int i = 0; i < num_io; i++)
    {
        if(io_blocks[i] != -1)
        {
            int temp = abs(num - io_blocks[i]);
            if(mini > temp)
            {
                mini = temp;
                ind = i;
            }
        }
    }
    return ind;
}


void Total_Cost()
{
    int num = init_head, Sum = 0;
    for(int i = 0; i < num_io; i++)
    {
        int ind = find_min(num);
        Sum += abs(num - io_blocks[ind]);
        num = io_blocks[ind];
        io_blocks[ind] = -1;
    }
    cout << "Total " << Sum << endl;
}

int main()
{
    freopen("sstf_input.txt", "r", stdin);

    scanf("%d %d", &num_io, &init_head);

    for(int i = 0; i < num_io; i++)
    {
        scanf("%d", &io_blocks[i]);
    }
    Total_Cost();
}
/*
8 53
98 183 37 122 14 124 65 67
*/

