#include <iostream>
#include <cmath>

class ElectricField {
private:
    double *fieldComponents;

public:
    ElectricField() {
        fieldComponents = new double[3]{0.0, 0.0, 0.0};
    }

    ElectricField(double Ex, double Ey, double Ez) {
        fieldComponents = new double[3]{Ex, Ey, Ez};
    }

    ~ElectricField() {
        delete[] fieldComponents;
    }

    double getEx() const { return fieldComponents[0]; }
    double getEy() const { return fieldComponents[1]; }
    double getEz() const { return fieldComponents[2]; }

    void setEx(double Ex) { fieldComponents[0] = Ex; }
    void setEy(double Ey) { fieldComponents[1] = Ey; }
    void setEz(double Ez) { fieldComponents[2] = Ez; }

    double getMagnitude() const {
        return std::sqrt(fieldComponents[0] * fieldComponents[0] +
                         fieldComponents[1] * fieldComponents[1] +
                         fieldComponents[2] * fieldComponents[2]);
    }

    double calculateInnerProduct() const {
        return fieldComponents[0] * fieldComponents[0] +
               fieldComponents[1] * fieldComponents[1] +
               fieldComponents[2] * fieldComponents[2];
    }
};

class MagneticField {
private:
    double *fieldVector;

public:
    MagneticField() {
        fieldVector = new double[3]{0.0, 0.0, 0.0};
    }

    MagneticField(double Bx, double By, double Bz) {
        fieldVector = new double[3]{Bx, By, Bz};
    }

    ~MagneticField() {
        delete[] fieldVector;
    }

    double getBx() const { return fieldVector[0]; }
    double getBy() const { return fieldVector[1]; }
    double getBz() const { return fieldVector[2]; }

    void setBx(double Bx) { fieldVector[0] = Bx; }
    void setBy(double By) { fieldVector[1] = By; }
    void setBz(double Bz) { fieldVector[2] = Bz; }

    double getMagnitude() const {
        return std::sqrt(fieldVector[0] * fieldVector[0] +
                         fieldVector[1] * fieldVector[1] +
                         fieldVector[2] * fieldVector[2]);
    }

    void displayUnitVector() const {
        double mag = getMagnitude();
        if (mag != 0) {
            std::cout << "Unit vector: (" << fieldVector[0] / mag << ", "
                      << fieldVector[1] / mag << ", " << fieldVector[2] / mag << ")" << std::endl;
        } else {
            std::cout << "Magnetic field vector is zero; no unit vector." << std::endl;
        }
    }
};

int main() {
    ElectricField eFieldDefault;
    ElectricField eFieldWithComponents(1e5, 10.9, 1.7e2);

    std::cout << "Default electric field magnitude: " << eFieldDefault.getMagnitude() << std::endl;
    std::cout << "Electric field with components magnitude: " << eFieldWithComponents.getMagnitude() << std::endl;
    std::cout << "Electric field inner product: " << eFieldWithComponents.calculateInnerProduct() << std::endl;

    eFieldDefault.setEx(5.5);
    eFieldDefault.setEy(10.1);
    eFieldDefault.setEz(-3.3);
    std::cout << "Modified default electric field magnitude: " << eFieldDefault.getMagnitude() << std::endl;

    MagneticField mFieldDefault;
    MagneticField mFieldWithComponents(0.5, -1.2, 3.4);

    std::cout << "Default magnetic field magnitude: " << mFieldDefault.getMagnitude() << std::endl;
    std::cout << "Magnetic field with components magnitude: " << mFieldWithComponents.getMagnitude() << std::endl;
    std::cout << "Magnetic field unit vector: ";
    mFieldWithComponents.displayUnitVector();

    mFieldDefault.setBx(2.2);
    mFieldDefault.setBy(-3.1);
    mFieldDefault.setBz(4.5);
    std::cout << "Modified default magnetic field magnitude: " << mFieldDefault.getMagnitude() << std::endl;
    std::cout << "Modified magnetic field unit vector: ";
    mFieldDefault.displayUnitVector();

    return 0;
}

