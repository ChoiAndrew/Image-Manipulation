//Images.cpp
//Author: Andrew Choi
//Purpose: Implementation class representing images. 
//         This image class has the following capabilities,
//         overloaded constructors, accessors/mutators
//		   for dimensions and pixels, outputs to file, 
//         creates/returns a mirror image and overloaded operators. 


#include "Images.h"
#include "ImageLib.h"
#include <iostream>  

using namespace std;

//Images:Constructor using a filename (read from a file)
//Precondition:fileName exists and is a valid GIF image
//Postcondition:Reads from file and stores image in temp
Images::Images(string fileName)
{
	temp = ReadGIF(fileName);
	if (temp.rows == 0) 
		cout << "Unable to open file: test.gif" << endl;
}

//Images:Overload constructor using just the number of rows
//       and columns
//Precondition:input row and col must be non-negative
//Postcondition:Creates a blank black image from inputs
Images::Images(int row, int col)
{
		image newImage = CreateImage(row, col);
}

//Images:Copy Constructor that calls CopyImage from 
//        ImageLib.h to create copy of instance
//Precondition:Input exists and contains a valid image 
//Postcondition:Copy of input(newobj) is made
Images::Images(const Images &newObj)
{
	temp = CopyImage(newObj.temp);
}

//Operator=:Equal overload that sets inut to temp
//Precondition:obj exist andc contains a valid image
//             (non-negative amount of rows and columns)
//Postcondition: Sets input data to current classes data
Images Images::operator=(const Images obj)
{
	DeallocateImage(this->temp);
	*this = obj;
	return *this;
}

//~Images:Destructor for the class. Calls DeallocateImage from
//        ImageLib.h and deallocates image
//Precondition: temp must contain a valid image, containing
//              rows,columns and pixels.
Images::~Images()
{
	DeallocateImage(this->temp);
}

//getRow:Returns the number of rows that the image contains
//Preconditon:Temp is a valid image containing a non-negative 
//            amount of rows
//Postcondition:Returns the number of rows that the image 
//              contains
 int Images::getRow() const
{
	return temp.rows;
}

//getCol:Returns the number of columns that the image contains
//Precondition: Temp is a valid image containing a non-negative 
//            amount of rows
 //Postconditions:Returns the number of columns that the image 
//              contains
int Images::getCol() const
{
	return temp.cols;
}

//setPixel:Sets the pixels of temp
//Preconditions:Bytes of pix, row and col should be non-negative
//              Pix should contain green,red and blue component
//Postcondition:Green, red and blue byte of pixel (pix) should be 
//              set to the input at the given row and col input
void Images::setPixel(pixel& pix, int row, int col)
{
	temp.pixels[row][col].green = pix.green;
	temp.pixels[row][col].blue = pix.blue;
	temp.pixels[row][col].red = pix.red;
}

//getPixel:Gets the pixel at input location
//Precondition:Input rows(row) and columns(col) must
//             not exceed the bounds of the image(temp)
//Postcondition:Returns the pixel at the given row and
//              column input.
pixel Images::getPixel(int row, int col)const 
{
	return temp.pixels[row][col];
}

//outputFile:Outputs the image to the inputed file name
//Precondition:Inuput(file) is a valid string file
//Postcondition: Calls WriteGIF from ImageLib.h and
//               outputs file to name of the file
void Images::outputFile(string file)
{
	WriteGIF(file,temp);
}

//operator ==: Overload opertor for == comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if inputed image from object 
//              is the same as current image(temp)
bool Images::operator == (const Images & obj)const
{
	bool tempbool = true;
	if (temp.rows != obj.getRow() && temp.cols != obj.getCol())
		return false;
	for(int row = 0; row < temp.rows; row++)
		{
		for (int col = 0; col < temp.cols; col++)
			{
				if (temp.pixels[row][col].red != obj.getPixel(row, col).red)
					return false;
				if (temp.pixels[row][col].green != obj.getPixel(row, col).green)
					return false;
				if (temp.pixels[row][col].blue != obj.getPixel(row, col).blue)
					return false;
			}
		}
	return tempbool;
}

//operator !=: Overload opertor for != comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if inputed image from object 
//              is not the same as current image(temp)
bool Images::operator != (const Images & obj)const
{
	bool tempbool = false;
	for (int row = 0; row < temp.rows; row++)
	{
		for (int col = 0; col < temp.cols; col++)
		{
			if (temp.pixels[row][col].red != obj.getPixel(row, col).red)
				return true;
			if (temp.pixels[row][col].green != obj.getPixel(row, col).green)
				return true;
			if (temp.pixels[row][col].blue != obj.getPixel(row, col).blue)
				return true;
		}
	}
	return tempbool;
}

//operator <: Overload opertor for < comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if current image is
//              less (smaller dimensions or amount of pixels)
//              than inputted image (obj)
bool Images::operator < (const Images & obj)const
{
	int image1 = temp.rows * temp.cols;
	int image2 = obj.getRow() * obj.getCol();
	if (image1 < image2)
		return true;
	else
		return false;
}

//operator >: Overload opertor for > comparison
//Precondition:Input(obj) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns boolean to check if current image is
//              greater(larger dimensions or amount of pixels)
//              than inputted image (obj)
bool Images::operator > (const Images & obj)const
{
	int image1 = temp.rows * temp.cols;
	int image2 = obj.getRow() * obj.getCol();
	if (image1 > image2)
		return true;
	else
		return false;
}

//operator<<: Overloads << for cout
//Precondition:Input(input) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postconditions:Overload the << operator to output the number 
//               of rows and columns in the image. Returns ostream
ostream & operator <<(ostream & os, const Images & input )
{
	int col = input.getCol();
	int row = input.getRow();
	os << "Rows: " << row << " " << "Columns :" <<  col;
	return os;
}

//mirrorImage():Creates a mirrored image of temp
//Precondition:Input(input) contains a valid image containing
//             non-negative rows, columns and pixels with byes
//             within bounds (0-255)
//Postcondition:Returns a  mirror-image of the original image
Images Images:: mirrorImage()
{
	Images tempImage(*this);
	//cout << this << " " << &tempImage << endl;
		for (int row = 0; row < tempImage.getRow(); row++)
			for (int col = 0; col < tempImage.getCol() / 2; col++)
			{

				int swapCol = tempImage.getCol() - col - 1;
				pixel temporary = tempImage.getPixel(row,col);
				pixel name = tempImage.getPixel(row, swapCol);
				tempImage.setPixel(name, row, col);
				tempImage.setPixel(temporary,row,swapCol);
	         }

		return tempImage;
}
