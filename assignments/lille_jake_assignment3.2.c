/*
COP3223 Summer 2023 Assignment 3.2
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
#include <string.h>

// Define max students, enough to avoid going outside memory bounds
#define MAX_STUDENTS 100

// create struct for our data (first, last, id, grade)
// typedef struct to avoid typing struct everytime
typedef struct {
  char firstName[50]; //string array for first name
  char lastName[50]; //string array for last name
  int id; //int for id number
  char grade; // char for singular letter grade "A" "B" "C" "D" "F"
} Student; //struct type 'Student'

Student students[MAX_STUDENTS]; //create students[100] array of struct type Student
int numStudents = 6; //6 records to initialize

void initializeStudents();
void search_id(int id);
void search_firstname(char *name);
void search_lastname(char *name);



int main() {
  //call function that initializes the data
  //neater to put into function, avoid storing it all in main
  initializeStudents();

  //init var for figuring out search type
  int searchType;
  printf(
      "Please enter your search type:\n0: First Name\n1: Last Name\n2: ID\n: ");
  scanf("%d", &searchType);
  
  //conditionals to call appropriate search type
  //first name search
  if (searchType == 0) {
    char searchName[50];
    printf("Please enter the name you want to search: ");
    scanf("%s", searchName);

    search_firstname(searchName);
  }
  //last name search
  if (searchType == 1) {
    char searchName[50];
    printf("Please enter the name you want to search: ");
    scanf("%s", searchName);
    search_lastname(searchName);
  }
  //id search
  if (searchType == 2) {
    int searchId;
    printf("%s", "Enter ID to search: ");
    scanf("%d", &searchId); // Convert input to int
    search_id(searchId);
  } else {
    printf("Invalid search type.\n");
  }

  return 0;
}

// Function Definitions
void initializeStudents() {
  //6 students, index 0-5 of the init array students[MAX_STUDENTS]
  strcpy(students[0].firstName, "John"); //Copy the string "John" to index 0.firstName
  strcpy(students[0].lastName, "Johnson"); // same
  students[0].id = 895645; // set id approprietly
  students[0].grade = 'A'; // same with grade, as char

  //do the rest...
  strcpy(students[1].firstName, "Jake");
  strcpy(students[1].lastName, "Michaelson");
  students[1].id = 236598;
  students[1].grade = 'A';

  strcpy(students[2].firstName, "Sally");
  strcpy(students[2].lastName, "Weber");
  students[2].id = 225584;
  students[2].grade = 'C';

  strcpy(students[3].firstName, "Tou");
  strcpy(students[3].lastName, "Xiong");
  students[3].id = 364875;
  students[3].grade = 'B';

  strcpy(students[4].firstName, "Jacquelyn");
  strcpy(students[4].lastName, "Jackson");
  students[4].id = 984587;
  students[4].grade = 'D';

  strcpy(students[5].firstName, "John");
  strcpy(students[5].lastName, "White");
  students[5].id = 560258;
  students[5].grade = 'C';
}

void search_id(int id) {
  int found = 0; // if found, set found to 1;
  //loop through array (numStudents)
  for (int i = 0; i < numStudents; i++) { 
    if (students[i].id == id) {
      printf("Found the record name %s %s, id %d, grade %c\n",
             students[i].firstName, students[i].lastName, students[i].id,
             students[i].grade);
      found = 1; //1, non-zero so true
    }
  }
  //found !0, run the condition...
  if (!found) {
    printf("No records found with ID %d\n", id);
  }
}

//pass pointer to name asked in main function
void search_firstname(char *name) {
  int found = 0;
  for (int i = 0; i < numStudents; i++) {
    //use strcmp function, returns 0 if strings are same
    if (strcmp(students[i].firstName, name) == 0) {
      printf("Found the record name %s %s, id %d, grade %c\n",
             students[i].firstName, students[i].lastName, students[i].id,
             students[i].grade);
      found = 1;
    }
  }
  if (!found) {
    printf("No records found with first name %s\n", name);
  }
}

//same for last name
void search_lastname(char *name) {
  int found = 0;
  for (int i = 0; i < numStudents; i++) {
    if (strcmp(students[i].lastName, name) == 0) {
      printf("Found the record name %s %s, id %d, grade %c\n",
             students[i].firstName, students[i].lastName, students[i].id,
             students[i].grade);
      found = 1;
    }
  }
  if (!found) {
    printf("No records found with last name %s\n", name);
  }
}