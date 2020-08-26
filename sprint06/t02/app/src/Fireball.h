#pragma once

#include "ISpell.h"
#include "SpellType.h"

class Fireball : public Spells::ISpell {
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override {
        other.setHealth(other.getHealth() - 40);
        owner.setMana(owner.getMana() - 50);
        return true;
    }
    Spells::SpellType getType() const override {
        return Spells::SpellType::Fireball;
    }
    std::string getSpellName() const override {
        return "fireball";
    }
    int getManaCost() const override {
        return 50;
    }
};
