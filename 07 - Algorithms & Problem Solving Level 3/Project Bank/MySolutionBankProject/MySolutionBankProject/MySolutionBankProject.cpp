// äÙÇã ÅÏÇÑÉ ÇáÚãáÇÁ ÇáÈäßí - Bank Client Management System
// íŞæã ÇáÈÑäÇãÌ ÈÅÏÇÑÉ ÍÓÇÈÇÊ ÇáÚãáÇÁ ãä ÎáÇá æÇÌåÉ äÕíÉ ÊİÇÚáíÉ

#include <iostream>   // ãßÊÈÉ ÇáÅÏÎÇá æÇáÅÎÑÇÌ - ááÊÚÇãá ãÚ cin æ cout
#include <string>     // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáäÕæÕ - ááÊÚÇãá ãÚ string
#include <fstream>    // ãßÊÈÉ ÇáÊÚÇãá ãÚ ÇáãáİÇÊ - ááŞÑÇÁÉ æÇáßÊÇÈÉ ãä æÅáì ÇáãáİÇÊ
#include <iomanip>    // ãßÊÈÉ ÇáÊäÓíŞ - áÇÓÊÎÏÇã setw æ setprecision
#include <vector>     // ãßÊÈÉ ÇáãÕİæİÇÊ ÇáÏíäÇãíßíÉ - áÇÓÊÎÏÇã vector
using namespace std;

// ÊÚÑíİ äæÚ ÈíÇäÇÊ ÊÚÏÇÏí íãËá ÎíÇÑÇÊ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
// Enumeration for main menu options
enum enMainMenueOptions {
	SHOW_CLIENT_LIST = 1,      // ÎíÇÑ ÚÑÖ ŞÇÆãÉ ÇáÚãáÇÁ
	ADD_NEW_CLIENT = 2,        // ÎíÇÑ ÅÖÇİÉ Úãíá ÌÏíÏ
	DELETE_CLIENT = 3,         // ÎíÇÑ ÍĞİ Úãíá
	UPDATE_CLIENT_INFO = 4,    // ÎíÇÑ ÊÍÏíË ãÚáæãÇÊ Úãíá
	FIND_CLIENT = 5,           // ÎíÇÑ ÇáÈÍË Úä Úãíá
	EXIT = 6                   // ÎíÇÑ ÇáÎÑæÌ ãä ÇáÈÑäÇãÌ
};

//-----------------------------ŞÓã ÇáÓÊßÑÊ - Structure Section
// åíßá ÈíÇäÇÊ íÍÊæí Úáì ãÚáæãÇÊ ÇáÚãíá
// Structure to store client information
struct stClient
{
	string Name = "";           // ÇÓã ÇáÚãíá - Client name
	string AccountNumber = "";  // ÑŞã ÇáÍÓÇÈ - Account number
	double Balance = 0;         // ÇáÑÕíÏ - Balance amount
	string PinCode = "";        // ÇáÑŞã ÇáÓÑí - PIN code
	string Phone = "";          // ÑŞã ÇáåÇÊİ - Phone number
};

// ÊÕÑíÍ ãÓÈŞ ááÏæÇá - Forward declarations
// åĞå ÇáÊÕÑíÍÇÊ ÊÓãÍ ÈÇÓÊÎÏÇã ÇáÏæÇá ŞÈá ÊÚÑíİåÇ ÇáßÇãá
void UpdateClientInfo();    // ÏÇáÉ ÊÍÏíË ãÚáæãÇÊ ÇáÚãíá
void FindClient();          // ÏÇáÉ ÇáÈÍË Úä Úãíá
void DeleteClient();        // ÏÇáÉ ÍĞİ Úãíá
vector <stClient> LoadClientsFromFile(string FileName);  // ÏÇáÉ ÊÍãíá ÇáÚãáÇÁ ãä Çáãáİ

//-------------------------ØÈÇÚÉ ÇáæÇÌåÇÊ ÇáÑÆíÓíÉ - Print Main Interfaces Section

// ÏÇáÉ áÅäÔÇÁ ãÓÇİÇÊ ÈÇÏÆÉ (tabs) áÊäÓíŞ ÇáÚÑÖ
// Function to generate tabs for formatting
string Get_Tabs(short number) {
	string spaces = "";  // ãÊÛíÑ áÊÎÒíä ÇáãÓÇİÇÊ
	// ÍáŞÉ áÅÖÇİÉ ÚÏÏ ãÚíä ãä tabs
	for (short i = 0; i < number; i++) {
		spaces += "\t";  // ÅÖÇİÉ tab æÇÍÏ İí ßá ÏæÑÉ
	}
	return spaces;  // ÅÑÌÇÚ ÇáäÕ ÇáãÍÊæí Úáì ÇáãÓÇİÇÊ
}

// ÏÇáÉ áØÈÇÚÉ ÑÃÓ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
// Function to print main menu header
void HederMainMenueScreen() {
	cout << "----------------------------------\n";
	cout << "     Main Menue Screen      \n";
	cout << "----------------------------------\n";
}

// ÏÇáÉ áØÈÇÚÉ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ ßÇãáÉ
// Function to print complete main menu
void PrintMainMenueScreen() {
	system("cls");  // ãÓÍ ÇáÔÇÔÉ - Clear screen
	HederMainMenueScreen();  // ØÈÇÚÉ ÑÃÓ ÇáŞÇÆãÉ
	// ØÈÇÚÉ ÎíÇÑÇÊ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
	cout << "\t[1] Show Client List\n";        // ÚÑÖ ŞÇÆãÉ ÇáÚãáÇÁ
	cout << "\t[2] Add New Client\n";          // ÅÖÇİÉ Úãíá ÌÏíÏ
	cout << "\t[3] Delete Client\n";           // ÍĞİ Úãíá
	cout << "\t[4] Update Client Info\n";      // ÊÍÏíË ãÚáæãÇÊ Úãíá
	cout << "\t[5] Find Client\n";             // ÇáÈÍË Úä Úãíá
	cout << "\t[6] Exit\n";                    // ÇáÎÑæÌ
	cout << "----------------------------------\n";
}

