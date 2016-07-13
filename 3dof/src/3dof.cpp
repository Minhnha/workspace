//============================================================================
// Name        : 3dof.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <boost/numeric/odeint.hpp>


using namespace std;
using namespace boost::numeric::odeint;


/* we solve the simple ODE x' = 3/(2t^2) + x/(2t)
 * with initial condition x(1) = 0.
 * Analytic solution is x(t) = sqrt(t) - 1/t
 */

void rhs( const double x , double &dxdt , const double t )
{
    dxdt = 3.0/(2.0*t*t) + x/(2.0*t);
}
char data[100];
void write_cout( const double &x , const double t )
{
    cout << t << '\t' << x << endl;

// save to file-------------------------------------------------------
    ofstream outfile;
    outfile.open("afile.txt", std::ios_base::app); // append to a file
    outfile << t << '\t'<< x << endl;
    outfile.close();
//--------------------------------------------------------------------
}

// state_type = double
typedef runge_kutta_dopri5< double, double, double,double, vector_space_algebra > stepper_type;

int main()
{
    double x = 0.0;
    integrate_adaptive( make_controlled( 1E-12 , 1E-12 , stepper_type() ) ,
                        rhs , x , 1.0 , 10.0 , 0.1 , write_cout );



   // char data[100];
    // open file in write mode

/*    ofstream outfile;
    outfile.open("afile.dat");
    cout << "Writing to the file" << endl;
    cin.getline(data,100);
    outfile << data << endl;
    outfile.close();*/

    // Open file in read mode
/*
    ifstream infile;
    infile.open("afile.dat");
    cout << "Reading from file"<<endl;
    infile >> data;
    cout << data<<endl;
    infile.close();
    */

}
