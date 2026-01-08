#include <iostream>
using namespace std;
enum enLevelType { Easy = 1, Med = 2, Hard = 3, Mix = 4 };//هذا انم يحدد نوع الصعوبة للأسألة 
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };//هذا انم يحدد نوع العميلة المطلوب الامتحان فيها 

//ستركت فيه مكونات الامتحان
struct stQuestions
{
	enLevelType Level;//مستوى الصعوبة 
	enOperationType OperationType;//نوع العمية
	int number1;//الرقم الاول في الامتحان
	int number2;//الرقم الثاني في الامتحان
	short AnswerPlayer;//اجابة المستخدم
	int CorrectAnser;//الاجابة الصحيحه 
	bool IsCorrect;//هل اجابة المستخدم صحيحه ام لا
};

// ستركت فيه معلومات الامتحان
struct stQuiz
{
	stQuestions Questions[10];//مصفوفة الاسألة
	enLevelType Level;//مستوى الصعوبة
	enOperationType OperationType;//نوع العملية
	short QuestionsCount=0;//عدد الاسألة
	short CorrectAnswersCount=0;//عدد الاجابات الصحيحة
	short WrongAnswersCount=0;//عدد الاجابات الخاطئة
	bool IsPassed;//هل اجتاز الامتحان ام لا
};


//هذا الفنكشن يقوم باعطائك ارقام عشوائية بين رقمين تحددها انت له 
int RandomNumber(int From, int To)
{
	// Generate a random number between 0 and (To - From) using rand(),
	// then add From to shift the range to [From, To].
	int randNum = rand() % (To - From + 1) + From;
	return randNum;  // Return the generated random number.
}

//هذا الفنكشن يقوم بقرائة الرقم من المستخدم بين رقمين  انت تحددها 
int ReadNumberRangeBetween(string txt, int From, int To) {
	int number;
	do//يعيد المستخدم لادخال الرقم بين الرقمين المحددين 
	{
		cout << txt;//عرض الرسالة للمستخدم 
		cin >> number;

	} while (From > number || To < number);//فحص الرقم انه بين الرقمين المحددين للفنكشن 

	return number;
}

//سؤال المستخدم عن المستوى المطلوب 
enLevelType ReadLevelQuiz() {


	return (enLevelType)ReadNumberRangeBetween("Enter Questions Level [1] Easy , [2] Med , [3] Hard , [4] Mix ?", 1, 4);

}


//سؤال المستخدم عن العملية المطلوب الاختبار فيها 
enOperationType ReadOperationType() {

	return (enOperationType)ReadNumberRangeBetween("Enter Operation Type [1] Add, [2] Sub , [3] Mul , [4] Div , [5] Mix ?", 1, 5);

}


enOperationType GetOperationType(enOperationType Operation) {
	if (Operation == enOperationType::MixOp) {
		return (enOperationType)RandomNumber(1, 4);
	}
	return Operation;
}

enLevelType GetLevelQueastion(stQuiz Quiz) {

	if (Quiz.Level == enLevelType::Mix) {
		return  (enLevelType)RandomNumber(1, 3);
	}
	return Quiz.Level;
}

int SimpleCalculator(short Number1, short Number2, enOperationType OpType) {
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Div:
		return (Number2 != 0) ? (Number1 / Number2) : 0;  // Avoid division by zero.
	default:
		return Number1 + Number2;
	}
}