// ÏÇáÉ áØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÅÖÇİÉ Úãíá ÌÏíÏ
// Function to print add new client screen header
void HederAddNewClientScreen() {
	cout << "----------------------------------\n";
	cout << "     Add New Client Screen      \n";
	cout << "----------------------------------\n";
}

// İäßÔä áØÈÇÚÉ ÑÃÓ ÇáÌÏæá (Header) ßãÇ İí ÇáÕæÑÉ
// Function to print table header with number of clients
void PrintHederListClientsScreen(int numberOfClients) {
	// ØÈÇÚÉ ÚäæÇä ÇáÌÏæá ãÚ ÚÏÏ ÇáÚãáÇÁ
	cout << "\n" << Get_Tabs(5) << "Client List (" << numberOfClients << ") Client(s).";
	cout << "\n_________________________________________________________________________________________________________\n" << endl;

	// ÇÓÊÎÏÇã left áÌÚá ÇáäÕ íÈÏÃ ãä ÇáíÓÇÑ ÏÇÎá ÇáãÓÇÍÉ ÇáãÍÏÏÉ
	// ÇáÑŞã ÏÇÎá setw íãËá ÚÏÏ ÇáÍÑæİ ÇáÅÌãÇáí ááãßÇä ÇáãÎÕÕ ááßáãÉ
	// Using left alignment and setw to format column headers
	cout << "| " << left << setw(20) << "Account Number";  // ÚãæÏ ÑŞã ÇáÍÓÇÈ - 20 ÍÑİ
	cout << "| " << left << setw(15) << "Pin Code";        // ÚãæÏ ÇáÑŞã ÇáÓÑí - 15 ÍÑİ
	cout << "| " << left << setw(30) << "Client Name";     // ÚãæÏ ÇÓã ÇáÚãíá - 30 ÍÑİ
	cout << "| " << left << setw(20) << "Phone";           // ÚãæÏ ÑŞã ÇáåÇÊİ - 20 ÍÑİ
	cout << "| " << left << setw(10) << "Balance";         // ÚãæÏ ÇáÑÕíÏ - 10 ÍÑİ

	cout << "\n_________________________________________________________________________________________________________\n" << endl;
}

// ÏÇáÉ áØÈÇÚÉ ÓØÑ æÇÍÏ íÍÊæí Úáì ãÚáæãÇÊ Úãíá æÇÍÏ
// Function to print one client record as a table row
void PrintClientRecordLine(stClient Client)
{
	// ØÈÇÚÉ ãÚáæãÇÊ ÇáÚãíá ÈÊäÓíŞ ÌÏæáí ãÚ ãÍÇĞÇÉ ááíÓÇÑ
	cout << "| " << left << setw(20) << Client.AccountNumber;  // ÑŞã ÇáÍÓÇÈ
	cout << "| " << left << setw(15) << Client.PinCode;   // ÇáÑŞã ÇáÓÑí
	cout << "| " << left << setw(30) << Client.Name;      // ÇáÇÓã
	cout << "| " << left << setw(20) << Client.Phone;     // ÑŞã ÇáåÇÊİ
	// ØÈÇÚÉ ÇáÑÕíÏ ãÚ ÊÍÏíÏ ÚÏÏ ÇáÃÑŞÇã ÈÚÏ ÇáİÇÕáÉ ÇáÚÔÑíÉ (2 ÑŞã)
	cout << "| " << left << setw(10) << fixed << setprecision(2) << Client.Balance;
	cout << endl;
}

// ÏÇáÉ áØÈÇÚÉ ÔÇÔÉ ŞÇÆãÉ ÇáÚãáÇÁ ÇáßÇãáÉ
// Function to print complete client list screen
void PrintListClientsScreen() {
	// ÊÍãíá ÌãíÚ ÇáÚãáÇÁ ãä Çáãáİ Åáì vector
	vector <stClient> vClients = LoadClientsFromFile("Clients.txt");
	// ØÈÇÚÉ ÑÃÓ ÇáÌÏæá ãÚ ÚÏÏ ÇáÚãáÇÁ
	PrintHederListClientsScreen((short)vClients.size());
	// ÍáŞÉ áØÈÇÚÉ ãÚáæãÇÊ ßá Úãíá İí ÓØÑ ãäİÕá
	for (const stClient& Client : vClients) {
		PrintClientRecordLine(Client);  // ØÈÇÚÉ ÓØÑ ÇáÚãíá
	}
	// ØÈÇÚÉ ÎØ ÇáÅÛáÇŞ ÇáÓİáí ááÌÏæá
	cout << "\n_________________________________________________________________________________________________________\n" << endl;
}

// ÏÇáÉ áØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÍĞİ Úãíá
// Function to print delete client screen header
void PrintHeaderDeleteClientScreen() {
	cout << "----------------------------------\n";
	cout << "     Delete Client Screen      \n";
	cout << "----------------------------------\n";
}

// ÏÇáÉ áØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÊÍÏíË ãÚáæãÇÊ Úãíá
// Function to print update client info screen header
void PrintHeaderUpdateClientInfoScreen() {
	cout << "----------------------------------\n";
	cout << "     Update Client Info Screen      \n";
	cout << "----------------------------------\n";
}

