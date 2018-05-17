#ifndef GB_MATH_H
#define GB_MATH_H

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

	// Copy constructor
	Vector2(const Vector2<T>& _vec) :
		x(_vec.x),
		y(_vec.y)
	{}

	////////////////////
	// Public Methods //
	////////////////////

	// Set both values
	void Set(T _x, T _y) { x = _x; y = _y; }

	// Set x value
	void SetX(T _x) { x = _x; }

	// Set y value
	void SetY(T _y) { y = _y; }

	// Magnitude/Length of vector
	T Magnitude() const {
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

	// Euclidean Distance between 2 vectors
	T Distance(const Vector2<T>& _vec) {
		return static_cast<T>(sqrt(
			((x - _vec.x)*(x - _vec.x)) +
			((y - _vec.y)*(y - _vec.y))
		));
	}

	//////////////////////
	// Static functions //
	//////////////////////

	static bool compareFD(const T &a, const T &b);
	static const Vector2<T> Zero;
	static const Vector2<T> Unit;
	static const Vector2<T> Up;
	static const Vector2<T> Down;
	static const Vector2<T> Left;
	static const Vector2<T> Right;
	static T Dot(const Vector2<T>& _vecA, const Vector2<T>& _vecB);
	static T Cross(const Vector2<T>& _vecA, const Vector2<T>& _vecB);
	static T Distance(const Vector2<T>& _vecA, const Vector2<T>& _vecB);

	////////////////////////
	// Operator functions //
	////////////////////////

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
bool Vector2<T>::compareFD(const T &a, const T &b) {
	return (std::fabs(a - b) < static_cast<T>(0.005));
}

template<class T>
const Vector2<T> Vector2<T>::Zero(static_cast<T>(0), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Unit(static_cast<T>(1), static_cast<T>(1));

template<class T>
const Vector2<T> Vector2<T>::Up(static_cast<T>(0), static_cast<T>(1));

template<class T>
const Vector2<T> Vector2<T>::Down(static_cast<T>(0), static_cast<T>(-1));

template<class T>
const Vector2<T> Vector2<T>::Left(static_cast<T>(-1), static_cast<T>(0));

template<class T>
const Vector2<T> Vector2<T>::Right(static_cast<T>(1), static_cast<T>(0));

template<class T>
T Vector2<T>::Dot(const Vector2<T>& _vecA, const Vector2<T>& _vecB) {
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y);
}

template<class T>
T Vector2<T>::Cross(const Vector2<T>& _vecA, const Vector2<T>& _vecB) {
	return (_vecA.x * _vecB.y - _vecA.y * _vecB.x);
}

template<class T>
T Vector2<T>::Distance(const Vector2<T>& _vecA, const Vector2<T>& _vecB) {
	return static_cast<T>(sqrt(
		((_vecA.x - _vecB.x)*(_vecA.x - _vecB.x)) + 
		((_vecA.y - _vecB.y)*(_vecA.y - _vecB.y))
	));
}

// Type alias
using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;

#endif // GB_MATH_H