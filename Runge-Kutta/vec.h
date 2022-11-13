#ifndef VEC_H
#define VEC_H


class vec{
   public:
   float x, y, vx, vy;
   vec():x(0),y(0),vx(0),vy(0){}
   vec(float ax, float ay, float avx, float avy): x(ax), y(ay), vx(avx), vy(avy){}
   vec operator+(const vec& b) const;
   vec operator -(const vec& b) const;
   friend vec operator *(float a, vec b);
   friend vec operator *(vec b, float a);
};

#endif // VEC_H