// ÏÇáÉ áØÈÇÚÉ ãÚáæãÇÊ Úãíá ÈÔßá ÊİÕíáí
// Function to print client information in detail
void PrintInfoClient(stClient Client) {
	cout << "--------------------------------------------\n";
	cout << "Account Number: " << Client.AccountNumber << "\n";  // ÑŞã ÇáÍÓÇÈ
	cout << "Name: " << Client.Name << "\n";                     // ÇáÇÓã
	cout << "Pin Code: " << Client.PinCode << "\n";              // ÇáÑŞã ÇáÓÑí
	cout << "Phone: " << Client.Phone << "\n";                   // ÑŞã ÇáåÇÊİ
	cout << "Balance: " << Client.Balance << "\n";               // ÇáÑÕíÏ
	cout << "--------------------------------------------\n";
}

// ÏÇáÉ áØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÇáÈÍË Úä Úãíá
// Function to print find client screen header
void PrintHeaderFindClientScreen() {
	cout << "----------------------------------\n";
	cout << "     Find Client Screen      \n";
	cout << "----------------------------------\n";
}

//----------------------------------------------------------
// ŞÑÇÁÉ ÎíÇÑ ãä ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
// Function to read and validate main menu choice
enMainMenueOptions ReadMainMenueOption() {
	int choice = 0;  // ãÊÛíÑ áÊÎÒíä ÇÎÊíÇÑ ÇáãÓÊÎÏã
	// ÍáŞÉ ááÊÃßÏ ãä Ãä ÇáÇÎÊíÇÑ Èíä 1 æ 6
	do {
		cout << "Please enter your choice [1 to 6]: ";
		cin >> choice;  // ŞÑÇÁÉ ÇáÇÎÊíÇÑ ãä ÇáãÓÊÎÏã
	} while (choice < SHOW_CLIENT_LIST || choice > EXIT);  // ÇáÊßÑÇÑ ÍÊì íÏÎá ÇÎÊíÇÑ ÕÍíÍ
	return (enMainMenueOptions)choice;  // ÊÍæíá ÇáÑŞã Åáì äæÚ enum æÅÑÌÇÚå
}

// ÏÇáÉ áãÓÍ ÇáÔÇÔÉ
// Function to clear screen
void ClearScreen() {
	system("cls");  // ÃãÑ ãÓÍ ÇáÔÇÔÉ İí Windows
}

// ÊÕÑíÍ ãÓÈŞ áÏÇáÉ ShowScreen
void ShowScreen(enMainMenueOptions NumScreen);

// ÇáÚæÏÉ Åáì ÇáÔÇÔÉ ÇáÑÆíÓíÉ
// Function to return to main menu screen
void GoBackToMinueScreen() {
	// ØáÈ ãä ÇáãÓÊÎÏã ÇáÖÛØ Úáì Ãí ÒÑ ááÚæÏÉ
	cout << "Press any key to go back to Main Menue Screen...";
	system("pause>0");  // ÅíŞÇİ ãÄŞÊ ÍÊì íÖÛØ ÇáãÓÊÎÏã Ãí ÒÑ
	PrintMainMenueScreen();  // ØÈÇÚÉ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ ãÑÉ ÃÎÑì
	ShowScreen(ReadMainMenueOption());  // ŞÑÇÁÉ ÇáÇÎÊíÇÑ ÇáÌÏíÏ æÚÑÖ ÇáÔÇÔÉ ÇáãäÇÓÈÉ
}

// ÊÕÑíÍ ãÓÈŞ áÏÇáÉ AddNewClient
void AddNewClient();

// ÚÑÖ ÇáÔÇÔÉ ÇáãÎÊÇÑÉ
// Function to display selected screen based on user choice
void ShowScreen(enMainMenueOptions NumScreen) {
	ClearScreen();  // ãÓÍ ÇáÔÇÔÉ ÃæáÇğ
	// ÇÓÊÎÏÇã switch ááÊİÑÚ ÍÓÈ ÇáÇÎÊíÇÑ
	switch (NumScreen) {
	case SHOW_CLIENT_LIST:  // ÅĞÇ ÇÎÊÇÑ ÚÑÖ ŞÇÆãÉ ÇáÚãáÇÁ
		ClearScreen();
		PrintListClientsScreen();  // ÚÑÖ ŞÇÆãÉ ÇáÚãáÇÁ
		GoBackToMinueScreen();     // ÇáÚæÏÉ ááŞÇÆãÉ ÇáÑÆíÓíÉ
		break;

	case ADD_NEW_CLIENT:  // ÅĞÇ ÇÎÊÇÑ ÅÖÇİÉ Úãíá ÌÏíÏ
		AddNewClient();          // ÇÓÊÏÚÇÁ ÏÇáÉ ÅÖÇİÉ Úãíá
		GoBackToMinueScreen();   // ÇáÚæÏÉ ááŞÇÆãÉ ÇáÑÆíÓíÉ
		break;

	case DELETE_CLIENT:  // ÅĞÇ ÇÎÊÇÑ ÍĞİ Úãíá
		DeleteClient();        // ÇÓÊÏÚÇÁ ÏÇáÉ ÍĞİ Úãíá
		GoBackToMinueScreen(); // ÇáÚæÏÉ ááŞÇÆãÉ ÇáÑÆíÓíÉ
		break;

	case UPDATE_CLIENT_INFO:  // ÅĞÇ ÇÎÊÇÑ ÊÍÏíË ãÚáæãÇÊ Úãíá
		UpdateClientInfo();      // ÇÓÊÏÚÇÁ ÏÇáÉ ÊÍÏíË ÇáãÚáæãÇÊ
		GoBackToMinueScreen();   // ÇáÚæÏÉ ááŞÇÆãÉ ÇáÑÆíÓíÉ
		break;

	case FIND_CLIENT:  // ÅĞÇ ÇÎÊÇÑ ÇáÈÍË Úä Úãíá
		FindClient();          // ÇÓÊÏÚÇÁ ÏÇáÉ ÇáÈÍË
		GoBackToMinueScreen(); // ÇáÚæÏÉ ááŞÇÆãÉ ÇáÑÆíÓíÉ
		break;

	case EXIT:  // ÅĞÇ ÇÎÊÇÑ ÇáÎÑæÌ
		cout << "Exiting the program. Goodbye!\n";  // ÑÓÇáÉ æÏÇÚ
		break;
	}
}

