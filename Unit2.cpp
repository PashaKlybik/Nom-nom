//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)
#include "Unit1.h"
#include "Unit3.h"
TForm2 *Form2;
//---------------------------------------------------------------------------
static int number = 0;
static int num, diff_x, start_x;
static bool drag;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
Fridge::Fridge(int i, int j) : ctg(i), ing(j) {

	Basement = new TPanel(Form2);
	Basement->Position->X = 7;
	Basement->Position->Y = (7 + (number * 80));
	Basement->Size->Height = 70;
	Basement->Size->Width = 730;
	Basement->OnClick = Onclick;
	Basement->OnMouseDown = svoup_1;
	Basement->OnMouseMove = svoup_2;
	Basement->OnMouseUp = svoup_3;
	Basement->Tag = (NativeInt)number;

	OutName = new TLabel(Basement);
	OutName->Text = catg_arr[ctg].catgr_ingr[ing].name;
	OutName->Size->Height = 35;
	OutName->Size->Width =  350;
	OutName->TextSettings->Font->Family = "Roboto";
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::FontColor;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Family;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Size;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Style;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Other;
	OutName->Position->X = 20;
	OutName->Position->Y = 50;
	OutName->TextSettings->Font->Size = 30;
 //	OutName->TextSettings->FontColor = TAlphaColors::Blue;
	id = catg_arr[ctg].catgr_ingr[ing].id;
	Basement->AddObject(OutName);
	Form2->VertScrollBox1->AddObject(Basement);
	number++;

}
//--------------------------------------------------------------------------
void __fastcall  Fridge::Onclick(TObject *Sender) {
  //	ShowMessage(IntToStr(id));
}
//--------------------------------------------------------------------------
void __fastcall  Fridge::svoup_1(TObject *Senderr, TMouseButton Button, TShiftState Shift,
		  float X, float Y) {
	num = ((TPanel*)(Senderr))->Tag;
	diff_x = X;
	start_x = Form2->Ell[num].Basement->Position->X;
	drag = true;
  //	Form2->Ell[num]
}
//--------------------------------------------------------------------------
void __fastcall  Fridge::svoup_2(TObject *Sender, TShiftState Shift, float X,
		  float Y) {
	if (drag) {
		int posit = start_x + (X - diff_x);
		Form2->Ell[num].Basement->Position->X = posit;
		if ((Y == Form2->Ell[num].Basement->Height) && (Y == 0)) {
			drag = false;
			if ( ((start_x - X)> 200) ^ ((start_x - X)< -200) ) {

				for (int i = num + 1; i < Form2->Ell.size(); i++) {
					Form2->Ell[i].Basement->Position->Y = Form2->Ell[i].Basement->Position->Y - 80;
					Form2->Ell[i].Basement->Tag = Form2->Ell[i].Basement->Tag - 1;
				}
				catg_arr[Form2->Ell[num].ctg].c_ing++;
				catg_arr[Form2->Ell[num].ctg].catgr_ingr[Form2->Ell[num].ing].select = true;
			   //Form2->Ell[num].Basement->Visible = false;
				Form2->VertScrollBox1->RemoveObject(Form2->Ell[num].Basement);
				Form2->Ell.erase(Form2->Ell.begin() + num);
				number--;
			} else {
					Form2->Ell[num].Basement->Position->X = start_x;
			}
		}
	}

}
//--------------------------------------------------------------------------
void __fastcall  Fridge::svoup_3(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y) {

	if (drag) {
		drag = false;
		if ( ((start_x - X)> 200) ^ ((start_x - X)< -200) ) {

			for (int i = num + 1; i < Form2->Ell.size(); i++) {
				Form2->Ell[i].Basement->Position->Y = Form2->Ell[i].Basement->Position->Y - 80;
				Form2->Ell[i].Basement->Tag = Form2->Ell[i].Basement->Tag - 1;
			}
			catg_arr[Form2->Ell[num].ctg].c_ing++;
			catg_arr[Form2->Ell[num].ctg].catgr_ingr[Form2->Ell[num].ing].select = true;
		   //Form2->Ell[num].Basement->Visible = false;
			Form2->VertScrollBox1->RemoveObject(Form2->Ell[num].Basement);
			Form2->Ell.erase(Form2->Ell.begin() + num);
			number--;
		} else {
				Form2->Ell[num].Basement->Position->X = start_x;
		}
	}
}
//--------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
//  	Layout1->Scale->X = Layout2->Width / Layout1->Width;
//    Layout1->Scale->Y = Layout2->Height / Layout1->Height;
	Layout1->Scale->Y = Form1->Layout1->Scale->Y;
	Layout1->Scale->X = Form1->Layout1->Scale->X;
	Layout1->Position->X = 0;
	Layout1->Position->Y = 0;

  //	VertScrollBox1->StyleLookup->color >Color = Grey;
//	Fridge *Ell_class = new Fridge(5,"zxcasc");

}
//---------------------------------------------------------------------------


void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
	Form2->Hide();
	Form1->Show();
}
//---------------------------------------------------------------------------

/*void __fastcall  TForm2::AddEll(int id, AnsiString Name)
{
	Fridge *Ell_class = new Fridge(id, Name);
}  */
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
	Form2->Hide();
	Form3->Show();
}
//---------------------------------------------------------------------------





