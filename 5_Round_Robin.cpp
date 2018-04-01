#include "bits/stdc++.h"
using namespace std;

vector <string> my_ans_pro, turn_arround_pro, all_process;
vector <int> my_ans_time, turn_arround_time, all_burst_time, wt;
int num_pro;
int tq;

void clear_all()
{
    all_process.clear();
    all_burst_time.clear();
    my_ans_pro.clear();
    turn_arround_pro.clear();
    my_ans_time.clear();
    turn_arround_time.clear();
    wt.clear();
}

void display_ganttchart()
{
    cout << "\n\nDisplaying GanttChart\n";
    cout << "  ";
    for(int i = 0; i < my_ans_pro.size(); i++)
    {
        cout << my_ans_pro[i] << "\t  ";
    }
    cout << endl;
    for(int i = 0; i < my_ans_time.size(); i++)
    {
        cout << my_ans_time[i] << "\t";
    }
    cout << "\n\n\n";
}


void display_turnarround_time()
{
    cout << "Displaying Turn Arround Time with Process\n\t";
    for(int i = 0; i < turn_arround_pro.size(); i++)
    {
        cout << turn_arround_pro[i] << "\t";
    }
    cout << "\n\t";
    for(int i = 0; i < turn_arround_time.size(); i++)
    {
        cout << turn_arround_time[i] << "\t";
    }
    cout << endl;
}


void findWaitingTime()
{
    vector <int> rem_bt = all_burst_time;

    int t = 0; // Current time
    while (true)
    {
        bool done = true;
        for (int i = 0 ; i < num_pro; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > tq)
                {
                    t += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt.push_back(t - all_burst_time[i]);
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}

void display_average_waiting_time()
{
    double wt_sum = 0;
    for(int i = 0; i < wt.size(); i++)
    {
        wt_sum += wt[i];
        cout << wt[i] << endl;
    }

    printf("Average Waiting Time is = %0.4lf\n", wt_sum/num_pro);
}

bool Check(queue <int> T)
{
    int size = T.size(), Count = 0;
    while(T.empty() == false)
    {
        int time = T.front();
        T.pop();
        if(time <= 0)
            Count++;
        if(Count >= size)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("Round_Robin_input.txt", "r", stdin);
    cin >> tq;
    cin >> num_pro;

    clear_all();

    queue <string> P;
    queue <int> T;
    for(int i = 0; i < num_pro; i++)
    {
        string pro;
        int burst_time;
        cin >> pro >> burst_time;
        all_process.push_back(pro);
        all_burst_time.push_back(burst_time);
        P.push(pro);
        T.push(burst_time);
    }

    int sum = 0, last_val;
    string last_pro;
//    cout << sum << " ";
    my_ans_time.push_back(sum);
    while(P.empty() == false && Check(T) == true)
    {
        string str = P.front();
        int time = T.front();
        int temp = time;

        if(time >= tq)
        {
            sum += tq;
            time -= tq;
        }
        else
        {
            turn_arround_pro.push_back(str);
            turn_arround_time.push_back(sum);
            //cout << str << " " << sum << endl;
            sum += time;
            time -= time;
        }

        my_ans_pro.push_back(str);
        my_ans_time.push_back(sum);
        last_pro = str;
        last_val = sum;

        P.pop();
        T.pop();
        if(time >= 1)
        {
            T.push(time);
            P.push(str);
        }
    }

    turn_arround_pro.push_back(last_pro);
    turn_arround_time.push_back(last_val);

    display_ganttchart();
    display_turnarround_time();

    findWaitingTime();
    display_average_waiting_time();

    //cout << last_pro << " " << last_val << endl;
}

/*
4
3
P1 24
P2 3
P3 3
*/

/*
2
3
P1 24
P2 3
P3 3
*/