// ÈÏÁ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
// Function to start main menu
void StartMainMenue() {
	PrintMainMenueScreen();  // ØÈÇÚÉ ÇáŞÇÆãÉ ÇáÑÆíÓíÉ
	ShowScreen(ReadMainMenueOption());  // ŞÑÇÁÉ ÇáÇÎÊíÇÑ æÚÑÖ ÇáÔÇÔÉ ÇáãäÇÓÈÉ
}

//----------------------------------------------------

//----------------------------ŞÓã ÇáãáİÇÊ - File Operations Section

// íÚØíß ãÚáæãÇÊ ÇáÚãíá İí ÓØÑ æÇÍÏ ÈÕíÛÉ ÇÓÊÑäŞ æÈíä ßá ãÚáæãÉ æãÚáæãÉ #//#
// åßĞÇ : AccountNumber#//#Name#//#PinCode#//#Phone#//#Balance
// Function to format client data as a single line string
string GetFormatClientRecord(stClient Client) {
	// ÏãÌ ÌãíÚ ãÚáæãÇÊ ÇáÚãíá İí ÓØÑ æÇÍÏ ãÚ İÇÕá #//#
	return   Client.AccountNumber + "#//#" + Client.Name + "#//#" + Client.PinCode + "#//#" + Client.Phone + "#//#" + to_string(Client.Balance);
}

// ÏÇáÉ ááÍÕæá Úáì ãæÇİŞÉ ÇáãÓÊÎÏã (äÚã Ãæ áÇ)
// Function to get user consent (yes or no)
bool GetUserConsent(string Message) {
	char UserInput = 'y';  // ãÊÛíÑ áÊÎÒíä ÅÌÇÈÉ ÇáãÓÊÎÏã
	// ÍáŞÉ ááÊÃßÏ ãä Ãä ÇáãÓÊÎÏã ÃÏÎá y Ãæ n İŞØ
	do
	{
		cout << Message << " (y/n): ";
		cin >> UserInput;  // ŞÑÇÁÉ ÅÌÇÈÉ ÇáãÓÊÎÏã

		// ÅĞÇ ÃÏÎá y Ãæ Y
		if (UserInput == 'y' || UserInput == 'Y') {
			return true;  // ÅÑÌÇÚ true (ãæÇİŞ)
		}
		// ÅĞÇ ÃÏÎá n Ãæ N
		else if (UserInput == 'n' || UserInput == 'N') {
			return false;  // ÅÑÌÇÚ false (ÛíÑ ãæÇİŞ)
		}
		// ÅĞÇ ÃÏÎá ÔíÁ ÂÎÑ
		else {
			cout << "Invalid input. Please enter 'y' or 'n'.\n";  // ÑÓÇáÉ ÎØÃ
		}
	} while (UserInput != 'Y' || UserInput != 'y' || UserInput != 'N' || UserInput != 'n');
}

// ÇÖÇİÉ Úãíá Çáì ãáİ
// Function to add a record to file with user confirmation
bool AddRecordToFile(string FileName, string  Text, string textConfirm = "Do you want this?") {
	bool success = false;  // ãÊÛíÑ áÊÎÒíä ÍÇáÉ äÌÇÍ ÇáÚãáíÉ
	fstream ClientFile;    // ãÊÛíÑ ááÊÚÇãá ãÚ Çáãáİ
	// İÊÍ Çáãáİ İí æÖÚ ÇáßÊÇÈÉ æÇáÅÖÇİÉ İí ÇáäåÇíÉ
	ClientFile.open(FileName, ios::out | ios::app);

	if (ClientFile.is_open()) {  // ÇáÊÃßÏ ãä Ãä Çáãáİ İõÊÍ ÈäÌÇÍ
		// ØáÈ ãæÇİŞÉ ÇáãÓÊÎÏã ŞÈá ÇáÍİÙ
		if (GetUserConsent(textConfirm))
		{
			ClientFile << Text << endl;  // ßÊÇÈÉ ÇáÈíÇäÇÊ İí Çáãáİ
			success = true;  // ÊÍÏíÏ ÍÇáÉ ÇáäÌÇÍ
		}
		else
		{
			cout << "data not saved.\n";  // ÅĞÇ áã íæÇİŞ ÇáãÓÊÎÏã
			success = false;
		}
		ClientFile.close();  // ÅÛáÇŞ Çáãáİ
	}
	else {
		return success;  // ÅÑÌÇÚ false ÅĞÇ İÔá İÊÍ Çáãáİ
	}
}

