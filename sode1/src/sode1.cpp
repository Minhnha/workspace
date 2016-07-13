//============================================================================
// Name        : sode1.cpp
// Author      : Minh nha pham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

float h = 0.1;
float t[92];
float x[92];
float k_1,k_2,k_3,k_4;

float ode1(float t, float x)
{
float result;
result = 3/(2*t*t)+x/(2*t);
return (result);
}

int main() {
	cout << "start.." << endl; // prints !!!Hello World!!!


	for (int i=1;i<93;i++)
	{
	t[i]=(i-1)*h+1;
//	x[i]=0;
	}


//	float result;
//	result = ode1(1,1);
//	cout << result << endl;

	for (int i=1;i<93;i++)
		{
	    k_1 = h*ode1(t[i],x[i]);

	    k_2 = h*ode1(t[i]+0.5*h,x[i]+0.5*k_1);

	    k_3 = h*ode1((t[i]+0.5*h),(x[i]+0.5*k_2));

	    k_4 = h*ode1((t[i]+h),(x[i]+k_3));

	    x[i+1] = x[i] + 0.16667*(k_1+2*k_2+2*k_3+k_4);

		// save to file-------------------------------------------------------
		    ofstream outfile;
		    outfile.open("afile.txt", std::ios_base::app); // append to a file
		    outfile << t[i] << '\t'<< x[i] << endl;
		    outfile.close();
		//--------------------------------------------------------------------


		}

//	cout << x[90] << endl;


	cout << "finish" << endl; // prints !!!Hello World!!!
	return 0;
}
