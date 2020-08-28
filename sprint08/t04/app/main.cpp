#include "src/Serializer.h"
#include "src/SomeClass.h"

void argsValidator(char **argv, int& intVal, float& floatVal) {
    auto index = 0ul;

    intVal = stoi(std::string(argv[2]), &index);
    if (argv[2][index] != '\0') {
        throw std::invalid_argument("Invalid argument");
    }
    floatVal = stof(std::string(argv[4]), &index);
    if (argv[4][index] != '\0') {
        throw std::invalid_argument("Invalid argument");
    }
}

int main(int argc, char **argv) {
    Serializer ser;

    if (argc == 2) {
        if (std::string(argv[1]) == "int") {
            int res = ser.deserialize<int>("int");
            std::cout << "Deserialized int: " << std::to_string(res) << '\n';
        } else if (std::string(argv[1]) == "float") {
            float res = ser.deserialize<float>("float");
            std::cout << "Deserialized float: " << std::to_string(res) << '\n';
        } else {
            SomeClass res = ser.deserialize<SomeClass>(std::string(argv[1]));
            std::cout << "Deserialized ";
            res.output();
        }
    } else if (argc == 3) {
        if (std::string(argv[1]) == "int") {
            auto index = 0ul;
            int intVal = stoi(std::string(argv[2]), &index);
            if (argv[2][index] != '\0') {
                throw std::invalid_argument("Invalid argument");
            }
            ser.serialize<int>(&intVal, "int");
            std::cout << "int: " << intVal << " serialized\n";
        } else if (std::string(argv[1]) == "float") {
            auto index = 0ul;
            float floatVal = stof(std::string(argv[2]), &index);
            if (argv[2][index] != '\0') {
                throw std::invalid_argument("Invalid argument");
            }
            ser.serialize<float>(&floatVal, "float");
            std::cout << "float: " << floatVal << " serialized\n";
        } else {
            std::cerr << "error" << '\n';
        }
    } else if (argc == 5) {
        int intVal;
        if (std::string(argv[3]).length() != 1) {
            throw std::invalid_argument("Invalid argument");
        }
        char charVal = argv[3][0];
        float floatVal;
        argsValidator(argv, intVal, floatVal);
        SomeClass type(intVal, charVal, floatVal);
        ser.serialize(&type, std::string(argv[1]));
        type.output();
        std::cout << " serialized\n";
    } else {
        std::cerr << "usage: ./serializer [arg1] [arg2] [arg3] [arg4]" << '\n';
    }
    return 0;
}