// ÏÇáÉ ááÊÍŞŞ ãä æÌæÏ ÑŞã ÍÓÇÈ İí Çáãáİ
// Function to check if account number exists in file
bool ExistAccountNumber(string AccountNumber, string FileName) {
	fstream ClientFile;  // ãÊÛíÑ ááÊÚÇãá ãÚ Çáãáİ
	ClientFile.open(FileName, ios::in);  // İÊÍ Çáãáİ İí æÖÚ ÇáŞÑÇÁÉ
	string Line = "";  // ãÊÛíÑ áÊÎÒíä ßá ÓØÑ ãä Çáãáİ

	if (ClientFile.is_open()) {  // ÇáÊÃßÏ ãä İÊÍ Çáãáİ ÈäÌÇÍ
		// ŞÑÇÁÉ Çáãáİ ÓØÑ ÈÓØÑ
		while (getline(ClientFile, Line)) {
			// ÇáÈÍË Úä ÇáİÇÕá #//#
			short pos = Line.find("#//#");
			if (pos != string::npos) {  // ÅĞÇ æÌÏ ÇáİÇÕá
				// ÇÓÊÎÑÇÌ ÑŞã ÇáÍÓÇÈ (ÇáÌÒÁ ŞÈá Ãæá İÇÕá)
				string ExistingAccountNumber = Line.substr(0, pos);
				// ãŞÇÑäÉ ÑŞã ÇáÍÓÇÈ ÇáãÓÊÎÑÌ ãÚ ÑŞã ÇáÍÓÇÈ ÇáãØáæÈ
				if (ExistingAccountNumber == AccountNumber) {
					ClientFile.close();  // ÅÛáÇŞ Çáãáİ
					return true; // ÑŞã ÇáÍÓÇÈ ãæÌæÏ - Account number exists
				}
			}
		}
		ClientFile.close();  // ÅÛáÇŞ Çáãáİ
	}
	return false; // ÑŞã ÇáÍÓÇÈ ÛíÑ ãæÌæÏ - Account number does not exist
}

// ÊÍæíá ÓØÑ äÕí Çáì İíßÊæÑ ãä äæÚ ÇÓÊÑäŞ
// Function to split a string record into vector of strings
vector<string>  ConvertRecordToVectorString(string ClientRecord, string d, short numberChar) {
	vector<string> TempRecord;  // vector áÊÎÒíä ÇáäÊÇÆÌ
	short Pos = 0;  // ãÊÛíÑ áÊÎÒíä ãæŞÚ ÇáİÇÕá
	short index = 0;  // ãÊÛíÑ ááÚÏ

	// ÍáŞÉ áÊŞÓíã ÇáäÕ
	do
	{
		Pos = ClientRecord.find(d);  // ÇáÈÍË Úä ÇáİÇÕá
		string text = ClientRecord.substr(0, Pos);  // ÇÓÊÎÑÇÌ ÇáÌÒÁ ŞÈá ÇáİÇÕá
		TempRecord.push_back(text);  // ÅÖÇİÉ ÇáÌÒÁ Åáì ÇáÜ vector
		// ÍĞİ ÇáÌÒÁ ÇáãÓÊÎÑÌ æÇáİÇÕá ãä ÇáäÕ ÇáÃÕáí
		ClientRecord.erase(0, Pos + numberChar);
		index++;
	} while (Pos != string::npos);  // ÇáÊßÑÇÑ ÍÊì áÇ íæÌÏ ÇáãÒíÏ ãä ÇáİæÇÕá

	return TempRecord;  // ÅÑÌÇÚ ÇáÜ vector ÇáãÍÊæí Úáì ÇáÃÌÒÇÁ
}

// ÊÍæíá ÓØÑ äÕí Çáì åíßá ãä äæÚ stClient
// Function to convert string record to stClient structure
stClient ConvertRecordToStClient(string ClientRecord) {
	stClient Client;  // ÅäÔÇÁ ãÊÛíÑ ãä äæÚ stClient
	// ÊÍæíá ÇáÓØÑ ÇáäÕí Åáì vector ãä ÇáäÕæÕ
	vector<string>  InfoRecord = ConvertRecordToVectorString(ClientRecord, "#//#", 4);
	// ÊÚÈÆÉ ãÚáæãÇÊ ÇáÚãíá ãä ÇáÜ vector
	Client.AccountNumber = InfoRecord.at(0);  // ÑŞã ÇáÍÓÇÈ İí ÇáãæÖÚ 0
	Client.Name = InfoRecord.at(1);           // ÇáÇÓã İí ÇáãæÖÚ 1
	Client.PinCode = InfoRecord.at(2);        // ÇáÑŞã ÇáÓÑí İí ÇáãæÖÚ 2
	Client.Phone = InfoRecord.at(3);          // ÑŞã ÇáåÇÊİ İí ÇáãæÖÚ 3
	Client.Balance = stod(InfoRecord.at(4));  // ÇáÑÕíÏ İí ÇáãæÖÚ 4 (ÊÍæíá ãä äÕ Åáì double)
	return Client;  // ÅÑÌÇÚ Çáåíßá ÇáãÚÈÃ
}

