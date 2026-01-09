#include <iostream>
using namespace std;
enum enLevelType { Easy = 1, Med = 2, Hard = 3, Mix = 4 };//هذا انم يحدد نوع الصعوبة للأسألة 
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };//هذا انم يحدد نوع العميلة المطلوب الامتحان فيها 

//ستركت فيه مكونات الامتحان
struct stQuestions
{
	enLevelType Level;//مستوى الصعوبة 
	enOperationType OperationType;//نوع العمية
	int number1=0;//الرقم الاول في الامتحان
	int number2=0;//الرقم الثاني في الامتحان
	short AnswerPlayer=0;//اجابة المستخدم
	int CorrectAnser=0;//الاجابة الصحيحه 
	bool IsCorrect=false;//هل اجابة المستخدم صحيحه ام لا

	//تم تهيئة المتغيرات داخل الستركتر لتجنب القيم العشوائية
	//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
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
	bool IsPassed=false;//هل اجتاز الامتحان ام لا
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
//هذا الفنكشن يقوم باعطاء نوع مستوى عشوائي تم استخدامه في حالة اختيار المستخدم لمستوى المكس
//فائدتة في حالة اننا اضفنا مستوى جديد في المستقبل لن نحتاج لتعديل الفنكشنات التي تستخدم هذا الفنكشن
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
enLevelType GetRandomLevelType() {
	
		return (enLevelType)RandomNumber(1, 3);
	
}
//هذا الفنكشن يقوم باعطاء نوع عملية عشوائي تم استخدامه في حالة اختيار المستخدم لنوع العملية المكس
//فائدتة في حالة اننا اضفنا عملية جديدة في المستقبل لن نحتاج لتعديل الفنكشنات التي تستخدم هذا الفنكشن
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
enOperationType GetRandomOperationType() {
	return (enOperationType)RandomNumber(1, 4);
}
stQuestions GenerateQueation(enLevelType Level,enOperationType Operation)//تم اضافة انم الفل وانم الأبريشر في هذا الفنكشن لكي يكون هذا الفنكشن متخصص في انشاء سؤال واحد فقط 
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
{

	stQuestions Question;
	
	if (Level == enLevelType::Mix) {
		Level = GetRandomLevelType();
	}
	
	if (Operation == enOperationType::MixOp) {
		Operation = GetRandomOperationType();
	}

	Question.OperationType = Operation;

	switch (Level) {
	case enLevelType::Easy:
	{ 
		Question.Level = Level;
		Question.number1 = RandomNumber(1, 10);
		Question.number2 = RandomNumber(1, 10);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	case enLevelType::Med: {
		Question.Level = Level;
		Question.number1 = RandomNumber(10, 50);
		Question.number2 = RandomNumber(10, 50);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	case enLevelType::Hard: {
		Question.Level = Level;
	
		Question.number1 = RandomNumber(50, 100);
		Question.number2 = RandomNumber(50, 100);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	}
	
	
}

void GenerateQueations(stQuiz &Quizs) {

	for (short Quiz=0; Quiz < Quizs.QuestionsCount; Quiz++) {

		Quizs.Questions[Quiz] = GenerateQueation(Quizs.Level,Quizs.OperationType);
	}
}


string GetOperation(enOperationType Operation);

//هذا الفنكشن يقوم بطباعة الاختبار مثال 
//5
//7 +
//---------
void PrintQueastion(stQuiz Quiz, short NumberQueastion) {

	cout << "Question [" << NumberQueastion + 1 << "/" <<  Quiz.QuestionsCount << "]\n";
	cout << Quiz.Questions[NumberQueastion].number1 << endl;
	cout << Quiz.Questions[NumberQueastion ].number2<< " " << GetOperation(Quiz.Questions[NumberQueastion].OperationType) << endl;
	cout << "----------------------------------\n";

}
//هذا الفنكشن يقوم بتصحيح اجابة المستخدم
//وتمت الاستفادة منه في حالة اننا نريد تصحيح اجابة سؤال معين فقط
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber) {
	if (Quiz.Questions[QuestionNumber].CorrectAnser == Quiz.Questions[QuestionNumber].AnswerPlayer)
	{
		Quiz.Questions[QuestionNumber].IsCorrect = true;
		cout << "Correct Answer (-:\n";
		Quiz.CorrectAnswersCount++;
	}
	else {
		Quiz.Questions[QuestionNumber].IsCorrect = false;
		cout << "Worng Answer )-:\n";//طباعة هذا عندما يكون الجواب خاطأ
		cout << "the right answer is:" << Quiz.Questions[QuestionNumber].CorrectAnser << endl;//طباعة الجواب الصحيح للمستخدم
		Quiz.WrongAnswersCount++;
	}
}

void ReadAnswersPlayer(stQuiz &Quiz)
{
	for (short Queastion = 0; Queastion < Quiz.QuestionsCount; Queastion++)
	{
		PrintQueastion(Quiz, Queastion);
		cin>>Quiz.Questions[Queastion].AnswerPlayer;
		CorrectTheQuestionAnswer(Quiz, Queastion);//هذا الاضافة بعد مع مشاهدة حل الاستاذ محمد
	}
	Quiz.IsPassed = (Quiz.CorrectAnswersCount > Quiz.WrongAnswersCount);
}
void PrintFinalQuizz(stQuiz FinalQuizz);
void ReadInfoQuiz() {
	stQuiz Quiz;
	//ادخال عدد الأسإلة التي يريدها المستخدم 
	Quiz.QuestionsCount = ReadNumberRangeBetween("How Many Questions do you want to answr from 1 to 10?", 1, 10);
	Quiz.Level = ReadLevelQuiz();
	Quiz.OperationType = ReadOperationType();

	GenerateQueations(Quiz);
	ReadAnswersPlayer(Quiz);
	PrintFinalQuizz(Quiz);

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
cout<<(FinalQuizz.IsPassed ? "You Passed the Quiz :-)\n" : "Final Resutls is fail :-(\n");
	cout << "--------------------------------\n";
	cout << "Number of Questions     :" << FinalQuizz.QuestionsCount << endl;
	cout << "Questions Level         :" << GetLevelText(FinalQuizz.Level) << endl;
	cout << "OpType                  :" << GetOperation(FinalQuizz.OperationType )<< endl;
	cout << "Number Of Right Answers :" << FinalQuizz.CorrectAnswersCount << endl;
	cout << "Number Of Wrong Answers :" << FinalQuizz.WrongAnswersCount << endl;

}
void ResetScreen() {
	system("cls");
	system("color 0F");

}

void start() {
	//بداية الامتحان
	stQuiz Quiz;
	char PlayAgin = 'Y';
	do
	{
		ResetScreen();
		ReadInfoQuiz();//تم حذف الستركتر كوز واضافته في الفنكشن مباشرة تعديل لمشابهة حل الاستاذ محمد 
	

		cout << endl << "Do you want to play agin Y/N?";
		cin >> PlayAgin;
	} while (PlayAgin=='Y'|| PlayAgin=='y'); 

	//تم اضافة الدو وايل لكي يسأل المستخدم اذا كان يريد اعادة الامتحان ام لا
	//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد 

}
int main()
{
	srand((unsigned)time(NULL));
	start();
}
