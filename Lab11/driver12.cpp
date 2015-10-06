/** 
 *  @file driver.cpp
 *  @brief CSC 112, Lab 12, driver program  
 *
 *  This program tests the PixelLinkList class, enjoy... 
 *  
 *  @author Nomed Nocaed (nnocae10)
 *  @date   4/26/2015  
 *  @bug    No known bugs.
 */

#include<iostream>  
#include "pixel.h"  
#include "pixellist.h"
#include "pixelnode.h"  
#include "pixellinklist.h"  
using namespace std;  

int main()  
{  
   cout << "================= (lab 11) constructor tests ================= \n" << flush;  
   PixelLinkList ll1;  
   cout << "ll1 (empty):                          " << ll1 <<'\n' << flush;  
   PixelLinkList ll2(Pixel(1, 1, 1));  
   cout << "ll2 (Pixel(1, 1, 1)):                 " << ll2 << '\n' << flush;  
   PixelList pl(Pixel(1, 1, 1));  
   pl.append(Pixel(2, 2, 2));  
   PixelLinkList ll3(pl);  
   cout << "ll3 (Pixel(1, 1, 1)->Pixel(2, 2, 2)): " << ll3 << '\n' << flush;  
   PixelLinkList ll4(ll3);  
   cout << "ll4 (ll3):                            " << ll4 << '\n' << flush;  

   cout << "\n================= (lab 11) append tests ====================== \n" << flush;  

   PixelLinkList ll5;  
   cout << "ll5:                                         " << ll5 << '\n' << '\n' << flush;  
   ll5.append(Pixel(10, 10, 10));  
   cout << "ll5 (Pixel(10, 10, 10)):                     " << ll5 << '\n' << flush;  
   ll5.append(Pixel(20, 20, 20));  
   cout << "ll5 (Pixel(10, 10, 10)-> Pixel(20, 20, 20)): " << ll5 << '\n' << flush;  

   cout << "\n================= (lab 11) size tests ======================== \n" << flush;  

   cout << "ll1.size() (0): " << ll1.size() << '\n' << flush;  
   cout << "ll3.size() (2): " << ll3.size() << '\n' << flush;  

   cout << "\n================= (lab 11) operator= tests =================== \n" << flush;  

   cout << "ll1: " << ll1 << '\n' << flush;  
   cout << "ll2: " << ll2 << '\n' << flush;  
   cout << "ll4: " << ll4 << '\n' << '\n' << flush;  

   ll4 = ll1;  
   cout << "ll4 = ll1: " << ll4 << '\n' << flush;  
   ll4 = ll2;  
   cout << "ll4 = ll2: " << ll4 << '\n' << flush;  
   
   cout << "\n================= (lab 12) single remove tests =============== \n" << flush;  

   ll4 = ll5;  
   ll4.append(Pixel(30, 30, 30));  
   ll4.append(Pixel(40, 40, 40));  
   cout << "ll4: " << ll4 << '\n' << '\n' << flush;  
   
   ll4.remove(Pixel(30, 30, 30));  
   cout << "ll4 (removed (30, 30, 30)): " << ll4 << '\n' << flush;  
   ll4.remove(Pixel(40, 40, 40));  
   cout << "ll4 (removed (40, 40, 40)): " << ll4 << '\n' << flush;  
   ll4.remove(Pixel(10, 10, 10));  
   cout << "ll4 (removed (10, 10, 10)): " << ll4 << '\n' << flush;  
   ll4.remove(Pixel(20, 20, 20));  
   cout << "ll4 (removed (20, 20, 20)): " << ll4 << '\n' << flush;  

   cout << "\n================= (lab 12) multi remove tests ================ \n" << flush;  

   ll4 = ll1;  
   ll4.append(Pixel(10, 10, 10));  
   ll4.append(Pixel(10, 10, 10));  
   ll4.append(Pixel(30, 30, 30));  
   ll4.append(Pixel(20, 20, 20));  
   ll4.append(Pixel(30, 30, 30));  
   cout << "ll4: " << ll4 << '\n' << '\n' << flush;  

   ll4.remove(Pixel(30, 30, 30));  
   cout << "ll4 (removed (30, 30, 30)): " << ll4 << '\n' << flush;  
   ll4.remove(Pixel(20, 20, 20));  
   cout << "ll4 (removed (20, 20, 20)): " << ll4 << '\n' << flush;  
   ll4.remove(Pixel(10, 10, 10));  
   cout << "ll4 (removed (10, 10, 10)): " << ll4 << '\n' << flush;  

   cout << "\n================= (lab 12) operator+ tests =================== \n" << flush;  
   
   cout << "pl:  " << pl << '\n' << flush;  
   cout << "ll1: " << ll1 << '\n' << flush;  
   cout << "ll5: " << ll5 << '\n' << '\n' << flush;  

   cout << "ll1 + ll1:             " << ll1 + ll1 << '\n' << flush;  
   cout << "ll5 + ll5:             " << ll5 + ll5 << '\n' << flush;  
   cout << "ll5 + pl:              " << ll5 + pl << '\n' << flush;  
   cout << "pl + ll5:              " << pl + ll5 << '\n' << flush;  
   cout << "Pixel(1, 1, 1) + ll5:  " << Pixel(1, 1, 1) + ll5 << '\n' << flush;  
   cout << "ll5 + Pixel(1, 1, 1):  " << ll5 + Pixel(1, 1, 1) << '\n' << flush;  

   cout << '\n' << flush;  
   cout << "ll1: " << ll1 << '\n' << flush;  
   cout << "ll2: " << ll2 << '\n' << flush;  
   cout << "ll3: " << ll3 << '\n' << flush;  
   cout << "ll4: " << ll4 << '\n' << flush;  
   cout << "ll5: " << ll5 << '\n' << flush;  
   
   cout << "kitchen sink test: ll1 + ll2 + ll3 + ll4 +  ll5 \n" << flush;  
   cout << ll1 + ll2 + ll3 + ll4 + ll5 << '\n' << flush;  

   return 0;  
} 


