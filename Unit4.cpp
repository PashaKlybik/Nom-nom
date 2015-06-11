//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
std::vector<ReciptCard> Cards;
static int number = 0;
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
ReciptCard::ReciptCard(int i) : num(i) {
    num = i;
	Back = new TPanel (Form4);//->VertScrollBox1);
	Back->Position->X = 10;
	Back->Position->Y = (17 + (number * 175));
	Back->Size->Height = 165;
	Back->Size->Width = 723;
	Back->Tag = (NativeInt)number;


	Background = new TImage (Back);
	Background->Position->X = 0;
	Background->Position->Y = 0;
	Background->Size->Height = 164;
	Background->Size->Width = 723;
	Background->Bitmap = Form4->Image2->Bitmap;
	Background->Tag = (NativeInt)i;

	Background->OnClick = OnClick;

	ReciptName = new TLabel (Background);
// 	ReciptName->
	ReciptName->Text = Recepts[num].Name;
	ReciptName->Size->Height = 120;
	ReciptName->Size->Width =  450;
	ReciptName->TextSettings->Font->Family = "Roboto";
	ReciptName->StyledSettings = ReciptName->StyledSettings>>TStyledSetting::FontColor;
	ReciptName->StyledSettings = ReciptName->StyledSettings>>TStyledSetting::Family;
	ReciptName->StyledSettings = ReciptName->StyledSettings>>TStyledSetting::Size;
	ReciptName->StyledSettings = ReciptName->StyledSettings>>TStyledSetting::Style;
	ReciptName->StyledSettings = ReciptName->StyledSettings>>TStyledSetting::Other;
	ReciptName->Position->X = 20;
	ReciptName->Position->Y = 20;
	ReciptName->TextSettings->Font->Size = 35;

	Kol = new TLabel (Background);
// 	ReciptName->
	Kol->Text = FloatToStrF(Recepts[num].interest, ffFixed, 3, 1);
	Kol->Size->Height = 70;
	Kol->Size->Width =  150;
	Kol->TextSettings->Font->Family = "Roboto";
	Kol->StyledSettings = Kol->StyledSettings>>TStyledSetting::FontColor;
	Kol->StyledSettings = Kol->StyledSettings>>TStyledSetting::Family;
	Kol->StyledSettings = Kol->StyledSettings>>TStyledSetting::Size;
	Kol->StyledSettings = Kol->StyledSettings>>TStyledSetting::Style;
	Kol->StyledSettings = Kol->StyledSettings>>TStyledSetting::Other;
	Kol->Position->X = 520;
	Kol->Position->Y = 20;
	Kol->TextSettings->Font->Size = 35;
	Kol->Visible = false;

	Sz = new TProgressBar (Background);
	Sz->Position = Recepts[num].interest;
	Sz->Position->X = 580;
	Sz->Position->Y = 20;
	Sz->Height = 40;
	Sz->Width =  150;
	Sz->

	Background->AddObject(ReciptName);
	Background->AddObject(Kol);
	Background->AddObject(Sz);
	Back->AddObject(Background);
	Form4->VertScrollBox1->AddObject(Back);
	number++;

	//TFixedBitmapItem *MultiResBitmap = new TFixedBitmapItem();
   //	Background->MultiResBitmap[0]->Bitmap =  Image2->MultiResBitmap[0]->Bitmap;


}
//---------------------------------------------------------------------------
void __fastcall ReciptCard::OnClick(TObject *Sender) {

	Form4->Hide();
//	TForm5* Form5 = new TForm5(this);
//	Form5->FormCreate(Sender);
	Form5->Show();
	num = (int)((TImage*)(Sender))->Tag;
	Form5->PrintRecipt(num);
}
//---------------------------------------------------------------------------
void __fastcall ReciptCard::Del() {
	Form4->VertScrollBox1->RemoveObject(Back);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::SpeedButton2Click(TObject *Sender)
{
	number = 0;
	//VertScrollBox1->Visible = false;
	for (int i = 0; i < Cards.size(); i++) {
		Cards[i].Del();
		Cards.pop_back();
	}

   Cards.clear();
  /*	for (int i = VertScrollBox1->ComponentCount - 1 ; i > 0 ; i--){
		if (!VertScrollBox1->Components[i]) {
			VertScrollBox1->Components[i]->Free();
		}
	}   */
	//VertScrollBox1->Visible = true;
	Form4->Hide();
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{

	Layout1->Scale->X = Layout2->Width / Layout1->Width;
	Layout1->Scale->Y = Layout2->Height / Layout1->Height;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ShowRec(int flag)
{
	if (flag) {
		for (int i  = 0 ; i < Recepts.size() ; i++) {
			if (Recepts[i].interest) {
				Cards.push_back(ReciptCard(i));
			}
		}
	} else   {
		for (int i  = 0 ; i < Recepts.size() ; i++) {
			Cards.push_back(ReciptCard(i));

		}
    }
}

//---------------------------------------------------------------------------

