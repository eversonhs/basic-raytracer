#include "Vector3.h"



Vector3 Vector3::zero = Vector3(0.0, 0.0, 0.0);
Vector3 Vector3::forward = Vector3(0.0, 0.0, 1.0);
Vector3 Vector3::backward = Vector3(0.0, 0.0, -1.0);
Vector3 Vector3::up = Vector3(0.0, 1.0, 0.0);
Vector3 Vector3::down = Vector3(0.0, -1.0, 0.0);
Vector3 Vector3::right = Vector3(1.0, 0.0, 0.0);
Vector3 Vector3::left = Vector3(-1.0, 0.0, 0.0);
//TODO: Implement this method
//double Vector3::magnitude()
//{
//    return;
//}

//TODO: Implement this method
//Vector3 Vector3::unit()
//{
//    return Vector3();
//}

Vector3::Vector3(double x, double y, double z) :
    _x(x), _y(y), _z(z)
{
}

Vector3& Vector3::operator+(const Vector3& vector)
{
    Vector3 result(_x + vector._x, _y + vector._y, _z + vector._z);
    return result;
}

Vector3& Vector3::operator-(const Vector3& vector)
{
    Vector3 result(_x - vector._x, _y - vector._y, _z - vector._z);
    return result;
}

Vector3& Vector3::operator*(double value)
{
    Vector3 result(_x * value, _y * value, _z * value);
    return result;
}

double Vector3::dot(Vector3 & leftVector, Vector3& rightVector)
{
    return (leftVector._x * rightVector._x)
           +(leftVector._y * rightVector._y)
           +(leftVector._z * rightVector._z);
}

double Vector3::getX() const
{
    return _x;
}

double Vector3::getY() const
{
    return _y;
}

double Vector3::getZ() const
{
    return _z;
}
