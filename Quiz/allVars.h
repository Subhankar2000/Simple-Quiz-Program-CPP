// This file contains all the structures and variables used in the Simple Quiz System

// Structure for question bank
struct QuizData
{
	char qCategory[20];
	int  qId;
	char qText[100];
	char qAnswer1[100];
	char qAnswer2[100];
	char qAnswer3[100];
	char qAnswer4[100];
	int  qCAnswer;
	int  qAllottedMarks;
	int  qDeleted;
};

// Structure that contains the selected questions for a quiz session and it also stores the answers that the student selects
struct TestQuestions
{
	int  qIndex;
	char qCategory[20];
	int  qId;
	char qText[100];
	char qAnswer1[100];
	char qAnswer2[100];
	char qAnswer3[100];
	char qAnswer4[100];
	int  qCAnswer;
	int  qAllottedMarks;
	int  qSelectedAns;
	int  qRecivedMarks;
};

// This structure will store categorywise marks for a session
struct CategoryTotals
{
	char qCategory[20];
	int  totMarks;
	int  fullMarks;	
};

// The variables used for the above structures.
struct QuizData quizQuestions[1000];  // There may be as many as 1000 questions in the question bank array. The data file constains 15.
struct TestQuestions testQuestions[10]; //Array containing questions selected for a quiz session 
struct CategoryTotals categoryTotals[10]; // Array containing category wize results.

int maxCategory = 0;
int maxQuestions = 0;
char playerName[100];
int fullMarks = 0;
int totMarks = 0;