// ÊÍãíá ÌãíÚ ÇáÚãáÇÁ ãä ãáİ Çáì İíßÊæÑ ãä äæÚ stClient
// Function to load all clients from file into vector
vector <stClient> LoadClientsFromFile(string FileName) {
	fstream ClientFile;  // ãÊÛíÑ ááÊÚÇãá ãÚ Çáãáİ
	ClientFile.open(FileName, ios::in);  // İÊÍ Çáãáİ İí æÖÚ ÇáŞÑÇÁÉ
	string Line = "";  // ãÊÛíÑ áÊÎÒíä ßá ÓØÑ
	vector <stClient> vClients;  // vector áÊÎÒíä ÌãíÚ ÇáÚãáÇÁ

	if (ClientFile.is_open()) {  // ÇáÊÃßÏ ãä İÊÍ Çáãáİ ÈäÌÇÍ
		// ŞÑÇÁÉ Çáãáİ ÓØÑ ÈÓØÑ
		while (getline(ClientFile, Line)) {
			// ÊÍæíá ßá ÓØÑ Åáì stClient
			stClient Client = ConvertRecordToStClient(Line);
			vClients.push_back(Client);  // ÅÖÇİÉ ÇáÚãíá Åáì ÇáÜ vector
		}
		ClientFile.close();  // ÅÛáÇŞ Çáãáİ
	}
	return vClients;  // ÅÑÌÇÚ ÇáÜ vector ÇáãÍÊæí Úáì ÌãíÚ ÇáÚãáÇÁ
}

// ÍĞİ ÓÌá Úãíá ãä Çáãáİ ÈäÇÁğ Úáì ÑŞã ÇáÍÓÇÈ
// Function to delete a client record from file by account number
bool DeleteFileRecordByAccountNumber(string FileName, string AccountNumber) {
	// ÊÍãíá ÌãíÚ ÇáÚãáÇÁ ãä Çáãáİ
	vector <stClient> vClients = LoadClientsFromFile(FileName);
	fstream ClientFile;  // ãÊÛíÑ ááÊÚÇãá ãÚ Çáãáİ
	bool found = false;  // ãÊÛíÑ áÊÊÈÚ ãÇ ÅĞÇ Êã ÇáÚËæÑ Úáì ÇáÚãíá
	ClientFile.open(FileName, ios::out);  // İÊÍ Çáãáİ İí æÖÚ ÇáßÊÇÈÉ (ãÓÍ ÇáãÍÊæì ÇáŞÏíã)

	if (ClientFile.is_open()) {  // ÇáÊÃßÏ ãä İÊÍ Çáãáİ ÈäÌÇÍ
		// ÇáãÑæÑ Úáì ÌãíÚ ÇáÚãáÇÁ
		for (const stClient& Client : vClients) {
			// ßÊÇÈÉ ÌãíÚ ÇáÚãáÇÁ ãÇ ÚÏÇ ÇáĞí äÑíÏ ÍĞİå
			if (Client.AccountNumber != AccountNumber) {
				string ClientRecord = GetFormatClientRecord(Client);
				ClientFile << ClientRecord << endl;  // ßÊÇÈÉ ÓÌá ÇáÚãíá
			}
			else {
				found = true;  // Êã ÇáÚËæÑ Úáì ÇáÚãíá ÇáãØáæÈ ÍĞİå
			}
		}
		ClientFile.close();  // ÅÛáÇŞ Çáãáİ
	}
	else {
		return false;  // İÔá İÊÍ Çáãáİ
	}
	return true;  // äÌÍÊ ÚãáíÉ ÇáÍĞİ
}

// ÏÇáÉ ááÈÍË Úä Úãíá ÈæÇÓØÉ ÑŞã ÇáÍÓÇÈ
// Function to find client by account number
stClient FindClientByAccountNumber(string FileName, string AccountNumber) {
	// ÊÍãíá ÌãíÚ ÇáÚãáÇÁ ãä Çáãáİ
	vector <stClient> vClients = LoadClientsFromFile(FileName);

	// ÇáÊÍŞŞ ãä æÌæÏ ÑŞã ÇáÍÓÇÈ ÃæáÇğ
	if (!ExistAccountNumber(AccountNumber, FileName)) {
		return stClient();  // ÅÑÌÇÚ åíßá İÇÑÛ ÅĞÇ áã íßä ãæÌæÏÇğ
	}

	// ÇáÈÍË Úä ÇáÚãíá İí ÇáÜ vector
	for (const stClient& Client : vClients) {
		if (Client.AccountNumber == AccountNumber) {
			return Client;  // ÅÑÌÇÚ ãÚáæãÇÊ ÇáÚãíá ÅĞÇ æÌÏ
		}
	}
	return stClient(); // ÅÑÌÇÚ åíßá İÇÑÛ ÅĞÇ áã íÊã ÇáÚËæÑ Úáì ÇáÚãíá
}

// ÏÇáÉ áÊÍÏíË ãÚáæãÇÊ Úãíá İí Çáãáİ
// Function to update client record in file
bool UpdateFileRecordByAccountNumber(string FileName, stClient UpdatedClient) {
	// ÊÍãíá ÌãíÚ ÇáÚãáÇÁ ãä Çáãáİ
	vector <stClient> vClients = LoadClientsFromFile(FileName);
	fstream ClientFile;  // ãÊÛíÑ ááÊÚÇãá ãÚ Çáãáİ
	bool found = false;  // ãÊÛíÑ áÊÊÈÚ ãÇ ÅĞÇ Êã ÇáÚËæÑ Úáì ÇáÚãíá
	ClientFile.open(FileName, ios::out);  // İÊÍ Çáãáİ İí æÖÚ ÇáßÊÇÈÉ (ãÓÍ ÇáãÍÊæì ÇáŞÏíã)

	if (ClientFile.is_open()) {  // ÇáÊÃßÏ ãä İÊÍ Çáãáİ ÈäÌÇÍ
		// ÇáãÑæÑ Úáì ÌãíÚ ÇáÚãáÇÁ
		for (const stClient& Client : vClients) {
			// ÅĞÇ ßÇä ÇáÚãíá áíÓ ÇáĞí äÑíÏ ÊÍÏíËå
			if (Client.AccountNumber != UpdatedClient.AccountNumber) {
				string ClientRecord = GetFormatClientRecord(Client);
				ClientFile << ClientRecord << endl;  // ßÊÇÈÉ ÓÌáå ßãÇ åæ
			}
			else {  // ÅĞÇ ßÇä åæ ÇáÚãíá ÇáãØáæÈ ÊÍÏíËå
				// ßÊÇÈÉ ÇáãÚáæãÇÊ ÇáãÍÏËÉ
				string UpdatedClientRecord = GetFormatClientRecord(UpdatedClient);
				ClientFile << UpdatedClientRecord << endl;
				found = true;  // Êã ÇáÚËæÑ Úáì ÇáÚãíá æÊÍÏíËå
			}
		}
		ClientFile.close();  // ÅÛáÇŞ Çáãáİ
	}
	else {
		return false;  // İÔá İÊÍ Çáãáİ
	}
	return found;  // ÅÑÌÇÚ ÍÇáÉ ÇáäÌÇÍ
}

