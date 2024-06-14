#include <iostream>
#include <string>
#include <cctype> // for std::tolower

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        while (!std::isalnum(str[left]) && left < right) {
            left++;
        }
        while (!std::isalnum(str[right]) && left < right) {
            right--;
        }
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome.\n";
    } else {
        std::cout << "The string is not a palindrome.\n";
    }

    return 0;
}

