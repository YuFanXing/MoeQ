#include "MoeQ.h"

#if defined(_WIN_PLATFORM_)
wchar_t DataPath[MAX_PATH + 1];
#endif

#if defined(_LINUX_PLATFORM_)
char DataPath[MAX_PATH + 1];
#endif

bool DevMode = true;

PluginSystem Plugin;

Android::Token Token;
//GUID 86A445BF44A2C287597618F6F36EB68C   MAC 4F923C3D4568   4F:92:3C:3D:45:68
Android Sdk("861891778567", "460013521635791", (const byte *)"\x86\xA4\x45\xBF\x44\xA2\xC2\x87\x59\x76\x18\xF6\xF3\x6E\xB6\x8C", (const byte *)"\x4F\x92\x3C\x3D\x45\x68", "Alpha", "XiaoMi");

void Debug()
{
}

int main()
{
#if defined(_WIN_PLATFORM_)
    SetConsoleOutputCP (65001);
    wchar_t szFilePath[MAX_PATH + 1], DataFilePath[MAX_PATH + 1], DllFilePath[MAX_PATH + 1] = {0};
    _wgetcwd(szFilePath, MAX_PATH);
    wcscpy(DataPath, szFilePath);
    wcscat(DataPath, L"\\data\\");

    if (!std::filesystem::exists(DataPath))
        std::filesystem::create_directory(DataPath);

    Log::Init();
    Database::Init();
    Plugin.Load(szFilePath);

    wchar_t _QQ[12];
    wchar_t str[256];
    wcscpy(DataFilePath, DataPath);
    wcscat(DataFilePath, L"data.ini");

    try
    {
        GetPrivateProfileString(L"Token", L"QQ", NULL, _QQ, 50, DataFilePath);

        GetPrivateProfileString(L"Token", L"A2", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.A2) != 64)
            throw "A2 len error";

        GetPrivateProfileString(L"Token", L"TGT", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.TGT) != 72)
            throw "TGT len error";

        GetPrivateProfileString(L"Token", L"D2Key", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.D2Key) != 16)
            throw "D2Key len error";

        GetPrivateProfileString(L"Token", L"wtSessionTicket", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.wtSessionTicket) != 48)
            throw "wtSessionTicket len error";

        GetPrivateProfileString(L"Token", L"wtSessionTicketKey", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.wtSessionTicketKey) != 16)
            throw "wtSessionTicketKey len error";

        GetPrivateProfileString(L"Token", L"token_16A", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.token_16A) != 56)
            throw "token_16A len error";

        GetPrivateProfileString(L"Token", L"md5", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.md5) != 16)
            throw "md5 len error";

        GetPrivateProfileString(L"Token", L"TGTkey", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.TGTkey) != 16)
            throw "TGTkey len error";

        GetPrivateProfileString(L"Token", L"ksid", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.ksid) != 16)
            throw "ksid len error";
    }
    catch (...)
    {
        goto login;
    }
#endif

#if defined(_LINUX_PLATFORM_)
    char szFilePath[MAX_PATH + 1], DataFilePath[MAX_PATH + 1], DllFilePath[MAX_PATH + 1] = {0};
    getcwd(szFilePath, MAX_PATH);
    strcpy(DataPath, szFilePath);
    strcat(DataPath, "data\\");

    Log::Init();
    Database::Init();
    Plugin.Load(szFilePath);

    wchar_t _QQ[12];
    wchar_t str[256];
    strcpy(DataFilePath, DataPath);
    strcat(DataFilePath, "data.ini");

    try
    {
        GetPrivateProfileString("Token", "QQ", NULL, _QQ, 50, DataFilePath);

        GetPrivateProfileString("Token", "A2", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.A2) != 64)
            throw "A2 len error";

        GetPrivateProfileString("Token", "TGT", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.TGT) != 72)
            throw "TGT len error";

        GetPrivateProfileString("Token", "D2Key", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.D2Key) != 16)
            throw "D2Key len error";

        GetPrivateProfileString("Token", "wtSessionTicket", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.wtSessionTicket) != 48)
            throw "wtSessionTicket len error";

        GetPrivateProfileString("Token", "wtSessionTicketKey", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.wtSessionTicketKey) != 16)
            throw "wtSessionTicketKey len error";

        GetPrivateProfileString("Token", "token_16A", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.token_16A) != 56)
            throw "token_16A len error";

        GetPrivateProfileString("Token", "md5", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.md5) != 16)
            throw "md5 len error";

        GetPrivateProfileString("Token", "TGTkey", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.TGTkey) != 16)
            throw "TGTkey len error";

        GetPrivateProfileString("Token", "ksid", NULL, str, 256, DataFilePath);
        if (XBin::Hex2BinEx(Iconv::UnicodeToAnsi(str).c_str(), Token.ksid) != 16)
            throw "ksid len error";
    }
    catch (std::exception e)
    {
    }
