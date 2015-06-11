//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit4.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm5 *Form5;
std::vector<StepRecipe> Steps;
static int numb = 0;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 StepRecipe::StepRecipe(AnsiString Link, AnsiString Text) {  // конструктор шагов

	numb++;
	Bottom = new TTabItem(Form5);

	ImgStep = new TImage(Bottom);
	ImgStep->Position->X = 5;
	ImgStep->Position->Y = 2;
	ImgStep->Size->Height = 225;
	ImgStep->Size->Width = 300;
	ImgStep->Scale->Y = 2,46;
	ImgStep->Scale->X = 2.46;

	TStream* ms = new TMemoryStream;
	Form5->IdHTTP1->Get(Link, ms);
	ImgStep->Bitmap->LoadFromStream(ms);
	ImgStep->AutoCapture = true;


	TextStep = new TLabel(Bottom);
	TextStep->Text = Text;
	TextStep->Position->X = 10;
	TextStep->Position->Y = 470;
	TextStep->Height = 500;
	TextStep->Width = 745;
	TextStep->TextSettings->Font->Size = 50;
	TextStep->StyledSettings = TextStep->StyledSettings>>TStyledSetting::FontColor;
	TextStep->StyledSettings = TextStep->StyledSettings>>TStyledSetting::Family;
	TextStep->StyledSettings = TextStep->StyledSettings>>TStyledSetting::Size;
	TextStep->StyledSettings = TextStep->StyledSettings>>TStyledSetting::Style;
	TextStep->StyledSettings = TextStep->StyledSettings>>TStyledSetting::Other;
	TextStep->AutoSize = true;

	Bottom->Text =  IntToStr(numb);
	Bottom->AddObject(ImgStep);
	Bottom->AddObject(TextStep);
	Form5->TabControl1->AddObject(Bottom);

   //	ImgStep->

   //	TImage *ImgStep;
  //	TLabel *TextStep;

}
//---------------------------------------------------------------------------
void StepRecipe::Del()                          // Удаление
{
	Form5->TabControl1->RemoveObject(Bottom);
}
//---------------------------------------------------------------------------
void StepRecipe::SetFoc()     //Установка фокуса на вызываемый эллемент
{
	Bottom->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::SpeedButton2Click(TObject *Sender)  // возвращение на 4 форму
{       int i = 0;
	while( Steps.size()) {
		Steps[i].Del();
		i++;
	}
	Steps.clear();

	numb = 0;
  /*	TabControl1->Free();
	TabControl1 = TTabControl();
	*/Form5->Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PrintRecipt(int i)    // Вывод шагов
{
	for (int j = 0; j < Recepts[i].Steps.size() ; j++) {
	  Steps.push_back(StepRecipe(Recepts[i].Steps[j].Link,Recepts[i].Steps[j].Text));
	 /*	if (j == 0) {
				a->Bottom->SetFocus();
		}  */
	}
	Steps[0].SetFoc();

}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)     // создание четвёртой формы, подгон под экран
{
	Layout1->Scale->Y = Form4->Layout1->Scale->Y;
	Layout1->Scale->X = Form4->Layout1->Scale->X;
	Layout1->Position->X = 0;
	Layout1->Position->Y = 0;
  //	StepRecipe* a = new StepRecipe("http://ist1.objorka.com/img0009/67/967_0383fkj_1520_p.jpg","asdasdsad");

}
//---------------------------------------------------------------------------

