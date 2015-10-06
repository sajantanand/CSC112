/** 
 *  @file driver.cpp
 *  @brief CSC 112, Lab 10, driver program  
 *
 *  This program tests the Pixel class, enjoy... and the Pixel List class
 *  
 *  @author Nomed Nocaed (nnocae10) and Sajant Anand
 *  @date	4/14/2015  
 *  @bug	No known bugs. Too many to count
 */

#include<iostream>  
#include "pixel.h" 
#include "pixellist.h" 
using namespace std;  

int main()  
{  	cout << "===========  Pixel Class Test - Fulp  =========== \n";
	cout << "========= constructor and accessor tests ======== \n";  
	Pixel p1;  
	Pixel p2(10, 20);  
	Pixel p3(10, 20, 30);    

	// note the casting...  
	cout << "p1 (255, 255, 255): " << (int) p1.red() << ' ' << (int) p1.green() 
		  << ' ' << (int) p1.blue() << '\n';  
	cout << "p2 (10, 20, 255): " << (int) p2.red() << ' ' << (int) p2.green() 
		  << ' ' << (int) p2.blue() << '\n';  
	cout << "p3 (10, 20, 30): " << (int) p3.red() << ' ' << (int) p3.green() 
		  << ' ' << (int) p3.blue() << '\n';  

	cout << "======== setRed, setGreen, setBlue tests ======== \n";  
	bool first = p1.setRed(18);  
	bool second = p1.setGreen(-20);  
	bool third = p1.setBlue(270);  
	cout << "p1 (18, 0, 255): " << (int) p1.red() << ' ' << (int) p1.green() 
		  << ' ' << (int) p1.blue() << '\n';  
	cout << "results of the set functions (1, 0, 0) " << first << ' '  
		  << second << ' ' << third << '\n';  
	
	cout << "================= grayscale test ================ \n";  
	cout << "p3 (18): " << (int) p3.grayscale() << '\n';  
	
	cout << "================== output tests ================= \n";  
	cout << "p1: " << p1 << '\n';  
	cout << "p2: " << p2 << '\n';  
	cout << "p3: " << p3 << '\n';  

	cout << "=================== logic tests ================= \n";  
	cout << "p1 == p2: " << (p1 == p2) << '\n';  
	cout << "p1!== p2: " << (p1 != p2) << '\n';  
	cout << "p1 == p1: " << (p1 == p1) << '\n';  

	cout << "=============== operator+ tests ================= \n";  
	cout << "p1 + p2: " << p1 + p2 << '\n';  
	cout << "p2 + p3: " << p2 + p3 << '\n';  
	cout << "p1 + p2 + Pixel(255, 255, 255): " << p1 + p2 + Pixel(255, 255, 255)
		  << '\n';  

	cout << "============== output tests again =============== \n";  
	cout << "p1: " << p1 << '\n';  
	cout << "p2: " << p2 << '\n';  
	cout << "p3: " << p3 << '\n';


	cout << "\n\n============= Pixel List Class Test ============= \n";
	cout << "========= constructor and accessor tests ======== \n";  
	PixelList pl1;  
	PixelList pl2(p2);  
	PixelList pl3(pl2);    
 
	cout << "pl1 (): " << pl1 << " 			size (0): " << pl1.size() << '\n';
	cout << "pl2 (p2): " << pl2 << " 	size (1): " << pl2.size() << '\n'; 
	cout << "pl3 (pl2): " << pl3 << " 	size (1): " << pl3.size() << '\n'; 

	cout << "============== Appending Elements =============== \n"; 
	pl1.append(Pixel(8, 8, 8));
	cout << "pl1 (8, 8, 8): 		" << pl1 << "	 		size (1): " << pl1.size() << '\n';
	pl1.append(p1);
	cout << "pl1 [...(18, 0, 255)]: 	" << pl1 << "	size (2): " << pl1.size() << '\n';

	pl2.append(p1);
	cout << "pl2 [...(18, 0, 255)]: 	" << pl2 << " 	size (2): " << pl2.size() << '\n'; 

	cout << "============== Assignment Operator ============== \n";
	pl2 = pl1;
	cout << "pl2 (pl1): 		" << pl2 << " 	size (2): " << pl2.size() << '\n';

	cout << "=============== operator+ tests ================= \n"; 
	cout << "pl1 + pl2: " << pl1 + pl2 << '\n';  
	cout << "pl2 + pl3: " << pl2 + pl3 << '\n';  
	cout << "pl1 + pl2 + Pixel(255, 255, 255): " << pl1 + pl2 + Pixel(255, 255, 255)
		  << '\n';
	cout << "pl1 + Pixel(255, 255, 255)+ pl2: " << pl1 + Pixel(255, 255, 255) + pl2
		  << '\n';

	cout << "=================== logic tests ================= \n";  
	cout << "pl1 == pl2: " << (pl1 == pl2) << '\n';  
	cout << "pl1!== pl2: " << (pl1 != pl2) << '\n';  
	cout << "pl1 == pl1: " << (pl1 == pl1) << '\n'; 
	cout << "pl1 == Pixel(255, 255, 255): " << (pl1 == Pixel(255, 255, 255)) << '\n';
	cout << "Pixel(255, 255, 255) !== pl1: " << (Pixel(255, 255, 255) != pl1) << '\n';

	cout << "================ destructor tests =============== \n";
	cout << "pl1 (): 	" << pl1 << "	size (2): " << pl1.size() << '\n';
	cout << "pl2 (p2): 	" << pl2 << " 	size (2): " << pl2.size() << '\n'; 
	cout << "pl3 (pl2): 	" << pl3 << " 		size (1): " << pl3.size() << '\n';

	pl1.~PixelList();
	pl2.~PixelList();
	pl3.~PixelList();
	//delete(pl3);
	/*pl1.delete();
	pl2.delete();
	pl3.delete();*/

	cout << "~pl1: " << pl1 << " 	size: " << pl1.size() << '\n';
	cout << "~pl2: " << pl2 << " 	size: " << pl2.size() << '\n'; 
	cout << "~pl3: " << pl3 << " 	size: " << pl3.size() << '\n';
	
	return 0;  
}  