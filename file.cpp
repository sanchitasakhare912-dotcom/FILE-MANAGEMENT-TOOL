#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManager {
public:
    void writeToFile(const string& filename) {
        ofstream file(filename); // overwrite mode
        if (!file) {
            cout << "Error opening file for writing.\n";
            return;
        }
        string data;
        cout << "Enter data to write (end with a single line containing 'END'):\n";
        while (getline(cin, data)) {
            if (data == "END") break;
            file << data << endl;
        }
        file.close();
        cout << "Data written successfully.\n";
    }

    void appendToFile(const string& filename) {
        ofstream file(filename, ios::app); // append mode
        if (!file) {
            cout << "Error opening file for appending.\n";
            return;
        }
        string data;
        cout << "Enter data to append (end with a single line containing 'END'):\n";
        while (getline(cin, data)) {
            if (data == "END") break;
            file << data << endl;
        }
        file.close();
        cout << "Data appended successfully.\n";
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading.\n";
            return;
        }
        string line;
        cout << "\n--- File Contents ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    FileManager fm;
    int choice;
    string filename;

    while (true) {
        cout << "\n--- File Management Tool ---\n";
        cout << "1. Write to File\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        cout << "Enter filename: ";
        getline(cin, filename);

        switch (choice) {
            case 1: fm.writeToFile(filename); break;
            case 2: fm.appendToFile(filename); break;
            case 3: fm.readFromFile(filename); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
