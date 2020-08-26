#pragma once

#include "ISpell.h"
#include "SpellType.h"

class Equilibrium : public Spells::ISpell {
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override {
        owner.setHealth(owner.getHealth() - 25);
        owner.setMana(owner.getMana() + 25);
        return true;
    }
    Spells::SpellType getType() const override {
        return Spells::SpellType::Equilibrium;
    }
    std::string getSpellName() const override {
        return "equilibrium";
    }
    int getManaCost() const override {
        return 0;
    }
};
