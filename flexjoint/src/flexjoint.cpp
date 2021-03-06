//============================================================================
// Name        : flexjoint.cpp
// Author      : Minh nha pham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

double h = 0.001;
double I,mgl,k,N,J,B;
double t[10001];
double q1[10001], q2[10001], z1[10001],z2[10001];
double k_0,k_1,k_2,k_3,l_0,l_1,l_2,l_3,m_0,m_1,m_2,m_3,n_0,n_1,n_2,n_3;

double f(double z1)  //dq1dt
{
double result;
result = z1;
return (result);
}

double g(double q1, double q2)  //dz1dt
{
double result;
result = -0.0512820512820513*k*(q1-0.00625*q2)-0.0512820512820513*mgl*sin(q1);
return (result);
}

double x(double z2)  //dq2dt
{
double result;
result = z2;
return (result);
}

double y(double q1, double q2, double z2)   //dz2dt
{
double result;
result = -3.125e3*B*z2+k*19.53125*(q1-0.00625*q2);
return (result);
}

int main() {

	I = 19.5;
	J = 320e-6;
	mgl = 213.6618;
	k = 121e3;
	B = 0.0011;
	N = 160;

	q1[0] = 0.1;


	for (int i=0;i<10001;i++)
	{
	t[i]=i*h;
//	x[i]=0;
//	cout << t[i] << endl;
	}



	for (int i=0;i<10001;i++)
		{
	    k_0 = h*f(z1[i]);
	    l_0 = h*g(q1[i],q2[i]);
	    m_0 = h*x(z2[i]);
	    n_0 = h*y(q1[i],q2[i],z2[i]);

	    k_1 = h*f(z1[i]+0.5*l_0);
	    l_1 = h*g(q1[i]+0.5*k_0,q2[i]+0.5*m_0);
	    m_1 = h*x(z2[i]+0.5*n_0);
	    n_1 = h*y(q1[i]+0.5*k_0,q2[i]+0.5*m_0,z2[i]+0.5*n_0);

	    k_2 = h*f(z1[i]+0.5*l_1);
	    l_2 = h*g(q1[i]+0.5*k_1,q2[i]+0.5*m_1);
	    m_2 = h*x(z2[i]+0.5*n_1);
	    n_2 = h*y(q1[i]+0.5*k_1,q2[i]+0.5*m_1,z2[i]+0.5*n_1);

	    k_3 = h*f(z1[i]+l_2);
	    l_3 = h*g(q1[i]+k_2,q2[i]+m_2);
	    m_3 = h*x(z2[i]+n_2);
	    n_3 = h*y(q1[i]+k_2,q2[i]+m_2,z2[i]+n_2);

	    q1[i+1] = q1[i] + 0.1666666666666667*(k_0+2*k_1+2*k_2+k_3);
	    z1[i+1] = z1[i] + 0.1666666666666667*(l_0+2*l_1+2*l_2+l_3);
	    q2[i+1] = q2[i] + 0.1666666666666667*(m_0+2*m_1+2*m_2+m_3);
	    z2[i+1] = z2[i] + 0.1666666666666667*(n_0+2*n_1+2*n_2+n_3);



	    // save to file-------------------------------------------------------
	        ofstream outfile;
	        outfile.open("afile.txt", std::ios_base::app); // append to a file
	        outfile << t[i] << '\t'<< q1[i] << '\t'<< q2[i]<< '\t'<< z1[i] << '\t'<< z2[i] << endl;
	        outfile.close();
	    //--------------------------------------------------------------------


		}

//	cout << sizeof(z)/sizeof(z[0]) << endl;


	cout << "finish" << endl; // prints !!!Hello World!!!
	return 0;
}

/*
// save to file-------------------------------------------------------
    ofstream outfile;
    outfile.open("afile.txt", std::ios_base::app); // append to a file
    outfile << t[i] << '\t'<< y[i] << '\t' << z[i] << endl;
    outfile.close();
//--------------------------------------------------------------------
*/
