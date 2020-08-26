#pragma once

#include "ISpell.h"
#include "SpellType.h"

class Healing : public Spells::ISpell {
    bool cast(Creatures::Creature& owner, Creatures::Creature& other) override {
        owner.setHealth(owner.getHealth() + 10);
        owner.setMana(owner.getMana() - 15);
        return true;
    }
    Spells::SpellType getType() const override {
        return Spells::SpellType::Healing;
    }
    std::string getSpellName() const override {
        return "healing";
    }
    int getManaCost() const override {
        return 15;
    }
};
