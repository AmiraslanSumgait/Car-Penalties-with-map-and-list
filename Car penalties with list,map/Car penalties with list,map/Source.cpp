#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;


class Penalty {
	string content;
	size_t penaltyPoint;
	int paymentOfPenalty;
	string policeName;
	string policeSurname;
public:
	
	Penalty() :content(), penaltyPoint(), paymentOfPenalty(), policeName(), policeSurname() {}

	Penalty(const string& content, const size_t& penaltyPoint, const size_t& paymentOfPenalty, const string& policeName, const string& policeSurname)
	{
		
		this->penaltyPoint = penaltyPoint;
	
		this->paymentOfPenalty = paymentOfPenalty;
		this->content = content;
		this->policeName = policeName;
		this->policeSurname = policeSurname;
	}

	void showPenalty() {
		
		cout << "Penalty text: " << this->content << endl;
		cout << "Penalty point: " << this->penaltyPoint << endl;
		cout << "Penalty amount: " << this->paymentOfPenalty << " manat" << endl;
		cout << "Police name: " << this->policeName << endl;
		cout << "Police surname: " << this->policeSurname << endl;
	}
};



class Car {
	map<string, list<Penalty>> carPenalties;
public:
	void printPenalties() {
		for (auto& carPenalty : carPenalties)
		{
			cout << "Car number: " << carPenalty.first << endl;
			cout << "Penalties" << endl;
			for (auto& i : carPenalty.second)
			{
				i.showPenalty();
			}
			cout << endl;
		}
	}

	void addPenalty(string carNumber, list<Penalty> penalty) {
		carPenalties.insert({ carNumber,penalty });
	}
};

void main() {
	Penalty p1("Ara mesafesi ", 3, 40, "Namiq", "Qaracuxurlu");
	Penalty p2("Sernisin dasima qaydasinin pozulmas ", 3, 60, "Ferhad", "Aliyev");
	list<Penalty> c1penalty;
	c1penalty.push_back(p1);
	c1penalty.push_back(p2);
	Car c1;
	c1.addPenalty("90 EE 320",c1penalty);
	c1.printPenalties();

}