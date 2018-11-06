//---------------------------------------------------------------------------

#ifndef ArkaH
#define ArkaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *BackGround;
        TShape *Ball;
        TTimer *Timer1_Balls;
        TShape *Paddle;
        TTimer *Timer2_Left;
        TTimer *Timer3_Right;
        TLabel *Label1;
        TLabel *Game_Over;
        void __fastcall Timer1_BallsTimer(TObject *Sender);
        void __fastcall Timer2_LeftTimer(TObject *Sender);
        void __fastcall Timer3_RightTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
