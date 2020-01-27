#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//FUNCTIONS--------------------------------------------------------

//contains " fill='rgb(r, g, b)'/>"
void fill(ofstream& output) {
	output << " fill='rgb(" << rand() % 256 << "," << rand() % 256 << "," << rand() % 256 << ")'/>" << endl;
}

void rect(ofstream& output, double size, double shapespace) {
	for (double x = 0; x < size; x += shapespace) {
		for (double y = 0; y < size; y += shapespace) {
			output << "<rect x='" << x << "' y='" << y << "' width='" << shapespace << "' height='" << shapespace << "'";
			fill(output);
		}
	}
}

void circle(ofstream& output, double size, double shapespace) {
	for (double x = shapespace / 2; x < size; x += shapespace) {
		for (double y = shapespace / 2; y < size; y += shapespace) {
			output << "<circle cx='" << x << "' cy='" << y << "' r='" << shapespace / 2 << "'";
			fill(output);
		}
	}
}

void triangle(ofstream& output, double size, double shapespace, bool isUp) {

	if (isUp) {
		for (double x1 = 0; x1 < size; x1 += shapespace) {
			for (double Y1 = 0; Y1 < size; Y1 += shapespace) {
				output << "<polygon points='" << x1 << "," << Y1 + shapespace << " " << x1 + shapespace << "," << Y1 + shapespace << " " << x1 + shapespace / 2 << "," << Y1 << "'";
				fill(output);
			}
		}
	}
	else {
		for (double x1 = 0; x1 < size; x1 += shapespace) {
			for (double Y1 = 0; Y1 < size; Y1 += shapespace) {
				output << "<polygon points='" << x1 << "," << Y1 << " " << x1 + shapespace << "," << Y1 << " " << x1 + shapespace / 2 << "," << Y1 + shapespace << "'";
				fill(output);
			}
		}
	}
}

void background(ofstream& output, double x, string color, double size) {
	output << "<svg xmlns='http://www.w3.org/2000/svg'"
		<< " width=\"" << x << "\" height=\"" << x << "\" version=\"1.1\">"
		<< endl;

	if (color == "red" || color == "Red") {
		output << "<rect x='0' y='0' width='" << x << "' height='" << x << "' fill='rgb(255,0,0)'/>" << endl;
	}
	else if (color == "green" || color == "Green") {
		output << "<rect x='0' y='0' width='" << x << "' height='" << x << "' fill='rgb(0,255,0)'/>" << endl;
	}
	else if (color == "blue" || color == "Blue") {
		output << "<rect x='0' y='0' width='" << x << "' height='" << x << "' fill='rgb(0,0,255)'/>" << endl;
	}
	else if (color == "white" || color == "White") {
		output << "<rect x='0' y='0' width='" << x << "' height='" << x << "' fill='rgb(255,255,255)'/>" << endl;
	}
	else if (color == "black" || color == "Black") {
		output << "<rect x='0' y='0' width='" << x << "' height='" << x << "' fill='rgb(0,0,0)'/>" << endl;
	}
}

void generateSVG(double x, string color, double size, int shapeType, double shapespace) {
	ofstream output;
	output.open("art.svg");

	int randNum;

	background(output, x, color, size);

	if (shapeType == 1) {
		rect(output, size, shapespace);
	}
	if (shapeType == 2) {
		circle(output, size, shapespace);
	}
	if (shapeType == 3) {
		triangle(output, size, shapespace, true);
	}
	if (shapeType == 4) {
		triangle(output, size, shapespace, false);
	}
	if (shapeType == 5) {
		for (double x1 = 0; x1 < size; x1 += shapespace) {
			for (double y1 = 0; y1 < size; y1 += shapespace) {
				randNum = rand() % 4 + 1;
				if (randNum == 1) {
					output << "<rect x='" << x1 << "' y='" << y1 << "' width='" << shapespace << "' height='" << shapespace << "'";
				}
				else if (randNum == 2) {
					output << "<circle cx='" << x1 + shapespace / 2 << "' cy='" << y1 + shapespace / 2 << "' r='" << shapespace / 2 << "'";
				}
				else if (randNum == 3) {
					output << "<polygon points='" << x1 << "," << y1 + shapespace << " " << x1 + shapespace << "," << y1 + shapespace << " " << x1 + shapespace / 2 << "," << y1 << "'";
				}
				else if (randNum == 4) {
					output << "<polygon points='" << x1 << "," << y1 << " " << x1 + shapespace << "," << y1 << " " << x1 + shapespace / 2 << "," << y1 + shapespace << "'";
				}
				fill(output);
			}
		}
	}

	if (shapeType == 6) {
		for (double x1 = 0; x1 < size; x1 += shapespace) {
			for (double y1 = 0; y1 < size; y1 += shapespace) {
				randNum = rand() % 5 + 1;
				if (randNum == 1) {
					output << "<rect x='" << x1 << "' y='" << y1 << "' width='" << shapespace << "' height='" << shapespace << "'";
				}
				else if (randNum == 2) {
					output << "<circle cx='" << x1 + shapespace / 2 << "' cy='" << y1 + shapespace / 2 << "' r='" << shapespace / 2 << "'";
				}
				else if (randNum == 3) {
					output << "<polygon points='" << x1 << "," << y1 + shapespace << " " << x1 + shapespace << "," << y1 + shapespace << " " << x1 + shapespace / 2 << "," << y1 << "'";
				}
				else if (randNum == 4) {
					output << "<polygon points='" << x1 << "," << y1 << " " << x1 + shapespace << "," << y1 << " " << x1 + shapespace / 2 << "," << y1 + shapespace << "'";
				}
				fill(output);
			}
		}
	}

	output << "</svg>" << endl;
	output.close();
}

int main() {
	cout << "_____________________________" << endl;
	cout << "|      Ethan McCrary's    v.|" << endl;
	cout << "|      Shape Generator    1 |" << endl;
	cout << "|___________________________|" << endl << endl;
	cout << "-------------------------------" << endl << endl;

	double size;
	double shapes;
	int shapeType;
	string backgroundColor;
	ofstream output;
	srand(time(NULL));

	cout << "Enter the image size: ";
	cin >> size;

	cout << "Enter the number of shapes per row/column: ";
	cin >> shapes;

	cout << "Enter the background color:" << endl
		<< "Red" << endl
		<< "Green" << endl
		<< "Blue" << endl
		<< "White" << endl
		<< "Black" << endl;
	cin >> backgroundColor;

	cout << "Enter the shape(s) to use: " << endl
		<< "1 - Square" << endl
		<< "2 - Circle" << endl
		<< "3 - Up Triangle" << endl
		<< "4 - Down Triangle" << endl
		<< "5 - All Shapes" << endl
		<< "6 - All Shapes with Blanks" << endl;
	cin >> shapeType;

	double shapeSpace = size / shapes;

	generateSVG(size, backgroundColor, size, shapeType, shapeSpace);

	return 0;
}