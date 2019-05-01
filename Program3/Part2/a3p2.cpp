#include <iostream>
using namespace std;

void CoutCstr(char cstr[]);
void CoutCstrNL(char cstr[]);
void CoutOneInt(int oneInt);
void PopulateArray(int a[], int* usedPtr, int cap);
void ShowArray(int a[], int size);
void ShowArrayLabeled(int intArr[], int used, char label[]);
void CopyArray(int dIntArr[], int* dSizePtr, int sIntArr[], int sSize);
int  ProcArrayL_Aux(int* begPtr, int* endPtr, int* usedPtr);
void ProcArrayL(int intArr[], int* usedPtr);
int  RemAllOccur(int intArr[], int used, int target);
void ProcArrayM(int a1[], int* used1Ptr, int a3[], int* used3Ptr);
void ProcArrays(int* used3Ptr, int a1[], int a2[], int a3[], int* used1Ptr, int* used2Ptr);

int main()
{
             int  a1[12],
                  a2[12],
                  a3[12];
             char reply;
             int  used1,
                  used2,
                  used3;

             char begA1Str[] = "beginning a1: ";
             char proA1Str[] = "processed a1: ";
             char comA2Str[] = "          a2: ";
             char comA3Str[] = "          a3: ";
             char dacStr[]   = "Do another case? (n or N = no, others = yes) ";
             char dlStr[]    = "================================";
             char byeStr[]   = "bye...";

             do
             {
                PopulateArray(a1, &used1, 12);
                ShowArrayLabeled(a1, used1, begA1Str);
                ProcArrays(&used3, a1, a2, a3, &used1, &used2);
                ShowArrayLabeled(a1, used1, proA1Str);
                ShowArrayLabeled(a2, used2, comA2Str);
                ShowArrayLabeled(a3, used3, comA3Str);
                CoutCstr(dacStr);
                cin >> reply;
             }
             while (reply != 'n' && reply != 'N');

             CoutCstrNL(dlStr);
             CoutCstrNL(byeStr);
             CoutCstrNL(dlStr);
             return 0;
}

void CoutCstr(char cstr[])
{
             cout << cstr;
}

void CoutCstrNL(char cstr[])
{
             CoutCstr(cstr);
             cout << '\n';
}

void CoutOneInt(int oneInt)
{
             cout << oneInt;
}

void PopulateArray(int intArr[], int* usedPtr, int cap)
{
             char reply;

             char einStr[]   = "Enter integer #";
             char moStr[]    = "Max of ";
             char ieStr[]    = " ints entered...";
             char emiStr[]   = "Enter more ints? (n or N = no, others = yes) ";

             *usedPtr = 0;
             do
             {
                CoutCstr(einStr);
                CoutOneInt(*usedPtr + 1);
                cout << ':' << ' ';
                cin >> intArr[*usedPtr];
                ++(*usedPtr);
                if (*usedPtr == cap)
                {
                   CoutCstr(moStr);
                   CoutOneInt(cap);
                   CoutCstr(ieStr);
                   cout << endl;
                   reply = 'n';
                }
                else
                {
                   CoutCstr(emiStr);
                   cin >> reply;
                }
             }
             while (reply != 'n' && reply != 'N');
             if (*usedPtr < cap)
             {
                cout << endl;
             }
             return;
}

void ShowArray(int intArr[], int used)
{
             int* hopPtr;
             int* endPtr;

             endPtr = intArr + used;
             for (hopPtr = intArr; hopPtr < endPtr; ++hopPtr)
             {
                if (hopPtr == endPtr - 1)
                {
                   cout << *hopPtr << endl;
                }
                else
                {
                   cout << *hopPtr << ' ';
                }
             }
}

void ShowArrayLabeled(int intArr[], int used, char label[])
{
             CoutCstr(label);
             ShowArray(intArr, used);
}

void CopyArray(int dIntArr[], int* dSizePtr, int sIntArr[], int sSize)
{
             int* hopPtr1;
             int* hopPtr2;
             int* endPtr1;

             *dSizePtr = 0;
             endPtr1 = sIntArr + sSize;
             for (hopPtr1 = sIntArr, hopPtr2 = dIntArr; hopPtr1 < endPtr1; ++hopPtr1, ++hopPtr2)
             {
                *hopPtr2 = *hopPtr1;
                ++(*dSizePtr);
             }
}

int ProcArrayL_Aux(int* begPtr, int* endPtr, int* usedPtr)
{
             int* hopPtr22;
             int* hopPtr222;
             int anchor;
             int remCount;

             anchor = (*begPtr);
             remCount = 0;
             for (hopPtr22 = begPtr + 1; hopPtr22 < endPtr; ++hopPtr22)
             {
                if (*hopPtr22 == anchor)
                {
                   for (hopPtr222 = hopPtr22 + 1; hopPtr222 < endPtr; ++hopPtr222)
                   {
                      *(hopPtr222 - 1) = *hopPtr222;
                   }
                   --(*usedPtr);
                   --endPtr;
                   --hopPtr22;
                   ++remCount;
                }
             }
             return remCount;
}

void ProcArrayL(int intArr[], int* usedPtr)
{
             int* hopPtr2;
             int* endPtr2;
             int remCount;

             endPtr2 = intArr + (*usedPtr);
             for (hopPtr2 = intArr; hopPtr2 < endPtr2; ++hopPtr2)
             {
                remCount = ProcArrayL_Aux(hopPtr2, endPtr2, usedPtr);
                if (remCount != 0)
                {
                   --hopPtr2;
                   endPtr2 -= remCount;
                }
             }
}

int RemAllOccur(int* begPtr, int* endPtr, int target)
{
             int remCount;
             int* hopPtr;

             remCount = 0;
             for (hopPtr = begPtr; hopPtr < endPtr; ++hopPtr)
             {
                if (*hopPtr == target)
                {
                   ++remCount;
                }
                else
                {
                   *(hopPtr - remCount) = (*hopPtr);
                }
             }
             return remCount;
}

void ProcArrayM(int a1[], int* used1Ptr, int a3[], int* used3Ptr)
{
             int remCount;
             int* hopPtr1;
             int* endPtr1;

             *used3Ptr = 0;
             hopPtr1 = a1;
             endPtr1 = a1 + (*used1Ptr);
             while (hopPtr1 < endPtr1)
             {
                *(a3 + *used3Ptr) = *hopPtr1;
                ++(*used3Ptr);
                remCount = RemAllOccur(hopPtr1 + 1, endPtr1, *hopPtr1);
                *used1Ptr -= remCount;
                endPtr1 -= remCount;
                ++hopPtr1;
             }
}

void ProcArrays(int* used3Ptr, int a1[], int a2[], int a3[], int* used1Ptr, int* used2Ptr)
{
             CopyArray(a2, used2Ptr, a1, *used1Ptr);
             ProcArrayL(a2, used2Ptr);
             ProcArrayM(a1, used1Ptr, a3, used3Ptr);
}



