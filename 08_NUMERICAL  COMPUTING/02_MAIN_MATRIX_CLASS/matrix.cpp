#include "matrix.hpp"

Matrix::Matrix() : r(0), c(0) {}

void Matrix::load(const string &f) {
    ifstream file(f);
    if (!file) {
        cout << "Error opening: " << f << endl;
        return;
    }

    file >> r >> c;
    d.resize(r, vector<double>(c));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            file >> d[i][j];

    file.close();
}

void Matrix::show() const {
    for (const auto &row : d) {
        for (double v : row)
            cout << v << " ";
        cout << endl;
    }
}

Matrix Matrix::add(const Matrix &m) const {
    if (r != m.r || c != m.c) {
        cout << "Size mismatch.\n";
        return *this;
    }

    Matrix res;
    res.r = r;
    res.c = c;
    res.d.resize(r, vector<double>(c));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            res.d[i][j] = d[i][j] + m.d[i][j];

    return res;
}

Matrix Matrix::sub(const Matrix &m) const {
    if (r != m.r || c != m.c) {
        cout << "Size mismatch.\n";
        return *this;
    }

    Matrix res;
    res.r = r;
    res.c = c;
    res.d.resize(r, vector<double>(c));

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            res.d[i][j] = d[i][j] - m.d[i][j];

    return res;
}

bool Matrix::isId() const {
    if (r != c) return false;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if ((i == j && d[i][j] != 1) || (i != j && d[i][j] != 0))
                return false;

    return true;
}

double Matrix::det() const {
    if (r != c) {
        cout << "Only square matrices.\n";
        return 0;
    }

    if (r == 1) return d[0][0];

    if (r == 2)
        return d[0][0] * d[1][1] - d[0][1] * d[1][0];

    double det = 0;
    for (int k = 0; k < c; k++) {
        Matrix sub;
        sub.r = r - 1;
        sub.c = c - 1;
        sub.d.resize(sub.r, vector<double>(sub.c));

        for (int i = 1; i < r; i++) {
            int cj = 0;
            for (int j = 0; j < c; j++) {
                if (j == k) continue;
                sub.d[i - 1][cj++] = d[i][j];
            }
        }
        det += (k % 2 == 0 ? 1 : -1) * d[0][k] * sub.det();
    }
    return det;
}

bool Matrix::isDiagDom() const {
    for (int i = 0; i < r; i++) {
        double sum = 0;
        for (int j = 0; j < c; j++) {
            if (i != j) sum += abs(d[i][j]);
        }
        if (abs(d[i][i]) < sum) return false;
    }
    return true;
}

void Matrix::gs(vector<double> &b, vector<double> &x, int maxItr, double tol) {
    if (!isDiagDom()) {
        cout << "Not diagonally dominant. Gauss-Seidel may not converge.\n";
        return;
    }

    for (int itr = 0; itr < maxItr; itr++) {
        cout << "Iteration " << itr + 1 << ":\n";
        vector<double> x_old = x;

        for (int i = 0; i < r; i++) {
            double sum = 0;
            for (int j = 0; j < r; j++) {
                if (j != i) sum += d[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / d[i][i];
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }

        double err = 0;
        for (int i = 0; i < r; i++)
            err += abs(x[i] - x_old[i]);

        if (err < tol) {
            cout << "Converged in " << itr + 1 << " iterations.\n";
            break;
        }
    }
}

void Matrix::ge(vector<double> &b, vector<double> &x) {
    int n = r;
    x.resize(n);

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = d[k][i] / d[i][i];
            for (int j = i; j < n; j++) {
                d[k][j] -= factor * d[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= d[i][j] * x[j];
        }
        x[i] /= d[i][i];
    }
}
