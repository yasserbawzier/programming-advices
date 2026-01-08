
#include <iostream>
using namespace std;
enum enLevel { Easy = 1, Med = 2, Hard = 3, mix = 4 };//هذا انم يحدد نوع الصعوبة للأسألة 
enum enOperationType { Add = 1, Sub =2, Mul = 3, Div = 4, Mix = 5 };//هذا انم يحدد نوع العميلة المطلوب الامتحان فيها 

//هذا الفنكشن يقوم بقرائة الرقم من المستخدم بين رقمين  انت تحددها 
int ReadNumberRangeBetween(string txt, int From, int To) {
	int number;
	do//يعيد المستخدم لادخال الرقم بين الرقمين المحددين 
	{
		cout << txt;//عرض الرسالة للمستخدم 
		cin >> number;

	} while (From>number||To<number);//فحص الرقم انه بين الرقمين المحددين للفنكشن 
	
	return number;
}

//ستركت فيه مكونات الامتحان
struct stQuizz 
{
	short NumberQuuestions;//رقم السؤال 
	enLevel Level;//مستوى الصعوبة 
	enOperationType OperationType;//نوع العمية
	int number1;//الرقم الاول في الامتحان
	int number2;//الرقم الثاني في الامتحان
	short AnswerPlayer;//اجابة المستخدم
	int CorrectAnser;//الاجابة الصحيحه 
};
// ستركت فيه النتائج النهائية للأسألة التي تم عرضها للمستخدم
struct stFinalQuizzRuslte {
	short NumberQuuestions;//أجمالي عدد الأسألة 
	string Level;//نوع الصعوبة المختار في الأسألة
	string OperationType;//نوع العميلات التي تم اختيارة للأسألة 
	short NumberRightAnswer;//عدد الإجابات الصحيحه من المستخدم 
	short NubmerWrongAnswer;//عدد الإجابات الخاطئة من المستخدم 
};

//هذا الفنكشن يقوم باعطائك ارقام عشوائية بين رقمين تحددها انت له 
int RandomNumber(int From, int To)
{
	// Generate a random number between 0 and (To - From) using rand(),
	// then add From to shift the range to [From, To].
	int randNum = rand() % (To - From + 1) + From;
	return randNum;  // Return the generated random number.
}
//يقوم الفنكشن باعطائك  رقم حسب مستوى الصعوبة المطلوب في الامتحان 
//مثال مصتوى الصعوبة كان سهل  يقوم باعطائك ارقام عشوائية بين 1 الى 10 
short getNumberQuuestionsLevel(enLevel Level) {
	//في حالة ان مستوى الصعوبة كان مكس يقوم باختيار مستوى صعوبة بين السهل والصعب والمتوسط 
	if (Level == enLevel::mix) {
		Level = (enLevel)RandomNumber(1, 3);//هذا يقوم باختيار رقم عشوائي موجود في انم اللفل ثم يحولها الى نوع انم اللفل 
	}

	switch (Level) {
	case enLevel::Easy:
		return RandomNumber(1, 10);//مستوى صعوبة سهل 
	case enLevel::Med:
		return RandomNumber(10, 20);//مستوى صعوبة متوسط
	case enLevel::Hard:
		return RandomNumber(20, 30);//مستوى صعوبة صعب
	}
}

//هذا الفنكشن يعطيك نوع العميلة الحسابية جمع ضرب قسمة ضرح
enOperationType getOperationType(enOperationType OperationType) {
	//اذا كان مكس يقوم باختيار عملية بطريقة عشوائية 
	if (OperationType == enOperationType::Mix) {
		OperationType = (enOperationType)RandomNumber(1, 4);
	}

	switch (OperationType) {
	case enOperationType::Add:
		return enOperationType::Add;
	case enOperationType::Div:
		return enOperationType::Div;
	case enOperationType::Mul:
		return enOperationType::Mul;
	case enOperationType::Sub:
		return enOperationType::Sub;
	}
}
//يقوم الفنكشن باعطائك قيمة العميلة الحسابية كحرف فقط مثلا اذا كان جمع اعطائك قيمة + واذاكان قسمة اعطاك قيمة / وهاكذا 
char PrintOperationType(enOperationType OperationType) {

	
	switch (OperationType) {
	case enOperationType::Add:
		return '+';
	case enOperationType::Div:
		return '/'; 
	case enOperationType::Mul:
			return '*';
	case enOperationType::Sub:
		return '-';
	}

}


