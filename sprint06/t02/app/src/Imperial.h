#pragma once

#include "Creature.h"

class Imperial : public Creatures::Creature {
public:
    Imperial(std::string&& name);
    void sayPhrase() const override;
};
