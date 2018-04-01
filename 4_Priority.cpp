#include "bits/stdc++.h"
using namespace std;

struct myStruct
{
    string Process;
    int Burst_Time;
    int Priority;
};

bool cmp(myStruct a, myStruct b)
{
    if(a.Priority == b.Priority)
        return a.Process > b.Process ? 0 : 1;
    return a.Priority > b.Priority ? 0 : 1;
}

int main()
{
    freopen("priority_input.txt", "r", stdin);
    int num_process;
    cin >> num_process;

    struct myStruct obj[120];

    for(int i = 0; i < num_process; i++)
    {
        cin >> obj[i].Process;
        cin >> obj[i].Burst_Time;
        cin >> obj[i].Priority;
    }
    sort(obj, obj+num_process, cmp);

    for(int i = 0; i < num_process; i++)
    {
        cout << obj[i].Process << "\t";
    }
    cout << endl;
    int sum = 0;
    double avg_sum = 0;
    for(int i = 0; i < num_process; i++)
    {
        avg_sum += sum;
        cout << sum << "\t";
        sum += obj[i].Burst_Time;
    }
    cout << sum << endl << endl;
    cout << "Average Time = " << avg_sum/num_process << endl;

}

/*
3
P1 24 2
P2 3 1
P3 3 2
*/
