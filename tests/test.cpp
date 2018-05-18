#include "gb-math.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

SCENARIO("Vector2 objects are created", "[vector2]") {
	GIVEN("Vector2 default constructors") {
		WHEN("object is created") {
			Vector2i veci;
			Vector2f vecf;
			Vector2d vecd;
			THEN("x,y components are zero") {
				REQUIRE(veci.x == 0);
				REQUIRE(veci.y == 0);
				REQUIRE(vecf.x == 0.0f);
				REQUIRE(vecf.y == 0.0f);
				REQUIRE(vecd.x == 0.0);
				REQUIRE(vecd.y == 0.0);
			}
		}
		WHEN("pointer object is created") {
			Vector2i *p_veci = new Vector2i;
			Vector2f *p_vecf = new Vector2f;
			Vector2d *p_vecd = new Vector2d;
			THEN("x,y components are zero") {
				REQUIRE(p_veci->x == 0);
				REQUIRE(p_veci->y == 0);
				REQUIRE(p_vecf->x == 0.0f);
				REQUIRE(p_vecf->y == 0.0f);
				REQUIRE(p_vecd->x == 0.0);
				REQUIRE(p_vecd->y == 0.0);
			}
		}
		
	}
	GIVEN("Vector2 constructor with values") {
		WHEN("object is created") {
			Vector2i veci(2, 3);
			Vector2f vecf(2.0f, 3.0f);
			Vector2d vecd(2.0, 3.0);
			THEN("x,y components are correctly set") {
				REQUIRE(veci.x == 2);
				REQUIRE(veci.y == 3);
				REQUIRE(vecf.x == 2.0f);
				REQUIRE(vecf.y == 3.0f);
				REQUIRE(vecd.x == 2.0);
				REQUIRE(vecd.y == 3.0);
			}
		}
		WHEN("pointer object is created") {
			Vector2i *p_veci = new Vector2i(2, 3);
			Vector2f *p_vecf = new Vector2f(2.0f, 3.0f);
			Vector2d *p_vecd = new Vector2d(2.0, 3.0);
			THEN("x,y components are correctly set") {
				REQUIRE(p_veci->x == 2);
				REQUIRE(p_veci->y == 3);
				REQUIRE(p_vecf->x == 2.0f);
				REQUIRE(p_vecf->y == 3.0f);
				REQUIRE(p_vecd->x == 2.0);
				REQUIRE(p_vecd->y == 3.0);
			}
		}
	}
	GIVEN("Vector2 constructor with another Vector2") {
		WHEN("object is created") {
			Vector2i vec_i(2, 3);
			Vector2f vec_f(2.0f, 3.0f);
			Vector2d vec_d(2.0, 3.0);
			
			Vector2i veci(vec_i);
			Vector2f vecf(vec_f);
			Vector2d vecd(vec_d);
			THEN("x,y components are correctly set") {
				REQUIRE(veci.x == 2);
				REQUIRE(veci.y == 3);
				REQUIRE(vecf.x == 2.0f);
				REQUIRE(vecf.y == 3.0f);
				REQUIRE(vecd.x == 2.0);
				REQUIRE(vecd.y == 3.0);
			}
		}
	}
}

