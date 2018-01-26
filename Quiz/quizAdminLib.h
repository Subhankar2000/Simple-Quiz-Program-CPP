// This header file contains all neccessary classes for Quiz Administration
// The features used here are mostly of C++ but to maintain compatibility with quizPerformLib.h, we have not used string class in most places. 
// The file handling features are also from C Language (You may modify them to use C++ classes used for file handling
// To do that, refer to the examples given in assignments in module 4 

using namespace std;
// Class Questions encapsulates all the data structures and functions related to Administering Question Bank
class Questions
{
private :
	char vqCategory[20];
	int  vqId;
	char vqText[100];
	char vqAnswer1[100];
	char vqAnswer2[100];
	char vqAnswer3[100];
	char vqAnswer4[100];
	int  vqCAnswer;
	int  vqAllottedMarks;
        
public :
        // Function to add a question in the question bank
        void addQuestions()
		{
		   char yn = 'y';
		   prepareQuizData();
		   while (yn == 'y' || yn == 'Y')
		   {
		     addNewQuestion();
		     cout << "Wish to add more questions (y/n) ::";
		     scanf(" %c", &yn);
	       }
		   writeQuizData();
		}
		
		// Function to modify an existing question in question bank
        void modifyQuestions()
		{
		   char yn = 'y';	
		   prepareQuizData();
		   while (yn == 'y' || yn == 'Y')
		   {
		     modifyQuestion();
		     cout << "Wish to modify more questions (y/n) ::";
		     scanf(" %c", &yn);		     
		   } 		   
		   writeQuizData();
		}
		
		// Function to delete a question from the question bank
        void deleteQuestions()
		{
		   char yn = 'y';	
		   prepareQuizData();
		   while (yn == 'y' || yn == 'Y')
		   {
		     deletQuestion();
		     cout << "Wish to delete more questions (y/n) ::";
		     scanf(" %c", &yn);		     
		   } 
		   writeQuizData();
		}
		
		// Function to print a list of all questions in question bank
        void printQuestions()
		{
		   prepareQuizData();
		   printQuestionsList();
		   cout << "The list has been stored in SQG-QTNBNKRPT.txt" << endl;
		   cout << "You may now print the content of the file" << endl;
		   cout << "Press any key to continue ..." << endl;
		   getch();
		}
		
		// Function to write the data from array to the file
		// packSpace() function has been described in miscFuncLib
		// Note that those questions that marked as deleted are not writen to the file.
		void writeQuizData()
		{
			char fld[100];
			FILE *fp;
		    fp = fopen("SQG-QTNBNK2.txt", "w" );
		    int i;
		    for(i = 0; i < maxQuestions; i++)
		    {
		        if (quizQuestions[i].qDeleted == 0)
		        {
			        fprintf(fp, "%9s",  packSpace(quizQuestions[i].qCategory, 9));
			        fprintf(fp, "%5d",  quizQuestions[i].qId);
			        fprintf(fp, "%40s", packSpace(quizQuestions[i].qText, 40));
			        fprintf(fp, "%50s", packSpace(quizQuestions[i].qAnswer1, 50));
			        fprintf(fp, "%50s", packSpace(quizQuestions[i].qAnswer2, 50));
					fprintf(fp, "%50s", packSpace(quizQuestions[i].qAnswer3, 50));
					fprintf(fp, "%50s", packSpace(quizQuestions[i].qAnswer4, 50));
					fprintf(fp, "%1d",  quizQuestions[i].qCAnswer);
			        fprintf(fp, "%3d",  quizQuestions[i].qAllottedMarks);
		        }
		    }
		    fclose(fp);
		    remove("SQG-QTNBNK.txt");
		    rename("SQG-QTNBNK2.txt", "SQG-QTNBNK.txt");
		}
		
