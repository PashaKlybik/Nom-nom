//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
using namespace std;
//---------------------------------------------------------------------------
std::vector<Catgr> catg_arr;


//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Create_ingr()
{

	for (int i = 0; i < catg_arr.size(); i++) {
		catg_arr[i].ListBoxGroupHeader =new TListBoxGroupHeader(ListBox1);
		catg_arr[i].ListBoxGroupHeader->Text = catg_arr[i].Name_catgr;
		for (int j = 0; j < catg_arr[i].catgr_ingr.size(); j++) {
			catg_arr[i].catgr_ingr[j].select = true;

			catg_arr[i].catgr_ingr[j].ListBoxItem =  new TListBoxItem(catg_arr[i].ListBoxGroupHeader);
			catg_arr[i].catgr_ingr[j].ListBoxItem->Text = catg_arr[i].catgr_ingr[j].name;
			catg_arr[i].catgr_ingr[j].ListBoxItem->OnClick = Form3->IngrClick;
			catg_arr[i].catgr_ingr[j].ListBoxItem->TextSettings->Font->Size = 36;
			catg_arr[i].catgr_ingr[j].ListBoxItem->TextSettings->Font->Family = "Roboto Bk";
			catg_arr[i].catgr_ingr[j].ListBoxItem->Tag = (NativeInt)i;  // catg_arr[i].catgr_ingr[j].id;
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyleName = IntToStr(j); 
			
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings = catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings>>TStyledSetting::FontColor;
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings = catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings>>TStyledSetting::Family;
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings = catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings>>TStyledSetting::Size;
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings = catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings>>TStyledSetting::Style;
			catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings = catg_arr[i].catgr_ingr[j].ListBoxItem->StyledSettings>>TStyledSetting::Other;

		}
	}
 //	Form3->print();

}
//---------------------------------------------------------------------------
void __fastcall TForm3::print()
{
  /*
	for (int i = 0; i < catg_arr.size(); i++) {
		if (catg_arr[i].c_ing) {
			Form3->ListBox1->RemoveObject(catg_arr[i].ListBoxGroupHeader);
		}
		for (int j = 0; j < catg_arr[i].catgr_ingr.size(); j++) {
			if (catg_arr[i].catgr_ingr[j].select) {
				Form3->ListBox1->RemoveObject(catg_arr[i].catgr_ingr[j].ListBoxItem);
			}
		}
	}        */
	ListBox1->BeginUpdate();
	ListBox1->Clear();
	for (int i = 0; i < catg_arr.size(); i++) {
		if (catg_arr[i].c_ing != 0) {
			ListBox1->AddObject(catg_arr[i].ListBoxGroupHeader);  }
		for (int j = 0; j < catg_arr[i].catgr_ingr.size(); j++) {
			if (catg_arr[i].catgr_ingr[j].select) {
				ListBox1->AddObject(catg_arr[i].catgr_ingr[j].ListBoxItem);
			}
		}
    }

	ListBox1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)                            // парсинг базы ингредиентов
{

	Layout1->Scale->Y = Form2->Layout1->Scale->Y;
	Layout1->Scale->X = Form2->Layout1->Scale->X;
	Layout1->Position->X = 0;
	Layout1->Position->Y = 0;


	AnsiString str;
	Ingr temp_ingr;
	TStringList *JS = new TStringList;
	TIdHTTP* IdHTTP = new TIdHTTP;

	JS->LoadFromFile("sdcard/Nom-nom/Ingr.txt");

 /*    Тут проверка будет на наличие интернета
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	TJSONObject *Arr_cat = (TJSONObject*) TJSONObject::ParseJSONValue(TEncoding::ASCII->GetBytes(IdHTTP->Get("http://pastebin.com/raw.php?i=VkhL7Bxw")),0);
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  */
	TJSONObject *Arr_cat = (TJSONObject*) TJSONObject::ParseJSONValue(JS->Text);




	__try {
		for (int i = 0; i < Arr_cat->Count; i++) {
			Catgr temp;
			TJSONArray *Ctg = (TJSONArray*) Arr_cat->Get(i)->JsonValue;
			str = Arr_cat->Pairs[i]->JsonString->ToString();
			temp.Name_catgr = "";
			for (int e = 1; e  < str.Length() - 1; e++) {
				temp.Name_catgr +=str[e];
			}
			temp.c_ing = 0;
			for (int j = 0; j< Ctg->Size(); j++) {
				temp.c_ing++;
				TJSONObject  *Ingr = (TJSONObject*) Ctg->Get(j);
				temp_ingr.id = StrToInt(Ingr->Pairs[0]->JsonValue->ToString());
				temp_ingr.name = "";
				str = Ingr->Pairs[1]->JsonValue->ToString();
				int sz = str.Length();
				for (int e = 1; e  < str.Length() - 1; e++) {
						temp_ingr.name +=str[e];
				}
				temp.catgr_ingr.push_back(temp_ingr);
			}
			catg_arr.push_back(temp);
		}
		Form3->Create_ingr();
	}
	__finally {
		Arr_cat->Free();
	}

	Form3->print();

}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	Form3->Hide();
	Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::IngrClick(TObject *Sender)                  // выбор нового ингредиента
{

	int i = (int)((TListBoxItem*)(Sender))->Tag;
	int j = StrToInt(((TListBoxItem*)(Sender))->StyleName);

	Form2->Ell.push_back(Fridge(i,j));
	ListBox1->RemoveObject(catg_arr[i].catgr_ingr[j].ListBoxItem);
	catg_arr[i].catgr_ingr[j].select = false;
	catg_arr[i].c_ing--;
	int a = catg_arr[i].c_ing;
	AnsiString z = catg_arr[i].ListBoxGroupHeader->Text;
	if (catg_arr[i].c_ing == 0) {
		ListBox1->RemoveObject(catg_arr[i].ListBoxGroupHeader);
	}


}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormShow(TObject *Sender)
{
 //	Form3->print();
}
//---------------------------------------------------------------------------

