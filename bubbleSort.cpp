#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <fstream>

using namespace std; 
const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified

// PART 1A: Create the data struct

struct patientInfo {
int age; 
int ID;
char firstname[MAX_NAME_LENGTH];
char lastname[MAX_NAME_LENGTH];
char sex;

};

    // PART 4/5: Sorting patient records

// Function to compare two patientInfo records by last name
int compareByLastName(const patientInfo& a, const patientInfo& b) {
    int result = strcmp(a.lastname, b.lastname);
    if (result == 0) {
        //If last names are the same, compare by first name
        return strcmp(a.firstname, b.firstname);
   }
    return result;
}

// Function to compare two patientInfo records by first name
int compareByFirstName(const patientInfo& a, const patientInfo& b) {
   int result = strcmp(a.firstname, b.firstname);
    return result;
}

// Function to compare two patientInfo records by age
int compareByAge(const patientInfo& a, const patientInfo& b) {
    int result = a.age - b.age;
    if (result == 0) {
        // If ages are the same, compare by first name
        return strcmp(a.firstname, b.firstname);
    }
    return result;
}

// Function to compare two patientInfo records by ID
int compareByID(const patientInfo& a, const patientInfo& b) {
    int result = a.ID - b.ID;
    if (result == 0) {
        // If IDs are the same, compare by first name
        return strcmp(a.firstname, b.firstname);
   }
    return result;
}

// Function to compare two patientInfo records by sex
int compareBySex(const patientInfo& a, const patientInfo& b) {
    int result = a.sex - b.sex;
    if (result == 0) {
        //If sexes are the same, compare by first name
       return strcmp(a.firstname, b.firstname);
    }
    return result;
}


// Function to perform the Bubble Sort on patient records
void bubbleSort(patientInfo records[], int numRecords, int (*compare)(const patientInfo&, const patientInfo&)) {
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = 0; j < numRecords - i - 1; j++) {
            if (compare(records[j], records[j + 1]) > 0) {
                // Swap records[j] and records[j + 1]
                patientInfo temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}



int main()
{
    // PART 1B: Read the patient record

patientInfo record[NUM_PATIENTS];

    ifstream input;
    input.open ("patientInfo.txt");

for (int i = 0; i < NUM_PATIENTS; i++)
{

    if (input.peek () !=  EOF) {
        input >> record[i].age;
        input >> record[i].ID;
        input >> record[i].firstname;
        input >> record[i].lastname;
        input >> record[i].sex;
 }  


    }
    
// PART 2: Select a primary sorting category from user input

    bool validInput = false;

    do{
        cout << "Please input a category to sort patient records by." << endl;
        cout << "Options (case sensitive) are Age, ID, First, Last, Sex: ";

        string category;
        cin >> category;

        if (category == "Age") {
            cout << "Case 1, sorting by patient age:" << endl;
            // Sort by age
            bubbleSort(record, NUM_PATIENTS, compareByAge);
            validInput = true;

        } else if (category == "ID") {
            cout << "Case 2, sorting by patient ID:" << endl;
            // Sort by ID
            bubbleSort(record, NUM_PATIENTS, compareByID);
            validInput = true;

        } else if (category == "First") {
            cout << "Case 3, sorting by patient first name:" << endl;
            // Sort by first name
            bubbleSort(record, NUM_PATIENTS, compareByFirstName);
            validInput = true;
        } else if (category == "Last") {
            cout << "Case 4, sorting by patient last name:" << endl;
            // Sort by last name
            bubbleSort(record, NUM_PATIENTS, compareByLastName);
            validInput = true;
        } else if (category == "Sex") {
            cout << "Case 5, sorting by patient sex:" << endl;
            // Sort by sex
            bubbleSort(record, NUM_PATIENTS, compareBySex);
            validInput = true;
        } else {
            cout << "Unexpected input. Please input either Age, ID, First, Last, or Sex." << endl;
        }
    }while (!validInput);

    // PART 3: Outputting patient records to terminal in tabular form

cout << setw(10) << "Age:" << setw(10);
    for (int i = 0; i < NUM_PATIENTS; i++) {
        cout << record[i].age << setw(10);
    }
    cout << endl;
cout << setw(10) << "ID:" << setw(10);
    for (int i = 0; i < NUM_PATIENTS; i++) {
        cout << record[i].ID << setw(10);
    }
    cout << endl;
cout << setw(10) << "First:" << setw(10);
    for (int i = 0; i < NUM_PATIENTS; i++) {
        cout << record[i].firstname << setw(10);
    }
    cout << endl;
cout << setw(10) << "Last:" << setw(10);
    for (int i = 0; i < NUM_PATIENTS; i++) {
        cout << record[i].lastname << setw(10);
    }
    cout << endl;
cout << setw(10) << "Sex:" << setw(10);
    for (int i = 0; i < NUM_PATIENTS; i++) {
        cout << record[i].sex << setw(10);
    }
    cout << endl;

    return 0;
}




