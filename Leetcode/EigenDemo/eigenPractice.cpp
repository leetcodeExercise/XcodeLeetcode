//
//  eigenPractice.cpp
//  EigenDemo
//
//  Created by dsh on 2021/7/18.
//
#include "eigenPractice.hpp"

void eigenPractice::eigenBasic() {
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    Matrix<float, 2, 3> matrix_23;
    Vector3d v_3d;
    Matrix<float, 3, 1> vd_3d;
    Matrix3d matrix_33 = Matrix3d::Zero();
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;
    MatrixXd matrix_x;

    matrix_23 << 1, 2, 3, 4, 5, 6;
    std::cout << "matrix 2x3 : \n" << matrix_23 << std::endl;
    std::cout << "print matrix 2x3: " << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) std::cout << matrix_23(i, j) << "\t";
        std::cout << std::endl;
    }

    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    std::cout << "matrix_23 * v_3d = " << result.transpose() << std::endl;

    matrix_33 << 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9;
    std::cout << "random matrix: \n" << matrix_33 << std::endl;
    std::cout << "transpose: \n" << matrix_33.transpose() << std::endl;
    std::cout << "sum: " << matrix_33.sum() << std::endl;
    std::cout << "trace: " << matrix_33.trace() << std::endl;
    std::cout << "times 10: \n" << 10 * matrix_33 << std::endl;
    std::cout << "inverse: \n" << matrix_33.inverse() << std::endl;
    std::cout << "det: " << matrix_33.determinant() << std::endl;

    SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    std::cout << "Eigen values = \n" << eigen_solver.eigenvalues() << std::endl;
    std::cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << std::endl;

    //matrix_NN * x = v_Nd
    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN
    = MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock();
    Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    std::cout << "time of normal inverse is " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout << "x = " << x.transpose() <<std::endl;

    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    std::cout << "time of Qr decomposition is " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout <<"x = " << x.transpose() << std::endl;

    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    std::cout << "time of ldlt decomposition is " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout <<"x = " << x.transpose() << std::endl;
}

void eigenPractice::eigenGeometry() {
    Matrix3d rotation_matrix = Matrix3d::Identity();
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));
    std::cout.precision(3);
    std::cout << "rotation matrix = \n" << rotation_vector.matrix() << std::endl;
    
    rotation_matrix = rotation_vector.toRotationMatrix();
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    std::cout << "(1, 0, 0) after rotation (by angle axis) = " << v_rotated.transpose() << std::endl;
    v_rotated = rotation_matrix * v;
    std::cout << "(1, 0, 0) after rotation (by matrix) = " << v_rotated.transpose() << std::endl;
    
    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX
    std::cout << "yaw pitch roll = " << euler_angles.transpose() << std::endl;
    
    Isometry3d T = Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1, 3, 4));
    std::cout << "Transform matrix = \n" << T.matrix() << std::endl;
    Vector3d v_transformed = T * v;
    std::cout << "v transformed = " << v_transformed.transpose() << std::endl;
    
    Quaterniond q = Quaterniond(rotation_vector);
    std::cout << "quaternion from rotation vecter = " << q.coeffs().transpose() << std::endl;
    q = Quaterniond(rotation_matrix);
    std::cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << std::endl;
    v_rotated = q * v;
    std::cout << "(1, 0, 0) after rotation = " << v_rotated.transpose() << std::endl;
    std::cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << std::endl;
}
