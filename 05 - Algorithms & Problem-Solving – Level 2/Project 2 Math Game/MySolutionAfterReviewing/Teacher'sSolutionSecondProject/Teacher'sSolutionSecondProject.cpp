#include <iostream>
using namespace std;

// تعريف Enum لتحديد مستويات الصعوبة في الاختبار
enum enLevelType { Easy = 1, Med = 2, Hard = 3, Mix = 4 };//هذا انم يحدد نوع الصعوبة للأسألة 

// تعريف Enum لتحديد نوع العملية الحسابية
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };//هذا انم يحدد نوع العميلة المطلوب الامتحان فيها 

// Structure يحتوي على جميع معلومات السؤال الواحد في الاختبار
struct stQuestions
{
	enLevelType Level;              // مستوى صعوبة السؤال (سهل، متوسط، صعب)
	enOperationType OperationType;  // نوع العملية الحسابية المطلوبة في السؤال
	int number1 = 0;                  // العدد الأول في المسألة الحسابية
	int number2 = 0;                  // العدد الثاني في المسألة الحسابية
	short AnswerPlayer = 0;           // الإجابة التي أدخلها اللاعب/المستخدم
	int CorrectAnser = 0;             // الإجابة الصحيحة للسؤال
	bool IsCorrect = false;           // متغير Boolean للتحقق من صحة إجابة المستخدم (true: صحيح، false: خاطئ)

	//تم تهيئة المتغيرات داخل الستركتر لتجنب القيم العشوائية
	//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
};

// Structure يحتوي على جميع معلومات الاختبار الكامل
// ستركت فيه معلومات الامتحان
struct stQuiz
{
	stQuestions Questions[10];          // Array يحتوي على 10 أسئلة كحد أقصى
	enLevelType Level;                  // مستوى الصعوبة العام للاختبار
	enOperationType OperationType;      // نوع العملية الحسابية العام للاختبار
	short QuestionsCount = 0;             // العدد الفعلي للأسئلة في الاختبار (من 1 إلى 10)
	short CorrectAnswersCount = 0;        // عداد الإجابات الصحيحة
	short WrongAnswersCount = 0;          // عداد الإجابات الخاطئة
	bool IsPassed = false;                // حالة نجاح أو رسوب المستخدم في الاختبار
};


// Function يولد رقم عشوائي ضمن نطاق محدد
// Parameters: From (الرقم الأدنى)، To (الرقم الأعلى)
// Return: رقم عشوائي بين From و To
//هذا الفنكشن يقوم باعطائك ارقام عشوائية بين رقمين تحددها انت له 
int RandomNumber(int From, int To)
{
	// Generate a random number between 0 and (To - From) using rand(),
	// then add From to shift the range to [From, To].
	// استخدام دالة rand() لتوليد رقم عشوائي وإضافة From لتحويل النطاق
	int randNum = rand() % (To - From + 1) + From;
	return randNum;  // Return the generated random number.
}

// Function تقرأ رقم من المستخدم ضمن نطاق محدد مع التحقق من الصحة
// Parameters: txt (رسالة توضيحية)، From (الحد الأدنى)، To (الحد الأعلى)
// Return: الرقم الذي أدخله المستخدم بعد التحقق من صحته
//هذا الفنكشن يقوم بقرائة الرقم من المستخدم بين رقمين  انت تحددها 
int ReadNumberRangeBetween(string txt, int From, int To) {
	int number;
	do//يعيد المستخدم لادخال الرقم بين الرقمين المحددين 
	{
		cout << txt;  // طباعة الرسالة التوضيحية للمستخدم
		cin >> number;  // قراءة الرقم من input المستخدم

	} while (From > number || To < number);  // استمرار التكرار حتى يدخل المستخدم رقم صحيح ضمن النطاق

	return number;  // إرجاع الرقم الصحيح
}

// Function تطلب من المستخدم اختيار مستوى صعوبة الاختبار
// Return: مستوى الصعوبة المختار من نوع enLevelType
enLevelType ReadLevelQuiz() {

	return (enLevelType)ReadNumberRangeBetween("Enter Questions Level [1] Easy , [2] Med , [3] Hard , [4] Mix ?", 1, 4);

}


// Function تطلب من المستخدم اختيار نوع العملية الحسابية للاختبار
// Return: نوع العملية المختار من نوع enOperationType
//سؤال المستخدم عن العملية المطلوب الاختبار فيها 
enOperationType ReadOperationType() {

	
	return (enOperationType)ReadNumberRangeBetween("Enter Operation Type [1] Add, [2] Sub , [3] Mul , [4] Div , [5] Mix ?", 1, 5);

}

