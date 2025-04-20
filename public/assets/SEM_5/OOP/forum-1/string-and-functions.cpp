#include <iostream>
#include <string>

class StringManipulator {
  public:
  static bool compare(const std::string& str1, const std::string& str2) {
    return str1 == str2;
  }

  static void swap(std::string& str1, std::string& str2) {
    std::swap(str1, str2);
  }

  static void replace(std::string& str, const std::string& oldSubstr, const std::string& newSubstr) {
        size_t pos = 0;
        while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
            str.replace(pos, oldSubstr.length(), newSubstr);
            pos += newSubstr.length();
        }
    }

  static void append(std::string& str, const std::string& addtional) {
    str.append(addtional);
  }

  static size_t find(const std::string& str, const std::string& substr) {
    return str.find(substr);
  }
};

int main() {
  std::string str1 = "Hallo";
  std::string str2 = "World";

  // Compare string
  if(StringManipulator::compare(str1, str2)) {
    std::cout << "Strings are equal.\n";
  } else {
    std::cout << "Strings are not equal.\n";
  }

  // Swap
  StringManipulator::swap(str1, str2);
  std::cout<< "After swap: str1 = " << str1 << ", str2 = " << str2 << "\n";

  // Replace 
  std::string sentence = "I love apples and apples are delicious.";
  StringManipulator::replace(sentence, "appels", "oranges");
  std::cout<< "After replacement: " << sentence << "\n"; 

  // Append
  StringManipulator::append(sentence, " Especially with cream!");
  std::cout << "After appending: " << sentence << "\n";

  // Find
  size_t pos = StringManipulator::find(sentence, "oranges");
  if(pos != std::string::npos) {
    std::cout << "Found 'oranges' at position " << pos << "\n";
  } else {
    std::cout << "'oranges' not found.\n";
  }

  return 0;
};

