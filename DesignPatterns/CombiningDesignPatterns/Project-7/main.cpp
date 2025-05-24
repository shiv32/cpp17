/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
    Shopping Cart System
    Patterns: Factory, Strategy, Decorator, Observer, Composite
 * 
 * 
 * 
 * @version 0.1
 * @date 2025-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// ------------------- Observer -------------------
class CartObserver
{
public:
    virtual void onPriceUpdate(double total) = 0;
};

class ConsoleUI : public CartObserver
{
public:
    void onPriceUpdate(double total) override
    {
        std::cout << "[Cart Updated] Total Price: $" << total << "\n";
    }
};

// ------------------- Strategy -------------------
class PricingStrategy
{
public:
    virtual double calculate(double basePrice) = 0;
    virtual ~PricingStrategy() = default;
};

class StandardPricing : public PricingStrategy
{
public:
    double calculate(double basePrice) override { return basePrice; }
};

class DiscountPricing : public PricingStrategy
{
    double discount;

public:
    DiscountPricing(double d) : discount(d) {}
    double calculate(double basePrice) override { return basePrice * (1.0 - discount); }
};

// ------------------- Component (Composite) -------------------
class Product
{
protected:
    std::string name;
    double price;

public:
    Product(std::string name, double price) : name(std::move(name)), price(price) {}
    virtual ~Product() = default;
    virtual double getPrice() const = 0;
    virtual void display(int indent = 0) const = 0;
    const std::string &getName() const { return name; }
};

using ProductPtr = std::shared_ptr<Product>;

class SimpleProduct : public Product
{
public:
    SimpleProduct(const std::string &name, double price) : Product(name, price) {}
    double getPrice() const override { return price; }
    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "- " << name << ": $" << price << "\n";
    }
};

class BundleProduct : public Product
{
    std::vector<ProductPtr> items;

public:
    BundleProduct(const std::string &name) : Product(name, 0) {}
    void add(ProductPtr item) { items.push_back(item); }
    double getPrice() const override
    {
        double total = 0;
        for (auto &i : items)
            total += i->getPrice();
        return total;
    }
    void display(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << "+ Bundle: " << name << "\n";
        for (auto &i : items)
            i->display(indent + 2);
    }
};

// ------------------- Decorator -------------------
class PromotionDecorator : public Product
{
protected:
    ProductPtr wrapped;
    std::unique_ptr<PricingStrategy> strategy;

public:
    PromotionDecorator(ProductPtr product, std::unique_ptr<PricingStrategy> strategy)
        : Product(product->getName(), 0), wrapped(std::move(product)), strategy(std::move(strategy)) {}

    double getPrice() const override
    {
        return strategy->calculate(wrapped->getPrice());
    }

    void display(int indent = 0) const override
    {
        wrapped->display(indent);
        std::cout << std::string(indent, ' ') << "  -> Promotion Applied: New Price $" << getPrice() << "\n";
    }
};

// ------------------- Factory -------------------
class ProductFactory
{
public:
    static ProductPtr createProduct(const std::string &name, double price)
    {
        return std::make_shared<SimpleProduct>(name, price);
    }

    static ProductPtr createBundle(const std::string &name, const std::vector<ProductPtr> &items)
    {
        auto bundle = std::make_shared<BundleProduct>(name);
        for (auto &item : items)
            bundle->add(item);
        return bundle;
    }
};

// ------------------- Shopping Cart -------------------
class ShoppingCart
{
    std::vector<ProductPtr> items;
    std::vector<CartObserver *> observers;

public:
    void add(ProductPtr product)
    {
        items.push_back(product);
        notify();
    }

    void attach(CartObserver *observer) { observers.push_back(observer); }

    void notify()
    {
        double total = getTotalPrice();
        for (auto obs : observers)
            obs->onPriceUpdate(total);
    }

    double getTotalPrice() const
    {
        double total = 0;
        for (auto &item : items)
            total += item->getPrice();
        return total;
    }

    void displayCart() const
    {
        std::cout << "\nShopping Cart:\n";
        for (auto &item : items)
        {
            item->display(2);
        }
        std::cout << "Total: $" << getTotalPrice() << "\n";
    }
};

// ------------------- Main -------------------
int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ShoppingCart cart;
    ConsoleUI ui;
    
    cart.attach(&ui);

    auto apple = ProductFactory::createProduct("Apple", 1.0);
    auto banana = ProductFactory::createProduct("Banana", 1.5);
    auto milk = ProductFactory::createProduct("Milk", 2.0);

    auto fruitPack = ProductFactory::createBundle("Fruit Pack", {apple, banana});

    auto promoMilk = std::make_shared<PromotionDecorator>(milk, std::make_unique<DiscountPricing>(0.2));

    cart.add(fruitPack);
    cart.add(promoMilk);

    cart.displayCart();

    return 0;
}
