# code (1)
## Support Ticketing System
The Support Ticketing System is a command-line application that allows users to create support tickets, list open tickets, and resolve tickets. It provides a simple interface for managing customer support requests efficiently.

### Features
Create a support ticket by providing the category, type, and details of the issue.
List open tickets to view their category, type, and details.
Resolve a ticket by either its ID or its type.
Display available categories and their associated types.
Data is stored in a file, allowing persistence between program executions.
Prerequisites
C++ compiler
File access permissions
Getting Started
Clone the repository:

```shell
git clone https://github.com/kyrillosishak/codes.git
```
Compile the source code:

```shell
g++ -o support-ticketing-system code1.cpp
```
Run the application:

```shell
./support-ticketing-system
```
### Usage
Choose an option from the main menu by entering the corresponding number and pressing Enter.
Follow the prompts to perform the desired action.
The application will display the results or appropriate messages.
Press Enter to continue after viewing the output.
File Structure
main.cpp: The main C++ source code file containing the implementation of the Support Ticketing System.
tickets.txt: A text file used to store the ticket data. The file is created automatically and updated when tickets are created or resolved.
issue_types.txt: A text file used to store the available categories and types of issues. The file should be populated with category and type information before running the application.
