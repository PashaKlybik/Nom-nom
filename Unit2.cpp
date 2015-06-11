//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h"
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
std::vector<recept> Recepts;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
Fridge::Fridge(int i, int j) : ctg(i), ing(j) {

	Basement = new TPanel(Form2);
	Basement->Position->X = 10;
	Basement->Position->Y = (17 + (number * 120));
	Basement->Size->Height = 110;
	Basement->Size->Width = 723;
	Basement->OnClick = Onclick;
   /*	Basement->OnMouseDown = svoup_1;
	Basement->OnMouseMove = svoup_2;
	Basement->OnMouseUp = svoup_3;   */
	Basement->Tag = (NativeInt)number;

	OutName = new TLabel(Basement);
	OutName->Text = catg_arr[ctg].catgr_ingr[ing].name;
	OutName->Size->Height = 70;
	OutName->Size->Width =  700;
	OutName->TextSettings->Font->Family = "Roboto";
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::FontColor;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Family;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Size;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Style;
	OutName->StyledSettings = OutName->StyledSettings>>TStyledSetting::Other;
	OutName->Position->X = 20;
	OutName->Position->Y = 20;
	OutName->TextSettings->Font->Size = 52;
 //	OutName->TextSettings->FontColor = TAlphaColors::Blue;
	id = catg_arr[ctg].catgr_ingr[ing].id;

	Basement->AddObject(OutName);
	Form2->VertScrollBox1->AddObject(Basement);
	number++;

	for (int i = 0; i < Recepts.size(); i++) {
			bool check = false;
			for (int j = 0; j < Recepts[i].Ingrd.size(); j++){
				if (Recepts[i].Ingrd[j].id == id)
				{
					check = true;

				}
			}
			if (check) {
				Recepts[i].interest += 100.0 / Recepts[i].Ingrd.size();
			}

	}

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
}
//--------------------------------------------------------------------------
void __fastcall  Fridge::svoup_2(TObject *Sender, TShiftState Shift, float X,
		  float Y) {
	if (drag) {
		int posit = start_x + (X - diff_x);
		Form2->Ell[num].Basement->Position->X = posit;
		if ((Y > Form2->Ell[num].Basement->Height - 5) && (Y < 5)) {
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
	Button1->Visible = false;
	Form2->ParsRecipe();


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
void __fastcall TForm2::Button1Click(TObject *Sender)
{
/*
//			Парсинг рецептов из файла/(в будущемна выбор еще будет сервер)
	TStringList *JS = new TStringList;
	JS->LoadFromFile("sdcard/Nom-nom/Base_rec.txt");
	ShowMessage(JS->Text);
	TJSONObject *ArrRecept = (TJSONObject*) TJSONObject::ParseJSONValue(JS->Text);
//    		Расштфровка JSON-строки
	__try {
		for (int i = 0; i < ArrRecept->Count; i++) {
			AnsiString name = ArrRecept->Pairs[i]->JsonString->ToString();
			recept TempRecept;
			#ifdef __ANDROID__
			name.Delete(name.Length()-1,1);
			name.Delete(0,1);
			#endif
			#ifdef _WIN32
			name.Delete(name.Length(),1);
			name.Delete(1,1);
			#endif
			TempRecept.Name = name;
		//	ShowMessage(TempRecept.Name);
			TempRecept.interest = 0;
			TJSONArray *Temp = (TJSONArray*) ArrRecept->Pairs[i]->JsonValue;
			TJSONObject *DescRecept = (TJSONObject*) Temp->Get(0);
//		    	Ингридиенты используеиые в рецепте
			for (int j = 0; j < DescRecept->Count ; j++) {
				AnsiString id  = DescRecept->Pairs[j]->JsonString->ToString();


				#ifdef __ANDROID__
				id.Delete(id.Length()-1,1);
				id.Delete(0,1);
				#endif
				#ifdef _WIN32
				id.Delete(id.Length(),1);
				id.Delete(1,1);
				#endif
				CookIngr t;
				t.id = StrToInt(id);
				t.NameIngr = DescRecept->Pairs[j]->JsonValue->ToString();
				TempRecept.Ingrd.push_back(t);
//			 	ShowMessage(IntToStr(t.id) + t.NameIngr);
			}

//		    	Шаги приготовления рецепта
			DescRecept = (TJSONObject*) Temp->Get(1);
			TJSONArray *StepArr = (TJSONArray*) DescRecept->Get(0)->JsonValue;
			for (int j = 0; j < StepArr->Count; j++) {
				TJSONObject *Step = (TJSONObject*) StepArr->Get(j);
				AnsiString Link = Step->Pairs[0]->JsonValue->ToString();
				AnsiString Text = Step->Pairs[1]->JsonValue->ToString();
				#ifdef __ANDROID__
				Link.Delete(Link.Length()-1,1);
				Link.Delete(0,1);
				Text.Delete(Text.Length()-1,1);
				Text.Delete(0,1);
				#endif
				#ifdef _WIN32
				Link.Delete(Link.Length(),1);
				Link.Delete(1,1);
				Text.Delete(Text.Length(),1);
				Text.Delete(1,1);
				#endif
				CookStep t;
				t.Link = Link;
				t.Text = Text;
				TempRecept.Steps.push_back(t);
//		 		ShowMessage(Link + Text);
			}
			Recepts.push_back(TempRecept);

		}
	}
	__finally {
		ArrRecept->Free();
	}

		 */
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormShow(TObject *Sender)
{
	int KolRec = 0;
	for (int i = 0; i < Recepts.size(); i++) {
		if (Recepts[i].interest != 0) {
			KolRec++;
		}
	}
	if (KolRec > 0) {
		Label1->Text = IntToStr(KolRec);
		Label1->Visible = true;
		Label2->Visible = true;
		Label3->Visible = true;
		SpeedButton1->Visible = true;
		}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{

	Form2->Hide();
	Form4->Show();
	Form4->ShowRec(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ParsRecipe()
{

//			Парсинг рецептов из файла/(в будущемна выбор еще будет сервер)
	TStringList *JS = new TStringList;
	JS->LoadFromFile("sdcard/Nom-nom/Base_rec.txt");
  //	ShowMessage(JS->Text);
	TJSONObject *ArrRecept = (TJSONObject*) TJSONObject::ParseJSONValue(JS->Text);
//    		Расштфровка JSON-строки
	__try {
		for (int i = 0; i < ArrRecept->Count; i++) {
			AnsiString name = ArrRecept->Pairs[i]->JsonString->ToString();
			recept TempRecept;
			#ifdef __ANDROID__
			name.Delete(name.Length()-1,1);
			name.Delete(0,1);
			#endif
			#ifdef _WIN32
			name.Delete(name.Length(),1);
			name.Delete(1,1);
			#endif
			TempRecept.Name = name;
		//	ShowMessage(TempRecept.Name);
			TempRecept.interest = 0;
			TJSONArray *Temp = (TJSONArray*) ArrRecept->Pairs[i]->JsonValue;
			TJSONObject *DescRecept = (TJSONObject*) Temp->Get(0);
//		    	Ингридиенты используеиые в рецепте
			for (int j = 0; j < DescRecept->Count ; j++) {
				AnsiString id  = DescRecept->Pairs[j]->JsonString->ToString();


				#ifdef __ANDROID__
				id.Delete(id.Length()-1,1);
				id.Delete(0,1);
				#endif
				#ifdef _WIN32
				id.Delete(id.Length(),1);
				id.Delete(1,1);
				#endif
				CookIngr t;
				t.id = StrToInt(id);
				t.NameIngr = DescRecept->Pairs[j]->JsonValue->ToString();
				TempRecept.Ingrd.push_back(t);
//			 	ShowMessage(IntToStr(t.id) + t.NameIngr);
			}

//		    	Шаги приготовления рецепта
			DescRecept = (TJSONObject*) Temp->Get(1);
			TJSONArray *StepArr = (TJSONArray*) DescRecept->Get(0)->JsonValue;
			for (int j = 0; j < StepArr->Count; j++) {
				TJSONObject *Step = (TJSONObject*) StepArr->Get(j);
				AnsiString Link = Step->Pairs[0]->JsonValue->ToString();
				AnsiString Text = Step->Pairs[1]->JsonValue->ToString();
				#ifdef __ANDROID__
				Link.Delete(Link.Length()-1,1);
				Link.Delete(0,1);
				Text.Delete(Text.Length()-1,1);
				Text.Delete(0,1);
				#endif
				#ifdef _WIN32
				Link.Delete(Link.Length(),1);
				Link.Delete(1,1);
				Text.Delete(Text.Length(),1);
				Text.Delete(1,1);
				#endif
				CookStep t;
				t.Link = Link;
				t.Text = Text;
				TempRecept.Steps.push_back(t);
//		 		ShowMessage(Link + Text);
			}
			Recepts.push_back(TempRecept);

		}
	}
	__finally {
		ArrRecept->Free();
	}
}
//---------------------------------------------------------------------------