// Function تحدد نوع العملية الفعلي، إذا كان Mix فإنها تختار عملية عشوائية
// Parameter: Operation (نوع العملية المطلوب)
// Return: نوع العملية الفعلي الذي سيتم استخدامه
enOperationType GetOperationType(enOperationType Operation) {
	if (Operation == enOperationType::MixOp) {
		// في حالة اختيار Mix، يتم اختيار عملية عشوائية من 1 إلى 4
		return (enOperationType)RandomNumber(1, 4);
	}
	return Operation;  // إرجاع نفس نوع العملية إذا لم يكن Mix
}

// Function تحدد مستوى السؤال الفعلي، إذا كان Mix فإنها تختار مستوى عشوائي
// Parameter: Quiz (معلومات الاختبار)
// Return: مستوى الصعوبة الفعلي الذي سيتم استخدامه
enLevelType GetLevelQueastion(stQuiz Quiz) {

	if (Quiz.Level == enLevelType::Mix) {
		// في حالة اختيار Mix، يتم اختيار مستوى عشوائي من 1 إلى 3
		return  (enLevelType)RandomNumber(1, 3);
	}
	return Quiz.Level;  // إرجاع نفس المستوى إذا لم يكن Mix
}

// Function تقوم بإجراء العملية الحسابية البسيطة بناءً على نوع العملية
// Parameters: Number1 (العدد الأول)، Number2 (العدد الثاني)، OpType (نوع العملية)
// Return: نتيجة العملية الحسابية
int SimpleCalculator(short Number1, short Number2, enOperationType OpType) {
	switch (OpType)  // Switch Statement لتحديد نوع العملية
	{
	case enOperationType::Add:
		return Number1 + Number2;  // عملية الجمع
	case enOperationType::Sub:
		return Number1 - Number2;  // عملية الطرح
	case enOperationType::Mul:
		return Number1 * Number2;  // عملية الضرب
	case enOperationType::Div:
		return (Number2 != 0) ? (Number1 / Number2) : 0;  // عملية القسمة مع التحقق من عدم القسمة على صفر
	default:
		return Number1 + Number2;  // Default Case يرجع عملية جمع
	}
}

// Function تولد مستوى صعوبة عشوائي (Easy, Med, Hard)
//فائدتة في حالة اننا اضفنا مستوى جديد في المستقبل لن نحتاج لتعديل الفنكشنات التي تستخدم هذا الفنكشن
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
enLevelType GetRandomLevelType() {

	// توليد رقم عشوائي بين 1 و 3 وتحويله إلى enLevelType
	return (enLevelType)RandomNumber(1, 3);

}

// Function تولد نوع عملية حسابية عشوائي (Add, Sub, Mul, Div)
//فائدتة في حالة اننا اضفنا عملية جديدة في المستقبل لن نحتاج لتعديل الفنكشنات التي تستخدم هذا الفنكشن
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
enOperationType GetRandomOperationType() {
	// توليد رقم عشوائي بين 1 و 4 وتحويله إلى enOperationType
	return (enOperationType)RandomNumber(1, 4);
}

// Function تولد سؤال واحد كامل مع جميع تفاصيله
// Parameters: Level (مستوى الصعوبة)، Operation (نوع العملية)
// Return: Structure من نوع stQuestions يحتوي على السؤال الكامل
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
stQuestions GenerateQueation(enLevelType Level, enOperationType Operation)
{

	stQuestions Question;  // إنشاء Structure لتخزين بيانات السؤال

	// إذا كان المستوى Mix، اختر مستوى عشوائي
	if (Level == enLevelType::Mix) {
		Level = GetRandomLevelType();
	}

	// إذا كان نوع العملية Mix، اختر عملية عشوائية
	if (Operation == enOperationType::MixOp) {
		Operation = GetRandomOperationType();
	}

	Question.OperationType = Operation;  // تعيين نوع العملية للسؤال

	// Switch Statement لتوليد الأرقام بناءً على مستوى الصعوبة
	switch (Level) {
	case enLevelType::Easy:  // المستوى السهل: أرقام من 1 إلى 10
	{
		Question.Level = Level;  // تعيين مستوى السؤال
		Question.number1 = RandomNumber(1, 10);  // توليد الرقم الأول
		Question.number2 = RandomNumber(1, 10);  // توليد الرقم الثاني
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);  // حساب الإجابة الصحيحة
		return Question;  // إرجاع السؤال الكامل
	}
	case enLevelType::Med: {  // المستوى المتوسط: أرقام من 10 إلى 50
		Question.Level = Level;
		Question.number1 = RandomNumber(10, 50);
		Question.number2 = RandomNumber(10, 50);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	case enLevelType::Hard: {  // المستوى الصعب: أرقام من 50 إلى 100
		Question.Level = Level;

		Question.number1 = RandomNumber(50, 100);
		Question.number2 = RandomNumber(50, 100);
		Question.CorrectAnser = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
		return Question;
	}
	}


}

