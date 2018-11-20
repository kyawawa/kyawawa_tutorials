// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  eigen_test.cpp
 * @brief Eigen test
 * @author Tatsuya Ishikawa
 */

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int argc, char **argv)
{
    Translation<double, 3> trans(1, 0, 0);
    cout << AngleAxisd(M_PI / 2, Vector3d::UnitX()).toRotationMatrix() << endl;
    Affine3d affine = trans * AngleAxisd(M_PI / 2, Vector3d::UnitX());
    cout << affine.translation() << endl;
    cout << affine.rotation() << endl;
    affine.rotate(AngleAxisd(M_PI * 3 / 2, Vector3d::UnitX()));
    cout << affine.matrix() << endl;
    Vector3d a(2, 0, 1);
    affine.translate(a);
    cout << affine.matrix() << endl;
    return 0;
}
