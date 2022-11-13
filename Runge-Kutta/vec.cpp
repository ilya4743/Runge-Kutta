#include "vec.h"

vec vec::operator+(const vec& b) const
{
    vec c;
    c.x = this->x + b.x;
    c.y = this->y + b.y;
    c.vx = this->vx + b.vx;
    c.vy = this->vy + b.vy;
    return c;
}

vec vec::operator -(const vec& b) const
{
   vec c;
   c.x = this->x - b.x;
   c.y = this->y - b.y;
   c.vx = this->vx - b.vx;
   c.vy = this->vy - b.vy;
   return(c);
}

vec operator *(double a, vec b)
{
   vec c;
   c.x = a * b.x;
   c.y = a * b.y;
   c.vx = a * b.vx;
   c.vy = a * b.vy;
   return(c);
}

vec operator *(vec b, double a)
{
   vec c;
   c.x = a * b.x;
   c.y = a * b.y;
   c.vx = a * b.vx;
   c.vy = a * b.vy;
   return(c);
}
