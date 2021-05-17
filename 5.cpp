#include <iostream>
#include <string>
using namespace std;

class Coffee
{
public:
	virtual double Get_Price() = 0;
	virtual double Operation() = 0;
	virtual ~Coffee() {}
};

class Espresso : public Coffee
{
	double price = 22.10;
public:
	double Operation() override {
		cout << "\tEspresso\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

class Cappuccino : public Coffee
{
	double price = 35.20;
public:
	double Operation() override {
		cout << "\tCappuccino\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

class Americano : public Coffee
{
	double price = 14.50;
public:
	double Operation() override {
		cout << "\tAmericano\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

class Latte : public Coffee
{
	double price = 26.45;
public:
	double Operation() override {
		cout << "\tLatte\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

class Black_coffee : public Coffee
{
	double price = 10.50;
public:
	double Operation() override {
		cout << "\tBlack coffee\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

class Doppio : public Coffee
{
	double price = 23.80;
public:
	double Operation() override {
		cout << "\tDoppio\n";
		return this->Get_Price();
	}

	double Get_Price() override { return  this->price; }
};

////////////////////////////////////

class Decorator : public Coffee
{
protected:
	Coffee* coffee;
public:
	Decorator(Coffee* _coffee_) : coffee(_coffee_) { }

	double Operation() override { return this->coffee->Operation(); }
};

class Milk : public Decorator
{
	double price = 5.50;
public:
	Milk(Coffee* coffee) : Decorator(coffee) { }

	double Operation() override {
		cout << "+ Milk ";
		return this->Get_Price() + Decorator::Operation();
	}

	double Get_Price() override { return  this->price; }
};

class Sugar : public Decorator
{
	double price = 2.30;
public:
	Sugar(Coffee* coffee) : Decorator(coffee) {}

	double Operation() override {
		cout << "+ Sugar ";
		return this->Get_Price() + Decorator::Operation();
	}

	double Get_Price() override { return  this->price; }
};

class Cream : public Decorator
{
	double price = 8.25;
public:
	Cream(Coffee* coffee) : Decorator(coffee) {}

	double Operation() override {
		cout << "+ Cream ";
		return this->Get_Price() + Decorator::Operation();
	}

	double Get_Price() override { return  this->price; }
};

class Chocolate : public Decorator
{
	double price = 4.35;
public:
	Chocolate(Coffee* coffee) : Decorator(coffee) {}

	double Operation() override {
		cout << "+ Chocolate ";
		return this->Get_Price() + Decorator::Operation();
	}

	double Get_Price() override { return  this->price; }
};

////////////////////////////////////

Coffee* Get_Milk(Coffee* coffee)
{
	string choise;
	cout << "Add milk to coffee?\nyes/no\n"; cin >> choise; cout << endl;

	if (choise == "yes") {
		coffee = new Milk(coffee);
		return coffee;
	}

	else { return coffee; }
}

Coffee* Get_Sugar(Coffee* coffee)
{
	string choise;
	cout << "Add sugar to coffee?\nyes/no\n"; cin >> choise; cout << endl;

	if (choise == "yes") {
		coffee = new Sugar(coffee);
		return coffee;
	}

	else { return coffee; }
}

Coffee* Get_Cream(Coffee* coffee)
{
	string choise;
	cout << "Add cream to coffee?\nyes/no\n"; cin >> choise; cout << endl;

	if (choise == "yes") {
		coffee = new Cream(coffee);
		return coffee;
	}

	else { return coffee; }
}

Coffee* Get_Chocolate(Coffee* coffee)
{
	string choise;
	cout << "Add chocolate to coffee?\yes/no\n"; cin >> choise; cout << endl;

	if (choise == "yes") {
		coffee = new Chocolate(coffee);
		return coffee;
	}

	else { return coffee; }
}


void MakeCoffee()
{
	int choise = 0;
	cout << "\t\tWelcome!\n\n\tWhat coffee would you like to order?\n1. Espresso\n2. Cappuccino\n3. Americano\n4. Latte\n5. Black coffee\n6. Doppio\nSelect: ";
	cin >> choise; cout << endl;

	if (choise == 1) {
		Coffee* coffee = new Espresso();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else if (choise == 2) {
		Coffee* coffee = new Cappuccino();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else if (choise == 3) {
		Coffee* coffee = new Americano();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else if (choise == 4) {
		Coffee* coffee = new Latte();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else if (choise == 5) {
		Coffee* coffee = new Black_coffee();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else if (choise == 6) {
		Coffee* coffee = new Doppio();
		coffee = Get_Milk(coffee);
		coffee = Get_Sugar(coffee);
		coffee = Get_Cream(coffee);
		coffee = Get_Chocolate(coffee);
		cout << "\nPrice = " << coffee->Operation();
	}

	else { cout << "There is no such coffee\n"; }
	cout << endl;
	MakeCoffee();
}

////////////////////////////////////

int main()
{
	MakeCoffee();

	system("pause");
	return 0;
}