#include "ChemicalPartition.h"


int ChemicalPartition::size()
{
    return _formulas.size();
}

void ChemicalPartition::addFormula(Eigen::Matrix<double, ELEMENTS, 1> formula)
{
    _formulas.push_back(formula);
} 

void ChemicalPartition::addElement(int elementNum, int amount)
{
    Eigen::Matrix<double, ELEMENTS, 1> formula = Eigen::Matrix<double, ELEMENTS, 1>::Zero(ELEMENTS, 1); //zero the vector
    formula[elementNum] = (double)amount;

    _formulas.push_back(formula);
}

Eigen::MatrixXd ChemicalPartition::getMatrix(int size, int lhsSize, bool isRhs)
{
    Eigen::MatrixXd matrix;
    matrix.resize(ELEMENTS, size);

    matrix = Eigen::MatrixXd::Zero(ELEMENTS, size);

    if(!isRhs)
    {
        for(int i = 0; i < _formulas.size(); i++)
        {
            matrix.col(i) = _formulas[i];
        }
    }
    else
    {
        for(int i = lhsSize; i < size; i++)
        {
            matrix.col(i) = _formulas[i-lhsSize];
        }
    }

    return matrix;
}