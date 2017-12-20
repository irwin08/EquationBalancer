#include <Eigen/dense>
#include "ChemicalPartition.h"


class ChemicalEquation
{
    public:

        ChemicalEquation(ChemicalPartition lhs, ChemicalPartition rhs);

        Eigen::VectorXd solve();

    private:

        ChemicalPartition _lhs;
        ChemicalPartition _rhs;

        Eigen::MatrixXd _matrixForm;
};