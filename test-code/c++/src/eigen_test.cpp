// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  eigen_test.cpp
 * @brief Eigen test
 * @author Tatsuya Ishikawa
 */

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <functional>
#include <iostream>

using namespace Eigen;
using namespace std;

void changeBlock(Ref<MatrixXd> X)
{
    Matrix2d B;
    B << 0, 0,
         0, 0;
    X = B;
}

int main(int argc, char **argv)
{
    /// Transform
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

    /// Eigen::Ref
    Matrix3d A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;
    cout << "A: \n" << A << endl;
    changeBlock(A.block(1, 1, 2, 2)); // blockを書き換えられる
    cout << "A: \n" << A << endl;
    function<void(Ref<MatrixXd>)> changeLeftCorner = [&](Ref<MatrixXd> J)
        {
            Vector2d x;
            x << 0, 0;
            J = x;
        };
    changeLeftCorner(A.block(0, 0, 2, 1));
    cout << "A: \n" << A << endl;
    return 0;
}
