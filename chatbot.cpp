#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map> // Include this header for unordered_map

using namespace std;

int main() {
    unordered_map<string, string> memory; // unordered_map requires C++11
    string user_input;

    cout << "Welcome user, I am a chatbot" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, user_input);

        // Convert user input to lowercase
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

        if (user_input == "hi" || user_input == "hello" || user_input == "hey") {
            cout << "Chatbot: Hello user, how can I help you?" << endl;
        } else if (user_input == "how are you" || user_input == "are you ok") {
            cout << "Chatbot: As a chatbot, I have no emotional states." << endl;
        } else if (user_input == "what is my name") {
            if (memory.find("name") != memory.end()) {
                cout << "Chatbot: Your name is " << memory["name"] << endl;
            } else {
                cout << "Chatbot: Sorry, you did not tell your name yet. Tell me your name." << endl;
            }
        } else if (user_input.find("my name is ") != string::npos) {
            size_t pos = user_input.find("my name is ");
            string name = user_input.substr(pos + 11);
            memory["name"] = name;
            cout << "Chatbot: Nice to meet you, " << name << endl;
        } else if (user_input == "bye" || user_input == "see you later" || user_input == "later") {
            cout << "Chatbot: Bye" << endl;
            break;
        } else {
            cout << "Chatbot: I didn't get that, sorry." << endl;
        }
    }

    return 0;
}

