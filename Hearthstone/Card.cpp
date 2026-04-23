#include "../Hearthstone/Card.h"
#include <stdexcept>

void Card::setName(const std::string& n) {
    if (n.empty()) throw std::invalid_argument("Card name cannot be empty");
    name = n;
}

void Card::setManaCost(int cost) {
    if (cost < 0) throw std::invalid_argument("Mana cost cannot be negative");
    manaCost = cost;
}

Card::Card() : name("Unknown"), manaCost(0) {}

Card::Card(const std::string& name, int manaCost) {
    setName(name);
    setManaCost(manaCost);
}

Card::Card(const Card& other) : name(other.name), manaCost(other.manaCost) {}

Card& Card::operator=(const Card& other) {
    if (this != &other) {
        name = other.name;
        manaCost = other.manaCost;
    }
    return *this;
}

Card::~Card() {}

std::string Card::getName() const { return name; }
int Card::getManaCost() const { return manaCost; }

void Card::display(std::ostream& os) const {
    os << "[" << getType() << "] " << name << " (Cost: " << manaCost << ")";
}

void Card::read(std::istream& is) {
    std::string n;
    int cost;
    std::cout << "  Card name: ";
    is >> n;
    std::cout << "  Mana cost: ";
    is >> cost;
    setName(n);
    setManaCost(cost);
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.display(os);
    return os;
}

std::istream& operator>>(std::istream& is, Card& card) {
    card.read(is);
    return is;
}