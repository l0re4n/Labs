#include <iostream>
#include <string>

using namespace std;

class Goods {
private:
    string name;    // Name
    double price;   // Price
    int quantity;   // Amount
    string invoice; // ID

public:
    Goods(string n, double p, int q, string inv)
        : name(n), price(p), quantity(q), invoice(inv) {}

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    double calculateTotalCost() const {
        return price * static_cast<double>(quantity);
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Amount: " << quantity << endl;
        cout << "ID: " << invoice << endl;
        cout << "New price: " << calculateTotalCost() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "English");
    // double inputPrice;
    // int inputQuantity;

    Goods product("Laptop", 300000.0, 3, "FFF000");

    product.displayInfo();

    // cout << "Input new price: ";
    // cin >> inputPrice;
    // cout << "Input amount of product: ";
    // cin >> inputQuantity;

    product.setPrice(450000.0);
    product.setQuantity(2);

    product.displayInfo();

    return 0;
}
