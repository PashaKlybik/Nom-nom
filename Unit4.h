//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <vector>
//---------------------------------------------------------------------------
class ReciptCard {
	private:
		int num;
		TPanel *Back;
		TLabel *ReciptName;
		TProgressBar *Sz;
		TLabel *Kol;
		TImage *Background;
	public:
		void __fastcall Del();
		void __fastcall OnClick(TObject *Sender);
		ReciptCard(int i);
   //		~ReciptCard();

};
//---------------------------------------------------------------------------
//extern std::vector<ReciptCard> Cards;
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TImage *Image4;
	TVertScrollBox *VertScrollBox1;
	TImage *Image1;
	TSpeedButton *SpeedButton2;
	TLayout *Layout2;
	TImage *Image2;
	TProgressBar *ProgressBar1;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ShowRec(int flag);
private:	// User declarations
public:		// User declarations
  //	std::vector<RecipeCard> Cards;
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
