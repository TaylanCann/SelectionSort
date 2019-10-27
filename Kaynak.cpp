#include<iostream>
#include<ctime>
using namespace std;

void gives_rnd(int array[], int value);
void write_to_screen(int array[], int value);
void selectionSort(int array[], int value);

int main() {
	srand(time(NULL));
	clock_t time;

	int arrayA[3000], arrayB[5000], arrayC[1000]; //Diziler tan�mland�.

	gives_rnd(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	gives_rnd(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	gives_rnd(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Dizilere rastgele say�lar atand�.

	/*write_to_screen(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	write_to_screen(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	write_to_screen(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Diziler kontrol ama�l� ekrana yazd�r�ld�
	*/
	time = clock();
	selectionSort(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin s�releri �l��ld�.

	time = clock();
	selectionSort(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin s�releri �l��ld�.

	time = clock();
	selectionSort(arrayC, sizeof(arrayC) / sizeof(*arrayC));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin s�releri �l��ld�.

	/*write_to_screen(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	write_to_screen(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	write_to_screen(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Diziler kontrol ama�l� ekrana yazd�r�ld�
	*/

	return 0;
}

void gives_rnd(int array[], int value) //Dizilere rastgele say� atama fonksiyonu.
{
	for (int i = 0; i < value; i++)
	{
		array[i] = rand();
	}
}

void write_to_screen(int array[], int value) //Kontrol ama�l� ekrana yazd�rma fonksiyonu.
{
	for (int i = 0; i < value; i++)
	{
		cout << array[i] << endl;
	}

	cout << endl;
	cout << endl;
}

void selectionSort(int array[], int value) //Dizilerin selection sort ile s�ralama fonksiyonu.
{
	int temporary; // S�ralama i�in ge�ici fonksiyon tan�mland�.

	for (int i = 0; i < value; i++)
	{
		for (int j = 0; j < value; j++)
		{
			if (array[i] < array[j])
			{
				temporary = array[i];
				array[i] = array[j];
				array[j] = temporary;
			}
		}
	}
}

// Selection Short ile s�ralanm�� 3000'lik dizi : 0.045
// Selection Short ile s�ralanm�� 5000'lik dizi : 0.095
// Selection Short ile s�ralanm�� 10000'lik dizi : 0.390