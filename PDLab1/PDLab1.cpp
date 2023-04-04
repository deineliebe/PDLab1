#include <iostream>

int calculateAccuracy(float error)
{
    int accuracy = 0;
    if (error > 1)
    {
        while (abs(error) >= 1)
        {
            error /= 10;
            accuracy++;
        }
    }
    else
    {
        while (abs(error) <= 1)
        {
            error *= 10;
            accuracy--;
        }
    }
    return accuracy;
}

void show(float number, int accuracy)
{
    if (accuracy > 0)
    {
        for (int i = 0; i < accuracy - 1; i++)
        {
            number /= 10;
        }
    }
    else
    {
        for (int i = 0; i > accuracy + 1; i--)
        {
            number *= 10;
        }
        number *= 10;
    }
    int temp = number;
    std::cout << temp / 10. << "*10^" << accuracy;
}

void showRelativeError(float number)
{
    int accuracy = calculateAccuracy(number);
    if (accuracy > -1) accuracy = 0;
    for (int i = 0; i > accuracy + 1; i--)
    {
        number *= 10;
    }
    int temp = number;
    if (accuracy) std::cout << temp / 10. << "*10^" << accuracy << "%";
    else std::cout << temp / 1. << "%";
}

//Functions for the first task
float exponentiation(float number, int degree)
{
    float temp = number;
    for (int i = 1; i < degree; i++)
    {
        temp *= number;
    }
    return temp;
}

void liftingForceExecution(float c, float a, float p, float v, float S, float rc, float ra, float rp, float av, float rS)
{
    float F = c * a * p * exponentiation(v, 2) * S;
    float rF = rc + ra + rp + (2*av/v) + rS;
    float aF = F * rF;
    float accuracy = calculateAccuracy(aF);
    std::cout << "Answer is ";
    show(F, accuracy);
    std::cout << ", absolute error is ";
    show(aF, accuracy);
    std::cout << ", relative error is ";
    showRelativeError(rF * 100);
}

//Functions for the second task
float sin(float x, float eps)
{
    double s = 0;
    double r = x;
    int n = 1;
    while (abs(r) > eps)
    {
        s = s + r;
        n = n + 2;
        r = -r * x * x / (n * (n - 1));
    }
    return s;
}

float cos(float x, float eps)
{
    double s = 0;
    double r = 1;
    int n = 2;
    while (abs(r) > eps)
    {
        s = s + r;
        n = n + 2;
        r = -r * x * x / (n * (n - 1));
    }
    return s;
    
}

void function(float a, float ra, float b, float rb,  float C, float rC)
{
    float er = 3.14 / 180;
    float result = 0.5 * (a * b * sin(C * er, rC));
    float aA = a * ra;
    float aB = b * rb;
    float aC = cos(C * er) * (C * er * rC);
    float aTot = aA + aB + aC;
    float accuracy = calculateAccuracy(aTot);
    std::cout << "Absolute error is ";
    show(aTot, accuracy);

}

int main()
{
    std::cout << "This is the first lab of project design.\n\n";
    std::cout << "First task is to execute the lifting force of a plain's wing.\n";
    //Coefficient, depending on a plane's shape
    float c = 0.005;
    //Angle of attack
    float a = 15;
    //Atmospheric density
    float p = 0.99;
    //Airflow rate on the wing
    float v = 200;
    //Wing projection area to horizontal plane
    float S = 20;
    //Errors:
    float rc = 0.001;
    float ra = 0.01;
    float rp = 0.01;
    float av = 3;
    float rS = 0.001;
    liftingForceExecution(c, a, p, v, S, rc, ra, rp, av, rS);
    //Task two
    std::cout << "\n\nSecond task is to find an absolute error of function.\n";
    float b, rb, C, rC;
    //First example
    std::cout << "\n\nFirst example:\n";
    a = 17.25;
    ra = 0.01;
    b = 34.725;
    rb = 0.005;
    C = 18.3; 
    rC = 0.01;
    function(a, ra, b, rb, C, rC);
    //Second example
    a = 2.1;
    ra = 0.05;
    b = 18.4;
    rb = 0.05;
    C = 2.06;
    rC = 0.005;
    std::cout << "\n\nSecond example:\n";
    function(a, ra, b, rb, C, rC);
    //Third example
    a = 6.089;
    ra = 0.003;
    b = 0.121;
    rb = 0.001;
    C = 167.18;
    rC = 0.01;
    std::cout << "\n\nThird example:\n";
    function(a, ra, b, rb, C, rC);
}
