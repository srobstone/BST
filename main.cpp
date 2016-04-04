#include "BST.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include<string>

/**
 *  IMPORTANT!! YOU MUST USE THE FOLLOWING LINES OF CODE FOR PROMPTS AND OUTPUTS:
 *  To output size of tree: cout << "Size of tree: " << size << "\n";
 *  To output height of tree: cout << "Height of tree: " << height << "\n";
 *  To prompt the user to enter a name: cout << "Enter actor/actress name: " << "\n";
 *  To tell the user that actor/actress name was found: cout << name << " found!" << "\n";
 *  To tell the user that actor/actress name was NOT found: cout << name << " NOT found" << "\n";
 *  To prompt the user to try again: cout << "Search again? (y/n)" << "\n";
 *
 *  Use cin to process user input.
 *
 *  You MUST output size, then height, then prompt the user to search, as above.
 *
 *  You MUST have the prompt for entering the name appear if and only if 
 *  the user input for trying again is "y" followed by the return key
 *  You MUST have the program exit (exiting the prompt loop) if and only if
 *  the user input for trying again is "n" followed by the return key
 *  You should handle other inputs for the retry prompt, 
 *  but we will not be testing them.
 *
 *  Note that size, height, and name are local variables in main that you 
 *  should update accordingly. Also note that actor/actress names will be 
 *  in all caps, last name followed by first name 
 *  (except in odd cases, eg. "50 CENT" and "ICE-T")
*/

using namespace std;

int main(int argc, char* argv[])
{
	//Size of tree should be stored in local variable size.
	//Height of tree should be stored in local variable height.
	//Input name will be stored in a string name
	unsigned int size = 0;
	unsigned int height = 0;
	std::string name = "";

	//Check for Arguments
	if(argc != 2){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./main <input filename>.\n";
		return -1;
	}

	//Open file 
	ifstream in;
	in.open(argv[1], ios::binary);

	//Check if input file was actually opened
	if(!in.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}

	//Check for empty file
	in.seekg(0, ios_base::end); 
	unsigned int len = in.tellg();
	if(len==0) 
	{
		cout << "The file is empty. \n";
		return -1;
	}

	//Resets the stream to beginning of file
	in.seekg(0, ios_base::beg); 

	//TODO 
	//main function implementation should go here
    //create the BST to hold everything

    BST<string> b;

    while(in.peek() != EOF){
      getline(in, name);
      b.insert(name);       
    }
    
    size = b.size(); 
    cout << "Size of tree: " << size << "\n"; 

    height = b.height();
    cout << "Height of tree: " << height << "\n";

    while(1){
      cout << "Enter actor/actress name: " << "\n"; 
      getline(cin, name);

      cout << "The name to search is: " << name << endl;
 
      BST<string>::iterator toFind = b.find(name);
      //cout << "toFind value is: " << *toFind << endl;

      
      if( toFind != 0 )
        cout << name << " found!" << "\n";

      else
        cout << name << " NOT found" << "\n";

      cout << "Search again? (y/n)" << "\n";

      string toCont = "";
      cin >> toCont;
    
      if( toCont == "n" )
        break; 

    }  
    
    /* 
    BST<string>::iterator en = b.end();
    BST<string>::iterator it = b.begin();
    for(; it != en; ++it){
      cout << *it << endl;
    }    
    */
     
	if(in.is_open())
	{
		in.close();
	}


	return 0;
}
