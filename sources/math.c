#include "../fractol.h"

double  scale(double num, double n_mi, double n_ma, double o_mi, double o_ma)
{
    double scaled_number;

    scaled_number = (n_ma - n_mi) * (num - o_mi) / (o_ma - o_mi) + n_mi;
    return (scaled_number);
}