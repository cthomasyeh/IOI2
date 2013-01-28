void orderChocolate() {
			chocolate--;
			cherry--;
			revenue = revenue + 3;
		}
		void orderVanilla() {
			vanilla--;
			cherry--;
			revenue = revenue + 3;
		}
		void orderSundae() {
			vanilla = vanilla - 2;
			chocolate--;
			cherry = cherry - 3;
			revenue = revenue + 5;
		}
		void printSupplies() {
			cout << "Vanilla: " << vanilla << endl;
			cout << "Chocolate: " << chocolate << endl;
			cout << "Cherry: " << cherry << endl;
		}
		double getRevenue() {
			return revenue;
		}
};


int main() {
	BaskinRobbins myShop;
	cout << myShop.getRevenue();

	myShop.printSupplies();
	myShop.orderChocolate();
	myShop.orderVanilla();
	myShop.orderChocolate();
	myShop.orderSundae();
	myShop.printSupplies();
	cout << "Money made: " << myShop.getRevenue() << endl;

	Sleep (5000);
	return 0;
}
