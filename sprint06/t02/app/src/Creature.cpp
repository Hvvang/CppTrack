#include "Creature.h"

namespace Creatures {class Creature;}

Creatures::Creature::Creature(std::string&& name) {
    m_name = name;
    m_health = 100;
    m_mana = 100;
    std::cout << m_name << " was born!" << '\n';
};

Creatures::Creature::~Creature() {
    // delete m_spells;
}

void Creatures::Creature::learnSpell(Spells::ISpell* spell) {
    if (Utils::Find(m_spells, spell) == m_spells.end()) {
        m_spells.insert(spell);
        std::cout << m_name << " has learned " << spell->getSpellName()<< " spell successfully!" << '\n';
    } else {
        std::cout << m_name << "  already knows " << spell->getSpellName() << "  spell!" << '\n';
    }
}

void Creatures::Creature::castSpell(const Spells::SpellType type, Creature& creature) {
    auto it = Utils::FindIf(m_spells, [&type](Spells::ISpell* spell) {
        return spell->getType() == type;
    });
    if (it != m_spells.end()) {
        if ((*it)->getManaCost() <= m_mana && (*this).getHealth() > 0) {
            (*it)->cast(*this, creature);
            std::cout << m_name << " casted " << (*it)->getSpellName()
                      << " spell on " << creature.getName() << "!\n";
        } else {
            std::cout << m_name << " can't cast " << (*it)->getSpellName() << "!\n";
        }
    } else {
        if (type == Spells::SpellType::Equilibrium) {
            std::cout << "equilibrium";
        } else if (type == Spells::SpellType::Fireball) {
            std::cout << "fireball";
        } else if (type == Spells::SpellType::Flames) {
            std::cout << "flames";
        } else if (type == Spells::SpellType::Freeze) {
            std::cout << "freeze";
        } else if (type == Spells::SpellType::Healing) {
            std::cout << "healing";
        }
        std::cout << " spell is not learned by " << m_name << '\n';
    }
}

std::string Creatures::Creature::getName() const {
    return m_name;
}

int Creatures::Creature::getHealth() const {
    return m_health;
}

int Creatures::Creature::getMana() const {
    return m_mana;
}

void Creatures::Creature::setHealth(int health) {
    m_health = health;
}
void Creatures::Creature::setMana(int mana) {
    m_mana = mana;
}
std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    std::string out;

    out = creature.getName() + " : " + std::to_string(creature.getHealth())
          + " HP, " + std::to_string(creature.getMana()) + " MP.";
    os << out;
    return os;
}
