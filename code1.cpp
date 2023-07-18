#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

struct Ticket {
    int id;
    string category;
    string type;
    string details;
    bool resolved;
};

vector<Ticket> tickets;
map<string, vector<string>> issueCategories;
int ticketIdCounter = 1;

void clearScreen() {
    system(CLEAR_COMMAND);
}

void loadIssueTypes(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        // Process the line and extract the category and type
        // Assuming the format is "<category>,<type>"
        size_t commaPos = line.find(',');
        string category = line.substr(0, commaPos);
        string type = line.substr(commaPos + 1);

        issueCategories[category].push_back(type);
    }

    file.close();
}

void saveTicketsToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << endl;
        return;
    }

    for (const auto& ticket : tickets) {
        if (!ticket.resolved) {
            file << ticket.id << "," << ticket.category << "," << ticket.type << "," << ticket.details << "," << ticket.resolved << endl;
        }
    }

    file.close();
}

void loadTicketsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No tickets found." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        // Process the line and extract the ticket properties
        // Assuming the format is "<id>,<category>,<type>,<details>,<resolved>"
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);

        int id = stoi(line.substr(0, pos1));
        string category = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string type = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string details = line.substr(pos3 + 1, pos4 - pos3 - 1);
        bool resolved = (line.substr(pos4 + 1) == "1");

        Ticket ticket;
        ticket.id = id;
        ticket.category = category;
        ticket.type = type;
        ticket.details = details;
        ticket.resolved = resolved;

        tickets.push_back(ticket);

        if (id >= ticketIdCounter) {
            ticketIdCounter = id + 1;
        }
    }

    file.close();
}

void createTicket() {
    clearScreen();

    Ticket newTicket;
    newTicket.id = ticketIdCounter++;

    cout << "Enter the category of the issue: ";
    getline(cin >> ws, newTicket.category);

    cout << "Enter the type of the issue: ";
    getline(cin >> ws, newTicket.type);

    cout << "Enter the details of the issue: ";
    getline(cin >> ws, newTicket.details);

    newTicket.resolved = false;
    tickets.push_back(newTicket);

    saveTicketsToFile("tickets.txt");

    cout << "\nTicket created successfully!\n";
    cout << "Press Enter to continue...";
    cin.get();
}

void listTickets() {
    clearScreen();

    cout << "Open Tickets:\n";

    for (const auto& ticket : tickets) {
        if (!ticket.resolved) {
            cout << "ID: " << ticket.id << endl;
            cout << "Category: " << ticket.category << "\n";
            cout << "Type: " << ticket.type << "\n";
            cout << "Details: " << ticket.details << "\n";
            cout << "-------------------\n";
        }
    }

    cout << "Press Enter to continue...";
    cin.get();
}

void resolveTicketById() {
    clearScreen();

    int ticketId;
    cout << "Enter the ID of the ticket to resolve: ";
    cin >> ticketId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool resolved = false;

    for (auto& ticket : tickets) {
        if (!ticket.resolved && ticket.id == ticketId) {
            ticket.resolved = true;
            resolved = true;
            break;
        }
    }

    if (resolved) {
        saveTicketsToFile("tickets.txt");
        cout << "Ticket resolved successfully!\n";
    } else {
        cout << "Ticket not found or already resolved.\n";
    }

    cout << "Press Enter to continue...";
    cin.get();
}

void resolveTicketByType() {
    clearScreen();

    string ticketType;
    cout << "Enter the type of the ticket to resolve: ";
    getline(cin >> ws, ticketType);

    bool resolved = false;

    for (auto& ticket : tickets) {
        if (!ticket.resolved && ticket.type == ticketType) {
            ticket.resolved = true;
            resolved = true;
        }
    }

    if (resolved) {
        saveTicketsToFile("tickets.txt");
        cout << "Ticket(s) resolved successfully!\n";
    } else {
        cout << "Ticket(s) not found or already resolved.\n";
    }

    cout << "Press Enter to continue...";
    cin.get();
}

void displayCategories() {
    clearScreen();

    cout << "Available Categories:\n";

    for (const auto& category : issueCategories) {
        cout << category.first << "\n";
        cout << "-------------------\n";
        for (const auto& type : category.second) {
            cout << type << "\n";
        }
        cout << "\n";
    }

    cout << "Press Enter to continue...";
    cin.get();
}

void displayMenu() {
    clearScreen();

    cout << "==== Support Ticketing System ====\n";
    cout << "1. Create Ticket\n";
    cout << "2. List Tickets\n";
    cout << "3. Resolve Ticket by ID\n";
    cout << "4. Resolve Ticket by Type\n";
    cout << "5. Display Categories\n";
    cout << "6. Exit\n";
    cout << "==================================\n";
    cout << "Enter your choice: ";
}

int main() {
    loadTicketsFromFile("tickets.txt");
    loadIssueTypes("issue_types.txt");

    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createTicket();
                break;
            case 2:
                listTickets();
                break;
            case 3:
                resolveTicketById();
                break;
            case 4:
                resolveTicketByType();
                break;
            case 5:
                displayCategories();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}