SCENARIO("Vector2 default objects are created", "[vector2]") {
	Vector2i veci;
	Vector2f vecf;
	Vector2d vecd;
	GIVEN("Vector2 zero object is created") {
		veci = Vector2i::Zero;
		vecf = Vector2f::Zero;
		vecd = Vector2d::Zero;
		THEN("x,y components are zero") {
			REQUIRE(veci.x == 0);
			REQUIRE(veci.y == 0);
			REQUIRE(vecf.x == 0.0f);
			REQUIRE(vecf.y == 0.0f);
			REQUIRE(vecd.x == 0.0);
			REQUIRE(vecd.y == 0.0);
		}
	}
	GIVEN("Vector2 unit object is created") {
		veci = Vector2i::Unit;
		vecf = Vector2f::Unit;
		vecd = Vector2d::Unit;
		THEN("x,y components are unit values") {
			REQUIRE(veci.x == 1);
			REQUIRE(veci.y == 1);
			REQUIRE(vecf.x == 1.0f);
			REQUIRE(vecf.y == 1.0f);
			REQUIRE(vecd.x == 1.0);
			REQUIRE(vecd.y == 1.0);
		}
	}
	GIVEN("Vector2 up object is created") {
		veci = Vector2i::Up;
		vecf = Vector2f::Up;
		vecd = Vector2d::Up;
		THEN("x,y components get values (0,1) respectively") {
			REQUIRE(veci.x == 0);
			REQUIRE(veci.y == 1);
			REQUIRE(vecf.x == 0.0f);
			REQUIRE(vecf.y == 1.0f);
			REQUIRE(vecd.x == 0.0);
			REQUIRE(vecd.y == 1.0);
		}
	}
	GIVEN("Vector2 down object is created") {
		veci = Vector2i::Down;
		vecf = Vector2f::Down;
		vecd = Vector2d::Down;
		THEN("x,y components get values (0,-1) respectively") {
			REQUIRE(veci.x == 0);
			REQUIRE(veci.y == -1);
			REQUIRE(vecf.x == 0.0f);
			REQUIRE(vecf.y == -1.0f);
			REQUIRE(vecd.x == 0.0);
			REQUIRE(vecd.y == -1.0);
		}
	}
	GIVEN("Vector2 left object is created") {
		veci = Vector2i::Left;
		vecf = Vector2f::Left;
		vecd = Vector2d::Left;
		THEN("x,y components get values (-1,0) respectively") {
			REQUIRE(veci.x == -1);
			REQUIRE(veci.y == 0);
			REQUIRE(vecf.x == -1.0f);
			REQUIRE(vecf.y == 0.0f);
			REQUIRE(vecd.x == -1.0);
			REQUIRE(vecd.y == 0.0);
		}
	}
	GIVEN("Vector2 right object is created") {
		veci = Vector2i::Right;
		vecf = Vector2f::Right;
		vecd = Vector2d::Right;
		THEN("x,y components get values (1,0) respectively") {
			REQUIRE(veci.x == 1);
			REQUIRE(veci.y == 0);
			REQUIRE(vecf.x == 1.0f);
			REQUIRE(vecf.y == 0.0f);
			REQUIRE(vecd.x == 1.0);
			REQUIRE(vecd.y == 0.0);
		}
	}
}

SCENARIO("Vector2 set values", "[vector2]") {
	Vector2i veci;
	Vector2f vecf;
	Vector2d vecd;
	GIVEN("Vector2 both values are set") {
		veci.Set(2, 3);
		vecf.Set(2.0f, 3.0f);
		vecd.Set(2.0, 3.0);
		THEN("x,y components are correctly set") {
			REQUIRE(veci.x == 2);
			REQUIRE(veci.y == 3);
			REQUIRE(vecf.x == 2.0f);
			REQUIRE(vecf.y == 3.0f);
			REQUIRE(vecd.x == 2.0);
			REQUIRE(vecd.y == 3.0);;
		}
	}
	GIVEN("Vector2 x value is set") {
		veci.SetX(3);
		vecf.SetX(3.0f);
		vecd.SetX(3.0);
		THEN("x component value is set, y remains same") {
			REQUIRE(veci.x == 3);
			REQUIRE(veci.y == 0);
			REQUIRE(vecf.x == 3.0f);
			REQUIRE(vecf.y == 0.0f);
			REQUIRE(vecd.x == 3.0);
			REQUIRE(vecd.y == 0.0);
		}
	}
	GIVEN("Vector2 y value is set") {
		veci.SetY(3);
		vecf.SetY(3.0f);
		vecd.SetY(3.0);
		THEN("y component value is set, x remains same") {
			REQUIRE(veci.x == 0);
			REQUIRE(veci.y == 3);
			REQUIRE(vecf.x == 0.0f);
			REQUIRE(vecf.y == 3.0f);
			REQUIRE(vecd.x == 0.0);
			REQUIRE(vecd.y == 3.0);
		}
	}
}

