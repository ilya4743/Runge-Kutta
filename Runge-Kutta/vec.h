#ifndef VEC_H
#define VEC_H


class vec{
   public:
   double x, y, vx, vy;
   vec():x(0),y(0),vx(0),vy(0){}
   vec(double ax, double ay, double avx, double avy): x(ax), y(ay), vx(avx), vy(avy){}
   vec operator+(const vec& b) const;
   vec operator -(const vec& b) const;
   friend vec operator *(double a, vec b);
   friend vec operator *(vec b, double a);
};

#endif // VEC_H
