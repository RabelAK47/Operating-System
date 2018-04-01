#include "bits/stdc++.h"
using namespace std;

int main()
{
    freopen("FCFS_input.txt", "r", stdin);

    int num_process;
    scanf("%d", &num_process);

    vector <string> processVector;
    vector <int> timeVector;

    for(int i = 0; i < num_process; i++)
    {
        string process;
        int burstTime;
        cin >> process >> burstTime;
        processVector.push_back(process);
        timeVector.push_back(burstTime);
    }

    //printf("\t");
    for(int i = 0; i < num_process; i++)
    {
        cout << processVector[i] << "\t";
    }
    cout << "\n";

    printf("0\t");
    int sum = 0;
    double avgTime = 0;
    for(int i = 0; i < num_process; i++)
    {
        avgTime += sum;
        sum += timeVector[i];
        cout << sum << "\t";
    }
    cout << endl;

    printf("\nAverage waiting time %0.3lf\n", avgTime/num_process);
}
/*
3
P1 24
P2 3
P3 3
*/

