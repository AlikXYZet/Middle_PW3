#include <iostream>
#include <cmath>

using namespace std;

class Array
{
public:

	// Конструктор
	Array()
	{
		// Получение размеров Дин.массива
		cout << "\nВведите количество сттолбцов: n = ";
		cin >> n;
		cout << "Введите количество сттолбцов: m = ";
		cin >> m;

		// Создание и заполнение Дин.массива
		A = new int* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[m];
			for (int ii = 0; ii < m; ii++)
			{
				A[i][ii] = rand() % 10;	// Диапазон: 0-9
			}
		}

		// Заполнение Доп.данных
		string inInfo;
		cout << "Введите Слово (En): Info = ";
		cin >> inInfo;
		Info = new string(inInfo);

		int inNumber;
		cout << "Введите Число (int): Number = ";
		cin >> inNumber;
		Number = new int(inNumber);
	};

	// Деструктор
	~Array()
	{
		// Освобождение памяти
		FDelete();
	}

	// Перегрузка копирования (на основе присвоения)
	Array(Array& other)
	{
		*this = other;
	}

	// Перегрузка присвоения
	Array& operator=(Array& other)
	{
		// Освобождение памяти
		FDelete();

		// Присвоить размеры массива
		n = other.n;
		m = other.m;

		// Создание и заполнение Дин.массива
		A = new int* [n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new int[m];
			for (int ii = 0; ii < m; ii++)
			{
				A[i][ii] = other.A[i][ii];
			}
		}

		// Заполнение Доп.данных
		Info = new string(*(other.Info));
		Number = new int(*(other.Number));

		return *this;
	}

	// Вывод в консоль
	friend ostream& operator << (ostream& out, Array& Arr);

private:

	// Данные массива
	int n;
	int m;
	int** A;

	// Доп.данные
	string* Info;
	int* Number;

	// Ф-я освобождения памяти
	void FDelete()
	{
		// Удаление Дин.массива
		for (int i = 0; i < n; i++)
		{
			delete[] A[i];
		}
		delete[] A;

		// Удаление Доп.данных
		delete Info;
		delete Number;
	}
};

ostream& operator << (ostream& out, Array& Arr)
{
	// Вывод Дин.массива
	cout << '\n';
	for (int i = 0; i < Arr.n; i++)
	{
		for (int ii = 0; ii < Arr.m; ii++)
		{
			cout << Arr.A[i][ii] << "  ";
		}
		cout << '\n';
	}

	// Вывод Доп.данных
	cout << "Info = " << *Arr.Info << '\n';
	cout << "Number = " << *Arr.Number << '\n';

	return out;
};

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "\nИнициализация A1:";
	Array A1;
	cout << "\nA1:" << A1;

	cout << "\nИнициализация A2:";
	Array A2;
	cout << "\nA2:" << A2;

	A2 = A1;
	cout << "\nA2 = A1:" << A2;

	cout << "\nИнициализация A3:";
	Array A3(A1);
	cout << "\nA3(A1):" << A3;
}