//--------------------------ŞÓã ÇáÚãáíÇÊ - Operations Section

// ŞÑÇÁÉ ÑŞã ÍÓÇÈ ÌÏíÏ ãÚ ÇáÊÍŞŞ ãä ÚÏã ÊßÑÇÑå
// Function to read new account number with validation
string ReadNewAccount(string Message)
{
	string Text = "";  // ãÊÛíÑ áÊÎÒíä ÑŞã ÇáÍÓÇÈ
	// ÍáŞÉ ááÊÃßÏ ãä Ãä ÑŞã ÇáÍÓÇÈ ÛíÑ ãßÑÑ
	do {
		cout << Message;
		cin >> Text;  // ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ ãä ÇáãÓÊÎÏã

		// ÇáÊÍŞŞ ãä æÌæÏ ÑŞã ÇáÍÓÇÈ ãÓÈŞÇğ
		if (ExistAccountNumber(Text, "Clients.txt")) {
			cout << "Account Number already exists. Please enter a different one.\n";
		}
		else {
			break;  // ÇáÎÑæÌ ãä ÇáÍáŞÉ ÅĞÇ ßÇä ÑŞã ÇáÍÓÇÈ İÑíÏ
		}
	} while (true);
	return Text;  // ÅÑÌÇÚ ÑŞã ÇáÍÓÇÈ ÇáÌÏíÏ
}

// ÏÇáÉ áŞÑÇÁÉ ÑŞã ÍÓÇÈ æÇáÊÍŞŞ ãä æÌæÏå
// Function to read and verify existing account number
string ReadandChekAccountNumber(string Message)
{
	// ÍáŞÉ ááÊÃßÏ ãä Ãä ÑŞã ÇáÍÓÇÈ ãæÌæÏ
	do
	{
		string Text = "";
		cout << Message;
		cin >> Text;  // ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ

		// ÇáÊÍŞŞ ãä æÌæÏ ÑŞã ÇáÍÓÇÈ
		if (ExistAccountNumber(Text, "Clients.txt")) {
			return Text;  // ÅÑÌÇÚ ÑŞã ÇáÍÓÇÈ ÅĞÇ ßÇä ãæÌæÏÇğ
		}
		else {
			cout << "Account Number does not exist. Please enter a valid one.\n";
		}
	} while (true);
}

// ŞÑÇÁÉ ÓØÑ äÕí ßÇãá
// Function to read full line string (including spaces)
string GetLineString() {
	string Line;
	// ÊÌÇåá Ãí ÃÍÑİ ãÊÈŞíÉ İí buffer ÇáÅÏÎÇá (ãËá Enter) ŞÈá ŞÑÇÁÉ ÇáÓØÑ
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Line);  // ŞÑÇÁÉ ÓØÑ ßÇãá ÈãÇ İí Ğáß ÇáãÓÇİÇÊ
	return Line;  // ÅÑÌÇÚ ÇáÓØÑ ÇáãŞÑæÁ
}

// ŞÑÇÁÉ ãÚáæãÇÊ ÇáÚãíá
// Function to read client information from user
stClient ReadClientInfo() {
	stClient Client;  // ÅäÔÇÁ ãÊÛíÑ áÊÎÒíä ãÚáæãÇÊ ÇáÚãíá

	// ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ (ãÚ ÇáÊÍŞŞ ãä ÚÏã ÊßÑÇÑå)
	Client.AccountNumber = ReadNewAccount("Enter Account Number: ");
	// ŞÑÇÁÉ ÇáÇÓã (íãßä Ãä íÍÊæí Úáì ãÓÇİÇÊ)
	cout << "Enter Name: ";
	Client.Name = GetLineString();
	// ŞÑÇÁÉ ÇáÑŞã ÇáÓÑí
	cout << "Enter Pin Code: ";
	cin >> Client.PinCode;
	// ŞÑÇÁÉ ÑŞã ÇáåÇÊİ
	cout << "Enter Phone: ";
	cin >> Client.Phone;
	// ŞÑÇÁÉ ÇáÑÕíÏ
	cout << "Enter Balance: ";
	cin >> Client.Balance;
	return Client;  // ÅÑÌÇÚ ãÚáæãÇÊ ÇáÚãíá ÇáãßÊãáÉ
}

