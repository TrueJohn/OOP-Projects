#include <iostream>
#include "Brush.h"
#include "Image.h"
#include "Image_Filters.h"
#include "Test_ALL.h"

using std::cout;


void Tests() {
    Test_Size t1;
    t1.Test_all();
    Test_Point t2;
    t2.Test_all();
    Test_Rectangle t3;
    t3.Test_all();
    Test_Brightness_and_Contrast t4;
    t4.Test_all();
    Test_GammaCorrection t5;
    t5.Test_all();
    Test_Image t6;
    t6.Test_all();
    Test_Vector2D t7;
    t7.Test_all();
}
int main() {

    Tests();

    Image t1, t2,t3,t4,t5,t6,t7;
    
    t1.load("test2.ascii.pgm");
    t2 = t1;
   
   
    t2=t2+100;
    t2.save("test2_modified.pgm");

    t3 = t1 - 100;
    t3.save("test3_modified.pgm");

    t4 = t1 * 4;
    t4.save("test4_modified.pgm");


    BrightnessContrastFilter b1;

    b1.filter(t1, t5);
    t5.save("test5_modified.pgm");

    GammaCorrectionProcessor g1;
    
    g1.filter(t1, t6);
    t6.save("test6_modified.pgm");

    ConvolutionProcessor con1(ConvolutionType::VERTICAL_SOBEL);
    con1.filter(t1, t7);
    t7.save("test7_modified.pgm");

    t1.release();
    t2.release();
    t3.release();
    t4.release();
    t4.release();
    t5.release();
    t6.release();

    Image img3(25, 25);

    Draw::drawLine(img3, Point(15, 2), Point(15, 8), 7);
    
    std::cout << "---------------------------------------------------------------------";
    std::cout<<img3;

    Draw::drawCircle(img3, Point(5, 5),4,10);
  
    std::cout << "---------------------------------------------------------------------";
    std::cout << img3;

    Draw::drawRectangle(img3, Rectangle(10, 10, 10, 10), 20);
    std::cout << "---------------------------------------------------------------------";
    std::cout << img3;

  
    
    return 0;
}