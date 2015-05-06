//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <IdHTTP.hpp>
#include <System.JSON.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.SearchBox.hpp>
#include <vector>
//---------------------------------------------------------------------------

struct Ingr
{
	TListBoxItem *ListBoxItem;
	int id;
	AnsiString name;
	bool select = true;
//	int category;
};
//---------------------------------------------------------------------------
struct Catgr
{
	AnsiString Name_catgr;
	std::vector<Ingr> catgr_ingr;
	TListBoxGroupHeader *ListBoxGroupHeader;
	int c_ing = 0;
};

extern std::vector<Catgr> catg_arr;

class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TImage *Image1;
	TLayout *Layout2;
	TListBox *ListBox1;
	TSpeedButton *SpeedButton1;
	TSearchBox *SearchBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall IngrClick(TObject *Sender);
	void __fastcall print();
	void __fastcall Create_ingr();
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
