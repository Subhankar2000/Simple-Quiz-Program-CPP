#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "miscFuncLib.h"
#include "allVars.h"
#include "quizPerformLib.h"
#include "quizAdminLib.h"

using namespace std;


// The function that will administer the quiz
// Refer to quizAdminLib.h for classes and functions referred here
void administerQuiz()
{
	 int r;
     AdminUsers adm;
     r = adm.loginSystem();
     if (r == 1)
        adm.manageQuestion();
}

// This function will call the functions that runs a quiz session
// Refer to quizPerformLib.h for the functions referred here
void startQuiz()
{
	prepareQuizData();
	selectTenQuestions();
	runQuiz();
	displayResult();
}

// It shows the first opening menu 
void menuController()
{
  //	printf("Here is the menu controler\n");
  
  int ch = 0;
  
  while (ch != 3)
  {	
    // Present the menu
    system("cls");
	printf("Welcome to Simple Quiz Game\n");
	printf("---------------------------\n\n");
	printf("     Your Options\n");
	printf("     ------------\n\n");
    printf("     1) Administer Quiz\n");
    printf("     2) Play Quiz Game\n");
    printf("     3) Quit\n\n");
    printf("     Enter your choice (1/2/3) :: ");
    scanf ("%d", &ch);
    
    // Evaluate choices 
    switch (ch)
    {
    	case 1 :
    	    administerQuiz(); 
			break;	
		case 2 :
			startQuiz();
			break;
        case 3 :
        	break;
        default :
        	printf("Please choose between 1 or 2 .. Press a key to continue.\n");
        	getch();
	}
  }
}


// The main function
int main() {
	menuController();
	return 0;
}
