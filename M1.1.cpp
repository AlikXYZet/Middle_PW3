#include <iostream>
#include <cmath>

class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend Vector operator + (const Vector& a, const Vector& b);

	friend std::ostream& operator << (std::ostream& out, const Vector& v);

	friend bool operator > (const Vector& a, const Vector& b);

	float operator [] (int index)
	{
		switch (index)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			std::cout << "ibdex error: ";
			return 0;
			break;
		}
	}

	// ================================== Practical Work ================================
	Vector operator * (const float& a)
	{
		return Vector(x * a, y * a, z * a);
	};

	Vector operator *= (const float& a)
	{
		*this = *this * a;
		return *this;
	};

	friend Vector operator - (const Vector& a, const Vector& b);

	friend std::istream& operator >> (std::istream& in, Vector& v);
	// ==================================================================================

private:
	float x;
	float y;
	float z;
};

Vector operator  +(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator << (std::ostream& out, const Vector& v)
{
	out << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

bool operator > (const Vector& a, const Vector& b)
{
	return false;
}

// ================================== Practical Work ================================
Vector operator - (const Vector& a, const Vector& b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

std::istream& operator >> (std::istream& in, Vector& v)
{
	in >> v.x;
	in >> v.y;
	in >> v.z;
	return in;
};
// ==================================================================================

int main()
{
	Vector v1(0, 1, 2);
	Vector v2(3, 5, 7);
	Vector v3;
	v3 = v1 + v2;
	std::cout << v3 << '\n';
	std::cout << "v3 lenght " << static_cast<float>(v3) << '\n';
	std::cout << '\n';

	// ================================== Practical Work ================================
	std::cout << "v1: " << v1 << '\n';
	std::cout << "v2: " << v2 << '\n';
	std::cout << "v3: " << v3 << '\n';
	std::cout << '\n';

	// Operator *
	float a1 = 10;
	v3 = v1 * a1;
	std::cout << "Test operator* : " << v3 << '\n';
	std::cout << "v1: " << v1 << '\n';
	std::cout << '\n';

	v3 *= a1;
	std::cout << "Test operator*= : " << v3 << '\n';
	std::cout << '\n';

	// Operator -
	v3 = v2 - v1;
	std::cout << "Test operator- : " << v3 << '\n';
	std::cout << '\n';

	// std::cin
	std::cin >> v3;
	std::cout << "Test std::cin : " << v3 << '\n';
	// ==================================================================================
}