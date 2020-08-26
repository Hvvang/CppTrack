#include "FoodItem.h"

FoodItem::FoodItem(const FoodType type) {
    m_type = type;
};

FoodType FoodItem::getType() const {
    return m_type;
}
