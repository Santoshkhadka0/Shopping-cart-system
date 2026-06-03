#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =======================
// 1. PRODUCT CLASS
// (EXISTING – handled by Abishek)
// =======================
class Product
{
private:
    int id;
    string name;
    double price;

public:
    Product(int id, string name, double price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }

    void display()
    {
        cout << id << ". " << name << " - $" << price << endl;
    }
};

// =======================
// 2. CART CLASS
// (EXISTING – handled by Santosh)
// =======================
class Cart
{
private:
    vector<Product> items; // Encapsulated list of products

public:
    // add item to cart
    void addItem(Product p)
    {
        items.push_back(p);
        cout << p.getName() << " added to cart.\n";
    }

    // remove item from cart
    void removeItem(int id)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getId() == id)
            {
                cout << items[i].getName() << " removed from cart.\n";
                items.erase(items.begin() + i);
                return;
            }
        }
        cout << "Item not found in cart!\n";
    }

    // display cart contents
    void viewCart()
    {
        if (items.empty())
        {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "\n--- CART ITEMS ---\n";
        for (auto &item : items)
            item.display();
    }

    // ===== UPDATED PART =====
    // Added to allow Order object to receive cart items
    // This supports object interaction between Cart and Order
    vector<Product> getItems()
    {
        return items;
    }

    // checkout logic inside Cart (existing, but now used by Order)
    void checkout()
    {
        if (items.empty())
        {
            cout << "Cart is empty! Nothing to checkout.\n";
            return;
        }

        double total = 0;
        for (auto &item : items)
            total += item.getPrice();

        cout << "\n===========================\n";
        cout << "Total Bill: $" << total << endl;
        cout << "===========================\n";
    }
};
// =======================
// 3. ORDER CLASS   NEWLY ADDED
// (Added to ensure OOP usage for Roshan)
// =======================
class Order
{
private:
    int orderId;
    string userName;
    vector<Product> items;
    double total;

public:
    Order(int id, string userName, vector<Product> items)
    {
        orderId = id;
        this->userName = userName;
        this->items = items;
        total = 0;
        for (auto &item : items)
            total += item.getPrice();
    }

    void displayOrder()
    {
        cout << "\n--- ORDER SUMMARY ---\n";
        cout << "Customer: " << userName << endl;
        cout << "Order ID: " << orderId << endl;
        for (auto &item : items)
            item.display();
        cout << "Total Amount: $" << total << endl;
        cout << "Thank you for shopping!\n Visit Us again";
    }
};

// ==============================
// 4. USER CLASS  NEWLY ADDED
// (Added to ensure OOP usage for Anish)
// ==============================
class User
{
private:
    int userId;
    string name;
    Cart cart; // Composition: User HAS-A Cart

public:
    User(int id)
    {
        userId = id;
        name = "Guest";
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    Cart &getCart()
    {
        return cart;
    }
};
// =======================
// SAFE INTEGER INPUT
// (Procedural helper – acceptable utility function)
// =======================
int readInt()
{
    string input;
    while (true)
    {
        cin >> input;
        bool valid = true;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                break;
            }
        }
        if (valid)
            return stoi(input);
        cout << "Invalid input! Enter a number: ";
    }
}

// =======================
// MAIN PROGRAM
// (Handled by Diwash – object coordination)
// =======================
int main()
{

    vector<Product> products = {
        Product(1, "Laptop", 850.00),
        Product(2, "Keyboard", 20.00),
        Product(3, "Mouse", 10.50),
        Product(4, "Headphones", 45.99),
        Product(5, "iPhone 17 Pro Max", 1666.00),
        Product(6, "AirPods", 566.00)};

    // ===== UPDATED PART =====
    // User object introduced instead of using Cart directly
    User user(1);

    int choice, orderCounter = 1;

    do
    {
        cout << "\n===== SHOPPING CART MENU =====\n";
        cout << "0. Enter / Change User Name\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. Remove from Cart\n";
        cout << "4. View Cart\n";
        cout << "5. Checkout\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        choice = readInt();

        switch (choice)
        {

        case 0:
        {
            cout << "Enter user name: ";
            cin.ignore();
            string name;
            getline(cin, name);
            user.setName(name);
            cout << "User name set to: " << name << endl;
            break;
        }

        case 1:
            cout << "\n--- PRODUCT LIST ---\n";
            for (auto &p : products)
                p.display();
            break;

        case 2:
        {
            cout << "Enter Product IDs to add (0 to stop): ";
            while (true)
            {
                int id = readInt();
                if (id == 0)
                    break;

                bool found = false;
                for (auto &p : products)
                {
                    if (p.getId() == id)
                    {
                        user.getCart().addItem(p);
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Product not found!\n";
            }
            break;
        }

        case 3:
            cout << "Enter Product ID to remove: ";
            user.getCart().removeItem(readInt());
            break;

        case 4:
            user.getCart().viewCart();
            break;

        case 5:
        {
            user.getCart().checkout();

            // ===== UPDATED PART =====
            // Order object created after checkout to represent a completed purchase
            Order order(orderCounter++, user.getName(), user.getCart().getItems());
            order.displayOrder();
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
