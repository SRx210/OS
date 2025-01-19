#include <iostream>
#include <iomanip>
#define MAX 10
using namespace std;

class RoundRobin
{
public:
    int n, ts, p[MAX], bt[MAX], at[MAX], rem_bt[MAX], wt[MAX], tt[MAX], t = 0;
    float avg_wt = 0, avg_tt = 0;

    void input()
    {
        cout << "Enter number of process(es): ";
        cin >> n;

        cout << "Enter Time Slice: ";
        cin >> ts;
        cout << "\n";
        for(int i=0; i<n; i++)
        {
            cout << "Process No.: ";
            cin >> p[i];

            cout << "Arrival Time: ";
            cin >> at[i];

            cout << "Burst Time: ";
            cin >> bt[i];
            rem_bt[i] = bt[i];

            cout<< "\n";
        }
    }

    void compute()
    {
        while (true)
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                if (rem_bt[i] > 0 && at[i] <= t)
                {
                    flag = false;
                    if (rem_bt[i] > ts)
                    {
                        t += ts;
                        rem_bt[i] -= ts;
                    }
                    else
                    {
                        t += rem_bt[i];
                        wt[i] = t - bt[i] - at[i];
                        rem_bt[i] = 0;
                    }
                }
            }
            if (flag)
                break;
        }


        for (int i = 0; i < n; i++)
        {
            tt[i] = bt[i] + wt[i];
            avg_wt += wt[i];
            avg_tt += tt[i];
        }
    }

    void display()
    {
        cout << "\n";
        cout << setw(15) << left << "Process";
        cout << setw(15) << left << "Arrival Time";
        cout << setw(15) << left << "Burst Time";
        cout << setw(15) << left << "Waiting Time";
        cout << setw(15) << left << "Turnaround Time" << endl;

        for(int i=0; i<n; i++)
        {
            cout << setw(15) << left << p[i];
            cout << setw(15) << left << at[i];
            cout << setw(15) << left << bt[i];
            cout << setw(15) << left << wt[i];
            cout << setw(15) << left << tt[i] << endl;
        }

        cout << "\nAverage Waiting Time = " << (avg_wt/n) << endl;
        cout << "Average Turnaround Time = " << (avg_tt/n) << endl;
    }
};

int main()
{
    RoundRobin obj;
    obj.input();
    obj.compute();
    obj.display();

    return 0;
}
