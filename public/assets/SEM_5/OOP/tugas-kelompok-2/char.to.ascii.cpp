#include <iostream>
#include <string>
#include <bitset>

class InputHandler {
private:
    std::string input;

public:
    void getInput() {
        std::cout << "Masukkan Nama / Karakter: ";
        std::getline(std::cin, input);
    }

    std::string getInputValue() const {
        return input;
    }
};

class ASCIIconverter {
public:
    std::string convertToASCII(const std::string& input) {
        std::string asciiCode;
        for (char c : input) {
            asciiCode += std::bitset<8>(c).to_string() + " ";
        }
        return asciiCode;
    }
};

int main() {
    InputHandler inputHandler;
    inputHandler.getInput();
    std::string inputValue = inputHandler.getInputValue();

    ASCIIconverter converter;
    std::string asciiCode = converter.convertToASCII(inputValue);

    std::cout << "Kode Biner: " << asciiCode << std::endl;

    return 0;
}
