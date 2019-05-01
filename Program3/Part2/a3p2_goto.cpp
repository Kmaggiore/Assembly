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

//           do
begDW_M://   {
                PopulateArray(a1, &used1, 12);
                ShowArrayLabeled(a1, used1, begA1Str);
                ProcArrays(&used3, a1, a2, a3, &used1, &used2);
                ShowArrayLabeled(a1, used1, proA1Str);
                ShowArrayLabeled(a2, used2, comA2Str);
                ShowArrayLabeled(a3, used3, comA3Str);
                CoutCstr(dacStr);
                cin >> reply;
//           }
DW_MTest:
             //while (reply != 'n' && reply != 'N');
             ///if (reply != 'n' && reply != 'N') goto begDW_M;
             if (reply == 'n') goto xitDW_M;
             if (reply != 'N') goto begDW_M;
xitDW_M:

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
//           do
begDW_PA://  {
                CoutCstr(einStr);
                CoutOneInt(*usedPtr + 1);
                cout << ':' << ' ';
                cin >> intArr[*usedPtr];
                ++(*usedPtr);
                //if (*usedPtr == cap)
                if (*usedPtr != cap) goto elseI1_PA;
begI1_PA://     {
                   CoutCstr(moStr);
                   CoutOneInt(cap);
                   CoutCstr(ieStr);
                   cout << endl;
                   reply = 'n';
                goto endI1_PA;
//              }
elseI1_PA://    else
//              {
                   CoutCstr(emiStr);
                   cin >> reply;
endI1_PA://     }
//           }
DW_PATest:
             //while (reply != 'n' && reply != 'N');
             ///if (reply != 'n' && reply != 'N') goto begDW_PA;
             if (reply == 'n') goto xitDW_PA;
             if (reply != 'N') goto begDW_PA;
xitDW_PA:
             //if (*usedPtr < cap)
             if (*usedPtr >= cap) goto endI2_PA;
begI2_PA://  {
                cout << endl;
endI2_PA://  }
             return;
}

void ShowArray(int intArr[], int used)
{
             int* hopPtr;
             int* endPtr;

             endPtr = intArr + used - 1;
             //for (hopPtr = intArr; hopPtr <= endPtr; ++hopPtr)
             hopPtr = intArr;
             goto F_SATest;
begF_SA://   {
                //if (hopPtr == endPtr)
                if (hopPtr != endPtr) goto elseI_SA;
begI_SA://      {
                   cout << *hopPtr << endl;
                goto endI_SA;
//              }
elseI_SA://     else
//              {
                   cout << *hopPtr << ' ';
endI_SA://      }
             ++hopPtr;
//           }
F_SATest:
             if (hopPtr <= endPtr) goto begF_SA;
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
             //for (hopPtr1 = sIntArr, hopPtr2 = dIntArr; hopPtr1 < endPtr1; ++hopPtr1, ++hopPtr2)
             hopPtr1 = sIntArr;
             hopPtr2 = dIntArr;
             goto F_CATest;
begF_CA://   {
                *hopPtr2 = *hopPtr1;
                ++(*dSizePtr);
             ++hopPtr1;
             ++hopPtr2;
//           }
F_CATest:
             if (hopPtr1 < endPtr1) goto begF_CA;
}

int  ProcArrayL_Aux(int* begPtr, int* endPtr, int* usedPtr)
{
             int* hopPtr22;
             int* hopPtr222;
             int anchor;
             int remCount;

             anchor = (*begPtr);
             remCount = 0;
             //for (hopPtr22 = begPtr + 1; hopPtr22 < endPtr; ++hopPtr22)
             hopPtr22 = begPtr + 1;
             goto F1_PALATest;
begF1_PALA://{
                //if (*hopPtr22 == anchor)
                if (*hopPtr22 != anchor) goto endI_PALA;
begI_PALA://    {
                   //for (hopPtr222 = hopPtr22 + 1; hopPtr222 < endPtr; ++hopPtr222)
                   hopPtr222 = hopPtr22 + 1;
                   goto F2_PALATest;
begF2_PALA://      {
                      *(hopPtr222 - 1) = *hopPtr222;
                   ++hopPtr222;
//                 }
F2_PALATest:
                   if (hopPtr222 < endPtr) goto begF2_PALA;

                   --(*usedPtr);
                   --endPtr;
                   --hopPtr22;
                   ++remCount;
endI_PALA://    }
             ++hopPtr22;
//           }
F1_PALATest:
             if (hopPtr22 < endPtr) goto begF1_PALA;

             return remCount;
}

void ProcArrayL(int intArr[], int* usedPtr)
{
             int* hopPtr2;
             int* endPtr2;
             int remCount;

             endPtr2 = intArr + (*usedPtr);
             //for (hopPtr2 = intArr; hopPtr2 < endPtr2; ++hopPtr2)
             hopPtr2 = intArr;
             goto F_PALTest;
begF_PAL://  {
                remCount = ProcArrayL_Aux(hopPtr2, endPtr2, usedPtr);
                //if (remCount != 0)
                if (remCount == 0) goto endI_PAL;
begI_PAL://     {
                   --hopPtr2;
                   endPtr2 -= remCount;
endI_PAL://     }
             ++hopPtr2;
//           }
F_PALTest:
             if (hopPtr2 < endPtr2) goto begF_PAL;
}

int  RemAllOccur(int* begPtr, int* endPtr, int target)
{
             int remCount;
             int* hopPtr;

             remCount = 0;
             //for (hopPtr = begPtr; hopPtr < endPtr; ++hopPtr)
             hopPtr = begPtr;
             goto F_RAOTest;
begF_RAO://  {
                //if (*hopPtr == target)
                if (*hopPtr != target) goto elseI_RAO;
begI_RAO://     {
                   ++remCount;
                goto endI_RAO;
//              }
elseI_RAO://    else
//              {
                   *(hopPtr - remCount) = (*hopPtr);
endI_RAO://     }
             ++hopPtr;
//           }
F_RAOTest:
             if (hopPtr < endPtr) goto begF_RAO;

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
             //while (hopPtr1 < endPtr1)
             goto W_PAMTest;
begW_PAM://  {
                *(a3 + *used3Ptr) = *hopPtr1;
                ++(*used3Ptr);
                remCount = RemAllOccur(hopPtr1 + 1, endPtr1, *hopPtr1);
                *used1Ptr -= remCount;
                endPtr1 -= remCount;
                ++hopPtr1;
//           }
W_PAMTest:
             if (hopPtr1 < endPtr1) goto begW_PAM;
}

void ProcArrays(int* used3Ptr, int a1[], int a2[], int a3[], int* used1Ptr, int* used2Ptr)
{
             CopyArray(a2, used2Ptr, a1, *used1Ptr);
             ProcArrayL(a2, used2Ptr);
             ProcArrayM(a1, used1Ptr, a3, used3Ptr);
}



