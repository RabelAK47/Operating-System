#include "bits/stdc++.h"
using namespace std;

int Allocation[2000][2000], Max[2000][2000], Need[2000][2000];
int total_resource[2000], Available[2000], work[2000];
int process, resource;
bool Finish[2000];

void scan_allocation()
{
    for(int i = 0; i < process; i++)
    {
        for(int j = 0; j < resource; j++)
        {
            scanf("%d", &Allocation[i][j]);
        }
    }
}

void scan_max_matrix()
{
    for(int i = 0; i < process; i++)
    {
        for(int j = 0; j < resource; j++)
        {
            scanf("%d", &Max[i][j]);
        }
    }
}

void scan_total_resource()
{
    for(int i = 0; i < resource; i++)
    {
        scanf("%d", &total_resource[i]);
    }
}

void calculate_available()
{
    for(int i = 0; i < resource; i++)
    {
        int sum = 0;
        for(int j = 0; j < process; j++)
        {
            sum += Allocation[j][i];
        }
        Available[i] = total_resource[i]-sum;
    }
}

void calculate_need_matrix()
{
    for(int i = 0; i < process; i++)
    {
        for(int j = 0; j < resource; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

void set_Finish()
{
    for(int i = 0; i < process; i++)
    {
        Finish[i] = false;
    }
}

void set_initial_work()
{
    for(int i = 0; i < resource; i++)
    {
        work[i] = Available[i];
    }
}

void apply_bankers()
{
    int len = 0, Safe[process];
    bool flag = true;

    while(len < process)
    {
        bool found = false;
        for (int i = 0; i < process; i++)
        {
            if (Finish[i] == false)
            {
                int Count = 0;
                for (int j = 0; j < resource; j++)
                {
                    if (Need[i][j] <= work[j])
                        Count++;
                }

                if (Count == resource)
                {
                    for (int k = 0; k < resource; k++)
                    {
                        work[k] += Allocation[i][k];
                    }

                    Safe[len++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "System is not in safe state\n";
            flag = false;
            break;
        }
    }

    if(flag == true)
    {
        printf("Safe sequence is: ");
        for(int i = 0; i < process; i++)
        {
            printf("P%d, ", Safe[i]);
        }
        printf("\n");
    }
}

int main()
{
    // number_process, number_resource for allocation matrix
    // Allocation Matrix, Max Matrix, Total Resource

    freopen("bankers_input.txt", "r", stdin);
    scanf("%d %d", &process, &resource);

    scan_allocation();
    scan_max_matrix();
    scan_total_resource();

    calculate_available();
    calculate_need_matrix();

    set_initial_work();

    apply_bankers();

}

/*
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
10 5 7
*/
