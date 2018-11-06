//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Arkanoid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x,y;
        x=-5;
        y=-5;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Ball->left+=x;
        Ball->Top+=yl

        //Wall
        if(Ball->Left-5 <= BackGround->Left) x=-x;
        if(Ball->Top-5 <= BackGround->Top) y=-y;
}
//---------------------------------------------------------------------------

