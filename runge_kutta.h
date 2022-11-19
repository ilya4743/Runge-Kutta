#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

#include "vec.h"
#include <QVector>

class Runge_Kutta
{
private:
    static inline vec F(vec U, double t, double g){
       vec res;
       res.x = U.vx;
       res.y = U.vy;
       res.vx = 0;
       res.vy = - g;
       return(res);
    }
public:
    static std::pair<QVector<double>, QVector<double>> calc(double t, double dt, double x, double y, double Ux, double Uy, double g)
    {
        std::pair<QVector<double>, QVector<double>> result;
        result.first.push_back(x);
        result.second.push_back(y);
        vec U(x, y, Ux, Uy);
        vec k1, k2, k3, k4;
        while(U.y >= 0)
        {
            k1 = F(U, t, g)*dt;
            k2 = F(U + 0.5*k1, t+0.5*dt, g)*dt;
            k3 = F(U + 0.5*k2, t+0.5*dt, g)*dt;
            k4 = F(U + k3, t+dt, g)*dt;
            U = U + 1.0/6.0 * (k1 + 2*k2 + 2*k3 + k4);
            t += dt;
            result.first.push_back(U.x);
            result.second.push_back(U.y);
        }
        return result;
    }
};
class Runge_Kutta1
{
private:
    static inline double F(double x, double y)
    {
        return   1 / ( x * x + y * y  + 2) ;
    }
public:
    static std::pair<QVector<double>, QVector<double>> calc(double x0,//начало интегрирования
                                                            double x, //конец интегрирования
                                                            double y, //значение Y в точке X0
                                                            double h//шаг интегрирования
                                                            )
    {
        std::pair<QVector<double>, QVector<double>> result;
        int n = static_cast<int>((x - x0) / h);
        double k1, k2, k3, k4;

        for(int i=0; i<n;i++)
        {
            k1 = h*F(x0, y);
            k2 = h*F(x0 + h / 2.0, y + k1 / 2.0);
            k3 = h*F(x0 + h / 2.0, y + k2 / 2.0);
            k4 = h*F(x0 + h, y + k3);
            y += (k1 + 2 * k2 + 2 * k3 + k4)  / 6.0;
            x0 += h;
            result.first.push_back(x0);
            result.second.push_back(y);
        }
        return result;
    }
};
#endif // RUNGE_KUTTA_H
