#include <iostream> // std::cout, std::endl
#include <cmath>    //std::abs
#include <iomanip>  //std::setprecision

using std::abs;
using std::cout;
using std::endl;
using std::setprecision;

double b = -1.16583607818894, a = -1.25100322759761E-4, r = 0.08205, g = 0.0542253936905836, t = 273.15, p1 = 200, p0 = r * t / p1;

inline double f(double v) { return (r * t / v) + (b / pow(v, 2)) + (g / pow(v, 3)) + (a / pow(v, 4)) - p1; }
inline double df(double v) { return (-r * t / pow(v, 2)) - (2 * b / pow(v, 3)) - (3 * g / pow(v, 4)) - (4 * a / pow(v, 5)); }

double newton(double p0, double T)
{
    double p, paux;
    for (int i = 0; i < 40; i++)
    {
        p = p0 - (f(p0) / df(p0));
        cout << setprecision(10) << i << "\t" << p0 << "\t" << p << "\t" << abs(p - p0) << endl;

        if (abs(p - p0) < T)
        {
            cout << "Objetivo logrado con " << i + 1 << " iteraciones" << endl;
            break;
        }

        p0 = p;
    }
    return p;
}
int main()
{
    newton(p0, pow(10, -9));
    return 0;
}