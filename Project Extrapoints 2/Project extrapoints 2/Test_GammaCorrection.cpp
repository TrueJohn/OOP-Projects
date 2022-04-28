#include "Test_GammaCorrection.h"
#include <cassert>
void Test_GammaCorrection::Test_all()
{
    assert(Test_GammaCorrection_default_constructor() == true);
    assert(Test_GammaCorrection_constructor() == true);
    assert(Test_GammaCorrection_process() == true);

}

bool Test_GammaCorrection::Test_GammaCorrection_default_constructor()
{
    GammaCorrectionProcessor processor;

    assert(processor.gamma == 1);

    return true;
}

bool Test_GammaCorrection::Test_GammaCorrection_constructor()
{
    GammaCorrectionProcessor processor(2);

    assert(processor.gamma == 2);

    return true;
}

bool Test_GammaCorrection::Test_GammaCorrection_process()
{
    Image image1 = Image::generateFilled(5,5,2), image2;

    GammaCorrectionProcessor processor(2);

    processor.filter(image1, image2);

    assert(image2.at(0, 1) == 4);

    return true;

}
