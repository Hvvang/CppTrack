#pragma once

// #include "Creature.h"
/* ISpell.h */


namespace Creatures { class Creature ;}

namespace Spells {
    #include "SpellType.h"

class ISpell {
public:
    virtual ~ISpell() = default;
    virtual bool cast(Creatures::Creature& owner, Creatures::Creature& other) = 0;
    virtual SpellType getType() const = 0;
    virtual std::string getSpellName() const = 0;
    virtual int getManaCost() const = 0;
};
}
// end namespace Spells
bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs);
