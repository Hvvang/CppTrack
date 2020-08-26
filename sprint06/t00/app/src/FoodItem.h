#pragma once

#include "FoodType.h"

class FoodItem {
public:
    FoodItem(const FoodType type);
    FoodType getType() const;
private:
    FoodType m_type;
};
