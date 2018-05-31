/*
 *   This suppoerts a solver for continuation/GMRES(C/GMRES) method for nonlinear model predictive control
 *   This program is witten with reference to "T. Ohtsuka, "
 */

#ifndef CONTINUATION_GMRES_H
#define CONTINUATION_GMRES_H

#include <eigen3/Eigen/Core>
#include "matrixfree_gmres.h"

class continuation_gmres : public matrixfree_gmres{
private:
    int dimx, dimu, dv, dimeq, i_max;
    double hdir, dtau, rho;
    Eigen::MatrixXd x, lmd;
    Eigen::VectorXd u, u1, hu, hu1, du;
public:
    continuation_gmres(const int dim_x, const int dim_u, const int division_num, const double h_dir, const double rho, const int k_max, const double T_f, const double alpha, const double zeta) : matrixfree_gmres(dim_u * (division_num-1), k_max);
    ~continuation_gmres();
    void c_gmres(const double t, const Eigen::VectorXd& x, Eigen::VectorXd& s);
    void Hufunc(const double t, const Eigen::VectorXd& x0, const Eigen::VectorXd& u, Eigen::VectorXd& hu);
    void Func(const double t, const Eigen::VectorXd& x0, const Eigen::VectorXd& u, Eigen::VectorXd& s);
    void DhFunc(const double t, const Eigen::VectorXd& x0, const Eigen::VectorXd& u, const Eigen::VectorXd& v, Eigen::VectorXd& s);
    virtual void statefunc(const double t, const Eigen::VectorXd& x, const Eigen::VectorXd& u, Eigen::VectorXd& x1) = 0;
    virtual void hxfunc(const double t, const Eigen::VectorXd& x, const Eigen::VectorXd& u, const Eigen::VectorXd& lmd, Eigen::VectorXd& lmd1) = 0;
    virtual void hufunc(const double t, const Eigen::VectorXd& x, const Eigen::VectorXd& u, const Eigen::VectorXd& lmd, Eigen::VectorXd& hu1) = 0;
};

#endif