#endif

    if (true)
    {
        Sdk.QQ_Init(Iconv::UnicodeToAnsi(_QQ).c_str());
        Sdk.QQ_Set_Token(&Token);
        Sdk.QQ_Login_Second();
        Sdk.QQ_Login_Finish();
    }
    else
    {
    login:
        char QQ[15], Password[20];
        std::cin >> QQ;
        std::cin >> Password;
        byte state;
        Sdk.QQ_Init(QQ);
        state = Sdk.QQ_Login(Password);
    check:
        char SmsCode[7], Ticket[200];
        switch (state)
        {
        case LOGIN_SUCCESS:
            Log::AddLog(Log::LogType::INFORMATION, Log::MsgType::OTHER, u8"Login", u8"Login Successfully!");
            goto online;
        case LOGIN_VERIY:
            Log::AddLog(Log::LogType::INFORMATION, Log::MsgType::OTHER, u8"Login", u8"Slider verification code");
            std::cout << Sdk.QQ_Get_Viery_Ticket();
            std::cin >> Ticket;
            state = Sdk.QQ_Viery_Ticket(Ticket);
            goto check;
        case LOGIN_VERIY_SMS:
            Log::AddLog(Log::LogType::INFORMATION, Log::MsgType::OTHER, u8"Login", u8"Driver Lock");
            char notice[200];
            strcpy(notice, "Send Sms to ");
            strcat(notice, Sdk.QQ_Get_Viery_PhoneNumber());
            strcat(notice, " ?");

            switch (MessageBoxA(nullptr, notice, "Driver Lock", MB_OKCANCEL))
            {
            case IDOK:
                Sdk.QQ_Send_Sms();
                std::cin >> SmsCode;
                state = Sdk.QQ_Viery_Sms(SmsCode);
                break;
            case IDCANCEL:
                return TRUE;
            }
        case LOGIN_ERROR:
            Log::AddLog(Log::LogType::INFORMATION, Log::MsgType::OTHER, u8"Login", u8"Login failed");
            Log::AddLog(Log::LogType::INFORMATION, Log::MsgType::OTHER, u8"Login", Sdk.QQ_GetErrorMsg());
            return TRUE;
        default:
            break;
        }
        Sdk.QQ_Login_Finish();
    online:
        //Save Tokens
        Token = *Sdk.QQ_Get_Token();

#if defined(_WIN_PLATFORM_)
        WritePrivateProfileString(L"Token", L"QQ", Iconv::AnsiToUnicode(QQ).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"A2", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.A2, 64)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"TGT", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.TGT, 72)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"D2Key", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.D2Key, 16)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"wtSessionTicket", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.wtSessionTicket, 48)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"wtSessionTicketKey", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.wtSessionTicketKey, 16)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"token_16A", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.token_16A, 56)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"md5", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.md5, 16)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"TGTkey", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.TGTkey, 16)).c_str(), DataFilePath);
        WritePrivateProfileString(L"Token", L"ksid", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.ksid, 16)).c_str(), DataFilePath);
#endif

#if defined(_LINUX_PLATFORM_)
        WritePrivateProfileString("Token", "QQ", Iconv::AnsiToUnicode(QQ).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "A2", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.A2, 64)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "TGT", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.TGT, 72)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "D2Key", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.D2Key, 16)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "wtSessionTicket", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.wtSessionTicket, 48)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "wtSessionTicketKey", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.wtSessionTicketKey, 16)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "token_16A", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.token_16A, 56)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "md5", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.md5, 16)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "TGTkey", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.TGTkey, 16)).c_str(), DataFilePath);
        WritePrivateProfileString("Token", "ksid", Iconv::AnsiToUnicode(XBin::Bin2HexEx(Token.ksid, 16)).c_str(), DataFilePath);
#endif
    }

    Sdk.QQ_Online();
#ifdef DEBUG
    Debug();
#endif // DEBUG
    char a[99];
    std::cin >> a;

    return TRUE; // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}