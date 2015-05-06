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
	TPanel *Panel1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	std::vector<Fridge> Ell;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
