// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  nlopt_tutorial.cpp
 * @brief NLopt official tutorial
 * @author Tatsuya Ishikawa
 */

#include <iomanip>
#include <iostream>
#include <vector>

#include <nlopt.hpp>

typedef struct {
    double a, b;
} my_constraint_data;

double myfunc(const std::vector<double>& x, std::vector<double>& grad, void *my_func_data)
{
    if (!grad.empty()) {
        grad[0] = 0.0;
        grad[1] = 0.5 / sqrt(x[1]);
    }
    return sqrt(x[1]);
}

double myconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data)
{
    my_constraint_data *d = reinterpret_cast<my_constraint_data*>(data); // ほんとぉ？
    double a = d->a, b = d->b;
    if (!grad.empty()) {
        grad[0] = 3 * a * (a*x[0] + b) * (a*x[0] + b);
        grad[1] = -1.0;
    }
    return ((a*x[0] + b) * (a*x[0] + b) * (a*x[0] + b) - x[1]);
}

int main()
{
    nlopt::opt opt(nlopt::LD_MMA, 2); // algorithm and dimensionality
    std::vector<double> lb {-HUGE_VAL, 0};
    opt.set_lower_bounds(lb);
    opt.set_min_objective(myfunc, NULL);

    my_constraint_data data[2] = { {2, 0}, {-1, 1} };
    opt.add_inequality_constraint(myconstraint, &data[0], 1e-8);
    opt.add_inequality_constraint(myconstraint, &data[1], 1e-8);
    opt.set_xtol_rel(1e-4);

    std::vector<double> x {1.234, 5.678};

    double minf;

    try {
        nlopt::result result = opt.optimize(x, minf);
        std::cout << "found minimum af f(" << x[0] << ", " << x[1] << ") = "
                  << std::setprecision(10) << minf << std::endl;
    } catch (std::exception &e) {
        std::cout << "nlopt failed: " << e.what() << std::endl;
    }
}
