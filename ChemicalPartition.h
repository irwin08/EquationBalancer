#include <iostream>
#include <vector>
#include <Eigen/dense>

#define ELEMENTS 144

class ChemicalPartition
{
    public:

        int size();
        void addFormula(Eigen::Matrix<double, ELEMENTS, 1> formula);
        void addElement(int elemenNum, int amount);
        Eigen::MatrixXd getMatrix(int size, int lhsSize, bool isRhs=false);
    private:

        std::vector<Eigen::Matrix<double, ELEMENTS, 1>> _formulas;

};