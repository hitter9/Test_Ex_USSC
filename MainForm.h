//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <string>
#include <regex>
#include "sqlite3.h"

using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *NameEdit;
	TEdit *NumberEdit;
	TButton *EnterButton;
	TLabel *InfoLabel;
	TLabel *NameLabel;
	TLabel *NumberLabel;
	void __fastcall EnterButtonClick(TObject *Sender);
private:	// User declarations
	sqlite3* DB;
	sqlite3_stmt* stmt;
	const char* ErrorMessage;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
