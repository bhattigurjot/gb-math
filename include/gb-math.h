#pragma once

#include <cmath>

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

	// Constructor with values
	explicit Vector2(T _x, T _y) :
		x(_x),
		y(_y)
	{}

	// Set both values
	void Set(T _x, T _y) { x = _x; y = _y; }
	// Set x value
	void SetX(T _x) { x = _x; }
	// Set y value
	void SetY(T _y) { y = _y; }

	// Magnitude/Length of vector
	T Magnitude() {
		return static_cast<T>(sqrt((x * x) + (y * y)));
	}
	// Normalize vector
	void Normalize() {
		T val = static_cast<T>(sqrt((x * x) + (y * y)));
		x = static_cast<T>(x/val);
		y = static_cast<T>(y/val);
	}
	// Dot product of 2 vector
	T Dot(const Vector2<T>& _vec) {
		return (x * _vec.x + y * _vec.y);
	}
	// Cross product of 2 vector
	T Cross(const Vector2<T>& _vec) {
		return (x * _vec.y - y * _vec.x);
	}

	// Static functions
	static const Vector2<T> Zero;
	static const Vector2<T> Unit;

	// Vector Mathematics
	Vector2<T> operator+(const Vector2<T>& _vec) {
		// v = a + b
		return Vector2<T>(x + _vec.x, y + _vec.y);
	}
	Vector2<T>& operator+=(const Vector2<T>& _vec) {
		// v += a
		x += _vec.x;
		y += _vec.y;
		return *this;
	}
	Vector2<T> operator-(const Vector2<T>& _vec) {
		// v = a - b
		return Vector2<T>(x - _vec.x, y - _vec.y);
	}
	Vector2<T>& operator-=(const Vector2<T>& _vec) {
		// v -= a
		x -= _vec.x;
		y -= _vec.y;
		return *this;
	}
	Vector2<T> operator*(const T _val) {
		// v = a * scaler
		return Vector2<T>(x * _val, y * _val);
	}
	Vector2<T>& operator*=(const T _val) {
		// v *= scaler
		x *= _val;
		y *= _val;
		return *this;
	}
	Vector2<T> operator/(const T _val) {
		// v = a / scaler
		return Vector2<T>(x / _val, y / _val);
	}
	Vector2<T>& operator/=(const T _val) {
		// v /= scaler
		x /= _val;
		y /= _val;
		return *this;
	}
};

template<class T>
const Vector2<T> Vector2<T>::Zero(static_cast<T>(0), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Unit(static_cast<T>(1), static_cast<T>(1));

// Type alias
using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;