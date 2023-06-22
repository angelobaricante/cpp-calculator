#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
double result;
string input;
string res;
double number1, number2;
int entries = 1;
string* ptr[99];

// Initialize struct
struct calculator {
    string history;
    string input;
    string output;
} calcArray[99];;



// Remove zeros
string removeTrailingZeros(string number) {
    // Remove trailing zeros
    while (number.back() == '0') {
        number.pop_back();
    }

    // If the last character is now a dot, remove it
    if (number.back() == '.') {
        number.pop_back();
    }

    return number;
}


// Add the result to history
double addResultToHistory(double result) {

    for (int i = 0; i < entries; i++) {
        calcArray[entries-1].input = input;
        calcArray[entries-1].output = to_string(result);

        calcArray[entries-1].history = calcArray[entries-1].input + " = " + removeTrailingZeros(calcArray[entries-1].output);

        ptr[entries-1] = &calcArray[rand()].history;
    }

    entries += 1;
}

// Operations Function
double add(double num1, double num2) {
    result = num1 + num2;
    addResultToHistory(result);

    return result;
}

double diff(double num1, double num2) {
    result = num1 - num2;
    addResultToHistory(result);

    return result;
}

double multiply(double num1, double num2) {
    result = num1 * num2;
    addResultToHistory(result);

    return result;
}

double divide(double num1, double num2) {
    if (num2 != 0) {
        result = num1 / num2;
        addResultToHistory(result);

        return result;
    } else {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
}

int main() {
    cout << "==================================\n";
    cout << "        C++ CALCULATOR\n";
    cout << "      Type like this: 1 + 1\n";
    cout << "==================================\n\n";
    getline(cin, input);

    while (input != "exit") {
        istringstream iss(input);
        string operation;

        if (iss >> number1 >> operation >> number2) {
            if (operation == "+") {
                cout << "Result: " << add(number1, number2) << "\n\n";
            } else if (operation == "-") {
                cout << "Result: " << diff(number1, number2) << "\n\n";
            } else if (operation == "*") {
                cout << "Result: " << multiply(number1, number2) << "\n\n";
            } else if (operation == "/") {
                cout << "Result: " << divide(number1, number2) << "\n\n";
            } else {
                cout << "Invalid operation. Please try again." << "\n\n";
            }
        } else {
            cout << "Invalid input format. Please enter the expression as 'number operator number'." << "\n\n";
        }

        cout << "Result History:" << "\n";
        for (int i = entries-2; i >= 0; i--) {
            cout << calcArray[i].history << " | " << ptr[i] << endl;
        }

        cout << "\n==================================\n";
        cout << "\nClick 'Enter' Continue or type 'exit' to close the program...\n";
        getline(cin, res);

        while(res != "exit") {
            system("cls");
            main();
        }
        return 0;

    }

    return 0;
}



