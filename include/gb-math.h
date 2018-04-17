#pragma once

// Vector 2d template class
template<class T>
class Vector2
{
public:
	// x and y
	T x;
	T y;

	// Default constructor
	Vector2() :
		x(static_cast<T>(0)),
		y(static_cast<T>(0))
	{}

	// Only float values for now
	explicit Vector2(T _x, T _y)
		:x(_x),
		y(_y)
	{}

	// Set both values
	void Set(T _x, T _y) { x = _x; y = _y; }
	// Set x value
	void SetX(T _x) { x = _x; }
	// Set y value
	void SetY(T _y) { y = _y; }

	Vector2<T> operator+(const Vector2<T>&);
	Vector2<T>& operator+=(const Vector2<T>&);
	Vector2<T> operator-(const Vector2<T>&);
	Vector2<T>& operator-=(const Vector2<T>&);
	Vector2<T> operator*(const T);
	Vector2<T>& operator*=(const T);
	Vector2<T> operator/(const T);
	Vector2<T>& operator/=(const T);

	// Static functions
	static const Vector2<T> Zero;
	static const Vector2<T> Unit;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

template<class T>
const Vector2<T> Vector2<T>::Zero(static_cast<T>(0), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Unit(static_cast<T>(1), static_cast<T>(1));

template<class T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& _vec)
{
	return Vector2<T>(x + _vec.x,
		y + _vec.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& _vec)
{
	x += _vec.x;
	y += _vec.y;

	return *this;
}

template<class T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& _vec)
{
	return Vector2<T>(x - _vec.x,
		y - _vec.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& _vec)
{
	x -= _vec.x;
	y -= _vec.y;

	return *this;
}

template<class T>
Vector2<T> Vector2<T>::operator*(const T _val)
{
	return Vector2<T>(x * _val,
		y * _val);
}

template<class T>
Vector2<T>& Vector2<T>::operator*=(const T _val)
{
	x *= _val;
	y *= _val;

	return *this;
}

template<class T>
Vector2<T> Vector2<T>::operator/(const T _val)
{
	return Vector2<T>(x / _val,
		y / _val);
}

template<class T>
Vector2<T>& Vector2<T>::operator/=(const T _val)
{
	x /= _val;
	y /= _val;

	return *this;
}