// Function تولد جميع أسئلة الاختبار بناءً على العدد المطلوب
// Parameter: Quizs (Reference لـ Structure الاختبار الذي سيتم ملؤه بالأسئلة)
// ملاحظة: استخدام Pass by Reference لتعديل الـ Structure الأصلي
void GenerateQueations(stQuiz& Quizs) {

	// Loop لتوليد كل سؤال من الأسئلة المطلوبة
	for (short Quiz = 0; Quiz < Quizs.QuestionsCount; Quiz++) {

		// تخزين كل سؤال مولد في Array الأسئلة
		Quizs.Questions[Quiz] = GenerateQueation(Quizs.Level, Quizs.OperationType);
	}
}


//declaration of GetOperation function
string GetOperation(enOperationType Operation);

// Function تطبع السؤال بشكل منسق على الشاشة
// Parameters: Quiz (بيانات الاختبار)، NumberQueastion (رقم/index السؤال في Array)
//هذا الفنكشن يقوم بطباعة الاختبار مثال 
//5
//7 +
//---------
void PrintQueastion(stQuiz Quiz, short NumberQueastion) {

	// طباعة رقم السؤال الحالي من إجمالي عدد الأسئلة
	cout << "Question [" << NumberQueastion + 1 << "/" << Quiz.QuestionsCount << "]\n";
	cout << Quiz.Questions[NumberQueastion].number1 << endl;  // طباعة الرقم الأول
	// طباعة الرقم الثاني مع رمز العملية الحسابية
	cout << Quiz.Questions[NumberQueastion].number2 << " " << GetOperation(Quiz.Questions[NumberQueastion].OperationType) << endl;
	cout << "----------------------------------\n";  // خط فاصل للتنسيق

}

// Function تتحقق من صحة إجابة المستخدم لسؤال محدد وتحدث الإحصائيات
// Parameters: Quiz (Reference لبيانات الاختبار)، QuestionNumber (رقم السؤال المراد تصحيحه)
//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد
void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber) {
	// مقارنة إجابة المستخدم مع الإجابة الصحيحة
	if (Quiz.Questions[QuestionNumber].CorrectAnser == Quiz.Questions[QuestionNumber].AnswerPlayer)
	{
		Quiz.Questions[QuestionNumber].IsCorrect = true;  // تعيين حالة السؤال كصحيح
		cout << "Correct Answer (-:\n";  // رسالة تأكيد الإجابة الصحيحة
		Quiz.CorrectAnswersCount++;  // زيادة عداد الإجابات الصحيحة
	}
	else {
		Quiz.Questions[QuestionNumber].IsCorrect = false;  // تعيين حالة السؤال كخاطئ
		cout << "Worng Answer )-:\n";  // رسالة إجابة خاطئة
		cout << "the right answer is:" << Quiz.Questions[QuestionNumber].CorrectAnser << endl;  // عرض الإجابة الصحيحة للمستخدم
		Quiz.WrongAnswersCount++;  // زيادة عداد الإجابات الخاطئة
	}
}

// Function تقرأ إجابات المستخدم لجميع الأسئلة وتصححها مباشرة
// Parameter: Quiz (Reference لبيانات الاختبار)
// العملية: عرض كل سؤال، قراءة الإجابة، التصحيح الفوري، تحديد حالة النجاح النهائية
void ReadAnswersPlayer(stQuiz& Quiz)
{
	// Loop للمرور على جميع أسئلة الاختبار
	for (short Queastion = 0; Queastion < Quiz.QuestionsCount; Queastion++)
	{
		PrintQueastion(Quiz, Queastion);  // طباعة السؤال الحالي
		cin >> Quiz.Questions[Queastion].AnswerPlayer;  // قراءة إجابة المستخدم من Input
		CorrectTheQuestionAnswer(Quiz, Queastion);  // تصحيح الإجابة مباشرة
	}
	// تحديد حالة النجاح: إذا كانت الإجابات الصحيحة أكثر من الخاطئة = نجاح
	Quiz.IsPassed = (Quiz.CorrectAnswersCount > Quiz.WrongAnswersCount);
}

//Declaration of GetLevelText function
void PrintFinalQuizz(stQuiz FinalQuizz);

// Function رئيسية تقرأ معلومات الاختبار من المستخدم وتدير العملية كاملة
// تتضمن: قراءة عدد الأسئلة، المستوى، نوع العملية، توليد الأسئلة، قراءة الإجابات، عرض النتائج
void ReadInfoQuiz() {
	stQuiz Quiz;  // إنشاء Structure لتخزين بيانات الاختبار

	// قراءة عدد الأسئلة المطلوبة من المستخدم (من 1 إلى 10)
	Quiz.QuestionsCount = ReadNumberRangeBetween("How Many Questions do you want to answr from 1 to 10?", 1, 10);
	Quiz.Level = ReadLevelQuiz();  // قراءة مستوى الصعوبة
	Quiz.OperationType = ReadOperationType();  // قراءة نوع العملية الحسابية

	GenerateQueations(Quiz);  // توليد جميع أسئلة الاختبار
	ReadAnswersPlayer(Quiz);  // قراءة وتصحيح إجابات المستخدم
	PrintFinalQuizz(Quiz);  // طباعة النتائج النهائية

}

