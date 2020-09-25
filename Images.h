//Images.h
//Author: Andrew Choi
//Purpose: Header file for Images.cpp. Contains all the
//         methods in the public section of the class and
//         the local variable in the private section
#ifndef Images_H
#define Images_H
#include "ImageLib.h"

class Images
{
public:
//Images:Constructor using a filename (read from a file)
//Precondition:input exists and is a valid GIF image
//Postcondition:Reads from file and stores image in temp
	Images(string input);


//Images:Overload constructor using just the number of rows
//       and columns
//Precondition:input row and col must be non-negative
//Postcondition:Creates a blank black image from inputs
	Images(int row, int col);


//Images:Copy Constructor that calls CopyImage from 
//        ImageLib.h to create copy of instance
//Precondition:Input exists and contains a valid image 
//Postcondition:Copy of input(input) is made
	Images(const Images &input);


//Operator=:Equal overload that sets inut to temp
//Precondition:obj contains a valid image(non-negative
//             amount of rows and columns)
//Postcondition: Sets input data to current classes data
	Images operator = (Images obj);


//~Images:Destructor for the class. Calls DeallocateImage from
//        ImageLib.h and deallocates image
//Precondition: temp must contain a valid image, containing
//              rows,columns and pixels.
	~Images();
	

//getRow:Returns the number of rows that the image contains
//Preconditon:Temp is a valid image containing a non-negative 
//            amount of rows
//Postcondition:Returns the number of rows that the image 
//              contains
	int getRow()const;


//getCol:Returns the number of columns that the image contains
//Precondition: Temp is a valid image containing a non-negative 
//            amount of rows
 //Postconditions:Returns the number of columns that the image 
//              contains
	int getCol() const;


//setPixel:Sets the pixels of temp
//Preconditions:Bytes of pix, row and col should be non-negative
//              Pix should contain green,red and blue component
//Postcondition:Green, red and blue byte of pixel (input) should be 
//              set to the input at the given row and col input
	void setPixel(pixel& input, int rows, int columns);


//getPixel:Gets the pixel at input location
//Precondition:Input rows(row) and columns(col) must
//             not exceed the bounds of the image(temp)
//Postcondition:Returns the pixel at the given row and
//              column input.
	pixel getPixel( int row, int col) const;


//outputFile:Outputs the image to the inputed file name
//Precondition:Inuput(file) is a valid string file
//Postcondition: Calls WriteGIF from ImageLib.h and
//               outputs file to name of the file
	void outputFile(string file);


//operator ==: Overload opertor for == comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if inputed image from object 
//              is the same as current image(temp)
	bool operator == (const Images & obj)const;


//operator !=: Overload opertor for != comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if inputed image from object 
//              is not the same as current image(temp)
	bool operator != (const Images& obj)const;


//operator <: Overload opertor for < comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if current image is
//              less (smaller dimensions or amount of pixels)
//              than inputted image (obj)
	bool operator < (const Images& obj)const;


//operator >: Overload opertor for > comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if current image is
//              greater(larger dimensions or amount of pixels)
//              than inputted image (obj)
	bool operator > (const Images& obj)const;


//operator<<: Overloads << for cout
//Precondition:Input(input) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postconditions:Overload the << operator to output the number 
//               of rows and columns in the image. Returns ostream
	friend ostream& operator <<(ostream & os,const Images&);


//mirrorImage():Creates a mirrored image of temp
//Precondition:Input(input) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns a  mirror-image of the original image
	Images mirrorImage();

private:
//Variable to store the image of the file read in
	image temp;
};

#endif