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
		Info = new std::string("important!");
	}

	Vector(float num)
	{
		x = num;
		y = num;
		z = num;
		Info = new std::string("important!");
	}

	Vector(const Vector& other)
	{
		std::cout << "\nCopy constructor \n";
		x = other.x;
		y = other.y;
		z = other.z;
		Info = new std::string(*(other.Info));
	}

	Vector& operator=(Vector& other)
	{
		std::cout << "\noperator = \n";
		x = other.x;
		y = other.y;
		z = other.z;

		if (other.Info)
		{
			if (Info) delete Info;
			Info = new std::string(*(other.Info));
		}

		return (*this);
	}

	~Vector()
	{
		std::cout << "Destructor calling \n";
		delete Info;
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

	std::string* Info;
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
	Vector v1(1);
	Vector v2(2);
	Vector v3;
	std::cout << v2 << '\n';
	v3 = v2 = v1;
	std::cout << v2 << '\n';

}