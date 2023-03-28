#include <iostream>
#include <vector>
#include <stack>

#define INT_MAX       2147483647

int getHighNum(std::vector<int> vec, int &index) {
	if (vec.size() <= 0)
		return 0;

	int highNumber = -INT_MAX;

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > highNumber) {
			highNumber = vec[i];
			index = i;
		}
	}

	return highNumber;
}
void stackToVector(std::vector<int>& vec, std::stack<int>& st, int StSize) {
	for (int i = 0; i < StSize; i++) {
		vec.push_back(st.top());
		st.pop();
	}
}
void vectorToStack(std::vector<int>& vec, std::stack<int>& st, int VecSize) {
	for (int i = 0; i < VecSize; i++) {
		st.push(vec[i]);
	}
	vec.clear();
}
void printStack(std::stack<int> st, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << st.top() << " ";
		st.pop();
	}
}
void DeleteElementFromVector(std::vector<int>& vec, int index) {
	if (vec.size() <= 0 || vec.size() == index)
		return;

	for (int i = 0; i < vec.size(); i++) {
		if (i >= index) {
			vec[i] = vec[i + 1];
		}
	}

	vec.pop_back();
	return;
}

void moveStack(std::stack<int> &from, std::stack<int> &to, int size) {
	std::vector<int> vec = { NULL };
	stackToVector(vec, from, from.size());

	for (int i = 0; i < size; i++) {
		int index = -1;

		to.push(getHighNum(vec, index));

		std::cout << getHighNum(vec, index) << " - moved to stack #2\n";
		DeleteElementFromVector(vec, index);
	}
	std::cout << "\n";
}

void printAll(std::stack<int> st1, std::stack<int> st2, std::stack<int> st3) {
	std::cout << "stack #1: ";
	printStack(st1, st1.size());
	std::cout << "\nstack #2: ";
	printStack(st2, st2.size());
	std::cout << "\nstack #3: ";
	printStack(st3, st3.size());
	std::cout << "\n\n";
}

int main() {
	constexpr int size = 9;
	int numbers[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::stack<int> st1, st2, st3;

	for (int i = 0; i < size; i++) {
		st1.push(numbers[i]);
	}

	printAll(st1, st2, st3);
	moveStack(st1, st2, st1.size());
	printAll(st1, st2, st3);

	return 0;
}

/*
Створіть три стоси (тип даних можете використати будь-який). Один із них
заповніть числами 9, 8, 7, 6, 5, 4, 3, 2, 1. Саме в такому порядку. Два інші хай будуть порожніми.

Вам потрібно переставити всі елементи першого стоса в будь-який інший таким
чином, щоб кожен наступний елемент був менший попереднього.

Весь процес зі станами стосів на кожному кроці виведіть на екран.

Початок:
9, 8, 7, 6, 5, 4, 3, 2, 1
Перший крок:
9, 8, 7, 6, 5, 4, 3, 2
1
Другий крок:
9, 8, 7, 6, 5, 4, 3
2
1
Третій крок
9, 8, 7, 6, 5, 4, 3
2, 1
*/
