#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

class Point
{
private:
	int x, y, z;
	char name;
	double r;
public:
	void randEnter();
	void enter();
	void show();
	double rast();
	double rast(Point, Point);
	void maxR(Point*, int);
	void Radius(Point*, int);
	bool triangle(Point, Point, Point);
};

void Point::randEnter()
{
	srand(time(NULL));
	Sleep(1000);
	x = rand() % 100;
	y = rand() % 100;
	z = rand() % 100;
	r = rast();

	name = rand() % 26 + 65;
}
void Point::enter()
{
	cout << "Введите координаты: ";
	cin >> x >> y >> z;
	cout << "Введите имя: ";
	cin >> name;
	r = rast();
}

void Point::show()
{
	cout << "Координаты: (" << x << ", " << y << ", " << z << ")" << endl;
	cout << "Имя: " << name << endl;
	cout << "Расстояние от начала координат: " << r << endl;
}

double Point::rast()
{
	return sqrt(x * x + y * y + z * z);
}

double Point::rast(Point A, Point B)
{
	return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2) + pow((B.z - A.z), 2));
}

bool Point::triangle(Point A, Point B, Point C) 
{
	double a, b, c;
	a = rast(A, B);
	b = rast(B, C);
	c = rast(A, C);

	if (a + b > c && b + c > a && a + c > b)
		return true;
	else
		return false;
}

void Point::maxR(Point* T, int N)
{
	double maxR = rast(T[0], T[1]);
	Point A = T[0], B = T[1];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (rast(T[i], T[j]) > maxR)
			{
				maxR = rast(T[i], T[j]);
				A = T[i];
				B = T[j];
			}

	cout << "макс расстояние между точками " << A.name << " и " << B.name << " " << maxR << endl;
}

void Point::Radius(Point* T, int N)
{
	double maxR = rast(T[0], T[1]);
	Point A = T[0], B = T[1];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (rast(T[i], T[j]) > maxR)
			{
				maxR = rast(T[i], T[j]);
			}

	cout << "радиус = " << maxR / 2 << endl;
}

void Menu()
{
	cout << endl;
	cout << "1. Сгенерировать массив точек" << endl;
	cout << "2. Ввести массив точек вручную" << endl;
	cout << "3. Определить, могут ли 3 точки образовать треугольник" << endl;
	cout << "4. Определить, какая точка ближе всех к началу координат" << endl;
	cout << "5. Выход" << endl;
	int answer;
	cin >> answer;
	if (answer == 1)
	{
		int N;
		cout << "Введите размер массива: ";
		cin >> N;
		Point* T = new Point[N];
		for (int i = 0; i < N; i++)
		{
			T[i].randEnter();
			T[i].show();
		}

		cout << "1. Определить радиус шара, который вмещает все точки массива" << endl;
		cout << "2. Определить пару точек масимально отдаленных друг от друга" << endl;
		int input;
		cin >> input;

		switch (input)
		{
		case 1:
			T->Radius(T, N);
			break;
		case 2:
			T->maxR(T, N);
			break;
		default:
			break;
		}
		Menu();
	}
	else if (answer == 2)
	{
		int N;
		cout << "Введите размер массива: ";
		cin >> N;
		Point* T = new Point[N];
		for (int i = 0; i < N; i++)
			T[i].enter();

		cout << "1. Определить радиус шара, который вмещает все точки массива" << endl;
		cout << "2. Определить пару точек масимально отдаленных друг от друга" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			T->Radius(T, N);
			break;
		case 2:
			T->maxR(T, N);
			break;
		default:
			break;
		}
		Menu();
	}
	switch (answer)
	{
	case 3:
		Point t1, t2, t3;
		t1.enter();
		t2.enter();
		t3.enter();
		Point tri;
		tri.triangle(t1, t2, t3);
		if (tri.triangle(t1, t2, t3))
			cout << "Точки могут образовывать треугольник" << endl;
		else
			cout << "Точки не могут образовывать треугольник" << endl;
		Menu();
		break;
	case 4:
		Point t11, t21;
		t1.enter();
		t2.enter();
		if (t1.rast() < t2.rast())
		{
			cout << "Точка максимально приближенная к началу координат: " << endl;
			t1.show();
		}
		else
		{
			cout << "Точка максимально приближенная к началу координат: " << endl;
			t2.show();
		}
		Menu();
		break;
	case 5:
		break;
	default:
		break;
	}

	cout << endl;
}

int main()
{
	setlocale(0, "rus");

	Menu();

	//int N = 3;
	//Point* T = new Point[N];

	//for (int i = 0; i < N; i++)
	//{
	//	T[i].randEnter();
	//	T[i].show();
	//}

	//cout << endl;

	//T->maxR(T, N);


	return 0;
}
