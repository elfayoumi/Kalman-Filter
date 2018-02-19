========================================================================
    CONSOLE APPLICATION : kalmanfilter Project Overview
========================================================================

A simple implementation of Kalman Filter using Armadillo C++. Armadillo, is a useful library, that brings matlab to c++
The Kalman class is can be any dimension. 

kalmanfilter.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

kalmanfilter.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

kalmanfilter.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named kalmanfilter.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

example of projectile:

	Kalman K(2);
    mat s(1000, 2);
    s.randn(); 

    mat Z = mat(1000, 2).zeros() + .1*s;
    for (int i = 0; i < 1000; i++)
    {
        Z(i, 1) += sin(i*M_PI / 2000.0);
        Z(i, 0) += i / 1000.0;
    }
    std::cout << Z << std::endl;
    mat Y = K.estimate(Z);
    std::cout << Y << std::endl;
/////////////////////////////////////////////////////////////////////////////
