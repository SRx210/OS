#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAX 10
using namespace std;

class BankersAlgorithm {
public:
    int n, m, count = 0, k = 0;
    int p[MAX], available[MAX], work[MAX], finish[MAX], sequence[MAX];
    int allocation[MAX][MAX], maxx[MAX][MAX], need[MAX][MAX], request[MAX];

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
                cout << "Max of R" << (j + 1) << ": ";
                cin >> maxx[i][j];
            }
        }

        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout << "Available R" << (j+1) << ": ";
            cin >> available[j];
        }

        // Compute the need matrix
        compute_need_matrix();
    }

    void compute_need_matrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                need[i][j] = maxx[i][j] - allocation[i][j];
            }
        }

        cout << "Need Matrix\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << need[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void safe_sequence() {
        fill(finish, finish + n, 0);
        copy(available, available + m, work);
        count = 0;
        k = 0;

        while (count < n) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (finish[i] == 0) {
                    bool canFinish = true;
                    for (int j = 0; j < m; j++) {
                        if (need[i][j] > work[j]) {
                            canFinish = false;
                            break;
                        }
                    }

                    if (canFinish) {
                        for (int j = 0; j < m; j++) {
                            work[j] += allocation[i][j];
                        }
                        finish[i] = 1;
                        sequence[k++] = i;
                        count++;
                        found = true;
                    }
                }
            }
            if (!found) break;
        }

        if (count == n) {
            cout << "The safe sequence is as follows: { ";
            for (int i = 0; i < n; i++) {
                cout << "P" << (sequence[i] + 1);
                if (i < (n - 1)) {
                    cout << ", ";
                }
            }
            cout << " }\n";
        } else {
            cout << "It's a deadlock" << endl;
        }
    }

    void resource_request() {
        int process;
        cout << "Enter the process which is requesting: ";
        cin >> process;
        process--;

        if (process < 0 || process >= n) {
            cout << "The process doesn't exist." << endl;
            return;
        }

        cout << "Enter the request: \n";
        for (int i = 0; i < m; i++) {
            cout << "R" << (i+1) << ": ";
            cin >> request[i];
        }

        bool validRequest = true;
        for (int i = 0; i < m; i++) {
            if (request[i] > need[process][i]) {
                cout << "Request cannot be granted: Request exceeds maximum claim." << endl;
                validRequest = false;
                break;
            }
            if (request[i] > available[i]) {
                cout << "Request cannot be granted: Request exceeds available resources." << endl;
                validRequest = false;
                break;
            }
        }

        if (validRequest) {
            for (int j = 0; j < m; j++) {
                need[process][j] -= request[j];
                available[j] -= request[j];
                allocation[process][j] += request[j];
            }

            // Check for safe state after the request
            int workCopy[MAX];
            copy(available, available + m, workCopy);
            fill(finish, finish + n, 0);
            count = 0;
            k = 0;

            while (count < n) {
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (finish[i] == 0) {
                        bool canFinish = true;
                        for (int j = 0; j < m; j++) {
                            if (need[i][j] > workCopy[j]) {
                                canFinish = false;
                                break;
                            }
                        }
                        if (canFinish) {
                            for (int j = 0; j < m; j++) {
                                workCopy[j] += allocation[i][j];
                            }
                            finish[i] = 1;
                            count++;
                            found = true;
                        }
                    }
                }
                if (!found) break;
            }

            if (count == n) {
                cout << "Request can be granted!\n" << endl;

                cout << "\nUpdated Need Matrix: \n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << need[i][j] << "\t";
                    }
                    cout << endl;
                }
                cout << "\nUpdated Allocation Matrix: \n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        cout << allocation[i][j] << "\t";
                    }
                    cout << endl;
                }
                cout << "\nUpdated Available Resources: \n";
                for (int j = 0; j < m; j++) {
                    cout << available[j] << "\t";
                }
                cout << endl;
            } else {
                for (int j = 0; j < m; j++) {
                    need[process][j] += request[j];
                    available[j] += request[j];
                    allocation[process][j] -= request[j];
                }
                cout << "Request cannot be granted: System would enter an unsafe state." << endl;
            }
        }
    }
};

int main() {
    BankersAlgorithm b;
    b.input();
    b.safe_sequence();
    b.resource_request();
    return 0;
}
