Attribute VB_Name = "Module2"
'ר�����ڴ���ע�����ػ���Ϣ�ػ񼰴����¼�__��ʼ
Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" _
(ByVal hwnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function GetWindowLong Lib "user32" Alias "GetWindowLongA" _
(ByVal hwnd As Long, ByVal nIndex As Long) As Long
Declare Function CallWindowProc Lib "user32" Alias "CallWindowProcA" _
(ByVal lpPrevWndFunc As Long, ByVal hwnd As Long, ByVal Msg As Long, _
ByVal wParam As Long, ByVal lParam As Long) As Long

Public Const GWL_WNDPROC = (-4)
Public Const WM_ENDSESSION = &H16
Public Const WM_QUERYENDSESSION = &H11

Public preWinProc As Long

Public Function wndproc(ByVal hwnd As Long, ByVal Msg As Long, _
ByVal wParam As Long, ByVal lParam As Long) As Long
If Msg = WM_QUERYENDSESSION Then '�����ע��
    OnEnd
     '���������Լ�һЩ�Զ������
    End '�����˳�����ֹ�û���Ϊ������δ�˳����޷�ע����
Else
    If Msg = WM_ENDSESSION Then '����ǹػ�
        If wParam = 0 Then '����˳���ػ���LogOff����ʱ�����������������Ĳ���
        '���������Լ�һЩ�Զ������
        OnEnd
        End '�����˳�����ֹ�û���Ϊ������δ�˳����޷��ػ���
        End If
    End If
End If
'��֮����ԭ����Window Procedure
wndproc = CallWindowProc(preWinProc, hwnd, Msg, wParam, lParam)
End Function
'ר�����ڴ���ע�����ػ���Ϣ�ػ񼰴����¼�__����



