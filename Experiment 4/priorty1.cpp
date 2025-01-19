#include <iostream>
#include <iomanip>
#define MAX 10
using namespace std;

class PriorityScheduling
{
public:
    int n, t = 0, Count = 0, small, ct;
    int p[MAX], bt[MAX], remainingbt[MAX], wt[MAX], tt[MAX], At[MAX], priority[MAX];
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
            cin >> At[i];

            cout << "Burst Time: ";
            cin >> bt[i];
            remainingbt[i] = bt[i];

            cout << "Priority: ";
            cin >> priority[i];

            cout<< "\n";
        }
    }

    void compute()
    {
        while (Count != n)
        {
            small = n;
            for (int i = 0; i < n; i++)
            {
                if (At[i] <= t && remainingbt[i] > 0 && (small == n || priority[i] < priority[small]))
                {
                    small = i;
                }
            }

            if (small != n)
            {
                remainingbt[small]--;
                if (remainingbt[small] == 0)
                {
                    ct = t + 1;
                    wt[small] = ct - bt[small] - At[small];
                    tt[small] = wt[small] + bt[small];
                    Count++;
                }
            }
            else
            {
                t++;
            }
            t++;
        }

        for (int i = 0; i < n; i++)
        {
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
            cout << setw(15) << left << At[i];
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
    PriorityScheduling ps;
    ps.input();
    ps.compute();
    ps.display();
    return 0;
}
