#include "Vec3.h"
#include <math.h>

template <typename T>
Vec3<T>::Vec3()
{
}

template <typename T>
Vec3<T>::Vec3(T _x, T _y, T _z)
{
	x = _x;
	y = _y;
	z = _z;
}

template <typename T>
Vec3<T>::~Vec3()
{
}

template <typename T>
T Vec3<T>::getX()
{
	return x;
}
template <typename T>
T Vec3<T>::getY()
{
	return y;
}
template <typename T>
T Vec3<T>::getZ()
{
	return z;
}

template <typename T>
void const Vec3<T>::setX(T _x)
{
	x = _x;
}
template <typename T>
void const Vec3<T>::setY(T _y)
{
	y = _y;
}
template <typename T>
void const Vec3<T>::setZ(T _z)
{
	z = _z;
}

template <typename T>
Vec3<T> Vec3<T>::operator+( Vec3 &newvec3)
{
	return Vec3<T>(x + newvec3.x, y + newvec3.y, z + newvec3.z);
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const Vec3 &newvec3)
{
	return Vec3<T>(x - newvec3.x, y - newvec3.y, z - newvec3.z);
}

template <typename T>
void Vec3<T>::operator+=(const Vec3 &newvec3)
{
	x += newvec3.x;
	y += newvec3.y;
	z += newvec3.z;
}

template <typename T>
void Vec3<T>::operator-=(const Vec3 &newvec3)
{
	x -= newvec3.x;
	y -= newvec3.y;
	z -= newvec3.z;
}

template <typename T>
void Vec3<T>::operator=(const Vec3 &newvec3)
{
	x = newvec3.x;
	y = newvec3.y;
	z = newvec3.z;
}

template <typename T>
bool Vec3<T>::operator==(const Vec3 &newvec3)
{
	return (x == newvec3.x, y == newvec3.y, z == newvec3.z);
}

template <typename T>
void Vec3<T>::normalize()
{
	T norm = sqrt(x*x + y*y + z*z);
	if (norm != 0)
	{
		x /= norm;
		y /= norm;
		z /= norm;
	}
}

template <typename T>
void Vec3<T>::zero()
{
	x = y = z = 0;
}

template <typename T>
bool Vec3<T>::is_zero()
{
	return (x == 0, y == 0, z == 0);
}

template <typename T>
const T Vec3<T>::distance_to(const Vec3 &newvec3)
{
	T dis = sqrt((x - newvec3.x)*(x - newvec3.x) + (y - newvec3.y)*(y - newvec3.y) + (z - newvec3.z)*(z - newvec3.z));
}