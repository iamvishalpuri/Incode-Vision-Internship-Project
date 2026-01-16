#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string password;
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    int length = password.length();
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    
    // Check every character
    for(char c : password)
    {
        if(isupper(c))    hasUpper = true;
        else if(islower(c))  hasLower = true;
        else if(isdigit(c))  hasDigit = true;
        else                 hasSpecial = true;
    }
    
    // Calculate score
    int score = 0;
    if(length >= 8)          score++;
    if(length >= 12)         score++;
    if(hasUpper)             score++;
    if(hasLower)             score++;
    if(hasDigit)             score++;
    if(hasSpecial)           score++;
    
    // Decide strength
    cout << "\nYour password strength: ";
    
    if(score <= 2)
    {
        cout << "Weak \n\n";
        cout << "Suggestions to make it stronger:\n";
        if(length < 8)       cout << "Use at least 8 characters\n";
        if(!hasUpper)        cout << "Add uppercase letters (A-Z)\n";
        if(!hasLower)        cout << "Add lowercase letters (a-z)\n";
        if(!hasDigit)        cout << "Add numbers (0-9)\n";
        if(!hasSpecial)      cout << "Add special characters (!@#$% etc.)\n";
    }
    else if(score <= 4)
    {
        cout << "Medium \n\n";
        cout << "Good, but can be better!\n";
        if(length < 12)      cout << "Try to make it 12+ characters\n";
        if(!hasSpecial)      cout << "Add some special characters\n";
    }
    else
    {
        cout << "Strong \n\n";
        cout << "Excellent! This is a very good password.\n";
    }
    
    cout << "\nScore: " << score << "/6\n";
    
    return 0;
}