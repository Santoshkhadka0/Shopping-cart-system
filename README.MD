# 🛒 Shopping Cart Management System

OOP II Final Project — CLI-Based Shopping Cart Management System in C++

---

## 📖 Project Overview

The Shopping Cart Management System is a command-line based e-commerce shopping application developed in C++ using Object-Oriented Programming (OOP) principles.

The system allows users to:

* View available products
* Add products to a shopping cart
* Remove products from the cart
* View cart contents
* Checkout purchases
* Generate order summaries
* Manage customer information
* Demonstrate real-world OOP concepts

---

## ✨ Features

➕ Add products to cart

❌ Remove products from cart

🛍️ View shopping cart contents

📋 View product catalog

💳 Checkout and billing system

📦 Generate order summary

👤 Customer profile management

🧠 Runtime object interaction

⚠️ Input validation

---

## 🧠 OOP Concepts Used

| Concept            | Implementation                           |
| ------------------ | ---------------------------------------- |
| Encapsulation      | Private data members with public methods |
| Abstraction        | Product, Cart, User and Order classes    |
| Composition        | User HAS-A Cart                          |
| Object Interaction | Cart communicates with Order             |
| Data Hiding        | Private member variables                 |
| Class Design       | Separate responsibilities for each class |
| Validation         | Safe integer input function              |
| Modular Design     | Multiple interacting classes             |

---

## 👥 Team Members And Responsibilities

| No. | Name           | Role               | Main Responsibility                                                             |
| --- | -------------- | ------------------ | ------------------------------------------------------------------------------- |
| 1   | ABISHEK        | Product Module     | Product class implementation, product attributes, product display functionality |
| 2   | KHADKA SANTOSH | Cart Management    | Cart class, add/remove products, cart display, checkout functionality           |
| 3   | ROSHAN         | Order Management   | Order class, order summary generation, billing calculation                      |
| 4   | ANISH          | User Management    | User class, customer profile management, cart ownership through composition     |
| 5   | DIWASH         | System Integration | Main menu, object coordination, workflow integration, testing and debugging     |

---

## 👑 Team Leader Contribution

### DIWASH

Responsible for integrating all modules into one fully functional Shopping Cart Management System.

### Main Contributions

* Main menu implementation
* User interaction flow
* Integration of all classes
* Program execution workflow
* Input validation integration
* Testing and debugging
* Final project review
* Module coordination

---

## 📂 Project Structure

```text
Shopping_cart_updated.cpp

Classes:
│
├── Product
│   ├── id
│   ├── name
│   └── price
│
├── Cart
│   ├── addItem()
│   ├── removeItem()
│   ├── viewCart()
│   ├── getItems()
│   └── checkout()
│
├── Order
│   ├── orderId
│   ├── userName
│   ├── items
│   └── displayOrder()
│
├── User
│   ├── userId
│   ├── name
│   ├── cart
│   └── getCart()
│
└── Main Program
    ├── Product Management
    ├── Cart Operations
    ├── Checkout System
    └── Order Generation
```

---

## ⚙️ Build And Run

### Compile

```bash
g++ Shopping_cart_updated.cpp -o shoppingcart
```

### Run

```bash
./shoppingcart
```

---

## 📁 Files To Upload

### Upload These

```text
README.md
Shopping_cart_updated.cpp
.gitignore
```

### Do NOT Upload

```text
*.exe
*.o
*.obj
build/
```

---

## 🌿 Suggested Git Branches

| Team Member    | Branch                    |
| -------------- | ------------------------- |
| ABISHEK        | abishek-product-module    |
| KHADKA SANTOSH | santosh-cart-management   |
| ROSHAN         | roshan-order-management   |
| ANISH          | anish-user-management     |
| DIWASH         | diwash-system-integration |

---

## 💬 Suggested Commit Messages

### Product Module

* Add Product class implementation
* Add product display functionality
* Implement product attributes

### Cart Management

* Add shopping cart functionality
* Add product removal feature
* Implement checkout calculation

### Order Management

* Add Order class implementation
* Add billing and order summary
* Implement order generation workflow

### User Management

* Add User class
* Implement cart ownership
* Add customer profile functionality

### System Integration

* Integrate all project modules
* Add menu-driven interface
* Finalize application workflow

---

## 📚 Technologies Used

* C++17
* Object-Oriented Programming
* STL Vector
* Command Line Interface (CLI)
* Git
* GitHub

---

## 🏁 Final Notes

This project was developed as part of the OOP II Final Project and demonstrates practical implementation of:

* Object-Oriented Programming
* Encapsulation
* Composition
* Class Interaction
* Shopping Cart Systems
* Menu-Driven Applications
* Team Collaboration Using GitHub

⭐ If you like this project, give it a star on GitHub!
