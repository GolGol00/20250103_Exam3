
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
	//�⺻������
	SimpleVector() : data(new T[10]), currentCapacity(10), currentSize(0) {
		cout << "�⺻�����ڰ� �����Ǿ����ϴ�." << endl;
	}

	//overloading
	SimpleVector(int capacity) : data(new T[capacity]), currentCapacity(capacity), currentSize(0) {
		cout << "ũ��: " << capacity << "�迭�� �����Ǿ����ϴ�." << endl;
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
			cout << "�迭�� �� �߰�!" << endl;
		}
		else {
			cout << "�迭�� ���� ��" << endl;
		}
	}

	void pop() {
		if (currentSize > 0) {
			currentSize--;
			cout << "���� ����" << endl;
		}
		else {
			cout << "������ ���� ����" << endl;
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

			cout << "�迭�� ũ�Ⱑ " << currentCapacity << " ���� " << resizeValue << "�� ����." << endl;
		}
		else {
			cout << "�����Ϸ��� ���� ���� ũ�⺸�� �۾Ƽ� �۵�����!" << endl;
			cout << "�����Ϸ��� ��: " << resizeValue << ", �⺻ �迭�� ũ��: " << currentCapacity << endl;
		}
	}


	void sortData(bool isUpper) {
		if (isUpper) {
			sort(data, data + currentSize, greater<>());
		}
		else {
			sort(data, data + currentSize, less<>());
		}

		cout << "�迭�� �����Ͱ� " << (isUpper ? "��������" : "��������") << "������ ���ķ� ���ĵǾ����ϴ�." << endl;
	}

	/// <summary>
	/// ������ ���
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
	cout << "SimpleVector ����" << endl;
	cout << "���Ͻô� �迭�� ũ�⸦ �Է��ϼ���: ";
	int size = 0;
	cin >> size;

	auto MyVector = SimpleVector<int>(size);
	cout << "ũ�� " << size << "�� ���� �迭�� ����." << endl;
	MyVector.printValue();

	bool isFinish = false;
	int num = 0;
	while (isFinish == false) {
		cout << "���Ͻô� ����� �Է��ϼ���. \n1. ũ�� ���� \n2. �� �߰� \n3. �� ���� \n4. �������� ���� \n5. �������� ���� \n6. ����� \n9. ����" << endl;

		cin >> num;

		switch ((FUNCTION)num)
		{
		case CHANGE_SIZE:
		{
			int changeValue = 0;
			cout << "������ ũ�⸦ �Է��ϼ���" << endl;
			cin >> changeValue;
			MyVector.resize(changeValue);
			break;
		}
		case PUSH_VALUE:
		{
			int appendValue = 0;
			cout << "�߰� �� ���� �Է��ϼ���." << endl;
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
			cout << "�迭�� �����͸� ����մϴ�" << endl;
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
	cout << "���α׷� ����" << endl;
}

int main() {
	CreateSimpleVector();
}