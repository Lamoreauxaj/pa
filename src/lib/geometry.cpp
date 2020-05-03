#include "geometry.h"

// -------------------------------------------------------------------------------------------------------
// POINT
// -------------------------------------------------------------------------------------------------------

vector<pair<VarType, Figure>> Point::intersect(Point point) {
    vector<pair<VarType, Figure>> ret;

    if (p == point.p)
        ret.push_back(make_pair(POINT, *this));
    
    return ret;
}

vector<pair<VarType, Figure>> Point::intersect(Line line) {
    vector<pair<VarType, Figure>> ret;

    Vector3D norm = (line.p - p).cross(line.m);
    if (isZeroVector(norm))
        ret.push_back(make_pair(POINT, *this));

    return ret;
}

vector<pair<VarType, Figure>> Point::intersect(Circle circle) {
    vector<pair<VarType, Figure>> ret;

    if (withinEps(circle.norm.dot(circle.p - p), 0) && withinEps((p - circle.p).mag(), circle.r))
        ret.push_back(make_pair(POINT, *this));

    return ret;
}

vector<pair<VarType, Figure>> Point::intersect(Plane plane) {
    vector<pair<VarType, Figure>> ret;

    if (withinEps(plane.norm.dot(plane.p - p), 0))
        ret.push_back(make_pair(POINT, *this));

    return ret;
}

vector<pair<VarType, Figure>> Point::intersect(Sphere sphere) {
    vector<pair<VarType, Figure>> ret;

    if (withinEps((p - sphere.p).mag(), sphere.r))
        ret.push_back(make_pair(POINT, *this));

    return ret;
}

vector<pair<VarType, Figure>> Point::pointOn() {
    vector<pair<VarType, Figure>> ret;

    ret.push_back(make_pair(POINT, *this));

    return ret;
}

// -------------------------------------------------------------------------------------------------------
// LINE
// -------------------------------------------------------------------------------------------------------

vector<pair<VarType, Figure>> Line::intersect(Point point) {
    return point.intersect(*this);
}

vector<pair<VarType, Figure>> Line::intersect(Line line) {
    vector<pair<VarType, Figure>> ret;

    if (*this == line) {
        ret.push_back(make_pair(LINE, *this));
    } else {
        Vector3D v = m.cross(line.p - p);
        if (withinEps(v.dot(line.p + line.m - p), 0)) {
            return ret;
        }

        long double u = ((p - line.p).cross(line.m).mag()) / (m.cross(line.m).mag());
        ret.push_back(make_pair(POINT, Point(p + (m * u))));
    }

    return ret;
}

vector<pair<VarType, Figure>> Line::intersect(Circle circle) {
    vector<pair<VarType, Figure>> ret;

    return ret;
}

vector<pair<VarType, Figure>> Line::intersect(Plane plane) {
    vector<pair<VarType, Figure>> ret;

    long double dot = (p - plane.p).dot(plane.norm);
    if (withinEps(dot, 0))
        ret.push_back(make_pair(LINE, *this));

    return ret;
}

vector<pair<VarType, Figure>> Line::intersect(Sphere sphere) {
    vector<pair<VarType, Figure>> ret;

    return ret;
}

vector<pair<VarType, Figure>> Line::pointOn() {
    vector<pair<VarType, Figure>> ret;

    // TODO: try and update this to an exponential distri or smth
    long double r = rand();
    ret.push_back(make_pair(POINT, Point(p + m * r)));

    return ret;
}

// -------------------------------------------------------------------------------------------------------
// CIRCLE
// -------------------------------------------------------------------------------------------------------

vector<pair<VarType, Figure>> Circle::intersect(Point point) {
    return point.intersect(*this);
}

vector<pair<VarType, Figure>> Circle::intersect(Line line) {
    return line.intersect(*this);
}

vector<pair<VarType, Figure>> Circle::intersect(Circle circle) {
    
}

vector<pair<VarType, Figure>> Circle::intersect(Plane plane) {
    
}

vector<pair<VarType, Figure>> Circle::intersect(Sphere sphere) {
    
}

vector<pair<VarType, Figure>> Circle::pointOn() {
    
}

// -------------------------------------------------------------------------------------------------------
// PLANE
// -------------------------------------------------------------------------------------------------------

vector<pair<VarType, Figure>> Plane::intersect(Point point) {
    return point.intersect(*this);
}

vector<pair<VarType, Figure>> Plane::intersect(Line line) {
    return line.intersect(*this);
}

vector<pair<VarType, Figure>> Plane::intersect(Circle circle) {
    return circle.intersect(*this);
}

vector<pair<VarType, Figure>> Plane::intersect(Plane plane) {
    
}

vector<pair<VarType, Figure>> Plane::intersect(Sphere sphere) {
    
}

vector<pair<VarType, Figure>> Plane::pointOn() {
    
}

// -------------------------------------------------------------------------------------------------------
// SPHERE
// -------------------------------------------------------------------------------------------------------

vector<pair<VarType, Figure>> Sphere::intersect(Point point) {
    return point.intersect(*this);
}

vector<pair<VarType, Figure>> Sphere::intersect(Line line) {
    return line.intersect(*this);
}

vector<pair<VarType, Figure>> Sphere::intersect(Circle circle) {
    return circle.intersect(*this);
}

vector<pair<VarType, Figure>> Sphere::intersect(Plane plane) {
    return plane.intersect(*this);
}

vector<pair<VarType, Figure>> Sphere::intersect(Sphere sphere) {
    
}

vector<pair<VarType, Figure>> Sphere::pointOn() {
    
}