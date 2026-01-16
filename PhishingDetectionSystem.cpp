#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>

using namespace std;

// Function to check if the input contains suspicious keywords
bool containsSuspiciousKeywords(const string& input) {
    vector<string> keywords = {
        "login", "password", "bank", "secure", "update", "verify",
        "account", "suspended", "urgent", "click here", "phishing"
    };
g
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const string& keyword : keywords) {
        string lowerKeyword = keyword;
        transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);
        if (lowerInput.find(lowerKeyword) != string::npos) {
            return true;
        }
    }
    return false;
}

// Function to check for IP address in URL (common in phishing)
bool containsIPAddress(const string& input) {
    regex ipRegex(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})");
    return regex_search(input, ipRegex);
}

// Function to check for fake or misspelled domains
bool containsFakeDomain(const string& input) {
    vector<string> fakeDomains = {
        "g00gle", "faceb00k", "paypa1", "amaz0n", "app1e",
        "micr0soft", "netf1ix", "yaho0"
    };

    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const string& fake : fakeDomains) {
        if (lowerInput.find(fake) != string::npos) {
            return true;
        }
    }
    return false;
}

// Function to check for unusual URL patterns (e.g., HTTP basic auth with @)
bool hasUnusualURLPattern(const string& input) {
    regex unusualRegex(R"(https?://[^@]+@)");
    return regex_search(input, unusualRegex);
}

int main() {
    string input;

    // Prompt the user for input
    cout << "Enter a URL or email text to analyze for phishing: ";
    getline(cin, input);

    // Perform checks
    bool isSuspicious = false;

    if (containsSuspiciousKeywords(input)) {
        isSuspicious = true;
        cout << "Suspicious keywords detected." << endl;
    }

    if (containsIPAddress(input)) {
        isSuspicious = true;
        cout << "IP address in URL detected (common phishing indicator)." << endl;
    }

    if (containsFakeDomain(input)) {
        isSuspicious = true;
        cout << "Fake or misspelled domain detected." << endl;
    }

    if (hasUnusualURLPattern(input)) {
        isSuspicious = true;
        cout << "Unusual URL pattern detected (e.g., HTTP basic auth)." << endl;
    }

    // Classify the input
    if (isSuspicious) {
        cout << "Classification: Suspicious" << endl;
    }
    else {
        cout << "Classification: Safe" << endl;
    }

    return 0;
}