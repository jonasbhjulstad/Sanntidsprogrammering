#include <windows.h>
#include <stdio.h>

int i = 0;
int incFlag = 0;
int decFlag = 0;


DWORD WINAPI incrementingThreadFunction(){
    int k;
    for (k = 0; k < 1000000; k++)
    {
        i++;
    }
    incFlag = 1;
    return 0;
}

DWORD WINAPI decrementingThreadFunction(){
    int k;
    for (k = 0; k < 1000000; k++)
    {
        i--;
    }
    printf("dec done\n");

    decFlag = 1;
    return 0;
}


int main(){
    
    printf("test");

    DWORD decID;
    DWORD incID;
    HANDLE incHandle = CreateThread(0,0,incrementingThreadFunction, NULL, 0, &incID);
    HANDLE decHandle = CreateThread(0,0,decrementingThreadFunction, NULL, 0, &decID);
    
    Sleep(1000);

    printf("The magic number is: %d\n", i);

    CloseHandle(incHandle);
    CloseHandle(decHandle);

    return 0;
}
