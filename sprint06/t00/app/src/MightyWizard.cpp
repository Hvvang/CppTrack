#include "MightyWizard.h"

MightyWizard::MightyWizard(std::string& name) :
    m_name(name) { };

void MightyWizard::checkFood(FoodItem* foodItem) {
    auto food = MightyWizard::deductFoodType(foodItem);

    if (food == FoodType::ApplePie) {
        std::cout << "Apple pie. Ugh, not again!" << '\n';
    } else if (food == FoodType::Sweetroll) {
        std::cout << "Sweetroll. Mmm, tasty!" << '\n';
    } else if (food == FoodType::HoneyNut) {
        std::cout << "Honey nut. Mmm, tasty!" << '\n';
    } else if (food == FoodType::PoisonedFood) {
        std::cout << "Poison. Ugh, not again!" << '\n';
    } else {
        std::cout << "<wtf>. Ugh, not again!" << '\n';
    }
};
void MightyWizard::checkFood(FoodItem foodItem) {
    auto food = MightyWizard::deductFoodType(&foodItem);

    if (food == FoodType::ApplePie) {
        std::cout << "Apple pie. Ugh, not again!" << '\n';
    } else if (food == FoodType::Sweetroll) {
        std::cout << "Sweetroll. Mmm, tasty!" << '\n';
    } else if (food == FoodType::HoneyNut) {
        std::cout << "Honey nut. Mmm, tasty!" << '\n';
    } else if (food == FoodType::PoisonedFood) {
        std::cout << "Poison. Ugh, not again!" << '\n';
    } else {
        std::cout << "<wtf>. Ugh, not again!" << '\n';
    }
};

FoodType MightyWizard::deductFoodType(FoodItem* foodItem) {
    if (foodItem != nullptr) {
        return foodItem->getType();
    } else {
        return FoodType::Invalid;
    }
};
