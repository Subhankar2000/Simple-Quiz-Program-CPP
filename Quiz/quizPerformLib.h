// Simple Quiz Library 
// This header file contains all functions that are required to run a Quiz Session 
// These functions are all written in C language and non in C++ 
// This part of the program is common to the project in C


void startQuiz();
void menuController();
void prepareQuizData();
void selectTenQuestions();
int checkDup(int currQ);
void runQuiz();
void displayResult();
void addCategoryTotal(char *qCategory, int marks, int fmarks);



// This function will read all the data from the question bank (SQG-QTNBNK.txt) and stores it into an array 
void prepareQuizData()
{
	// read data from the file

    char buff[268];
    char fld[50];
    FILE *fp;
    fp = fopen("SQG-QTNBNK.txt", "r" );
    printf("Loading Question Bank ...\n");
    maxQuestions = 0;
    while (fgets(buff, 259, fp)!=NULL)
    {
            // Extract the actual fields content from buffer
            stringExtract(fld, buff, 0, 8);
            strcpy(quizQuestions[maxQuestions].qCategory, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qCategory);
            stringExtract(fld, buff, 9, 13);
            quizQuestions[maxQuestions].qId = atoi(fld);
            //printf("%d\n",quizQuestions[maxQuestions].qId);
            stringExtract(fld, buff, 14, 53);
            strcpy(quizQuestions[maxQuestions].qText, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qText);
            stringExtract(fld, buff, 54, 103);
            strcpy(quizQuestions[maxQuestions].qAnswer1, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qAnswer1);
            stringExtract(fld, buff, 104, 153);
            strcpy(quizQuestions[maxQuestions].qAnswer2, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qAnswer2);
            stringExtract(fld, buff, 154, 203);
            strcpy(quizQuestions[maxQuestions].qAnswer3, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qAnswer3);
            stringExtract(fld, buff, 204, 253);
            strcpy(quizQuestions[maxQuestions].qAnswer4, fld);
            //printf("%s\n",quizQuestions[maxQuestions].qAnswer4);
            stringExtract(fld, buff, 254, 254);
            quizQuestions[maxQuestions].qCAnswer = atoi(fld);
            //printf("%d\n",quizQuestions[maxQuestions].qCAnswer);
            stringExtract(fld, buff, 255, 257);
            quizQuestions[maxQuestions].qAllottedMarks = atoi(fld);
            //printf("%d\n",quizQuestions[maxQuestions].qAllottedMarks);
            quizQuestions[maxQuestions].qDeleted = 0;
            maxQuestions++;
            //getch();
    }
    fclose(fp);
}

// The function selects 10 questions randomly from the array containing the entire question bank
// These 10 questions would be stored in a seperate array
void selectTenQuestions()
{
   int i, currQ;
   time_t t;
   srand((unsigned) time(&t));
   printf("Prepareing the quiz question list ...\n");
   for(i=0; i<10; i++)
   {
     currQ = rand()%maxQuestions;
     while (checkDup(currQ))
     {
     	 currQ = rand()%maxQuestions;
	 }
	 
	    testQuestions[i].qIndex = currQ;
	    strcpy(testQuestions[i].qCategory, quizQuestions[currQ].qCategory);
	    testQuestions[i].qId = quizQuestions[currQ].qId;
	    strcpy(testQuestions[i].qText, quizQuestions[currQ].qText);
	    strcpy(testQuestions[i].qAnswer1, quizQuestions[currQ].qAnswer1);
	    strcpy(testQuestions[i].qAnswer2, quizQuestions[currQ].qAnswer2);
	    strcpy(testQuestions[i].qAnswer3, quizQuestions[currQ].qAnswer3);
	    strcpy(testQuestions[i].qAnswer4, quizQuestions[currQ].qAnswer4);
	    testQuestions[i].qCAnswer = quizQuestions[currQ].qCAnswer;
	    testQuestions[i].qAllottedMarks = quizQuestions[currQ].qAllottedMarks;
   }	
	
}	


// When selecting questions for the quiz session there is a possibility that same questions may be selected multiple times
// This function checks if the current query has already been stored in the array
int checkDup(int currQ)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if (testQuestions[i].qIndex == currQ)
		{
			return 1;
		}
	}
	return 0;
}


