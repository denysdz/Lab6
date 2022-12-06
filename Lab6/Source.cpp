#include <iostream>
#include <stdio.h>

using namespace std;

template <typename Type>
Type module(Type a)
{
	return abs(a);
}

template <class T>
class Array {
private:
	int ar_length;
	T* arr;
public:
	Array(int l) {
		this->ar_length = l;
		arr = new T[ar_length];
	}

	void appendElement(int index, T value) {
		arr[index] = value;
	}

	T findElement(int index) {
		return arr[index];
	}

	~Array()
	{
		delete[] arr;
	}
};

int main() {

	float numb = -0.63f;
	cout << module(numb) << endl;
	cout << "\n";
	cout << "Count elements: ";
	int c = 0;
	cin >> c;
	try {
		if (c > 0) {
			Array<int> intArray(c);
			for (int i = 0; i < c; i++) {
				int el = 0;
				cin >> el;
				intArray.appendElement(i, el);
			}
			int key = 0;
			cout << "Enter key element to find element: ";
			cin >> key;
			if (key >= 0) {
				cout << intArray.findElement(key) << endl;
			} else {
				throw("Key must be >= 0");
			}
		}
		else {
			throw("Count must be > 0");
		}
	}
	catch (char* err) {
		cout << err << endl;
	}

	system("pause");
	return 0;
}