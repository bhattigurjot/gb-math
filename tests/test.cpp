#include "gb-math.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

Vector2i veci;
Vector2f vecf;
Vector2d vecd;

TEST_CASE("Vector2 constructor", "[vector2]") {
	REQUIRE(veci.x == 0);
	REQUIRE(veci.y == 0);
	REQUIRE(vecf.x == 0.0f);
	REQUIRE(vecf.y == 0.0f);
	REQUIRE(vecd.x == 0.0);
	REQUIRE(vecd.y == 0.0);
}

TEST_CASE("Vector2 zero value", "[vector2]") {
	veci = Vector2i::Zero;
	vecf = Vector2f::Zero;
	vecd = Vector2d::Zero;

	REQUIRE(veci.x == 0);
	REQUIRE(veci.y == 0);
	REQUIRE(vecf.x == 0.0f);
	REQUIRE(vecf.y == 0.0f);
	REQUIRE(vecd.x == 0.0);
	REQUIRE(vecd.y == 0.0);
}

TEST_CASE("Vector2 unit value", "[vector2]") {
	veci = Vector2i::Unit;
	vecf = Vector2f::Unit;
	vecd = Vector2d::Unit;

	REQUIRE(veci.x == 1);
	REQUIRE(veci.y == 1);
	REQUIRE(vecf.x == 1.0f);
	REQUIRE(vecf.y == 1.0f);
	REQUIRE(vecd.x == 1.0);
	REQUIRE(vecd.y == 1.0);
}

TEST_CASE("Vector2 set both", "[vector2]") {
	veci.Set(2, 3);
	vecf.Set(2.0f, 3.0f);
	vecd.Set(2.0, 3.0);

	REQUIRE(veci.x == 2);
	REQUIRE(veci.y == 3);
	REQUIRE(vecf.x == 2.0f);
	REQUIRE(vecf.y == 3.0f);
	REQUIRE(vecd.x == 2.0);
	REQUIRE(vecd.y == 3.0);
}

TEST_CASE("Vector2 set x", "[vector2]") {
	veci.SetX(3);
	vecf.SetX(3.0f);
	vecd.SetX(3.0);

	REQUIRE(veci.x == 3);
	REQUIRE(vecf.x == 3.0f);
	REQUIRE(vecd.x == 3.0);
}

TEST_CASE("Vector2 set y", "[vector2]") {
	veci.SetY(4);
	vecf.SetY(4.0f);
	vecd.SetY(4.0);

	REQUIRE(veci.y == 4);
	REQUIRE(vecf.y == 4.0f);
	REQUIRE(vecd.y == 4.0);
}

TEST_CASE("Vector2 addition as v=a+b", "[vector2]") {
	Vector2i vi = Vector2i(2, 3) + Vector2i(4, 5);
	Vector2f vf = Vector2f(2.0f, 3.0f) + Vector2f(4.0f, 5.0f);
	Vector2d vd = Vector2d(2.0, 3.0) + Vector2d(4.0, 5.0);

	REQUIRE(vi.x == 6);
	REQUIRE(vi.y == 8);
	REQUIRE(vf.x == 6.0f);
	REQUIRE(vf.y == 8.0f);
	REQUIRE(vd.x == 6.0);
	REQUIRE(vd.y == 8.0);
}

TEST_CASE("Vector2 addition as v+=a", "[vector2]") {
	veci.Set(2, 3);
	vecf.Set(2.0f, 3.0f);
	vecd.Set(2.0, 3.0);
	veci += Vector2i(4, 5);
	vecf += Vector2f(4.0f, 5.0f);
	vecd += Vector2d(4.0, 5.0);

	REQUIRE(veci.x == 6);
	REQUIRE(veci.y == 8);
	REQUIRE(vecf.x == 6.0f);
	REQUIRE(vecf.y == 8.0f);
	REQUIRE(vecd.x == 6.0);
	REQUIRE(vecd.y == 8.0);
}

TEST_CASE("Vector2 subtraction as v=a-b", "[vector2]") {
	Vector2i vi = Vector2i(2, 3) - Vector2i(4, 5);
	Vector2f vf = Vector2f(2.0f, 3.0f) - Vector2f(4.0f, 5.0f);
	Vector2d vd = Vector2d(2.0, 3.0) - Vector2d(4.0, 5.0);

	REQUIRE(vi.x == -2);
	REQUIRE(vi.y == -2);
	REQUIRE(vf.x == -2.0f);
	REQUIRE(vf.y == -2.0f);
	REQUIRE(vd.x == -2.0);
	REQUIRE(vd.y == -2.0);
}