//  This function will present the selected 10 questions before the player and ask him to find right answer
//  This function will also record the performance and calculate the total allotted marks
void runQuiz()
{
	int i;
	char yn = ' ', ysno = ' ';
    // Present welcome scene
	printf("Welcome to Simple Quiz Game\n\n");	
	printf("Player's Name :: ");
	scanf(" %[^\n]s", playerName);		
	printf("\n\nReady for quiz ? (Y/N) :: ");
	scanf(" %c", &yn);
	if (yn == 'Y' || yn == 'y')
	{
		for(i = 0; i < 10; i++)
		{
			ysno = 'N';
			while (ysno == 'N' || ysno == 'n')
			{
					system("cls");
					printf("Question number - %d :: \n", i+1);
					printf("Question category - %s :: \n", testQuestions[i].qCategory);
					printf("Question text - %s \n\n", testQuestions[i].qText);
					printf("Avalilable answers .. \n");
					printf("1) %s\n", testQuestions[i].qAnswer1);
					printf("2) %s\n", testQuestions[i].qAnswer2);
					printf("3) %s\n", testQuestions[i].qAnswer3);
					printf("4) %s\n\n", testQuestions[i].qAnswer4);
					printf("Marks allotted - %d :: \n\n", testQuestions[i].qAllottedMarks);
					printf("Enter the correct answer (1/2/3/4) :: ");
					scanf("%d",  &testQuestions[i].qSelectedAns);
     		        printf("\n\nLock it ? (Y/N) :: ");
     		        scanf(" %c", &ysno);
     		        
		   }
		   if (testQuestions[i].qCAnswer == testQuestions[i].qSelectedAns)
		         testQuestions[i].qRecivedMarks = testQuestions[i].qAllottedMarks;
		   else
		         testQuestions[i].qRecivedMarks = 0;
		   totMarks = totMarks + testQuestions[i].qRecivedMarks;
		   fullMarks = fullMarks + testQuestions[i].qAllottedMarks;
		}
		
	}
	
}

// The function displays the final result after the quiz session is over
void displayResult()
{
	int i;
	system("cls");
	printf("Now you may see the results \n Press any key to continue ...");
	getch();
	for(i = 0; i < 10; i++)
	{
		        system("cls");
				printf("Question number - %d :: \n", i+1);
				printf("Question category - %s :: \n", testQuestions[i].qCategory);
				printf("Question text - %s \n\n", testQuestions[i].qText);
				printf("Avalilable answers .. \n");
				printf("1) %s\n", testQuestions[i].qAnswer1);
				printf("2) %s\n", testQuestions[i].qAnswer2);
				printf("3) %s\n", testQuestions[i].qAnswer3);
				printf("4) %s\n\n", testQuestions[i].qAnswer4);
				printf("Correct Answer - %d\n", testQuestions[i].qCAnswer);
	            printf("You Selected   - %d\n", testQuestions[i].qSelectedAns);	
				printf("Marks Received - %d\n\n", testQuestions[i].qRecivedMarks);
				getch();
				// Add category wise totals
				addCategoryTotal(testQuestions[i].qCategory, testQuestions[i].qRecivedMarks,testQuestions[i].qAllottedMarks);
	}
	
	printf("%s, you scored a total of %d out of %d \n\n", playerName, totMarks, fullMarks);
	
	// Printing the category summary
	printf("Categorywise breakup ..\n");
	for(i = 1; i <= maxCategory; i++)	
	{
		printf("Category : %s    Obtained Marks : %d   Total Marks : %d\n", categoryTotals[i].qCategory, categoryTotals[i].totMarks, categoryTotals[i].fullMarks);
	}
	getch();
	
}


// The function calculates the question category wise total and stores it into array.
void addCategoryTotal(char *qCategory, int marks, int fmarks)
{   
    int i;
    int marksAdded = 0;
	for(i = 1; i <= maxCategory; i++)
	{
		if (strcmp(qCategory, categoryTotals[i].qCategory)==0)
		{
			categoryTotals[i].totMarks = categoryTotals[i].totMarks + marks;
			categoryTotals[i].fullMarks = categoryTotals[i].fullMarks + fmarks;
			marksAdded = 1;
		}
	}
	if (marksAdded==0)
	{
		maxCategory += 1;
	    strcpy(categoryTotals[maxCategory].qCategory , qCategory);
		categoryTotals[maxCategory].totMarks = marks;
		categoryTotals[maxCategory].fullMarks = fmarks;
	}
}
