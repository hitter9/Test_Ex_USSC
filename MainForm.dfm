object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1042#1085#1077#1089#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 140
  ClientWidth = 465
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object InfoLabel: TLabel
    Left = 8
    Top = 66
    Width = 453
    Height = 71
    AutoSize = False
    Caption = 
      #1042#1074#1077#1076#1080#1090#1077' '#1074' '#1087#1086#1083#1103' '#1074#1099#1096#1077' '#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1091#1102#1097#1080#1077' '#1076#1072#1085#1085#1099#1077' '#1080' '#1074#1085#1077#1089#1080#1090#1077' '#1080#1093' '#1074' '#1073#1072#1079#1091' '#1076 +
      #1072#1085#1085#1099#1093' '#1089' '#1087#1086#1084#1086#1097#1100#1102' '#1082#1085#1086#1087#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object NameLabel: TLabel
    Left = 8
    Top = 8
    Width = 97
    Height = 23
    AutoSize = False
    Caption = #1060#1072#1084#1080#1083#1080#1103' '#1080' '#1080#1084#1103
  end
  object NumberLabel: TLabel
    Left = 8
    Top = 37
    Width = 97
    Height = 23
    AutoSize = False
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072
  end
  object NameEdit: TEdit
    Left = 117
    Top = 8
    Width = 217
    Height = 23
    TabOrder = 0
  end
  object NumberEdit: TEdit
    Left = 117
    Top = 37
    Width = 217
    Height = 23
    TabOrder = 1
  end
  object EnterButton: TButton
    Left = 340
    Top = 8
    Width = 121
    Height = 52
    Caption = #1042#1085#1077#1089#1090#1080' '#1076#1072#1085#1085#1099#1077' '#1074' '#1041#1044
    TabOrder = 2
    OnClick = EnterButtonClick
  end
end
