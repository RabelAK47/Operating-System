#include "bits/stdc++.h"
using namespace std;

struct myStruct
{
    string process;
    int time;
};

bool cmp(myStruct LHS, myStruct RHS)
{
    return LHS.time > RHS.time ? 0 : 1;
}

int main()
{
    freopen("SJF_input.txt", "r", stdin);
    struct myStruct data[1000];

    int num_process;
    scanf("%d", &num_process);

    for(int i = 0; i < num_process; i++)
    {
        cin >> data[i].process >> data[i].time;
    }

    sort(data, data + num_process, cmp);

    for(int i = 0; i < num_process; i++)
    {
        cout << data[i].process << "\t";
    }
    cout << endl;

    int sum = 0;
    double avgTime = 0;

    cout << "0\t";
    for(int i = 0; i < num_process; i++)
    {
        avgTime += sum;
        sum += data[i].time;
        cout << sum << "\t";
    }
    cout << endl;

    printf("\nAverage Waiting Time %0.3lf\n", avgTime/num_process);

}

/*
4
P1 6
P2 8
P3 7
P4 3
*/
