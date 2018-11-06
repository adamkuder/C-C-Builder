object Form1: TForm1
  Left = 403
  Top = 233
  Width = 1305
  Height = 675
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BackGround: TShape
    Left = 0
    Top = 0
    Width = 1289
    Height = 561
    Align = alTop
    Brush.Color = clBackground
  end
  object Ball: TShape
    Left = 504
    Top = 504
    Width = 17
    Height = 17
    Shape = stCircle
  end
  object Timer1: TTimer
    Interval = 15
    OnTimer = Timer1Timer
    Left = 16
    Top = 8
  end
end