// ÏÇáÉ áŞÑÇÁÉ ãÚáæãÇÊ ãÍÏËÉ ááÚãíá (ÈÏæä ÑŞã ÇáÍÓÇÈ)
// Function to read updated client information (without account number)
void ReadUpdatedClientInfo(stClient& Client) {
	// ŞÑÇÁÉ ÇáÇÓã ÇáÌÏíÏ
	cout << "Enter Name: ";
	Client.Name = GetLineString();
	// ŞÑÇÁÉ ÇáÑŞã ÇáÓÑí ÇáÌÏíÏ
	cout << "Enter Pin Code: ";
	cin >> Client.PinCode;
	// ŞÑÇÁÉ ÑŞã ÇáåÇÊİ ÇáÌÏíÏ
	cout << "Enter Phone: ";
	cin >> Client.Phone;
	// ŞÑÇÁÉ ÇáÑÕíÏ ÇáÌÏíÏ
	cout << "Enter Balance: ";
	cin >> Client.Balance;
}

// ÇÖÇİÉ Úãíá ÌÏíÏ
// Function to add a new client
void AddNewClient() {
	// ØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÅÖÇİÉ Úãíá ÌÏíÏ
	HederAddNewClientScreen();
	cout << "Adding New Client:\n";

	// ŞÑÇÁÉ ãÚáæãÇÊ ÇáÚãíá ÇáÌÏíÏ ãä ÇáãÓÊÎÏã
	stClient Client = ReadClientInfo();
	// ÊÍæíá ãÚáæãÇÊ ÇáÚãíá Åáì äÕ ÈÇáÕíÛÉ ÇáãØáæÈÉ
	string ClientRecord = GetFormatClientRecord(Client);

	// ãÍÇæáÉ ÅÖÇİÉ ÇáÚãíá Åáì Çáãáİ
	if (AddRecordToFile("Clients.txt", ClientRecord))
	{
		cout << "Client added successfully.\n";  // ÑÓÇáÉ äÌÇÍ
	}
	else {
		cout << "Error adding client to file.\n";  // ÑÓÇáÉ İÔá
	}
}

// ÍĞİ Úãíá
// Function to delete a client
void DeleteClient() {
	// ØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÍĞİ Úãíá
	PrintHeaderDeleteClientScreen();
	cout << "Delete Client\n";
	// ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ ÇáãÑÇÏ ÍĞİå (ãÚ ÇáÊÍŞŞ ãä æÌæÏå)
	string AccountNumber = ReadandChekAccountNumber("Enter Account Number to delete: ");

	// ãÍÇæáÉ ÍĞİ ÇáÚãíá ãä Çáãáİ
	if (DeleteFileRecordByAccountNumber("Clients.txt", AccountNumber)) {
		cout << "Client with Account Number " << AccountNumber << " deleted successfully.\n";  // ÑÓÇáÉ äÌÇÍ
	}
	else {
		cout << "Error deleting client. Account Number may not exist.\n";  // ÑÓÇáÉ İÔá
	}
}

// ÏÇáÉ ááÈÍË Úä Úãíá æÚÑÖ ãÚáæãÇÊå
// Function to find and display client information
void FindClient() {
	// ØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÇáÈÍË Úä Úãíá
	PrintHeaderFindClientScreen();
	// ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ ÇáãÑÇÏ ÇáÈÍË Úäå (ãÚ ÇáÊÍŞŞ ãä æÌæÏå)
	string AccountNumber = ReadandChekAccountNumber("Enter Account Number to Find: ");

	// ÇáÈÍË Úä ÇáÚãíá İí Çáãáİ
	stClient Client = FindClientByAccountNumber("Clients.txt", AccountNumber);

	// ØÈÇÚÉ ãÚáæãÇÊ ÇáÚãíá ÇáÊİÕíáíÉ
	PrintInfoClient(Client);
}

// ÏÇáÉ áÊÍÏíË ãÚáæãÇÊ Úãíá
// Function to update client information
void UpdateClientInfo() {
	// ØÈÇÚÉ ÑÃÓ ÔÇÔÉ ÊÍÏíË ãÚáæãÇÊ Úãíá
	PrintHeaderUpdateClientInfoScreen();
	// ŞÑÇÁÉ ÑŞã ÇáÍÓÇÈ ÇáãÑÇÏ ÊÍÏíËå (ãÚ ÇáÊÍŞŞ ãä æÌæÏå)
	string AccountNumber = ReadandChekAccountNumber("Enter Account Number to Update: ");
	// ÇáÈÍË Úä ÇáÚãíá æÌáÈ ãÚáæãÇÊå ÇáÍÇáíÉ
	stClient Client = FindClientByAccountNumber("Clients.txt", AccountNumber);
	// ÚÑÖ ÇáãÚáæãÇÊ ÇáÍÇáíÉ ááÚãíá
	cout << "Current Client Information:\n";
	PrintInfoClient(Client);
	// ØáÈ ÅÏÎÇá ÇáãÚáæãÇÊ ÇáÌÏíÏÉ
	cout << "\nEnter New Information:\n";
	ReadUpdatedClientInfo(Client);
	// ãÍÇæáÉ ÊÍÏíË ÇáãÚáæãÇÊ İí Çáãáİ
	if (UpdateFileRecordByAccountNumber("Clients.txt", Client)) {
		cout << "Client information updated successfully.\n";  // ÑÓÇáÉ äÌÇÍ
	}
	else {
		cout << "Error updating client information.\n";  // ÑÓÇáÉ İÔá
	}
}

// ÇáÏÇáÉ ÇáÑÆíÓíÉ - äŞØÉ ÈÏÇíÉ ÇáÈÑäÇãÌ
// Main function - Program entry point
int main()
{
	// ÈÏÁ ÊÔÛíá ÇáŞÇÆãÉ ÇáÑÆíÓíÉ ááÈÑäÇãÌ
	StartMainMenue();
	return 0;  // ÅäåÇÁ ÇáÈÑäÇãÌ ÈäÌÇÍ
}