//هذا الفنكشن يقوم بطباعة الاختبار مثال 
//5
//7 +
//---------
void PrintQuizz(stQuizz Quizz,short HowManyPlaying) {
	
	cout << "Question [" << Quizz.NumberQuuestions << "/" <<  HowManyPlaying << "]\n";
	cout << Quizz.number1 << endl;
	cout << Quizz.number2 << " " << PrintOperationType(Quizz.OperationType) << endl;
	cout << "------------------------------------------\n";

}


//هذا الفنكشن يقوم باعطائك النتيجه الصحيحه من العميل يأخذ ستركت الكوز وفيه الرقمين والعملية ويقوم باعطائك النتيجة الصحيحه
short CorrectAnser(stQuizz Quizz) {

	switch (Quizz.OperationType) {
	case enOperationType::Add:
		return Quizz.number1 + Quizz.number2;
	case enOperationType::Div:
		return Quizz.number1 / Quizz.number2;
	case enOperationType::Mul:
		return Quizz.number1 * Quizz.number2;
	case enOperationType::Sub:
		return Quizz.number1 - Quizz.number2;

	}
}

//هذا الفنكشن يحول مستوى الصعوبة من انم الى سترق ويعطيك نص يوضح لك مستوى الصعوبة 
string gettxetLevel(enLevel Level) {

	switch (Level) {
	case enLevel::Easy:
		return "Easy";
	case enLevel::Med:
		return "Med";
	case enLevel::Hard:
		return "Hard";
	case enLevel::mix:
		return "Mix";
	}
}

//هذا الفنكشن يحول نوع العميلة الحسابية من انم الى استرق ويعطيك نص يوضح لك نوع العملية التي تم الختيارها
string gettxetOperationType(enOperationType OperationType) {

	switch (OperationType) {
	case enOperationType::Add:
		return "Add";
	case enOperationType::Div:
		return "Div";
	case enOperationType::Mix:
		return "Mix";
	case enOperationType::Mul:
		return "Mul";
	case enOperationType::Sub:
		return "Sub";
	}
}

//هذا الفنكشن يتأكد من ان حل المستخدم صحيح 
bool DidPlayersAnswerCorrectly(stQuizz Quizz) {
	if (Quizz.CorrectAnser == Quizz.AnswerPlayer) 
		return true;
	else
		return false;
}

//هذا الفنكشن يستقبل معلومات الأسألة كاملا ثم يضيفها في استركت نتائج الامتحان النهائية 
stFinalQuizzRuslte FinalQuizzRuslte(short HowManyPlaying, enOperationType OperationType, enLevel level , short RightAnswers, short WrongAnswers) {
	stFinalQuizzRuslte FinalQuizz;
	FinalQuizz.Level = gettxetLevel(level);
	FinalQuizz.NubmerWrongAnswer = WrongAnswers;
	FinalQuizz.NumberQuuestions = HowManyPlaying;
	FinalQuizz.NumberRightAnswer = RightAnswers;
	FinalQuizz.OperationType = gettxetOperationType(OperationType);
	return FinalQuizz;
}

//هذا الفنكشن يقوم بتغير لون الشاشة في حالة ادخال ترو يكون اللون اخضر وفي حالة ادخال فولس يتحول اللون احمر مع اصدار صوت 
void ChangMonter(bool True) {
	if (True)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}
