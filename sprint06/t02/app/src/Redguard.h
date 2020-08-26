#pragma once

#include "Creature.h"
// #include "ISpell.h"
// namespace Spells {class ISpell;}
// namespace Creatures {class Creature;}

class Redguard : public Creatures::Creature {
public:
    Redguard(std::string&& name);
    void sayPhrase() const override;
};
