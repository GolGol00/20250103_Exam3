
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	//기본생성자
	SimpleVector() : data(new T[10]), currentCapacity(10), currentSize(0) {
		cout << "기본생성자가 생성되었습니다." << endl;
	}

	//overloading
	SimpleVector(int capacity) : data(new T[capacity]), currentCapacity(capacity), currentSize(0) {
		cout << "크기: " << capacity << "배열이 생성되었습니다." << endl;
	}

	SimpleVector(const SimpleVector& it) {
		data = it.data;
		currentSize = it.currentSize;
		currentCapacity = it.currentCapacity;
	}

	~SimpleVector() {
		delete[] data;
		cout << "SimpleVector Delete." << endl;
	}

	void push_back(T value) {
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;
			cout << "배열에 값 추가!" << endl;
		}
		else {
			cout << "배열이 가득 참" << endl;
		}
	}

	void pop() {
		if (currentSize > 0) {
			currentSize--;
			cout << "값을 제거" << endl;
		}
		else {
			cout << "제거할 원소 없음" << endl;
		}
	}


	int size() {
		return currentSize;
	}


	int capacity() {
		return currentCapacity;
	}

	void resize(int resizeValue) {
		if (resizeValue > currentCapacity) {
			auto temp = new T[resizeValue];

			for (int i = 0; i < currentCapacity; ++i) {
				temp[i] = data[i];
			}

			currentCapacity = resizeValue;

			cout << "배열의 크기가 " << currentCapacity << " 에서 " << resizeValue << "로 변경." << endl;
		}
		else {
			cout << "변경하려는 값이 기존 크기보다 작아서 작동안함!" << endl;
			cout << "변경하려는 값: " << resizeValue << ", 기본 배열의 크기: " << currentCapacity << endl;
		}
	}


	void sortData(bool isUpper) {
		if (isUpper) {
			sort(data, data + currentSize, greater<>());
		}
		else {
			sort(data, data + currentSize, less<>());
		}

		cout << "배열의 데이터가 " << (isUpper ? "내림차순" : "오름차순") << "선택한 정렬로 정렬되었습니다." << endl;
	}

	/// <summary>
	/// 데이터 출력
	/// </summary>
	void printValue() {
		for (int i = 0; i < currentSize; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

enum FUNCTION {
	CHANGE_SIZE = 1,
	PUSH_VALUE,
	POP_VALUE,
	DESCENDING_SORT,
	ASSCENDING_SORT,
	PRINT_VALUE,
	EXIT = 9,
};

void CreateSimpleVector() {
	cout << "SimpleVector 생성" << endl;
	cout << "원하시는 배열의 크기를 입력하세요: ";
	int size = 0;
	cin >> size;

	auto MyVector = SimpleVector<int>(size);
	cout << "크기 " << size << "를 가진 배열이 생성." << endl;
	MyVector.printValue();

	bool isFinish = false;
	int num = 0;
	while (isFinish == false) {
		cout << "원하시는 기능을 입력하세요. \n1. 크기 변경 \n2. 값 추가 \n3. 값 제거 \n4. 내림차순 정렬 \n5. 오름차순 정렬 \n6. 값출력 \n9. 종료" << endl;

		cin >> num;

		switch ((FUNCTION)num)
		{
		case CHANGE_SIZE:
		{
			int changeValue = 0;
			cout << "변경할 크기를 입력하세요" << endl;
			cin >> changeValue;
			MyVector.resize(changeValue);
			break;
		}
		case PUSH_VALUE:
		{
			int appendValue = 0;
			cout << "추가 할 값을 입력하세요." << endl;
			cin >> appendValue;
			MyVector.push_back(appendValue);
			MyVector.printValue();
			break;
		}
		case POP_VALUE:
		{
			MyVector.pop();
			MyVector.printValue();
			break;
		}
		case DESCENDING_SORT:
		{
			MyVector.sortData(true);
			MyVector.printValue();
			break;
		}
		case ASSCENDING_SORT:
		{
			MyVector.sortData(false);
			MyVector.printValue();
			break;
		}
		case PRINT_VALUE:
		{
			cout << "배열의 데이터를 출력합니다" << endl;
			MyVector.printValue();
			break;
		}
		case EXIT:
			isFinish = true;
			break;
		default:
			break;
		}
	}
	cout << "프로그램 종료" << endl;
}

int main() {
	CreateSimpleVector();
}