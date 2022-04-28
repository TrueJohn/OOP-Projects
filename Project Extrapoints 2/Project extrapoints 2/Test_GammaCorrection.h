#pragma once
#include "GammaCorrection.h"

class Test_GammaCorrection{

public:

    friend class GammaCorrection;

    void Test_all();


private:


    bool Test_GammaCorrection_default_constructor();

    bool Test_GammaCorrection_constructor();

    bool Test_GammaCorrection_process();



};