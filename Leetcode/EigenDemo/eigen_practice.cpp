//
//  eigenPractice.cpp
//  EigenDemo
//
//  Created by dsh on 2021/7/18.
//

#include <iostream>

#include "Eigen/Eigen"

#include "eigen_practice.hpp"

void EigenPractice::EigenBasic() {
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;

    Eigen::Matrix<float, 2, 3> matrix_23;
    Eigen::Vector3d v_3d;
    Eigen::Matrix<float, 3, 1> vd_3d;
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
    Eigen::MatrixXd matrix_x;

    matrix_23 << 1, 2, 3, 4, 5, 6;
    std::cout << "matrix 2x3 :" << std::endl;
    std::cout << matrix_23 << std::endl;
    std::cout << "print matrix 2x3: " << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            std::cout << matrix_23(i, j) << "\t";
        std::cout << std::endl;
    }

    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    std::cout << "matrix_23 * v_3d = " << result.transpose() << std::endl;

    matrix_33 << 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9;
    std::cout << "random matrix:" << std::endl;
    std::cout << matrix_33 << std::endl;
    std::cout << "transpose:" << std::endl;
    std::cout << matrix_33.transpose() << std::endl;
    std::cout << "sum: " << matrix_33.sum() << std::endl;
    std::cout << "trace: " << matrix_33.trace() << std::endl;
    std::cout << "times 10:" << std::endl;
    std::cout << 10 * matrix_33 << std::endl;
    std::cout << "inverse:" << std::endl;
    std::cout << matrix_33.inverse() << std::endl;
    std::cout << "det: " << matrix_33.determinant() << std::endl;

    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d>
    eigen_solver(matrix_33.transpose() * matrix_33);
    std::cout << "Eigen values =" << std::endl;
    std::cout << eigen_solver.eigenvalues() << std::endl;
    std::cout << "Eigen vectors =" << std::endl;
    std::cout << eigen_solver.eigenvectors() <<std::endl;

    //matrix_NN * x = v_Nd
    Eigen::Matrix<double, kMatrixSize, kMatrixSize> matrix_NN
    = Eigen::MatrixXd::Random(kMatrixSize, kMatrixSize);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Eigen::Matrix<double, kMatrixSize, 1> v_Nd =
    Eigen::MatrixXd::Random(kMatrixSize, 1);

    clock_t time_stt = clock();
    Eigen::Matrix<double, kMatrixSize, 1> x = matrix_NN.inverse() * v_Nd;
    std::cout << "time of normal inverse is " <<
    1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC) << "ms" << std::endl;
    std::cout << "x = " << x.transpose() <<std::endl;

    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    std::cout << "time of Qr decomposition is " <<
    1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC) << "ms" << std::endl;
    std::cout << "x = " << x.transpose() << std::endl;

    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    std::cout << "time of ldlt decomposition is " <<
    1000 * (clock() - time_stt) / static_cast<double>(CLOCKS_PER_SEC) << "ms" << std::endl;
    std::cout << "x = " << x.transpose() << std::endl;
}

void EigenPractice::EigenGeometry() {
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
    std::cout.precision(3);
    std::cout << "rotation matrix =" << std::endl;
    std::cout << rotation_vector.matrix() << std::endl;
    
    rotation_matrix = rotation_vector.toRotationMatrix();
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_vector * v;
    std::cout << "(1, 0, 0) after rotation (by angle axis) = " <<
    v_rotated.transpose() << std::endl;
    v_rotated = rotation_matrix * v;
    std::cout << "(1, 0, 0) after rotation (by matrix) = " <<
    v_rotated.transpose() << std::endl;
    
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);  // ZYX
    std::cout << "yaw pitch roll = " << euler_angles.transpose() << std::endl;
    
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Eigen::Vector3d(1, 3, 4));
    std::cout << "Transform matrix =" << std::endl;
    std::cout << T.matrix() << std::endl;
    Eigen::Vector3d v_transformed = T * v;
    std::cout << "v transformed = " << v_transformed.transpose() << std::endl;
    
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    std::cout << "quaternion from rotation vecter = " <<
    q.coeffs().transpose() << std::endl;
    q = Eigen::Quaterniond(rotation_matrix);
    std::cout << "quaternion from rotation matrix = " <<
    q.coeffs().transpose() << std::endl;
    v_rotated = q * v;
    std::cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << std::endl;
    std::cout << "should be equal to " <<
    (q * Eigen::Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << std::endl;
}
