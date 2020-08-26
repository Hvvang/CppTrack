#pragma once

#include "Container.h"

class Barrel final : public Container {
public:
    Barrel();
    std::string name() const override;
};
