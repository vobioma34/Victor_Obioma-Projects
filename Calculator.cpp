/* Necessary header files */
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
// Victor Obioma

/* Description: 
    A C++ Program to handle basic arithmetic operations 
    such as addition, subtraction, multiplication, and divison

    Input: Operator (*, /, -, +)
           Two number provided by the user
    Output:
           The final solution after the operation
*/


/*PROTOTYPES*/
double addition(string num1, string num2);
double subtraction(string num1, string num2);
double multiplication(string num1, string num2);
double division(string num1, string num2);
bool isNumeric(string num);

int main()
{
    string num1, num2; // operand1 and operand2 inputted by the user
    string inputOperator; // use string datatype instead of char!!!

    /* 
      Valid tokens for calculations: + , - , *, / 
    */
    cout << endl;
    cout << "------------ Calculator -------------------\n";
    cout << endl; // space

    do {
        // While the inputOperator is not the arithmetic symbols, keep reading in input
        cout << "Please enter a valid operator: \n";
        cin >> inputOperator; // Keep taking in input until the right symbol is passed in
    }while(inputOperator != "*" && inputOperator != "/" && inputOperator != "-" && inputOperator != "+"); // Use Boolean AND for this step


    // While the num1 is not a number, keep reading in input
    //...
    cout << endl; // space

    cout << "Enter a number: \n";
    cin >> num1; // Read in user input and store it in a variable

    
    while (isNumeric(num1) == false) // if the user input is not a numeric, keep taking in input until a number is passed in
    {
        cout << "Invalid! Try again \n"; // Display a error message
        cin >> num1; // Take input from user
    }

    cout << endl; // space

    cout << "Enter another number: \n"; // Displays message to prompt user to enter a number
    cin >> num2; // Take input from user

    while (isNumeric(num2) == false) // if the user input is not a numeric, keep taking in input until a number is passed in
    {
        cout << "Invalid! Try again \n"; // Display a error message
        cin >> num2; // Take input from user
    }

    cout << endl; // space

    if (inputOperator == "*")
    {
        cout << "The final result: " << multiplication(num1,num2) << " \n"; // Prints the result from the multiplication method
    }
    else if (inputOperator == "/")
    {
        cout << "The final result: " << division(num1,num2) << " \n"; // Prints the result from the division method
    }
    else if (inputOperator == "-")
    {
        cout << "The final result: " << subtraction(num1,num2) << " \n"; // Prints the result from the subtraction method
    }
    else if (inputOperator == "+")
    {
        cout << "The final result: " << addition(num1,num2) << " \n"; // Prints the result from the addition method
    }
    cout << endl; // space
    return 0;
}
double addition(string num1, string num2) // the Addition method
{
    double num_double1 = stod(num1), num_double2 = stod(num2);
    return num_double1 + num_double2;
}
double subtraction(string num1, string num2) // the Subtraction method
{
    double num_double1 = stod(num1), num_double2 = stod(num2);
    return num_double1 - num_double2;
}
double multiplication(string num1, string num2) // the multiplication method
{
    double num_double1 = stod(num1), num_double2 = stod(num2);
    return num_double1 * num_double2;
}
double division(string num1, string num2) // the division method
{
    double num_double1 = stod(num1), num_double2 = stod(num2);
    return num_double1 / num_double2;
}
bool isNumeric(string num) // check to see if the num is numeric or not
{
    // Base Case Scenario
    if (num.empty())
    {
        return false;
    }

    for (int i = 0; i < num.length(); i++)
    {
        // If the character is not a digit and not a valid sign (+/-), it's not numeric
        if (!isdigit(num[i]) && num[i] != '+' && num[i] != '-')
        {
            return false;
        }
    }
    // If the string contains only a sign, it's not considered numeric
    if (num.length() == 1 && (num[0] == '+' || num[0] == '-'))
    {
        return false;
    }

    // If the string contains multiple signs, it's not considered numeric
    if (num.find('+') != std::string::npos && num.find('+') != 0) 
    {
        return false;
    }
    if (num.find('-') != std::string::npos && num.find('-') != 0)
    {
        return false;
    }

    // If the string is valid according to the above checks, it's numeric
    return true;
}
