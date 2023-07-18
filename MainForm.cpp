//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <codecvt>
#include <locale>
TForm1 *Form1;
//---------------------------------------------------------------------------
wstring s2ws(const string& s)
{
	typedef codecvt<wchar_t, char, mbstate_t> codec_t;
    return wstring_convert<codec_t>(&use_facet<codec_t>(locale(".1251"))).from_bytes(s);
}
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    int result = sqlite3_open("phone.db", &DB);
	if (result != SQLITE_OK)
	{
		ShowMessage("Ошибка открытия БД");
		ExitProcess(1);
	}
	result = sqlite3_prepare_v2(DB, "create table if not exists list"
		"(ID integer primary key autoincrement, LastName nvarchar(255) not null,"
		" FirstName nvarchar(255) not null, Number nvarchar(255) not null)",
		-1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		ShowMessage("Ошибка подготовки запроса на создание таблицы");
		ExitProcess(2);
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		ShowMessage("Ошибка создания таблицы");
		ExitProcess(3);
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
	sqlite3_finalize(stmt);
    sqlite3_close(DB);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EnterButtonClick(TObject *Sender)
{
	string LastName, FirstName, Number, NumberType;
	if (NameEdit->Text == "" && NumberEdit->Text == "")
	{
		InfoLabel->Caption = "Оба поля обязательны для ввода!";
        return;
    }
	if (NameEdit->Text != "")
	{
		AnsiString Nam = NameEdit->Text;
		string Name = Nam.c_str();
		auto pos = Name.find(" ");
		if (pos != string::npos)
		{
			LastName = Name.substr(0, pos);
			FirstName = Name.substr(pos + 1);
			pos = FirstName.find(" ");
			if (pos != string::npos)
				FirstName.erase(pos);
		}
		else InfoLabel->Caption = "Введите фамилию и имя в формате:\n"
			 "Иванов Иван";

	}
	else InfoLabel->Caption = "Поле \"Фамилия и имя\" обязательно для ввода!";
	if (NumberEdit->Text != "")
	{
		AnsiString Num = NumberEdit->Text;
		Number = Num.c_str();
        regex reg_mob("(\\+7|8)?(\\(?[9]{1}[0-9]{2}\\)?)([0-9]{7})");
		regex reg_code3land("(\\+7|8)?(\\(?[1-8]{1}[0-9]{2}\\)?)([0-9]{7})");
		regex reg_code4land("(\\+7|8)?(\\(?[1-8]{1}[0-9]{3}\\)?)([0-9]{6})");
		regex reg_code5land("(\\+7|8)?(\\(?[1-8]{1}[0-9]{4}\\)?)([0-9]{5})");
		regex reg_land("([1-9]{1}[0-9]{4,6})");
		if (regex_match(Number.c_str(), reg_mob) ||
			regex_match(Number.c_str(), reg_code3land) ||
			regex_match(Number.c_str(), reg_code4land) ||
			regex_match(Number.c_str(), reg_code5land))
			NumberType = "Full Number (Mobile or Landline with area code)";
		else if (regex_match(Number.c_str(), reg_land))
			NumberType = "Landline phone number without area code";
		else
		{
			InfoLabel->Caption = "Введите номер телефона в одном из форматов:\n"
			"Мобильный: +79777777777, 8(988)8888888, 9999999999\n"
			"Городской с кодом города: +73434444444, 8(3435)555555, 3434466666\n"
			"Городской: 1111111, 222222, 33333";
            return;
		}
	}
	else InfoLabel->Caption = "Поле \"Номер телефона\" обязательно для ввода!";
    if (LastName != "" && FirstName != "" && NumberType != "")
	{
		const string sql = "insert into list(LastName, FirstName, Number)"
			" values('" + LastName + "','" + FirstName + "','" + Number + "')";
		wstring sql16 = s2ws(sql);
		int result = sqlite3_prepare16_v2(DB, sql16.c_str(), -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			ShowMessage("Ошибка подготовки запроса на добавление записи");
			ExitProcess(4);
		}
		result = sqlite3_step(stmt);
        if (result != SQLITE_DONE)
		{
			ShowMessage("Ошибка добавления записи в БД");
			ExitProcess(5);
		}
		NameEdit->Text = "";
        NumberEdit->Text = "";
		InfoLabel->Caption = ("Фамилия: " + LastName + "\nИмя: " +
		FirstName + "\nНомер телефона: " + Number +
		"\nДанные успешно внесены! Вы можете продолжить ввод").c_str();
	}
}
//---------------------------------------------------------------------------

