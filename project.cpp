#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    float price;

    void setProduct(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
    }

    void displayProduct() {
        cout << id << "\t" << name << "\t" << price << endl;
    }
};

class Cart {
public:
    Product items[10];
    int count = 0;
    float total = 0;

    void addToCart(Product p) {
        items[count] = p;
        total += p.price;
        count++;
        cout << "Product added to cart!\n";
    }

    void showCart() {
        cout << "\n--- Cart Items ---\n";
        for (int i = 0; i < count; i++) {
            cout << items[i].name << " - " << items[i].price << endl;
        }
        cout << "Total: " << total << endl;
    }
};

int main() {
    Product products[5];
    Cart cart;

    // Adding products
    products[0].setProduct(1, "Laptop", 50000);
    products[1].setProduct(2, "Mobile", 20000);
    products[2].setProduct(3, "Headphones", 2000);
    products[3].setProduct(4, "Keyboard", 1500);
    products[4].setProduct(5, "Mouse", 800);

    int choice, id;
    char cont;

    do {
        cout << "\n--- Product List ---\n";
        cout << "ID\tName\tPrice\n";
        for (int i = 0; i < 5; i++) {
            products[i].displayProduct();
        }

        cout << "\nEnter Product ID to add to cart: ";
        cin >> id;

        if (id >= 1 && id <= 5) {
            cart.addToCart(products[id - 1]);
        } else {
            cout << "Invalid ID!\n";
        }

        cout << "Do you want to continue shopping? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cart.showCart();

    cout << "\nThank you for shopping!\n";
    return 0;
}