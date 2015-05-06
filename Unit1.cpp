//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

#include "Unit2.h"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{

  Layout1->Scale->X = Layout2->Width / Layout1->Width;
  Layout1->Scale->Y = Layout2->Height / Layout1->Height;
  /*Form2->Layout1->Scale->X = Layout1->Scale->X;
  Form2->Layout1->Scale->Y = Layout1->Scale->Y; */

  //Form2->Create();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Form1->Hide();
	Form2->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image2Click(TObject *Sender)
{
	Form1->Hide();
	Form2->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image4Click(TObject *Sender)
{
	ShowMessage("Тут все красиво:)");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
	ShowMessage("Тут все красиво:)");
}
//---------------------------------------------------------------------------

