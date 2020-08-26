#pragma once

#include "ISpell.h"
#include "SpellType.h"

class Flames : public Spells::ISpell {
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override {
        other.setHealth(other.getHealth() - 8);
        owner.setMana(owner.getMana() - 14);
        return true;
    }
    Spells::SpellType getType() const override {
        return Spells::SpellType::Flames;
    }
    std::string getSpellName() const override{
        return "flames";
    }
    int getManaCost() const override {
        return 14;
    }
};
