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

	friend Vector operator+(const Vector& a, const Vector& b);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend bool operator>(const Vector& a, const Vector& b);

	float operator[](int index)
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

private:
	float x;
	float y;
	float z;
};

Vector operator+(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

bool operator>(const Vector& a, const Vector& b)
{
	return false;
}

int main()
{
	Vector v1(0, 1, 2);
	Vector v2(3, 4, 5);
	Vector v3;
	v3 = v1 + v2;
	std::cout << v3 << '\n';
	std::cout << "v3 lenght " << static_cast<float>(v3);
}