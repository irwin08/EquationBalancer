#include "ChemicalEquation.h"

ChemicalEquation::ChemicalEquation(ChemicalPartition lhs, ChemicalPartition rhs)
{
    _lhs = lhs;
    _rhs = rhs;

    _matrixForm.resize(ELEMENTS, (_lhs.size() + _rhs.size()));  

    std::cout << "LHS size: " << _lhs.size() << std::endl;
    std::cout << "RHS size: " << _rhs.size() << std::endl;

    std::cout << "LHS Rows: " << _lhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size()).rows() << std::endl;
    std::cout << "LHS Cols: " << _lhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size()).cols() << std::endl;
    std::cout << "RHS Rows: " << _rhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size(), true).rows() << std::endl;
    std::cout << "RHS Cols: " << _rhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size(), true).cols() << std::endl;
  
    _matrixForm = (_lhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size()) - _rhs.getMatrix((_lhs.size() + _rhs.size()), _lhs.size(), true));
}

Eigen::VectorXd ChemicalEquation::solve()
{
    Eigen::VectorXd zero;
    zero = Eigen::VectorXd::Zero(ELEMENTS);

    std::cout << "The matrix is: " << std::endl << _matrixForm << std::endl;

    Eigen::VectorXd solution = _matrixForm.fullPivLu().kernel();

    return solution;
}