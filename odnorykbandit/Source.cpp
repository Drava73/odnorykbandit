#include <iostream>
#include <time.h>
using namespace std;

const int elements = 15;
class Bandit
{
private:
	int** mas; 
	int put, get, count; 
	int size; 

public:
	~Bandit()
	{
		for (int i = 0; i < 3; i++)
			delete[] mas[i];
		delete[] mas;

	}
	Bandit() 
	{
		int chip[elements] = { 1, 2, 14, 16, 36 };
		count = 10;
		get = NULL;
		size = 5;
		mas = new int* [3];
		for (int i(0); i < 3; i++) 
			mas[i] = new int[size];
		for (int i(0); i < 3; i++) 
			for (put = 0; put < size; put++)
				putband(i, put, chip);
	}
	 
	void putband(int i, int put, int* mas_chip)
	{
		mas[i][put] = mas_chip[put];
	}

	 
	void getband(Bandit& A)
	{
		for (int i(0); i < 3; i++, cout << endl)
			for (int j(0); j < 3; j++)
				cout << (char)mas[j][i] << " ";
	}
	int summ()
	{
		return count;
	}
	void start()
	{
		for (int i(0); i < (3 + rand() % 3); i++) 
			for (int j(put - 1), tmp1 = mas[0][put - 1]; j > 0; j--)
			{
				mas[0][j] = mas[0][j - 1];
				if (j == 1)
					mas[0][get] = tmp1;
			}

		for (int i(0); i < (3 + rand() % 3); i++) 
			for (int j(put - 1), tmp1 = mas[1][put - 1]; j > 0; j--)
			{
				mas[1][j] = mas[1][j - 1];
				if (j == 1)
					mas[1][get] = tmp1;
			}

		for (int i(0); i < (3 + rand() % 3); i++) 
			for (int j(put - 1), tmp1 = mas[2][put - 1]; j > 0; j--)
			{
				mas[2][j] = mas[2][j - 1];
				if (j == 1)
					mas[2][get] = tmp1;
			}

		switch (true)
		{
		case (1): if ((mas[0][1] == mas[1][1]) && (mas[1][1] == mas[2][1]))
		{
			count += 3;
			break;
		}
		case (2):if ((mas[0][1] == mas[1][1]) || (mas[1][1] == mas[2][1]))
		{
			count += 1;
			break;
		}
		case (3):count -= 3;
			break;
		}
	}

	 


	 
 
};



bool main()
{
	setlocale(LC_ALL, "Rus");
	double start_time = clock();
	Bandit A;
	srand(time(NULL));
	while (true)
	{
		A.start();
		cout << endl << endl;
		A.getband(A);
		cout << endl << "Количество балов: " << A.summ() << endl << endl;

 

		if (A.summ() <= 0)
		{
			cout << "\nИгра окончена";
			return false;
		}

		system("pause");
		system("cls");
	}
}