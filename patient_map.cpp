#include <iostream>
#include <map>
#include <string>

int main() {
    // Mapping pateint ID to patient name
    std::map<int, std::string> patients;

    // Adding patients
    patients[101] = "Harry Smith";
    patients[102] = "Sally Johnson";
    patients[103] = "Joe Marler";

    // Looking up a patient by ID (by key)
    std::cout << "Patient 102: " << patients[102] << std::endl;

    // Checking if a patient ID exists in the map before accessing it
    int searchId = 105;
    if (patients.find(searchId) != patients.end()) {
        std::cout << "Found patient " << searchId << std::endl;
    }
    else {
        std::cout << "Patient " << searchId << " not found." << std::endl;
    }

    // Looping over every key value pair
    std::cout << "\nAll patients:" << std::endl;
    for (const auto& pair : patients) {
        std::cout << "ID: " << pair.first << ": " << pair.second << std::endl;
    }

    // Updating an existing entry
    patients[101] = "Harry Hewitt"; // He changed his surname
    std::cout << "\nUpdated: " << patients[101] << std::endl;

    // Removing an entry
    patients.erase(103); // Joe Marler has been discharged
    std::cout << "Number of patients after removing patient 103:" << patients.size() << std::endl;

    return 0;
}
