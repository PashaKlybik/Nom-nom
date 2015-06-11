//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Colors.hpp>
#include <vector>
//---------------------------------------------------------------------------
struct CookIngr {
	int id;
	AnsiString NameIngr;
};
//---------------------------------------------------------------------------
struct CookStep {
	AnsiString Link, Text;
};
//---------------------------------------------------------------------------
struct recept{
	std::vector<CookIngr> Ingrd;
	std::vector<CookStep> Steps;
	float interest;
	AnsiString Name;
};
//-!!!!!!!!!!!---------------------------------------------------------------
extern std::vector<recept> Recepts;
//-----------------------------------------------------------!!!!!!!!!!!!!!--
class Fridge {
	private:
		int ctg,ing;
		int id;
		AnsiString name;
		TPanel *Basement;
		TLabel *OutName;
	public:
		void __fastcall Onclick(TObject *Sender);
		void __fastcall svoup_1(TObject *Senderr, TMouseButton Button, TShiftState Shift,
		  float X, float Y);
		void __fastcall svoup_2(TObject *Sender, TShiftState Shift, float X,
		  float Y);
		void __fastcall svoup_3(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y);
		Fridge(int i, int j);

};

//---------------------------------------------------------------------------

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TLayout *Layout2;
	TImage *Image1;
	TImage *Image3;
	TVertScrollBox *VertScrollBox1;
	TSpeedButton *SpeedButton2;
	TImage *Image2;
	TTimer *Timer1;
	TButton *Button1;
	TImage *Image4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *SpeedButton1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall ParsRecipe();



private:	// User declarations
public:		// User declarations
	std::vector<Fridge> Ell;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
