#pragma once
template <typename T>
class Vec3
{
private:
	double x, y, z;
public:
	Vec3();
	Vec3(double _x, double _y, double _z);
	~Vec3();

	T getX();
	T getY();
	T getZ();

	void const setX(T _x);
	void const setY(T _y);
	void const setZ(T _z);

	Vec3<T> operator+(const Vec3 &newvec3);
	Vec3<T> operator-(const Vec3 &newvec3);
	void operator+=(const Vec3 &newvec3);
	void operator-=(const Vec3 &newvec3);
	void operator=(const Vec3 &newvec3);
	bool operator==(const Vec3 &newvec3);

	void normalize();
	void zero();
	bool is_zero();
	const double distance_to(const Vec3 &newvec3);

};