SCENARIO("Vector2 utility functions", "[vector2]") {
	GIVEN("Vector2 with set values") {
		Vector2i veci(4,3);
		Vector2f vecf(4.0f,3.0f);
		Vector2d vecd(4.0,3.0);

		WHEN("magnitude function is called") {
			THEN("return the scalar value of the vector") {
				REQUIRE(veci.Magnitude() == 5);
				REQUIRE(vecf.Magnitude() == 5.0f);
				REQUIRE(vecd.Magnitude() == 5.0);
			}
		}

		WHEN("magnitudesquared function is called") {
			THEN("return the scalar value of the vector") {
				REQUIRE(veci.MagnitudeSquared() == 25);
				REQUIRE(vecf.MagnitudeSquared() == 25.0f);
				REQUIRE(vecd.MagnitudeSquared() == 25.0);
			}
		}

		WHEN("normalize function is called") {
			veci.Normalize();
			vecf.Normalize();
			vecd.Normalize();

			THEN("normalize the x and y values of the vector") {
				REQUIRE(veci.x == 0);
				REQUIRE(veci.y == 0);
				REQUIRE(vecf.x == 0.8f);
				REQUIRE(vecf.y == 0.6f);
				REQUIRE(vecd.x == 0.8);
				REQUIRE(vecd.y == 0.6);
			}
		}
	}

	GIVEN("Two Vector2") {
		Vector2i veci(4, 3);
		Vector2f vecf(4.0f, 3.0f);
		Vector2d vecd(4.0, 3.0);

		Vector2i a(2, 1);
		Vector2f b(2.0f, 1.0f);
		Vector2d c(2.0, 1.0);

		WHEN("dot product is calculated") {
			REQUIRE(veci.Dot(a) == 11);
			REQUIRE(vecf.Dot(b) == 11.0f);
			REQUIRE(vecd.Dot(c) == 11.0);
		}

		WHEN("dot product is calculated, on static call") {
			REQUIRE(Vector2i::Dot(veci, a) == 11);
			REQUIRE(Vector2f::Dot(vecf, b) == 11.0f);
			REQUIRE(Vector2d::Dot(vecd, c) == 11.0);
		}

		WHEN("cross product is calculated") {
			REQUIRE(veci.Cross(a) == -2);
			REQUIRE(vecf.Cross(b) == -2.0f);
			REQUIRE(vecd.Cross(c) == -2.0);
		}

		WHEN("cross product is calculated, on static call") {
			REQUIRE(Vector2i::Cross(veci, a) == -2);
			REQUIRE(Vector2f::Cross(vecf, b) == -2.0f);
			REQUIRE(Vector2d::Cross(vecd, c) == -2.0);
		}

		WHEN("distance between 2 vectors is calculated") {
			REQUIRE(veci.Distance(a) == 2);
			REQUIRE(Vector2f::compareFD(vecf.Distance(b), 2.82843f) == true);
			REQUIRE(Vector2d::compareFD(vecd.Distance(c), 2.82843) == true);
		}

		WHEN("distance between 2 vectors is calculated, on static call") {
			REQUIRE(Vector2i::Distance(veci, a) == 2);
			REQUIRE(Vector2f::compareFD(Vector2f::Distance(vecf, b), 2.82843f) == true);
			REQUIRE(Vector2d::compareFD(Vector2d::Distance(vecd, c), 2.82843) == true);
		}

		// TODO: Needs refactoring
		WHEN("angle between 2 vectors is calculated") {
			REQUIRE(Vector2d::compareFD(veci.Angle(a), 0.1798534998) == true);
			REQUIRE(Vector2f::compareFD(vecf.Angle(b), 0.1798534998) == true);
			REQUIRE(Vector2d::compareFD(vecd.Angle(c), 0.1798534998) == true);
		}

		// TODO: Needs refactoring
		WHEN("angle between 2 vectors is calculated, on static call") {
			REQUIRE(Vector2d::compareFD(Vector2i::Angle(veci, a), 0.1798534998) == true);
			REQUIRE(Vector2f::compareFD(Vector2f::Angle(vecf, b), 0.1798534998) == true);
			REQUIRE(Vector2d::compareFD(Vector2d::Angle(vecd, c), 0.1798534998) == true);
		}
	}
}

