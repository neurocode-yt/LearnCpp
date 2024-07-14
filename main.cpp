#include <iostream>

using namespace std;

const int NUM_QUESTIONS = 4;
const int NUM_OPTIONS   = 4;

//structure for questions

struct Question{
    string qText;
    string options[NUM_OPTIONS];
    int cOption;  //it will store index of correct option
};
void displayQuestion(const Question& q)
{
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+++++                                             +++++"<<endl;
    cout<<"+++   Question:                                     +++"<<endl;
    cout<<"               "<<q.qText<<endl;
    for(int i=0; i<NUM_OPTIONS; i++)
    {
        cout<<"\t\t"<<q.options[i]<<"\n";
    }
    cout<<endl;
}
//function to get user choice
char getUserChoice()
{
    cout<<"Enter your choice (A,B,C,D) : ";
    char choice;
    cin>>choice;

    choice = toupper(choice);
    return choice;
}
//check if user entered A/B/C/D or not
bool validateChoice(char choice)
{
    return (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D');
}

//function to process our answer
void processAnswer(const Question& q, char userChoice, int& score)
{
    cout<<"\n";
    cout<<"_______________________________________________________\n\n";

    if(!validateChoice(userChoice))
    {
        cout<<"Invalid choice! Got 0 "<<endl;
        cout<<"+++++                                             +++++"<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        return;
    }
    int cIndex = userChoice - 'A';

    if(cIndex == q.cOption)
    {
        cout<<"\t\tCorrect!"<<endl;
        score+=10;
    }
    else
    {
        cout<<"\t\tIncorrect! Correct Answer: "<<q.options[q.cOption]<<endl;
    }
    cout<<"+++++                                             +++++"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}


//function to display result

void displayResult(int& score)
{
    cout<<">>>>>  Press Enter To Generate Report <<<<<"<<endl;
    system("pause");
    system("cls");

    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+++++                                             +++++"<<endl;
    cout<<"++                   QUIZ COMPLETED!                 ++"<<endl;
    cout<<"++                 You Got "<<score<<" out of "<<NUM_QUESTIONS*10<<"              ++"<<endl;

    cout<<"+++++                                             +++++"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

int main()
{
    Question questions[NUM_QUESTIONS] = {
        {"What is the capital of France?",
            {
            "A. London", "B. Paris", "C. Rome", "D. Berlin"
            },
        1},

        {"Which planet is known as the Red Planet?",
            {"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"
            },
        1},

        {"What is the powerhouse of the cell?",
            {"A. Nucleus", "B. Ribosome", "C. Mitochondrion", "D. Glogi Apparatus"
            },
        2},

        {"What is the name of this channel?",
            {"A. NeuroCode", "B. XYZcode", "C. Motivational", "D. NeuraLink"
            },
            0}
    };

    int score = 0;


    for(int i=0 ; i<NUM_QUESTIONS ; i++)
    {
        displayQuestion(questions[i]);
        char userChoice = getUserChoice();
        processAnswer(questions[i],userChoice,score);
        system("pause");
        system("cls");
    }

    displayResult(score);
    return 0;
}






