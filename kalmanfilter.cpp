// kalmanfilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include "Kalman.h"

#include <iostream>

#define _USE_MATH_DEFINES

int _tmain(int argc, _TCHAR* argv[])
{
    Kalman K(2);
    mat s(1000, 2);
    s.randn(); 

    mat Z = mat(1000, 2).zeros() + .1*s;
    for (int i = 0; i < 1000; i++)
    {
        Z(i, 1) = sin(i*3.14 / 2000.0);
        Z(i, 0) = i / 1000.0;
    }
    std::cout << Z << std::endl;
    mat Y = K.estimate(Z);
    std::cout << Y << std::endl;

    return (0);
}

