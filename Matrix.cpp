#include <iostream>
#include <cmath> 

using namespace std;

void gaussJordanElimination(float A[10][10], int n) {
    float ratio;
    int i, j, k;

    
    for (i = 0; i < n; i++) {
        if (fabs(A[i][i]) < 1e-8) {
            return; 
        }
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            ratio = A[j][i] / A[i][i]; 
            for (k = 0; k <= n; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    
    float x[n]; 
    for (i = n - 1; i >= 0; i--) {
        x[i] = A[i][n] / A[i][i];
        for (j = i + 1; j < n; j++) {
            x[i] -= x[j] * A[i][j];
        }
    }

   
    cout << endl << "Solution: " << endl;
    for (i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of unknowns: ";
    cin >> n;

    float A[10][10];
    cout << "Enter Coefficients of Augmented Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    gaussJordanElimination(A, n);

    return 0;
}