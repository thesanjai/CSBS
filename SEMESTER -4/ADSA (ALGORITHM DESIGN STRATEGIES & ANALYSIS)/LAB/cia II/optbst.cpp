#include <iostream>
#include <limits>

using namespace std;

void OptimalBST(int Keys[], float P[], float Q[], int n) {
    float** C = new float*[n + 2]; // Cost Matrix
    float** W = new float*[n + 2]; // Weight Matrix
    int** R = new int*[n + 2]; // Root Matrix

    for (int i = 0; i <= n + 1; i++) {
        C[i] = new float[n + 2]{0};
        W[i] = new float[n + 2]{0};
        R[i] = new int[n + 2]{0};
    }

    // Calculate Weight Matrix
    for (int len = 1; len <= n + 1; len++) {
        for (int i = 0; i <= n + 1 - len; i++) {
            int j = i + len - 1;
            if (i == j)
                W[i][j] = Q[i];
            else
                W[i][j] = W[i][j - 1] + P[j] + Q[j];
        }
    }

    // Calculate Cost Matrix and Root Matrix
    for (int len = 1; len <= n + 1; len++) {
        for (int i = 0; i <= n + 1 - len; i++) {
            int j = i + len - 1;
            if (i == j) {
                C[i][j] = R[i][j] = 0;
            } else {
                float minCost = numeric_limits<float>::max();
                int minK = -1;
                for (int k = i + 1; k <= j; k++) {
                    float sum = C[i][k - 1] + C[k][j] + W[i][j];
                    if (sum < minCost) {
                        minCost = sum;
                        minK = k;
                    }
                }
                C[i][j] = minCost;
                R[i][j] = minK;
            }
        }
    }

    // Display Weight Matrix
    cout << "Weight Matrix (W):" << endl;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++) {
        	if(W[i][j]!=0)
            cout << W[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Display Cost Matrix
    cout << "Cost Matrix (C):" << endl;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i <= n + 1; i++) {
        delete[] C[i];
        delete[] W[i];
        delete[] R[i];
    }
    delete[] C;
    delete[] W;
    delete[] R;
}

int main() {
    int Keys[] = {10, 20, 30,40}; // Dummy keys as keys are not directly used in the calculation.
    float P[] = {0,3,3,1,1}; // Including a dummy 0 at start for 1-based indexing
    float Q[] = {2, 3,1,1,1}; // Extra probability for Q[n]
    int n = 4;

    OptimalBST(Keys, P, Q, n);

    return 0;
}