stQuestions GenerateQueation(stQuiz &Quiz) {
	stQuestions Question;
	Question.Level = Quiz.Level;
	if (Quiz.Level == enLevelType::Mix) {
		Question.Level=(enLevelType)RandomNumber(1, 3);
	}
	


	switch (Question.Level) {
	case enLevelType::Easy:
	{ 
		
		Question.OperationType = GetOperationType(Quiz.OperationType);
		Question.number1 = RandomNumber(1, 10);
		Question.number2 = RandomNumber(1, 10);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	case enLevelType::Med: {

		Question.OperationType = GetOperationType(Quiz.OperationType);
		Question.number1 = RandomNumber(10, 50);
		Question.number2 = RandomNumber(10, 50);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	case enLevelType::Hard: {

	
		Question.OperationType = GetOperationType(Quiz.OperationType);
		Question.number1 = RandomNumber(50, 100);
		Question.number2 = RandomNumber(50, 100);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	}
	
	
}

void GenerateQueations(stQuiz &Quizs) {

	for (short Quiz=0; Quiz < Quizs.QuestionsCount; Quiz++) {

		Quizs.Questions[Quiz] = GenerateQueation(Quizs);
	}
}


string GetOperation(enOperationType Operation);

//هذا الفنكشن يقوم بطباعة الاختبار مثال 
//5
//7 +
//---------
void PrintQueastion(stQuiz Quiz, short NumberQueastion) {

	cout << "Question [" << Quiz.QuestionsCount << "/" << NumberQueastion +1 << "]\n";
	cout << Quiz.Questions[NumberQueastion].number1 << endl;
	cout << Quiz.Questions[NumberQueastion ].number2<< " " << GetOperation(Quiz.Questions[NumberQueastion].OperationType) << endl;
	cout << "------------------------------------------\n";

}
short ReadShort() {
	short number;
	cin >> number;
	return number;
}
void ReadAnswersPlayer(stQuiz &Quiz)
{
	for (short Queastion = 0; Queastion < Quiz.QuestionsCount; Queastion++)
	{
		PrintQueastion(Quiz, Queastion);
		Quiz.Questions[Queastion].AnswerPlayer = ReadShort();
		 
		if (Quiz.Questions[Queastion].CorrectAnser == Quiz.Questions[Queastion].AnswerPlayer)
		{
			Quiz.Questions[Queastion].IsCorrect = true;
			cout << "Correct Answer (-:\n";
			Quiz.CorrectAnswersCount++;
		}
		else {
			Quiz.Questions[Queastion].IsCorrect = false;
			cout << "Worng Answer )-:\n";//طباعة هذا عندما يكون الجواب خاطأ
			cout << "the right answer is:" << Quiz.Questions[Queastion].CorrectAnser << endl;//طباعة الجواب الصحيح للمستخدم
			Quiz.WrongAnswersCount++;
		}
	}
	Quiz.IsPassed = (Quiz.CorrectAnswersCount > Quiz.WrongAnswersCount);
}

void ReadInfoQuiz(stQuiz& Quiz) {

	//ادخال عدد الأسإلة التي يريدها المستخدم 
	Quiz.QuestionsCount = ReadNumberRangeBetween("How Many Questions do you want to answr from 1 to 10?", 1, 10);
	Quiz.Level = ReadLevelQuiz();
	Quiz.OperationType = ReadOperationType();
	GenerateQueations(Quiz);
	ReadAnswersPlayer(Quiz);
	

}

string GetLevelText(enLevelType enLevel) {
	string Level[4] = { "Easy","Med","Hard","Mix" };
	return Level[enLevel-1];
}
string GetOperation(enOperationType Operation) {

		string Op[5] = { "+","-","*","/","Mix" };
		return Op[Operation-1];
}
//هذا الفنكشن يقوم بطباعة العملوات النهائية للأمتحان 
void PrintFinalQuizz(stQuiz FinalQuizz) {
	cout << "--------------------------------\n";
cout<<	FinalQuizz.IsPassed?"You Passed the Quiz :-)\n" : "Final Resutls is fail :-(\n";
	cout << "--------------------------------\n";
	cout << "Number of Questions     :" << FinalQuizz.QuestionsCount << endl;
	cout << "Questions Level         :" << GetLevelText(FinalQuizz.Level) << endl;
	cout << "OpType                  :" << GetOperation(FinalQuizz.OperationType )<< endl;
	cout << "Number Of Right Answers :" << FinalQuizz.CorrectAnswersCount << endl;
	cout << "Number Of Wrong Answers :" << FinalQuizz.WrongAnswersCount << endl;

}
void start() {

	stQuiz Quiz;

	ReadInfoQuiz(Quiz);
	PrintFinalQuizz(Quiz);
	

}
int main()
{
	srand((unsigned)time(NULL));
	start();
}
