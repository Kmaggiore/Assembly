#include <iostream>
using namespace std;

int  a1[12],
     a2[12],
     a3[12];
char reply;
int  used1,
     used2,
     used3,
     remCount,
     anchor;
int* hopPtr1;
int* hopPtr11;
int* hopPtr2;
int* hopPtr22;
int* hopPtr222;
int* hopPtr3;
int* endPtr1;
int* endPtr2;
int* endPtr3;

char begA1Str[] = "\nbeginning a1: ";
char proA1Str[] = "processed a1: ";
char comA2Str[] = "          a2: ";
char comA3Str[] = "          a3: ";
char einStr[]   = "Enter integer #";
char moStr[]    = "Max of ";
char ieStr[]    = " ints entered...";
char emiStr[]   = "Enter more ints? (n or N = no, others = yes) ";
char dacStr[]   = "Do another case? (n or N = no, others = yes) ";
char dlStr[]    = "================================";
char byeStr[]   = "bye...";

int main()
{
             //do
begDW1://    {
                used1 = 0;
                hopPtr1 = a1;
                //do
begDW2://       {
                   cout << einStr;
                   cout << (used1 + 1);
                   cout << ':' << ' ';
                   cin >> *hopPtr1;
                   ++used1;
                   ++hopPtr1;
                   // if (used1 == 12)
                   if(used1 != 12) goto else1;
begI1://           {
                      cout << moStr;
                      cout << 12;
                      cout << ieStr;
                      cout << endl;
                      reply = 'n';
                      goto endI1;
//                 }
                   //else
else1://           {
                      cout << emiStr;
                      cin >> reply;
endI1://            }
endDW2://       }
                //while (reply != 'n' && reply != 'N');
                if(reply == 'n')goto xitDW2;
                if(reply != 'N')goto begDW2;
xitDW2:
                cout << begA1Str;
                hopPtr1 = a1;
                endPtr1 = a1 + used1;
                //while (hopPtr1 < endPtr1)
                goto WTest1;
begW1://        {
                   //if (hopPtr1 == endPtr1 - 1)
                   if(hopPtr1 != endPtr1 - 1) goto else2;
begI2://           {
                      cout << *hopPtr1 << endl;
                      goto endI2;
//                 }
else2://           else
//                 {
                      cout << *hopPtr1 << ' ';
//                 }
endI2:
                   ++hopPtr1;
WTest1:            if(hopPtr1 < endPtr1) goto begW1;
//              }
endW1:
                //for (hopPtr1 = a1, hopPtr2 = a2, used2 = 0; // multiple initializations
                //     hopPtr1 < endPtr1;                     // loop test
                //     ++hopPtr1, ++hopPtr2, ++used2)         // multiple updates
                hopPtr1 = a1, hopPtr2 = a2, used2 = 0;
                goto FTest1;
begF1://        {
                  *hopPtr2 = *hopPtr1;
                  ++hopPtr1, ++hopPtr2, ++used2;
FTest1:           if(hopPtr1 < endPtr1) goto begF1;
endF1://        }

                hopPtr2 = a2;
                endPtr2 = a2 + used2;
                //while (hopPtr2 < endPtr2)
                goto WTest2;
begW2://        {
                   anchor = *hopPtr2;
                   //for (hopPtr22 = hopPtr2 + 1; hopPtr22 < endPtr2; ++hopPtr22)
                   hopPtr22 = hopPtr2 + 1;
                   goto FTest2;
begF2://            {
                      //if (*hopPtr22 == anchor)
                      if(*hopPtr22 != anchor) goto endI3;
begI3://              {
                         //for (hopPtr222 = hopPtr22 + 1; hopPtr222 < endPtr2; ++hopPtr222)
                         hopPtr222 = hopPtr22 + 1;
                         goto FTest3;
begF3://                 {
                            *(hopPtr222 - 1) = *hopPtr222;
                            ++hopPtr222;
FTest3:                     if(hopPtr222 < endPtr2) goto begF3;
//                       }
                         --used2;
                         --endPtr2;
                         --hopPtr22;
endI3://             }
                   ++hopPtr22;
FTest2:            if(hopPtr22 < endPtr2) goto begF2;
//                 }
                   ++hopPtr2;
WTest2:            if(hopPtr2 < endPtr2) goto begW2;
//                }

                used3 = 0;
                hopPtr3 = a3;
                hopPtr1 = a1;
                //while (hopPtr1 < endPtr1)
                goto WTest3;
begW3://        {
                   *hopPtr3 = *hopPtr1;
                   ++used3;
                   ++hopPtr3;
                   anchor = *hopPtr1;
                   remCount = 0;
                   //for (hopPtr11 = hopPtr1 + 1; hopPtr11 < endPtr1; ++hopPtr11)
                   hopPtr11 = hopPtr1 + 1;
                   goto FTest4;
begF4://           {
                      //if (*hopPtr11 == anchor)
begI4:                if(*hopPtr11 != anchor) goto else4;
//                    {
                         ++remCount;
                         goto endI4;
//                    }
                      //else
else4://              {
                         *(hopPtr11 - remCount) = *hopPtr11;
endI4://              }
                      ++hopPtr11;
FTest4:               if(hopPtr11 < endPtr1) goto begF4;
//                 }
                   used1 -= remCount;
                   endPtr1 -= remCount;
                   ++hopPtr1;
WTest3:            if(hopPtr1 < endPtr1) goto begW3;
//              }

                cout << proA1Str;
                //for (hopPtr1 = a1; hopPtr1 < endPtr1; ++hopPtr1)
                hopPtr1 = a1;
                goto FTest5;
begF5://        {
                   //if (hopPtr1 == endPtr1 - 1)
                   if(hopPtr1 != endPtr1 - 1) goto else5;
begI5://           {
                      cout << *hopPtr1 << endl;
                      goto endI5;
//                 }
                   //else
else5://           {
                      cout << *hopPtr1 << ' ';
endI5://           }
                   ++hopPtr1;
FTest5:            if(hopPtr1 < endPtr1) goto begF5;
//              }
                cout << comA2Str;
                //for (hopPtr2 = a2; hopPtr2 < endPtr2; ++hopPtr2)
                hopPtr2 = a2;
//                cout << endl;
//                while(*hopPtr2 > 0 && *hopPtr2 < 5){
//                    cout << "hopPtr2: " << *hopPtr2 << endl;
//                    hopPtr2++;
//                }

                goto FTest6;
begF6://        {
                   //if (hopPtr2 == endPtr2 - 1)
                   if(hopPtr2 != endPtr2 - 1) goto else6;
begI6://           {
                      cout << *hopPtr2 << endl;
                      goto endI6;
//                 }
                   //else
else6://           {

                      cout << *hopPtr2 << ' ';
endI6://           }
                   ++hopPtr2;
FTest6:            if(hopPtr2 < endPtr2) goto begF6;
//              }
                cout << comA3Str;
                hopPtr3 = a3;
                endPtr3 = a3 + used3;

                //while (hopPtr3 < endPtr3)
                goto WTest4;
begW4://        {
                   //if (hopPtr3 == endPtr3 - 1)
                   if(hopPtr3 != endPtr3 - 1) goto else7;
begI7://           {
                      cout << *hopPtr3 << endl;
                      goto endI7;
//                 }
                   //else
else7://           {
                      cout << *hopPtr3 << ' ';
endI7://           }
                   ++hopPtr3;
WTest4:            if(hopPtr3 < endPtr3) goto begW4;
//              }

                cout << endl;
                cout << dacStr;
                cin >> reply;
                cout << endl;
 //          }
             //while (reply != 'n' && reply != 'N');
             if(reply == 'n') goto xitDW1;
             if(reply != 'N') goto begDW1;
xitDW1:
             cout << dlStr;
             cout << '\n';
             cout << byeStr;
             cout << '\n';
             cout << dlStr;
             cout << '\n';

             return 0;
}
