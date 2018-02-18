#pragma once
#include <armadillo>
using namespace arma;

class Kalman
{
private:
    mat A, H, Q, R, xest, pest;
    double dt;
    int nvar;

public:
    Kalman(int n);
    ~Kalman();
    mat estimate(const mat & Z);
};

