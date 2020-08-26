#pragma once

#include <iostream>
#include <string>
#include "FoodItem.h"


class AbstractWizard {
public:
    virtual FoodType deductFoodType(FoodItem* foodItem) = 0;
};

class MightyWizard final : public AbstractWizard {
public:
    MightyWizard(std::string& name);

    FoodType deductFoodType(FoodItem* foodItem) override;

    void checkFood(FoodItem foodItem);
    void checkFood(FoodItem* foodItem);

private:
    const std::string m_name;
};
