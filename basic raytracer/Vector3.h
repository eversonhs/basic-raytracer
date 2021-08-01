#pragma once

class Vector3
{
public:
    static Vector3 zero;
    // Vector3(0,0,1);
    static Vector3 forward;
    // Vector3(0,0,-1);
    static Vector3 backward;
    // Vector3(0,1,0);
    static Vector3 up;
    // Vector3(0,-1,0);
    static Vector3 down;
    // Vector3(1,0,0);
    static Vector3 right;
    // Vector3(-1,0,0);
    static Vector3 left;

    Vector3(double x, double y, double z);

    //double magnitude();
    //Vector3 unit();

    Vector3& operator+(const Vector3& vector);
    Vector3& operator-(const Vector3& vector);
    Vector3& operator*(double value);

    static double dot(Vector3& leftVector, Vector3& rightVector);

    double getX() const;
    double getY() const;
    double getZ() const;

private:
    double _x;
    double _y;
    double _z;

};

