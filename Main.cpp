//Main.cpp
//Author: Andrew Choi
//Purpose: Main class acts as a driver and 
//         includes a few modified methods from 
//         previous assignment(program1) such as
//         modify, compare and modify pixel
#include <iostream>
#include "Images.h"

// modifyPixel: Changes the red and blue components of a single pixel
// Precondition: row and column must be non-negative
//Postcondition: The blue component will be subtracted by % 7 in each row 
//               while the red component will be added by % 9 for each column
void modifyPixel(pixel& p, int row, int column)
{
	//Invarient to check over and underflow
	if (p.blue < 0)
		p.blue = 0;
	if (p.blue > 255)
		p.blue = 255;
	p.blue = p.blue - row % 7;

	if (p.red < 0)
		p.red = 0;
	if (p.red > 255)
		p.red = 255;
	p.red = p.red + column % 9;
}

//modify: modifies the image from input Images(input) to 
//         subtract each row by % 7 for the blue component
//         while adding % 9 to red for each column
//Precondition:The image inpuitted from Images(input) has input.rows 
//             and input.column pixels allocated
//Postcondition: The image from input is modified to subtract 
//               each row by % 7 for the blue component while 
//               adding %9 to red for each column
void modify(Images input) {
	pixel name;
	for (int row = 0; row < input.getRow(); row++)
		for (int col = 0; col < input.getCol(); col++)
		{
			name = input.getPixel(row, col);
			modifyPixel(name, row, col);
		}
}

// compare: Compares each pixel to determine the number of 
//			differences in the input image
// Precondition:Both images from Images have rows and columns 
//              allocated. Images must have the same dimensions.
// Postcondition: Returns the number of differences (count) in
//				  the image. Count increases by one if pixels have 
//				  a different value in red, green, or blue 
int compare(Images in, Images secIn)
{
	//Checks red, green, and blue component for differences
	int count = 0;
	//returns count after comparing each value
	for (int row = 0; row < in.getRow(); row++)
	{
		for (int col = 0; col < in.getCol(); col++)
		{
			if (in.getPixel(row,col).red != secIn.getPixel(row, col).red)
				count++;

			else if (in.getPixel(row, col).blue != secIn.getPixel(row, col).blue)
				count++;

			else if (in.getPixel(row, col).green != secIn.getPixel(row, col).green)
				count++;

			else
				count = count;
		}
	}
	return count;
}

//main: Test code written in Images.cpp
//Precondition: Images.cpp class exists and has 
//              appropriate methods  
//Postconditions: Test the capabilities stated in the
//               assignment. Reads in image, output dimensions
//               create mirror image, modify pixels, compare
//               images and outputs differences.        
int main()
{
	Images newImage("test2.gif");
	cout << newImage << endl;

	Images reflectedIm = newImage.mirrorImage();
	modify(reflectedIm);
	
	
	reflectedIm.outputFile("output.gif");
	Images modImage("output.gif");
	int sameImage = (newImage == modImage);
	cout << "Same Image(True:1, False:0) " << sameImage << endl;
	int numDif = -1;
	if(sameImage != 1)
	  numDif = compare(modImage, newImage);
	cout << "Number of Differences: " << numDif;
	
	return 0;
}