//هذا الفنكشن يبدا اللعبة ثم يعطي اخر شي استركت نتائج الاختبار النهائية محملة بالمعلومات
stFinalQuizzRuslte Playint(short HowManyPlaying) {
	stFinalQuizzRuslte FinalQuizz;//انشاء استركت يتم تحميل فيها معلومات اختيار العميل والأسألة كامل
	short RightAnswers = 0, WrongAnswers = 0;//معرفة عدد المرات التي كانت النتيجة خاطئة وعدد المرات التي كانت النتيجة صحيحة 

	stQuizz Quizz;//استركت الامتحان 
	
	
	//سؤال المستخدم عن المستوى المطلوب وحفظة في المتغير
    enLevel Level = (enLevel)ReadNumberRangeBetween("Enter Questions Level [1] Easy , [2] Med , [3] Hard , [4] Mix ?", 1, 40);

	//سؤال المستخدم عن العملية المطلوب الاختبار فيها وحفظة في المتغير
	enOperationType OperationType = (enOperationType)ReadNumberRangeBetween("Enter Operation Type [1] Add, [2] Sub , [3] Mul , [4] Div , [5] Mix ?", 1, 5);
	
	Quizz.Level = Level;//حفظ اللفل في الستركتر الكويز قبل الفورة لوب من اجل ان مستوى الصعوبة لا نريده ان يتغير داخل الفور 
	//مثلا اذا كان الصعوبة صعب لا يجب ان تتغير مع الفور الى شي ثاني وهاكذا ان كانت مكس او اي مستوى اخر 


	//الفور يتم فيها عرض الاسألة للمستخدم لكي يجيب عليها 
	for (short Games = 1; Games <= HowManyPlaying; Games++) {
		
		Quizz.NumberQuuestions = Games;//حفض رقم السؤال في استركت الكوز
		Quizz.number1 = getNumberQuuestionsLevel(Quizz.Level);//اختيار الرقم الاول في السؤال حسب مستوى الصعوبة المختار
		Quizz.number2= getNumberQuuestionsLevel(Quizz.Level);//اختيار الرقم الثاني في السؤال حسب مستوى الصعوبة المختار
		Quizz.OperationType = (enOperationType)getOperationType(OperationType);//اختيار العملية التي ستتم به السؤال سواء + او * او.....إلخ
		Quizz.CorrectAnser = CorrectAnser(Quizz);//اضافة الجواب الصحيح للعملية 
		PrintQuizz(Quizz, HowManyPlaying);//طباعة السؤال للمستخدم
		cin >> Quizz.AnswerPlayer;//إدخال جواب السؤال من المستخدم

		//التحقق من صحة الجواب
		if (DidPlayersAnswerCorrectly(Quizz)) {
			cout << "Correct Answer (-:\n";//صباعة هذي في حالة ان الجواب صحيح
			RightAnswers++;//زيادة واحد على المتغير لحساب عدد الإسإلة التي تم الاجابة عليها بطريقة صحيحه 
			ChangMonter(true);//تغير لون الشاشة الى اللون الاخضر
		}
		else 
		{
			WrongAnswers++;//زيادة واحد على المتغير لحساب عدد الأسإلة التي تم اللإجابة عليها بطريقة خاطئة
			cout << "Worng Answer )-:\n";//طباعة هذا عندما يكون الجواب خاطأ
			cout << "the right answer is:" << Quizz.CorrectAnser << endl;//طباعة الجواب الصحيح للمستخدم
			ChangMonter(false);//تغيير لون الشاشة الى الاحمر مع اصدار صوت
		}


	}

	if (WrongAnswers < RightAnswers) 
		ChangMonter(true);//يتم تغيير الشاشة الى اللون الاخضر اذا كان عدد الاجابات الصحيحه اكبر من عدد الاجابات الخاطئة
	else
		ChangMonter(false);//في حالة ان عدد مرات الإجابات الخاطئة اكبر يتم تغير الشاشة الى اللون الاحمر مع اصدار صوت 


	//تحويل معلومات إختيارات العميل الى استركت النتائج النهائية للأمتحان 
	return FinalQuizzRuslte(HowManyPlaying,OperationType,Level, RightAnswers, WrongAnswers);


}

//هذا الفنكشن يقوم بطباعة العملوات النهائية للأمتحان 
void PrintFinalQuizz(stFinalQuizzRuslte FinalQuizz) {
	cout << "--------------------------------\n";
	cout << "Final Resutls is fail :-(\n";
	cout << "--------------------------------\n";
	cout << "Number of Questions     :" << FinalQuizz.NumberQuuestions << endl;
	cout << "Questions Level         :" << FinalQuizz.Level << endl;
	cout << "OpType                  :" << FinalQuizz.OperationType << endl;
	cout << "Number Of Right Answers :" << FinalQuizz.NumberRightAnswer << endl;
	cout << "Number Of Wrong Answers :" << FinalQuizz.NubmerWrongAnswer << endl;
 
}
//يقوم بتغيير لون الشاشة الى اللون الاسود ومسح جميع الكتابة التي فيها 
void ResetScreen() {

	system("color 07"); // إعادة الخلفية سوداء والنص أبيض
	system("cls");//تنضيف الشاشة من الكتابات التي عليها 
}
void start()
{
	char ch = 'y';
	do
	{
		ResetScreen();//تنظيف الشاشة من الكتابات التي عليها 

		//ادخال عدد الأسإلة التي يريدها المستخدم 
		short HowManyPlaying = ReadNumberRangeBetween("How Many Questions do you want to answr from 1 to 100?", 1, 100);
		stFinalQuizzRuslte FinalQuizz = Playint(HowManyPlaying);//بداية اللعبة وتعبية البيانات النهائية في الستركت نتائج الاختبارات النهائية
		PrintFinalQuizz(FinalQuizz);//طباعة نتائج الاختبارات النهائية 

		cout << "do you wnats playing agen:[y] or [n] :";//سؤال المستخدم هل يريد ان يمتحن مرة اخرى ام لا
		cin >> ch;
	} while (ch=='y'||ch=='Y');
	

}


int main()
{
	srand((unsigned)time(NULL));
	start();
}
  
