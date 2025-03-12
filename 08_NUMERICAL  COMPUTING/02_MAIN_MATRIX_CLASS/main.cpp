#include "matrix.hpp"

void menu() {
    cout << "Select an operation:\n";
    cout << "1. Matrix Addition\n";
    cout << "2. Matrix Subtraction\n";
    cout << "3. Check Identity Matrix\n";
    cout << "4. Find Determinant\n";
    cout << "5. Gauss-Seidel\n";
    cout << "6. Gaussian Elimination\n";
    cout << "7. Exit\n";
}

vector<double> loadVector(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return {};
    }
    
    vector<double> b;
    double value;
    while (file >> value) {
        b.push_back(value);
    }

    file.close();
    return b;
}

int main() {
    Matrix m1, m2;
    m1.load("mat1.txt");
    m2.load("mat2.txt");

    vector<double> b = loadVector("b.txt"); // Load vector b from file

    if (b.empty()) {
        cout << "Error: Could not load vector b from file.\n";
        return 1;
    }

    int ch;
    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                Matrix sum = m1.add(m2);
                cout << "Sum:\n";
                sum.show();
                break;
            }
            case 2: {
                Matrix diff = m1.sub(m2);
                cout << "Difference:\n";
                diff.show();
                break;
            }
            case 3:
                cout << (m1.isId() ? "Matrix 1 is Identity\n" : "Matrix 1 is NOT Identity\n");
                break;
            case 4:
                cout << "Determinant: " << m1.det() << endl;
                break;
            case 5: {
                vector<double> x(m1.det(), 0);
                int maxItr = 100;
                double tol = 1e-6;
                m1.gs(b, x, maxItr, tol);
                break;
            }
            case 6: {
                vector<double> x;
                m1.ge(b, x);
                cout << "Solution using Gaussian Elimination:\n";
                for (double val : x) {
                    cout << val << " ";
                }
                cout << endl;
                break;
            }
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
