#include <iostream>
#include <vector>
using namespace std;

class Parent
{
public:
	virtual int Get_Element(const int number) const = 0;
	virtual int Get_Size() const = 0;
	virtual void Print() const = 0;
	virtual ~Parent() {};
};

class Array_Implemenation :public Parent
{
public:
	Array_Implemenation(const int size)
	{
		array = new int[size];
		this->size_of_array = size;
		for (int i = 0; i < size; i++)
			array[i] = rand() % 88 + 10;
	}
	~Array_Implemenation() override { delete[] array; }
	Array_Implemenation& operator =(Array_Implemenation& new_array)
	{
		if (this->array!=nullptr)
			delete[] this->array;
		this->size_of_array=new_array.size_of_array;
		this->array = new int[new_array.size_of_array];
		for (int i = 0; i < new_array.size_of_array; i++)
			this->array[i] = new_array.array[i];
		return *this;
	}
	void Print() const  override
	{
		for (int i = 0; i < size_of_array; i++)
			cout << array[i] << " ";
		cout << endl;
	}
	int Get_Element(const int number) const  override
	{
		return this->array[number];
	}
	int Get_Size() const  override
	{
		return this->size_of_array;
	}
private:
	int* array;
	int size_of_array;
};

class Vector_Implemenation :public Parent
{
public:
	Vector_Implemenation(const int size)
	{
		for (int i = 0; i < size; i++)
			array.push_back(rand() % 33);
	}
	void Print() const  override
	{
		for (int i = 0; i < array.size(); i++)
			cout << array[i] << " ";
		cout << endl;
	}
	int Get_Size() const override
	{
		return array.size();
	}
	int Get_Element(const int number) const override
	{
		return this->array[number];
	}
private:
	vector <int> array;
};

void Min_Search(const Parent& array)
{
	int min = array.Get_Element(0);
	for (int i = 0; i < array.Get_Size(); i++)
		if (array.Get_Element(i) < min)
			min = array.Get_Element(i);
	cout << min;
}

int main()
{
	Array_Implemenation a(6);
	Array_Implemenation b(4);
	Array_Implemenation c(2);
	c = b = a;
	a.Print();
	b.Print();
	c.Print();
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	return 0;
}