SCENARIO("Vector2 mathematics", "[vector2]") {
	GIVEN("Two Vector2") {
		Vector2i veci(2, 3);
		Vector2f vecf(2.0f, 3.0f);
		Vector2d vecd(2.0, 3.0);

		Vector2i veci_2(4, 5);
		Vector2f vecf_2(4.0f, 5.0f);
		Vector2d vecd_2(4.0, 5.0);

		WHEN("addition is performed as v = a + b") {
			Vector2i vi = veci + veci_2;
			Vector2f vf = vecf + vecf_2;
			Vector2d vd = vecd + vecd_2;

			THEN("new Vector2 has values as") {
				REQUIRE(vi.x == 6);
				REQUIRE(vi.y == 8);
				REQUIRE(vf.x == 6.0f);
				REQUIRE(vf.y == 8.0f);
				REQUIRE(vd.x == 6.0);
				REQUIRE(vd.y == 8.0);
			}
		}

		WHEN("addition is performed as v += a") {
			veci += veci_2;
			vecf += vecf_2;
			vecd += vecd_2;

			THEN("Vector2 v has values as") {
				REQUIRE(veci.x == 6);
				REQUIRE(veci.y == 8);
				REQUIRE(vecf.x == 6.0f);
				REQUIRE(vecf.y == 8.0f);
				REQUIRE(vecd.x == 6.0);
				REQUIRE(vecd.y == 8.0);
			}
		}

		WHEN("subtraction is performed as v = a + b") {
			Vector2i vi = veci - veci_2;
			Vector2f vf = vecf - vecf_2;
			Vector2d vd = vecd - vecd_2;

			THEN("new Vector2 has values as") {
				REQUIRE(vi.x == -2);
				REQUIRE(vi.y == -2);
				REQUIRE(vf.x == -2.0f);
				REQUIRE(vf.y == -2.0f);
				REQUIRE(vd.x == -2.0);
				REQUIRE(vd.y == -2.0);
			}
		}

		WHEN("subtraction is performed as v -= a") {
			veci -= veci_2;
			vecf -= vecf_2;
			vecd -= vecd_2;

			THEN("Vector2 v has values as") {
				REQUIRE(veci.x == -2);
				REQUIRE(veci.y == -2);
				REQUIRE(vecf.x == -2.0f);
				REQUIRE(vecf.y == -2.0f);
				REQUIRE(vecd.x == -2.0);
				REQUIRE(vecd.y == -2.0);
			}
		}
	}

	GIVEN("One Vector2") {
		Vector2i veci(2, 3);
		Vector2f vecf(2.0f, 3.0f);
		Vector2d vecd(2.0, 3.0);

		WHEN("multiplication of vector with scalar as v = a * scalar") {
			Vector2i vi = veci * 2;
			Vector2f vf = vecf * 2;
			Vector2d vd = vecd * 2;

			THEN("new Vector2 has values as") {
				REQUIRE(vi.x == 4);
				REQUIRE(vi.y == 6);
				REQUIRE(vf.x == 4.0f);
				REQUIRE(vf.y == 6.0f);
				REQUIRE(vd.x == 4.0);
				REQUIRE(vd.y == 6.0);
			}
		}

		WHEN("multiplication of vector with scalar as v *= scalar") {
			veci *= 2;
			vecf *= 2;
			vecd *= 2;

			THEN("Vector2 v has values as") {
				REQUIRE(veci.x == 4);
				REQUIRE(veci.y == 6);
				REQUIRE(vecf.x == 4.0f);
				REQUIRE(vecf.y == 6.0f);
				REQUIRE(vecd.x == 4.0);
				REQUIRE(vecd.y == 6.0);
			}
		}

		WHEN("division of vector with scalar as v = a / scalar") {
			Vector2i vi = veci / 2;
			Vector2f vf = vecf / 2;
			Vector2d vd = vecd / 2;

			THEN("new Vector2 has values as") {
				REQUIRE(vi.x == 1);
				REQUIRE(vi.y == 1);
				REQUIRE(vf.x == 1.0f);
				REQUIRE(vf.y == 1.5f);
				REQUIRE(vd.x == 1.0);
				REQUIRE(vd.y == 1.5);
			}
		}

		WHEN("division of vector with scalar as v /= scalar") {
			veci /= 2;
			vecf /= 2;
			vecd /= 2;

			THEN("Vector2 v has values as") {
				REQUIRE(veci.x == 1);
				REQUIRE(veci.y == 1);
				REQUIRE(vecf.x == 1.0f);
				REQUIRE(vecf.y == 1.5f);
				REQUIRE(vecd.x == 1.0);
				REQUIRE(vecd.y == 1.5);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);

	system("pause");
	return result;
}