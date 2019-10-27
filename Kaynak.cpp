#include<iostream>
#include<ctime>
using namespace std;

void gives_rnd(int array[], int value);
void write_to_screen(int array[], int value);
void selectionSort(int array[], int value);

int main() {
	srand(time(NULL));
	clock_t time;

	int arrayA[3000], arrayB[5000], arrayC[1000]; //Diziler tanýmlandý.

	gives_rnd(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	gives_rnd(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	gives_rnd(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Dizilere rastgele sayýlar atandý.

	/*write_to_screen(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	write_to_screen(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	write_to_screen(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Diziler kontrol amaçlý ekrana yazdýrýldý
	*/
	time = clock();
	selectionSort(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin süreleri ölçüldü.

	time = clock();
	selectionSort(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin süreleri ölçüldü.

	time = clock();
	selectionSort(arrayC, sizeof(arrayC) / sizeof(*arrayC));
	time = clock() - time;
	cout << (float)time / CLOCKS_PER_SEC << endl; //Dizilerin süreleri ölçüldü.

	/*write_to_screen(arrayA, sizeof(arrayA) / sizeof(*arrayA));
	write_to_screen(arrayB, sizeof(arrayB) / sizeof(*arrayB));
	write_to_screen(arrayC, sizeof(arrayC) / sizeof(*arrayC)); //Diziler kontrol amaçlý ekrana yazdýrýldý
	*/

	return 0;
}

void gives_rnd(int array[], int value) //Dizilere rastgele sayý atama fonksiyonu.
{
	for (int i = 0; i < value; i++)
	{
		array[i] = rand();
	}
}

void write_to_screen(int array[], int value) //Kontrol amaçlý ekrana yazdýrma fonksiyonu.
{
	for (int i = 0; i < value; i++)
	{
		cout << array[i] << endl;
	}

	cout << endl;
	cout << endl;
}

void selectionSort(int array[], int value) //Dizilerin selection sort ile sýralama fonksiyonu.
{
	int temporary; // Sýralama için geçici fonksiyon tanýmlandý.

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

// Selection Short ile sýralanmýþ 3000'lik dizi : 0.045
// Selection Short ile sýralanmýþ 5000'lik dizi : 0.095
// Selection Short ile sýralanmýþ 10000'lik dizi : 0.390