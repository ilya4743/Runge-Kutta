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

#endif // RUNGE_KUTTA_H
