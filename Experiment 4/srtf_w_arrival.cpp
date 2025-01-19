#include<iostream>
#include<iomanip>
#define MAX 10
using namespace std;

class srtf
{
    public:
            int n, t = 0, count = 0, small, ct;
            int p[MAX], bt[MAX], at[MAX], rem_bt[MAX], wt[MAX], tt[MAX];
            float avg_wt = 0, avg_tt = 0;

    void input()
    {
        cout << "Enter number of process(es): ";
        cin >> n;
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
        rem_bt[n] = 999;
        for(t=0; count!=n; t++)
        {
            small = n;
            for(int i=0; i<n; i++)
            {
                if((at[i] < t) && (rem_bt[i] > 0) && (rem_bt[i] < rem_bt[small]))
                {
                    small = i;
                }
            }

            rem_bt[small]--;

            if(rem_bt[small] == 0)
            {
                ct = t + rem_bt[small];
                wt[small] = ct - at[small] - bt[small];
                tt[small] = wt[small] + bt[small];
                avg_wt = avg_wt + wt[small];
                avg_tt = avg_tt + tt[small];
                count++;
            }

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
    srtf obj1;
    obj1.input();
    obj1.compute();
    obj1.display();

    return 0;
}