		// This function asks for input and adds a new record at the end of the array used for storing the question bank
		// Refer to allVars to know the structure definition of quizQuestions[]
		void addNewQuestion()
		{
		    char yn = 'y';
	        system("cls");
		    cout << "    Add New Questions      \n";
		    cout << "---------------------------\n\n";
			cout << "Question Category (9 Chrs) :: ";
			scanf(" %s", vqCategory);
			cout << "Question Id  :: ";
			cout << quizQuestions[maxQuestions-1].qId+1 << endl;
			vqId = quizQuestions[maxQuestions-1].qId+1;
			cout << "Question Text (40 Chrs) :: ";
			scanf(" %[^\n]s", vqText);
			cout << "Answer Option 1 (50 Chrs) :: ";
			scanf(" %[^\n]s", vqAnswer1);	
			cout << "Answer Option 2 (50 Chrs) :: ";
			scanf(" %[^\n]s", vqAnswer2);	
			cout << "Answer Option 3 (50 Chrs) :: ";
			scanf(" %[^\n]s", vqAnswer3);	
			cout << "Answer Option 4 (50 Chrs) :: ";
			scanf(" %[^\n]s", vqAnswer4);	
			cout << "Correct Option (1/2/3/4) :: ";
			scanf(" %d", &vqCAnswer);	
			cout << "Allotted Marks (within 100) :: ";
			scanf(" %d", &vqAllottedMarks);	
		    cout << "Commit Data (y/n) ::";
		    scanf(" %c", &yn);
		    if (yn == 'y' || yn == 'Y')
		    {	
		    	strcpy(quizQuestions[maxQuestions].qCategory, vqCategory);
		    	quizQuestions[maxQuestions].qId = vqId;
		    	strcpy(quizQuestions[maxQuestions].qText, vqText);
		    	strcpy(quizQuestions[maxQuestions].qAnswer1, vqAnswer1);
		    	strcpy(quizQuestions[maxQuestions].qAnswer2, vqAnswer2);
		    	strcpy(quizQuestions[maxQuestions].qAnswer3, vqAnswer3);
		    	strcpy(quizQuestions[maxQuestions].qAnswer4, vqAnswer4);
		    	quizQuestions[maxQuestions].qCAnswer = vqCAnswer;
		    	quizQuestions[maxQuestions].qAllottedMarks = vqAllottedMarks;
		    	maxQuestions = maxQuestions + 1;
			}
		}
		
		// The function asks for Question Id and locates the question in the array quizQuestions[], then marks it for deletion
		// Refer to allVars to know the structure definition of quizQuestions[]
		void deletQuestion()
		{
			int i;
		    char yn = 'y';
	        system("cls");
		    cout << "    Delete a Question      \n";
		    cout << "---------------------------\n\n";
			cout << "Question Id  :: ";
			scanf(" %d", &vqId);
			for (i = 0; i < maxQuestions; i++)
			{
				if (quizQuestions[i].qId == vqId)
				    break;
			}
			if (i < maxQuestions)
			{
			   cout << "Question Text :: " << quizQuestions[i].qText << endl;
		       cout << "Delete question (y/n) :: ";
		       scanf(" %c", &yn);
		       if (yn == 'y' || yn == 'Y')	
			      quizQuestions[i].qDeleted = 1;
		    }
		    else
		    {
		    	cout << "Question Id is not present in database \n Press any key to continue ..";
		    	getch();
			}
		}
		