TEST_CASE("Vector2 subtraction as v-=a", "[vector2]") {
	veci.Set(2, 3);
	vecf.Set(2.0f, 3.0f);
	vecd.Set(2.0, 3.0);
	veci -= Vector2i(4, 5);
	vecf -= Vector2f(4.0f, 5.0f);
	vecd -= Vector2d(4.0, 5.0);

	REQUIRE(veci.x == -2);
	REQUIRE(veci.y == -2);
	REQUIRE(vecf.x == -2.0f);
	REQUIRE(vecf.y == -2.0f);
	REQUIRE(vecd.x == -2.0);
	REQUIRE(vecd.y == -2.0);
}

TEST_CASE("Vector2 multiplication as v=a*scaler", "[vector2]") {
	Vector2i vi = Vector2i(2, 3) * 2;
	Vector2f vf = Vector2f(2.0f, 3.0f) * 2;
	Vector2d vd = Vector2d(2.0, 3.0) * 2;

	REQUIRE(vi.x == 4);
	REQUIRE(vi.y == 6);
	REQUIRE(vf.x == 4.0f);
	REQUIRE(vf.y == 6.0f);
	REQUIRE(vd.x == 4.0);
	REQUIRE(vd.y == 6.0);
}

TEST_CASE("Vector2 subtraction as v*=scaler", "[vector2]") {
	veci.Set(2, 3);
	vecf.Set(2.0f, 3.0f);
	vecd.Set(2.0, 3.0);
	veci *= 2;
	vecf *= 2;
	vecd *= 2;

	REQUIRE(veci.x == 4);
	REQUIRE(veci.y == 6);
	REQUIRE(vecf.x == 4.0f);
	REQUIRE(vecf.y == 6.0f);
	REQUIRE(vecd.x == 4.0);
	REQUIRE(vecd.y == 6.0);
}

TEST_CASE("Vector2 division as v=a/scaler", "[vector2]") {
	Vector2i vi = Vector2i(2, 3) / 2;
	Vector2f vf = Vector2f(2.0f, 3.0f) / 2;
	Vector2d vd = Vector2d(2.0, 3.0) / 2;

	REQUIRE(vi.x == 1);
	REQUIRE(vi.y == 1);
	REQUIRE(vf.x == 1.0f);
	REQUIRE(vf.y == 1.5f);
	REQUIRE(vd.x == 1.0);
	REQUIRE(vd.y == 1.5);
}

TEST_CASE("Vector2 division as v/=scaler", "[vector2]") {
	veci.Set(2, 3);
	vecf.Set(2.0f, 3.0f);
	vecd.Set(2.0, 3.0);
	veci /= 2;
	vecf /= 2;
	vecd /= 2;

	REQUIRE(veci.x == 1);
	REQUIRE(veci.y == 1);
	REQUIRE(vecf.x == 1.0f);
	REQUIRE(vecf.y == 1.5f);
	REQUIRE(vecd.x == 1.0);
	REQUIRE(vecd.y == 1.5);
}

TEST_CASE("Vector2 magnitude", "[vector2]") {
	veci.Set(4, 3);
	vecf.Set(4.0f, 3.0f);
	vecd.Set(4.0, 3.0);

	REQUIRE(veci.Magnitude() == 5);
	REQUIRE(vecf.Magnitude() == 5.0f);
	REQUIRE(vecd.Magnitude() == 5.0);
}

TEST_CASE("Vector2 dot product", "[vector2]") {
	veci.Set(4, 3);
	vecf.Set(4.0f, 3.0f);
	vecd.Set(4.0, 3.0);

	Vector2i a(2, 1);
	Vector2f b(2.0f, 1.0f);
	Vector2d c(2.0, 1.0);

	REQUIRE(veci.Dot(a) == 11);
	REQUIRE(vecf.Dot(b) == 11.0f);
	REQUIRE(vecd.Dot(c) == 11.0);
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);

	system("pause");
	return result;
}