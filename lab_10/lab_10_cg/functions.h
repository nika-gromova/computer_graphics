#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <math.h>
#define F_NUMBER 4

typedef double (*PFunction)(double, double);

struct surface_data
{
    PFunction func;
    double x_start;
    double x_end;
    double z_start;
    double z_end;
    double x_step;
    double z_step;
};

class Function
{
public:
    Function()
    {
        f_array[0] = &f1;
        f_array[1] = &f2;
        f_array[2] = &f3;
        f_array[3] = &f4;
    }

    PFunction get_function(int index)
    {
        return f_array[index];
    }
    QString get_function_name(int index)
    {
        switch (index) {
        case 1:
            return "y = x^2 - z^2";
            break;
        case 2:
            return "y = cos(sqrt(x^2 + z^2))";
            break;
        case 3:
            return "y = cos(x) * sin(z)";
            break;
        case 4:
            return "y = cos^2(x) + sin^2(z))";
            break;
        default:
            break;
        }
        return "";
    }

private:
    PFunction f_array[F_NUMBER];

    static double f1(double x, double z)
    {
        return x * x - z * z;
    }
    static double f2(double x, double z)
    {
        return cos(sqrt(x * x + z * z));
    }
    static double f3(double x, double z)
    {
        return cos(x) * sin(z);
    }
    static double f4(double x, double z)
    {
        return cos(x) * cos(x) + sin(z) * sin(z);
    }
};


#endif // FUNCTIONS_H