// Function تحول مستوى الصعوبة من Enum إلى String نصي
// Parameter: enLevel (مستوى الصعوبة من نوع Enum)
// Return: String يحتوي على اسم المستوى بالنص
string GetLevelText(enLevelType enLevel) {
	string Level[4] = { "Easy","Med","Hard","Mix" };  // Array يحتوي على أسماء المستويات
	return Level[enLevel - 1];  // إرجاع النص المقابل (طرح 1 لأن Enum يبدأ من 1)
}

// Function تحول نوع العملية من Enum إلى رمز نصي
// Parameter: Operation (نوع العملية من نوع Enum)
// Return: String يحتوي على رمز العملية (+, -, *, /, Mix)
string GetOperation(enOperationType Operation) {

	string Op[5] = { "+","-","*","/","Mix" };  // Array يحتوي على رموز العمليات
	return Op[Operation - 1];  // إرجاع الرمز المقابل (طرح 1 لأن Enum يبدأ من 1)
}

// Function تطبع النتائج النهائية للاختبار بشكل منسق ومفصل
// Parameter: FinalQuizz (بيانات الاختبار النهائية)
// المعلومات المعروضة: حالة النجاح/الرسوب، عدد الأسئلة، المستوى، نوع العملية، الإحصائيات
//هذا الفنكشن يقوم بطباعة العملوات النهائية للأمتحان 
void PrintFinalQuizz(stQuiz FinalQuizz) {
	cout << "--------------------------------\n";  // خط فاصل علوي
	// Ternary Operator لعرض رسالة النجاح أو الرسوب بناءً على IsPassed
	cout << (FinalQuizz.IsPassed ? "You Passed the Quiz :-)\n" : "Final Resutls is fail :-(\n");
	cout << "--------------------------------\n";  // خط فاصل
	cout << "Number of Questions     :" << FinalQuizz.QuestionsCount << endl;  // عدد الأسئلة
	cout << "Questions Level         :" << GetLevelText(FinalQuizz.Level) << endl;  // مستوى الصعوبة
	cout << "OpType                  :" << GetOperation(FinalQuizz.OperationType) << endl;  // نوع العملية
	cout << "Number Of Right Answers :" << FinalQuizz.CorrectAnswersCount << endl;  // عدد الإجابات الصحيحة
	cout << "Number Of Wrong Answers :" << FinalQuizz.WrongAnswersCount << endl;  // عدد الإجابات الخاطئة

}

// Function تقوم بمسح الشاشة وإعادة تعيين الألوان
// استخدام System Commands للتحكم بـ Console
void ResetScreen() {
	system("cls");  // Command لمسح الشاشة (Clear Screen)
	system("color 0F");  // Command لتعيين ألوان Console (خلفية سوداء، نص أبيض)

}

// Function رئيسية لبدء البرنامج وإدارة حلقة إعادة اللعب
// تتضمن: Loop للسماح بإعادة الاختبار، مسح الشاشة، سؤال المستخدم عن الإعادة
void start() {
	//بداية الامتحان
	stQuiz Quiz;  // تعريف Structure للاختبار
	char PlayAgin = 'Y';  // متغير للتحكم في إعادة اللعب، القيمة الافتراضية 'Y'

	do  // Do-While Loop للسماح بتكرار الاختبار
	{
		ResetScreen();  // مسح الشاشة قبل كل اختبار جديد
		ReadInfoQuiz();  // بدء الاختبار وقراءة جميع المعلومات

		// سؤال المستخدم إذا كان يريد إعادة الاختبار
		cout << endl << "Do you want to play agin Y/N?";
		cin >> PlayAgin;  // قراءة اختيار المستخدم

	} while (PlayAgin == 'Y' || PlayAgin == 'y');  // الاستمرار إذا أدخل Y أو y

	//تم اضافة الدو وايل لكي يسأل المستخدم اذا كان يريد اعادة الامتحان ام لا
	//هذي الاضافة بعد مع مشاهدة حل الاستاذ محمد 

}

// Function الرئيسية - نقطة بداية تنفيذ البرنامج
int main()
{
	// تهيئة مولد الأرقام العشوائية باستخدام الوقت الحالي كـ Seed
	// هذا يضمن توليد أرقام عشوائية مختلفة في كل مرة يتم تشغيل البرنامج
	srand((unsigned)time(NULL));

	start();  // استدعاء Function لبدء البرنامج
}