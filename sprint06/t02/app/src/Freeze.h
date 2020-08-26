#pragma once

#include "ISpell.h"
#include "SpellType.h"

class Freeze : public Spells::ISpell {
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override {
        other.setHealth(other.getHealth() - 20);
        owner.setMana(owner.getMana() - 30);
        return true;
    }
    Spells::SpellType getType() const override {
        return Spells::SpellType::Freeze;
    }
    std::string getSpellName() const override {
        return "freeze";
    }
    int getManaCost() const override {
        return 30;
    }
};
