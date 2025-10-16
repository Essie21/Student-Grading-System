// This program manages a small grading system for tracking performance of students.
// Features include input validation, calculation of averages and grade assignment

#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 


// Function Prototypes

void addStudent(string STD_names[], int numTests_scores[], float test_Scores[][5], float Finaltest_Scores[], char final_Grades[], int &currentStudent); // Adds a new student and their test scores to the system.

void calculateAverage(int numTests_scores[], float test_Scores[][5], float Finaltest_Scores[], int currentStudent); // Calculates average scores for all students

void assignGrades(float Finaltest_Scores[], char final_Grades[], int currentStudent); // Assigns letter grades based on average scores.

void displayResults(string STD_names[], float Finaltest_Scores[], char final_Grades[], int currentStudents); // Displays the grade report for all students including names, average scores and final grades

void displayMenu(); // Displays the menu options for the user

const int numStudents = 10; // Maximum number of students

int main(){
	
	// Declaring variables
  
  
  string STD_names[numStudents]; // Stores names of students

	int numTests_scores[numStudents] ; // Tracks number of tests per student
	
   float test_Scores[numStudents][5]; // Array to ensure that each student has up to 5 test scores
   
  float Finaltest_Scores[numStudents]; // Stores calculated average of scores
   
   char final_Grades[numStudents]; // Stores assigned letter grades (A-F)
   
   int currentStudent = 0;
   
   int choice; // User's menu selection
   
   
   // Main program loop
   
   do {
        displayMenu();
        cin >> choice;
        
        //Input validation for menu choices
        
        switch(choice) {
        	
            case 1: // Add new student
            	
                if(currentStudent < numStudents){
                
                    addStudent(STD_names, numTests_scores, test_Scores, Finaltest_Scores, final_Grades, currentStudent);
                }
				else {
                    cout << "Maximum number of students (" << numStudents << ") reached.\n";
            }
				break;
                
                case 2: // Calculate averages
                
                	if(currentStudent > 0) {
                	calculateAverage(numTests_scores, test_Scores, Finaltest_Scores, currentStudent);
                	cout << "\nAverages calculated successfully!\n";
                } else {
                	cout << "\nNo student added yet!\n";
				}
                	break;
                	
                	case 3: // Assign grades
                	
                	if (currentStudent > 0) {
                	assignGrades(Finaltest_Scores, final_Grades, currentStudent);
					cout << "\nGrades assigned successfully!\n";
				} else {
					cout << "\nNo student added yet!\n";
				}
					break;
                
			case 4: // Display results
			
				if(currentStudent > 0) {
                displayResults(STD_names, Finaltest_Scores, final_Grades, currentStudent);
            } else {
            	cout << "\nNo student added yet!\n";
			}
				break;
                
            case 5: // Exit program
            
                cout << "Exiting program.\n";
                break;
                
            default: // Invalid choice
            
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 5);
    
   
   return 0;
}

   // Functions Implementations
   
   // Function to collect student names and their test scores while performing validation
   
   void addStudent(string STD_names[], int numTests_scores[], float test_Scores[][5], float Finaltest_Scores[], char final_Grades[], int &currentStudent) {
   cin.ignore(); // Clear input buffer
   
   // Get name of student
   cout << "\nEnter name of student " << (currentStudent + 1)<< ": ";
   getline(cin, STD_names[currentStudent]);

   // Get and validate number of tests
   cout << "How many tests does " << STD_names[currentStudent]<< " have? (max. 5) : ";
   cin >> numTests_scores[currentStudent];
   
   
   while(numTests_scores[currentStudent] <= 0 || numTests_scores[currentStudent] > 5){
   	cout << "Error! Please enter between 1 and 5.\n";
   cin >> numTests_scores[currentStudent];
   }
      
   // Get and validate induvidual test scores
   for (int k = 0; k < numTests_scores[currentStudent]; k++) {
   	cout << "\nEnter score for test " << (k + 1) << " (0 - 100): ";
   	cin >>  test_Scores[currentStudent][k];
   	
   	   while (test_Scores[currentStudent][k] < 0 || test_Scores[currentStudent][k]> 100) {
   		cout <<"Invalid score entered! Enter a value between 0 and 100: ";
	  cin >> test_Scores[currentStudent][k]; 
        }
     }
     currentStudent++; // Increment student counter after successful addition
 }
  


// Function to computes the average test score for each student

void calculateAverage(int numTests_scores[], float test_Scores[][5], float Finaltest_Scores[], int currentStudent) {
	for(int i = 0; i < currentStudent; i++) {
		
		 float sum = 0;
	for(int k = 0;  k < numTests_scores[i]; k++) {
		sum += test_Scores[i][k];
	   }
	
    	Finaltest_Scores[i] = sum / numTests_scores[i]; // Calculate and store average
      }
  }


// Function to assign letter grades based on average scores

void assignGrades(float Finaltest_Scores[], char final_Grades[], int currentStudent){
	for (int i = 0; i < currentStudent; i++){ 
	
	// Grade assignment based on standard grading scale
	if(Finaltest_Scores[i] >= 90) final_Grades[i] = 'A'; // 90-100
	
    else if(Finaltest_Scores[i] >= 80) final_Grades[i] = 'B'; // 80-89
    
    else if(Finaltest_Scores[i] >= 70) final_Grades[i] = 'C'; // 70-79
    
    else if(Finaltest_Scores[i] >= 60) final_Grades[i] = 'D'; // 60-69
    
    else final_Grades[i] = 'F'; // Below 60
	}
}


// Function to display nmaes of students, their average scores and final grades.

void displayResults(string STD_names[], float Finaltest_Scores[], char final_Grades[], int currentStudent){
	
	cout << "\n--- Student Grade Report ---\n";
	
	cout << setprecision(2) << fixed; // Display averages with 2 decimal places
	
	// Display header with column titles
	cout << left << setw(20) << "Student Name" << setw(10) << "Average" << "Grade" << endl;
    cout << "--------------------------------------------------\n";

		// Display each student's information
		
		for(int i = 0; i < currentStudent; i++) {
			
        cout << left << setw(20) << STD_names[i] << setw(10) << Finaltest_Scores[i] << final_Grades[i] << endl;
	}
}
	


// Function to display menu options for navigating the program.

void displayMenu() {
	
	cout << "\nCLASS GRADING SYSTEM\n";
        cout << "1. Add Students & Scores\n";
        cout << "2. Calculate Averages\n";
        cout << "3. Assign Grades\n";
        cout << "4. Display Results\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
}



