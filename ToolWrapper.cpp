#include <iostream>
#include <cstdlib>

void checkAndRun(const std::string &tool) {
    std::string command = "command -v " + tool + " > /dev/null 2>&1";
    if (system(command.c_str()) == 0) {
        std::cout << tool << " is installed. Running " << tool << "...\n";
        system((tool + " --help").c_str());  // Display help to guide user on usage
    } else {
        std::cout << tool << " is not installed. Please install it using your package manager.\n";
    }
}

int main() {
    int choice;
    std::cout << "WiFi Penetration Testing Tool Wrapper\n";
    std::cout << "Select a tool to check or execute:\n";
    std::cout << "1. Reaver (WPS attacks)\n";
    std::cout << "2. Wifite (Automated wireless attack tool)\n";
    std::cout << "3. Kismet (Network detector, packet sniffer, and intrusion detection)\n";
    std::cout << "4. Fern Wifi Cracker (GUI-based wireless security tool)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            checkAndRun("reaver");
            break;
        case 2:
            checkAndRun("wifite");
            break;
        case 3:
            checkAndRun("kismet");
            break;
        case 4:
            checkAndRun("fern-wifi-cracker");
            break;
        case 0:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
    return 0;
}
