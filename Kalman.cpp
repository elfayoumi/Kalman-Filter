#include "stdafx.h"
#include "Kalman.h"
#include <ios>

Kalman::Kalman(int n) : dt(1.0),nvar(n) {
    //A.eye(6,6);
    //for (int i = 2; i < 3 * n ; i++){
    //    A[i- 2, i] = dt;
    //}
    //H.zeros(n, 3 * n);
    //for (int i = 0; i < n; i++)
    //{
    //    H[i, i] = 0;
    //}
    //
    //
    //Q.eye(6,6);
    //R = 1000 * eye(2,2);
    //xest.zeros(6, 1);
    //pest.zeros(6, 6);

    //std::cout << n << std::endl;
    
    A.eye(6, 6);
    A(0, 2) = A(1, 3) = dt;
    A(2, 4) = A(3, 5) = dt;
    H.zeros(2, 6);
    H(0, 0) = H(1, 1) = 1.0;
    Q.eye(6, 6);
    R = 1000 * eye(2, 2);
    xest.zeros(6, 1);
    pest.zeros(6, 6);
    std::cout << A << std::endl;
    std::cout << H << std::endl;


}

// sole member func.: estimate model
mat Kalman::estimate(const mat & Z) {
    unsigned int n = Z.n_rows,
        k = Z.n_cols;
    mat Y = zeros(n, k);
    mat xprd, pprd, S, B, kg;
    colvec z, y;
    for (unsigned int i = 0; i < n; i++) {
        z = Z.row(i).t();
        // predicted state and covariance
        xprd = A * xest;
        pprd = A * pest * A.t() + Q;
        // estimation
        S = H * pprd.t() * H.t() + R;
        B = H * pprd.t();
        kg = (solve(S, B)).t();
        // estimated state and covariance
        xest = xprd + kg * (z - H * xprd);
        pest = pprd - kg * H * pprd;
        // compute estimated measurements
        y = H * xest;
        Y.row(i) = y.t();
    }
    return Y;
}
Kalman::~Kalman()
{
}
