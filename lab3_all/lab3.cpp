#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

void bubble(int* arr, int i) {
	for (int k = 0; k < i - 1; k++) {
		for (int j = 0; j < i - 2; j++) {
			if (arr[j] > arr[j + 1]) {
				int change = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = change;
			}
		}
	}
}

void counter(char* arr1, int a) {
	const int elem = 26;
	int arr[elem] = { 0 };
	cout << "\n";
	for (int i = 0; i < a; i++) {
		int j = arr1[i] - 'a';
		arr[j]++;
	}
	int i = 0;
	int j = 0;
	while (j <= elem) {
		if (arr[j] > 0) {
			arr1[i] = 'a' + j;
			i++;
			arr[j]--;
		}
		else {
			j++;
		}
	}
}

void merge(int* a, int n)
{
	int mid = n / 2; // находим середину сортируемой последовательности
	if (n % 2 == 1)
		mid++;
	int h = 1; // шаг
	// выделяем память под формируемую последовательность
	int* c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // пока не дошли до конца пути
			  // заполняем следующий элемент формируемой последовательности
			  // меньшим из двух просматриваемых
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i < n; i++)
			a[i] = c[i];
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int quest;
	while (true) {
		cout << "Чтобы совершить сортировку массвива пузырьком, нажмите 1. \n Чтобы совершить сортировку массива подсчетом нажмите 2.\n Чтобы совершить сортировку массива слиянием нажмите 3\n Чтобы выйти нажмите 0" << endl;
		cin >> quest;
		if (quest == 1) {
			cout << "Вводите цифры для массива. Чтобы заврешить ввод нажмите -" << endl;
			//Задание 1 сортировка пузырьком
			int arr[1000] = {};//создание массива для целых чисел
			int i = 0;
			while (true) {  //ввод целых чисел	
				std::string num;
				cin >> num;
				arr[i] = atoi(num.c_str());
				i++;
				if (num == "-") {
					break;
				}
			}
			cout << "Массив который вы ввели" << endl;
			for (int j = 0; j < i - 1; j++) {
				cout << arr[j] << " ";
			}// вывод целых чисел
			cout << endl;
			bubble(arr, i);
			cout << "Сортированный массив" << endl;
			for (int j = 0; j < i - 1; j++) {
				cout << arr[j] << " ";
			} //вывод сортированного массива
			cout << "\n";
		}
		else if (quest == 2) {
			char arr1[1000] = {};
			int a = 0;
			cout << "Чтобы прекратить заполнение массива введите 0" << endl;
			while (true) {  //ввод целых чисел
				char sym;
				cin >> sym;
				arr1[a] = sym;
				a++;
				if (sym == '0') {
					break;
				}
			}
			cout << "Массив который вы ввели" << endl;
			for (int j = 0; j < a - 1; j++) {
				cout << arr1[j] << " ";
			}// вывод целых чисел
			cout << endl;
			cout << "Отсортированный массив";
			counter(arr1, a - 1);
			for (int j = 0; j < a - 1; j++) {
				cout << arr1[j] << " ";
			}// вывод целых чисел
			cout << endl;
		}
		else if (quest == 3) {
			cout << "Чтобы прекратить заполнение массива введите -" << endl;
			int arr1[1000] = {};
			int a = 0;
			std::string sym;
			while (true) {  //ввод целых чисел
				cin >> sym;
				arr1[a] = std::atoi(sym.c_str());
				a++;
				if (sym == "-") {
					break;
				}
			}
			for (int j = 0; j < a - 1; j++) {
				cout << arr1[j] << " ";
			}// вывод целых чисел
			cout << endl;
			merge(arr1, a);
			for (int j = 0; j < a - 1; j++) {
				cout << arr1[j] << " ";
			}// вывод целых чисел
			cout << endl;
		}
		else if (quest == 0) {
			break;
		}
		else {
			cout << "Такой операции нет. Введите цифру ещё раз";
		}
	}
}
