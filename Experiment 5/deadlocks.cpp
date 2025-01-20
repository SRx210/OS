#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

class Deadlock {
public:
    int n, m, process;
    int p[MAX], available[MAX], work[MAX], finish[MAX], sequence[MAX];
    int allocation[MAX][MAX], request[MAX][MAX];


    void input() {
    cout << "Enter number of processes: ";
        cin >> n;

        cout << "Enter number of resources: ";
        cin >> m;

        for (int i = 0; i < n; i++) {
            cout << "\nProcess No.: ";
            cin >> p[i];
            for (int j = 0; j < m; j++) {
                cout << "Allocation of R" << (j + 1) << ": ";
                cin >> allocation[i][j];
            }
            for (int j = 0; j < m; j++) {
                cout << "Request of R" << (j + 1) << ": ";
                cin >> request[i][j];
            }
        }

        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout << "Available R" << (j+1) << ": ";
            cin >> available[j];
        }
    }

    void deadlock_detection() {
        fill(finish, finish + n, 0);
        copy(available, available + m, work);
        int count = 0, k = 0;

        while(count < n) {
            bool found = false;
            for(int i = 0; i < n; i++) {
                int check1 = 0;
                if(finish[i] == 0) {
                    for(int j = 0; j < m; j++) {
                        if(request[i][j] <= work[j]) {
                            check1++;
                        }
                    }
                    if(check1 == m) {
                        for(int j = 0; j < m; j++) {
                            work[j] += allocation[i][j];
                        }
                        finish[i] = 1;
                        sequence[k++] = i;
                        count++;
                        found = true;
                    }
                }
            }
            if(!found) break;
        }

        if(count == n) {
            cout << "The safe sequence is as follows: { ";
            for (int i = 0; i < n; i++) {
                cout << "P" << (sequence[i] + 1);
                if (i < (n - 1)) {
                    cout << ", ";
                }
            }
            cout << " }\n";
        } else {
            cout << "Deadlock Occurred!" << endl;
        }
    }
    int resource_request() {
        cout << "Enter the process which is requesting: ";
        cin >> process;
        process--;

        if(process < 0 || process >= n) {
            cout << "The process doesn't exist." << endl;
            return 0;
        }

        cout << "Enter the request: \n";
        for(int i = 0; i < m; i++) {
            cout << "R" << (i+1) << ": ";
            cin >> request[process][i];
        }
        return 1;
    }


};


int main() {
    Deadlock d;
    d.input();
    d.deadlock_detection();
    d.resource_request();
    d.deadlock_detection();

    return 0;
}
