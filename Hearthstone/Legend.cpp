#include "../Hearthstone/Legend.h"
#include <stdexcept>
#include <iostream>

void Champion::setTitle(const std::string& t) {
    if (t.empty()) throw std::invalid_argument("Champion title cannot be empty");
    title = t;
}

Champion::Champion()
    : Card(), Adept(), Spell(), title("Unknown Champion") {}

Champion::Champion(const std::string& name, int manaCost,
                   int attack, int health,
                   SpellEffect spellEffect, int spellValue,
                   const std::string& t)
    : Card(name, manaCost),
      Adept(name, manaCost, attack, health),
      Spell(name, manaCost, spellEffect, spellValue),
      title(t) {}

Champion::Champion(const Champion& other)
    : Card(other), Adept(other), Spell(other), title(other.title) {}

Champion& Champion::operator=(const Champion& other) {
    if (this != &other) {
        Adept::operator=(other);
        Spell::operator=(other);
        title = other.title;
    }
    return *this;
}

Champion::~Champion() {}

std::string Champion::getTitle() const { return title; }

void Champion::play() {
    std::cout << "  >> Champion [" << getName() << " - " << title << "] intra pe tabla!\n";
    std::cout << "     Stats: " << getAttack() << "/" << getCurrentHealth() << "\n";
    std::cout << "     Spell activat: " << spellEffectToString(getEffect())
              << " (" << getValue() << ")\n";
}

std::string Champion::getType() const { return "Champion"; }

Card* Champion::clone() const { return new Champion(*this); }

void Champion::display(std::ostream& os) const {
    Card::display(os);
    os << " [" << title << "] ATK:" << getAttack()
       << " HP:" << getCurrentHealth() << "/" << getMaxHealth()
       << " Spell:" << spellEffectToString(getEffect()) << "(" << getValue() << ")";
}

void Champion::read(std::istream& is) {
    Card::read(is);
    int atk, hp;
    std::cout << "  Attack: ";
    is >> atk;
    std::cout << "  Health: ";
    is >> hp;
    setAttack(atk);
    setMaxHealth(hp);

    std::string eff;
    int v;
    std::cout << "  Spell Effect (DAMAGE/HEAL/BUFF_ATTACK/BUFF_HEALTH/BUFF_BOTH): ";
    is >> eff;
    std::cout << "  Spell Value: ";
    is >> v;
    setEffect(spellEffectFromString(eff));
    setValue(v);

    std::cout << "  Title: ";
    is >> title;
}