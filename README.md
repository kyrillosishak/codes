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
# code (2)
## Graph Loop Finder

This tool is designed to find and sketch loops in a graph based on edges defined in a CSV file.

### Requirements

- Python 3.x
- pandas
- networkx
- matplotlib

### Installation

1. Clone the repository or download the source code.
2. Install the required Python libraries by running the following command:

```shell
pip install pandas networkx matplotlib
```
### Usage
Prepare a CSV file with two columns: 'A' and 'B'. Each row represents an edge in the graph, where 'A' is the source node and 'B' is the target node.

Example CSV file:

A,B <br>
A,C <br>
B,D <br>
C,D <br>
D,A <br>

Update the file_path variable in the main.py file with the path to your CSV file.

Run the tool by executing the following command:
```shell
python main.py
```
The tool will find and display the loops in the graph, if any, and visualize the graph using matplotlib.

# code (3)
## URLExtractor
URLExtractor is a Java tool that extracts URLs recursively from websites. It utilizes the Jsoup library for HTML parsing and provides multi-threaded extraction for faster processing.

## How to Add Jsoup Library
To use the Jsoup library in your Java project, follow these steps:

Download the Jsoup library from the official website: https://jsoup.org/.

Extract the downloaded zip file to obtain the Jsoup JAR file.

Copy the Jsoup JAR file to your project's directory.

Open your Java project in your preferred development environment.

Add the Jsoup JAR file to your project's classpath:

For command-line compilation, include the JAR file in the classpath using the -cp flag:

```bash
javac -cp path/to/jsoup.jar YourJavaFile.java
``` 
For IDEs (e.g. IntelliJ IDEA), follow these steps:

IntelliJ IDEA:
Right-click on your project and select Open Module Settings.
In the Dependencies tab, click the + button and select JARs or directories.
Browse and select the Jsoup JAR file, then click OK.
You can now import and use the Jsoup library in your Java code:

```
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
```
Example usage:

```
Document doc = Jsoup.connect("https://www.example.com").get();
Elements links = doc.select("a[href]");
```