		// The function first asks for Question Id and them dumps the existing information about the question
		// Then it prompts for the field to be modified. Once given, shows the existing field content and prompts you to provide modified field content
		// The modified field content replaces the old field content
		// Refer to allVars.h to know the structure definition of quizQuestions[]
		void modifyQuestion()
		{
			int i;
		    int ch = 9;
	        system("cls");
		    cout << "    Modify a Question      \n";
		    cout << "---------------------------\n\n";
			cout << "Question Id  :: ";
			scanf(" %d", &vqId);
			for (i = 0; i < maxQuestions; i++)
			{
				if (quizQuestions[i].qId == vqId)
				    break;
			}
			if (i < maxQuestions)
			{
			   cout << "1) Question Category :: " << quizQuestions[i].qCategory << endl;
			   cout << "2) Question Text     :: " << quizQuestions[i].qText << endl;
			   cout << "3) Answer Option 1   :: " << quizQuestions[i].qAnswer1 << endl;
			   cout << "4) Answer Option 2   :: " << quizQuestions[i].qAnswer2 << endl;
			   cout << "5) Answer Option 3   :: " << quizQuestions[i].qAnswer3 << endl;
			   cout << "6) Answer Option 4   :: " << quizQuestions[i].qAnswer4 << endl;
			   cout << "7) Correct Option    :: " << quizQuestions[i].qCAnswer << endl;
			   cout << "8) Allotted Marks    :: " << quizQuestions[i].qAllottedMarks << endl<<endl;
			   cout << "9) No Modification   :: " << endl<<endl;
		       cout << "Which field to modify ? (1 - 9) :: ";
		       scanf(" %d", &ch);
		       switch(ch)
		       {
		       	  case 1 :
		       	  	cout << "Present Question Category :: " << quizQuestions[i].qCategory << endl;
		       	  	cout << "New Question Category (9 Chrs) :: " ;
		       	  	scanf(" %s", quizQuestions[i].qCategory);
	                break;
		       	  case 2 :
		       	  	cout << "Present Question Text :: " << quizQuestions[i].qText << endl;
		       	  	cout << "New Question Text (40 Chrs) :: " ;
		       	  	scanf(" %[^\n]s", quizQuestions[i].qText);
	                break;		       	  	
		       	  case 3 :
		       	  	cout << "Present Answer Option 1 :: " << quizQuestions[i].qAnswer1 << endl;
		       	  	cout << "New Answer Option 1 (50 Chrs) :: " ;
		       	  	scanf(" %[^\n]s", quizQuestions[i].qAnswer1);
	                break;		       	  		
		       	  case 4 :
		       	  	cout << "Present Answer Option 2 :: " << quizQuestions[i].qAnswer2 << endl;
		       	  	cout << "New Answer Option 2 (50 Chrs) :: " ;
		       	  	scanf(" %[^\n]s", quizQuestions[i].qAnswer2);
	                break;		       	  	
		       	  case 5 :
		       	  	cout << "Present Answer Option 3 :: " << quizQuestions[i].qAnswer3 << endl;
		       	  	cout << "New Answer Option 3 (50 Chrs) :: " ;
		       	  	scanf(" %[^\n]s", quizQuestions[i].qAnswer3);
	                break;		       	  			       	  	
		       	  case 6 :
		       	  	cout << "Present Answer Option 4 :: " << quizQuestions[i].qAnswer4 << endl;
		       	  	cout << "New Answer Option 4 (50 Chrs) :: " ;
		       	  	scanf(" %[^\n]s", quizQuestions[i].qAnswer4);
	                break;		       	  	
		       	  case 7 :
		       	  	cout << "Present Correct Answer Option :: " << quizQuestions[i].qCAnswer << endl;
		       	  	cout << "New Correct Answer Option (1/2/3/4) :: " ;
		       	  	scanf(" %d", &quizQuestions[i].qCAnswer);
	                break;		       	  	
		       	  case 8 :
		       	  	cout << "Present Allotted Marks :: " << quizQuestions[i].qAllottedMarks << endl;
		       	  	cout << "New Allotted Marks (1/2/3/4) :: " ;
		       	  	scanf(" %d", &quizQuestions[i].qAllottedMarks);
	                break;			       	  	
		       	  case 9 :
		       	  	break;
		       	  default :
		       	  	cout << "Wrong choice .. choose a number between 1 and 9 "<< endl;		       	  	
		       	  
			   }
		    }
		    else
		    {
		    	cout << "Question Id is not present in database \n Press any key to continue ..";
		    	getch();
			}
		}
		
		// The function writes into SQG-QTNBNKRPT.txt from the array quizQuestions[]
		// Refer to allVars.h to know the structure definition of quizQuestions[]
		void printQuestionsList()
		{
			FILE *fp;
		    fp = fopen("SQG-QTNBNKRPT.txt", "w" );
		    int i;
		    fprintf(fp, "    Question Bank Report      \n");
		    fprintf(fp,"-------------------------------\n\n");
		    for(i = 0; i < maxQuestions; i++)
		    {
		        {
			        fprintf(fp, "Question Category :: %s\n",  quizQuestions[i].qCategory);
			        fprintf(fp, "Question Id       :: %d\n",  quizQuestions[i].qId);
			        fprintf(fp, "Question Text     :: %s\n", quizQuestions[i].qText);
			        fprintf(fp, "Answer Option 1   :: %s\n", quizQuestions[i].qAnswer1);
			        fprintf(fp, "Answer Option 2   :: %s\n", quizQuestions[i].qAnswer2);
					fprintf(fp, "Answer Option 3   :: %s\n", quizQuestions[i].qAnswer3);
					fprintf(fp, "Answer Option 4   :: %s\n", quizQuestions[i].qAnswer4);
					fprintf(fp, "Correct Option    :: %d\n",  quizQuestions[i].qCAnswer);
			        fprintf(fp, "Allotted Marks    :: %d\n\n",  quizQuestions[i].qAllottedMarks);
		        }
		    }
		    fclose(fp);
		}
};

