#include <iostream>
using namespace std;

class Animal
{
public:
	
	Animal() {
		cout << "animal constructor called\n";
	}
	virtual ~Animal() {
		cout << "animal destructor called\n";
	}
	
	virtual void Say() = 0;
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "dog constructor called\n";
	}
	~Dog() override {
		cout << "dog destructor called\n";
	}
	void Say () override 
	{
		cout << "ruff" << endl;
	}
};

class Cat : public Animal 
{
public:
	Cat() {
		cout << "cat constructor called\n";
	}
	~Cat() override {
		cout << "cat destuctor called\n";
	}
	void Say() override
	{
		cout << "meow" << endl;
	}
	
};

int main()
{
	Cat* myCatPtr = new Cat();
	Dog* myDogPtr = new Dog();

	Animal** array = new Animal*[2];

	array[0] = myDogPtr;
	array[1] = myCatPtr;
	
	array[0]->Say();
	array[1]->Say();

	delete[] array;
	
	delete myCatPtr;
	delete myDogPtr;
}