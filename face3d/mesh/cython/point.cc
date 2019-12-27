#include "point.h"

double Point::Dot(Point p) { return this->x * p.x + this->y * p.y; }

Point Point::operator-(const Point& p) {
  Point new_p;
  new_p.x = this->x - p.x;
  new_p.y = this->y - p.y;
  return new_p;
}

Point Point::operator+(const Point& p) {
  Point new_p;
  new_p.x = this->x + p.x;
  new_p.y = this->y + p.y;
  return new_p;
}

Point Point::operator*(double s) {
  Point new_p;
  new_p.x = s * this->x;
  new_p.y = s * this->y;
  return new_p;
}
