#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <limits>

using namespace std;

// Class responsible for reading grocery data 
// & tracking item purchase frequencies 
class GroceryTracker {
private:
	//Map to store each item & its frequency count 
	map<string, int> itemCounts;

	// Converts a string to Lowercase so searches can be case insensitive
	static string ToLower(string str) {
		for (char& c : str) {
			c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
		}
		return str;
	}

public:
	// Loads item data from the input file 
	void LoadFromFile(const string& fileName);

	//Writes all item frequencies to a backup file 
	void WriteBackupFile(const string& fileName) const;

	//Returns how many times a specific item appears
	int GetItemFrequency(const string& item) const;

	// Prints all items & their frequency counts 
	void PrintAllFrequencies() const;

	//Prints a histogram using '*' for each count
	void PrintHistogram() const;
};

//Definition of LoadFromFile function 
void GroceryTracker::LoadFromFile(const string& fileName) {

	//Attempt to open the input file
	ifstream inFile(fileName);

	//Validate that file opened successfully 
	if (!inFile.is_open()) {
		cout << "Error opening file.\n";
		return;
	}

	string item;

	// Read each word (item) from the file until end of file
	while (inFile >> item) {
		// Normalize case so "Peaches" and "peaches" count as the same item
		item = ToLower(item);
		//Increment the frequency count for the item
		//If the item does not yet exist in the map, it is automatically created w/ value 0 then incremented to 1
		itemCounts[item]++;
	}

	//Close the file after processing 
	inFile.close();
}

void GroceryTracker::WriteBackupFile(const string& fileName) const {

	ofstream outFile(fileName);  

	// Validate that output file opened successfullly
	if (!outFile.is_open()) {
		cout << "Error: Could not create backup file: " << fileName << endl;
		return;
	}

	// Write each item & its count to the backup file
	for (const auto& pair : itemCounts) {
		outFile << pair.first << " " << pair.second << endl;
	}

	outFile.close();
}

int GroceryTracker::GetItemFrequency(const string& item) const {
	// Normalize the seached item to Lowercase (case insensitive search)
	string key = ToLower(item);

	// Try to find the item in the map
	auto it = itemCounts.find(key);

	// If found return the count; otherwise return 0 
	if (it != itemCounts.end()) {
		return it->second;
	}
	return 0;
}


// Definition of PrintAllFrequencies function 
void GroceryTracker::PrintAllFrequencies() const {

	//Iterate through the map & print each item & its count
	for (const auto& pair : itemCounts) {
		cout << pair.first << " " << pair.second << endl;
	}
}

void GroceryTracker::PrintHistogram() const {
	for (const auto& pair : itemCounts) {
		cout << pair.first << " ";
		// Print one '*' per count
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}

//Prints the user menu 
void PrintMenu() {
	cout << "\n===== Corner Grocer Item Tracker =====\n";
	cout << "1. Search for an item frequency\n";
	cout << "2. Print all item frequencies\n";
	cout << "3. Print histogram\n";
	cout << "4. Exit\n";
	cout << "Enter your choice (1-4): ";
}

int main() {
	//Create an instance of GroceryTracker
	GroceryTracker tracker;

	//Load data from the provided input file 
	tracker.LoadFromFile("CS210_Project_Three_Input_File.txt");

	// Create the backup file at the start (no user intervention)
	tracker.WriteBackupFile("frequency.dat");

	int choice = 0;

	// Keep showing the menu until the user chooses Exit
	while (choice != 4) {
		PrintMenu();
		cin >> choice;

		// Basic input validation (prevents infinite loop if user types letters)
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number 1-4.\n";
			continue;
		}

		if (choice == 1) {
			string searchItem;
			cout << "Enter the item you want to search for: ";
			cin >> searchItem;

			cout << searchItem << " was purchased "
				<< tracker.GetItemFrequency(searchItem)
				<< " time(s)." << endl;
		}
		else if (choice == 2) {
			tracker.PrintAllFrequencies();
		}
		else if (choice == 3) {
			tracker.PrintHistogram();
		}
		else if (choice == 4) {
			cout << "Exiting program. Goodbye!" << endl;
		}
		else {
			cout << "Invalid choice. Please enter 1-4." << endl;
		}
	}

	return 0;
}
