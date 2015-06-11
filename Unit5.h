//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.TabControl.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <vector>
//---------------------------------------------------------------------------
class StepRecipe {
  private:
	TTabItem *Bottom;
	TImage *ImgStep;
	TLabel *TextStep;
  public:
	StepRecipe(AnsiString s, AnsiString Text);
	void Del();
	void SetFoc();
};
//---------------------------------------------------------------------------
//std::vector<StepRecipe> Steps;
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TImage *Image1;
	TSpeedButton *SpeedButton2;
	TLayout *Layout2;
	TTabControl *TabControl1;
	TIdHTTP *IdHTTP1;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PrintRecipt(int i);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
