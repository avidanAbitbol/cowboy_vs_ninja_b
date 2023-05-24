//
// Created by avida on 5/15/2023.
//
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

#include "Point.hpp"

namespace ariel {

    Point::Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double Point::getX() const{
        return this->x;
    }
    double Point::getY()const {
        return this->y;
    }
    void Point::setX(double x) {
        this->x = x;
    }
    void Point::setY(double y) {
        this->y = y;
    }
    Point::Point() {
        this->x = 0;
        this->y = 0;
    }
    double Point::distance(const Point &other) const {

        return ::sqrt(((this->x - other.x) * (this->x - other.x)) + ((this->y - other.y) * (this->y - other.y)));
    }
    string Point::print() const{
        return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    }
    Point Point::moveTowards(const Point &point1, const Point &point2, double dist)  {
        return point1.moveTowards(point2, dist);
    }

    Point Point::moveTowards(const Point& other, double dist) const{
        if (dist < 0) {
            throw  std::invalid_argument("distance cannot be negative");
        }
        double x = this->x;
        double y = this->y;
        double x2 = other.x;
        double y2 = other.y;
        double distance = this->distance(other);
        if (distance <= dist) {
            return other;
        }
        double x3 = x + (dist * (x2 - x) / distance);
        double y3 = y + (dist * (y2 - y) / distance);
        return {x3, y3};
    }


} // ariel