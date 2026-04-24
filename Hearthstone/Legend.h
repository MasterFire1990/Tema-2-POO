#pragma once
#include "Adept.h"
#include "Spell.h"

class Champion : public Adept, public Spell {
    std::string title;

    void setTitle(const std::string& t);

public:
    Champion();
    Champion(const std::string& name, int manaCost,
             int attack, int health,
             SpellEffect spellEffect, int spellValue,
             const std::string& title);
    Champion(const Champion& other);
    Champion& operator=(const Champion& other);
    ~Champion() override;

    std::string getTitle() const;

    void play() override;
    std::string getType() const override;
    Card* clone() const override;

    void display(std::ostream& os) const override;
    void read(std::istream& is) override;
};