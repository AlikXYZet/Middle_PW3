#include <iostream>

class Vector
{
public:
	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	friend Vector operator+(const Vector& a, const Vector& b);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

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
	return Vector (a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

int main()
{
	Vector v1(0, 1, 2);
	Vector v2(3, 4, 5);
	std::cout << v1 + v2 << '\n';
	std::cout << v2[1];
}