#include "src/UniversalReferenceDeterminant.h"

int main() {
    UniversalReferenceDeterminant::determineReference(10);

    const auto intVal = 10;
    UniversalReferenceDeterminant::determineReference(intVal);

    UniversalReferenceDeterminant::determineReference('u');

    const auto charVal = 'u';
    UniversalReferenceDeterminant::determineReference(charVal);

    return 0;
}
