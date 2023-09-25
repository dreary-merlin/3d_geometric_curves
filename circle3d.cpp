#include "circle3d.h"
Circle3D::Circle3D(const Point3D& _center, double _radius) :Curve3D(_center), radius{ std::fabs(_radius) }
{
}
Circle3D::~Circle3D()
{
}
Point3D Circle3D::get_point(double t) const
{
	return Point3D{ center.x + radius*std::cos(t), center.y + radius*std::sin(t), center.z };
}
Vector3D Circle3D::get_first_derivative(double t) const
{
	return Vector3D{-radius*std::sin(t),radius*std::cos(t)};
}
double Circle3D::get_radius() const 
{
	return radius;
}