// Class AdminUsers encapsulates the information and functions partaining to User Administration
class AdminUsers
{
private  :
   int  userId ;
   string username;
   string actualUserName;
   string password;
public :
	
    //  The function shows that user login screen for Admin users
	//  The Username is "username" and Password is "password"
	//  The function masks the password 
	//  Refer getPassword() function in miscFuncLib.h	
   int   loginSystem() 
   {  
     char usrnm[11];
     string spsswrd;
     char psswrd[11];
     // Present the admin screen
    system("cls");
	cout << "    Adminstrator Login\n";
	cout << "---------------------------\n\n";
    cout << " User Name :: ";
    cin >> usrnm;
    cout << " Password  :: ";
    //cin >> psswrd;
    spsswrd = getPassword('*');
    // In the above step we recieved the password in a string class object 
    // To convert a string class object content to char * data type
	// use the following process 
    copy(spsswrd.begin(), spsswrd.end(), psswrd);
    psswrd[spsswrd.size()] = '\0'; 
	// Now use verify() function to compare the given username and password with content of the file.   
    if (verifyUser(usrnm, psswrd))
    {
    	  cout << endl << "Thank you .. your credentials successfully verified .." << endl;
    	  cout << "Press any key to continue .." << endl;
    	  getch();
          return 1;
    }   
    else
    {
    	  cout << endl << "Sorry .. your credentials do not match with our records .. " << endl;
    	  cout << "Press any key to continue .." << endl;
    	  getch();
          return 0;
    }  
  }
   
   // Function displays Manage Question Menu
   void manageQuestion()
   {
	  int ch = 0;
	  Questions qtn;
	  
	  while (ch != 5)
	  {	   	
	     // Present manage question menu
	    system("cls");
		cout << "    Manage Questions\n";
		cout << "---------------------------\n\n";
	    cout << "   1) Add New Questions " << endl;
	    cout << "   2) Modify existing questions " << endl;
	    cout << "   3) Delete questions " << endl;
	    cout << "   4) Print questions list" << endl;   
	    cout << "   5) Exit from menu " << endl<<endl;
	    cout << "   Enter your choice (1/2/3/4/5) :: ";
        scanf (" %d", &ch);
	   // Evaluate choices 
	    switch (ch)
	    {
	    	case 1 :
	    	    qtn.addQuestions();
				break;	
			case 2 :
				qtn.modifyQuestions();
				break;
	        case 3 :
	        	qtn.deleteQuestions();
	        	break;
	        case 4 :
	        	qtn.printQuestions();
	        	break;
	        case 5 :
	        	break;
	        default :
	        	printf("Please choose between 1,2,3,4 or 5 .. Press a key to continue.\n");
	        	getch();
		}
	   }
	 }
	 
	 // This function will compare the given username and password with the content of the file
	 // The file SQG-USRINF.txt contains username (10 characters) and password (next 10 characters)
	 int verifyUser(char *usr, char *pswd)
	 {
       char buff[50];
       char usrnm[20];
       char psswd[20];
       FILE *fp;
       fp = fopen("SQG-USRINF.txt", "r" );
       if (fgets(buff, 21, fp)!=NULL)
       {
            stringExtract(usrnm, buff, 0, 7);
            //cout << usrnm << strcmp(usr, usrnm) << endl;
            stringExtract(psswd, buff, 10, 19);
            //cout << psswd <<strcmp(pswd, psswd)<< endl;
            //getch();
            if (strcmp(usr, usrnm) == 0 && strcmp(pswd, psswd) == 0)    
			   return 1;
			else 
			   return 0;    
	   }
	   return 0; 
	 }
	 
};




