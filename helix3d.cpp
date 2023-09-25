#include "helix3d.h"
Helix3D::Helix3D(const Point3D& _center, double _radius, double _step) :Curve3D(_center), radius{ std::fabs(_radius) }, step{ _step }
{
}
Helix3D::~Helix3D() 
{
}
Point3D Helix3D::get_point(double t) const
{
	return Point3D{ center.x + radius*std::cos(t), center.y + radius*std::sin(t), center.z+step*(t/round) };
}
Vector3D Helix3D::get_first_derivative(double t) const 
{
	return Vector3D{ -radius*std::sin(t),radius*std::cos(t),step/round };
}