#include <iostream>
#include <Eigen/dense>
#include "ChemicalEquation.h"

using namespace std;
using namespace Eigen;
int main()
{

    ChemicalPartition lhs;
    ChemicalPartition rhs;

    lhs.addElement(11, 1);
    lhs.addElement(17, 2);

    

    Matrix<double, ELEMENTS, 1> rhsVector;
    rhsVector = MatrixXd::Zero(ELEMENTS, 1);

    
    rhsVector(11, 0) = 1;
    rhsVector(17, 0) = 1;
    

    rhs.addFormula(rhsVector);

    ChemicalEquation ceq = ChemicalEquation(lhs, rhs);


    cout << "The solution is:\n" << ceq.solve() << endl;
}