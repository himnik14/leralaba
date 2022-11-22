#include <conio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <vector>
using namespace std;
class Triangle 
{
    double corner, firstSide, secondSide;
public:
    void SetFirstSide(double firstSide);
    void SetSecondSide(double secondSide);
    void SetCorner(double corner);
    double GetFirstSide();
    double GetSecondSide();
    double GetCorner();
    double GetThirdSide();
    void ZoomCorner();
    void ShowBisector();
    void ShowAllCorner();
    double Bisectors(int number);
    double Corners(int number);
    void ShowSideBisector();
};
void Triangle::ShowSideBisector() {
    cout << "Первая биссектриса делит сторону на отрезки длиной: \n";
    double one, two, three;
    one = sqrt(pow(secondSide, 2) + pow(Bisectors(0), 2) - 2 * secondSide * Bisectors(0) * cos((Corners(0) / 2) * 3.14 / 180));
    cout << one << " и " <<  GetThirdSide() - one << "\n";
    two = sqrt(pow(firstSide, 2) + pow(Bisectors(1), 2) - 2 * firstSide * Bisectors(1) * cos((Corners(1) / 2) * 3.14 / 180));
    cout << "Вторая биссектриса делит сторону на отрезки длиной:\n";
    cout << two << " и " << secondSide - two << "\n";
    cout << "Третья биссектриса делит сторону на отрезки длиной:\n";
    three = sqrt(pow(GetThirdSide(), 2) + pow(Bisectors(2), 2) - 2 * GetThirdSide() * Bisectors(2) * cos((Corners(2) / 2) * 3.14 / 180));
    cout << three << " и " << firstSide - three << "\n";
}
double Triangle::GetCorner() {
    return corner;
}
double Triangle::GetFirstSide() {
    return firstSide;
}
double Triangle::GetSecondSide() {
    return secondSide;
}
void Triangle::SetFirstSide(double firstSide) {
    if (firstSide <= 0) {
        throw exception("Сторона треугольника не может быть меньше или равна нулю!\n");
    }
    this->firstSide = firstSide;

}
void Triangle::SetSecondSide(double secondSide) {
    if (firstSide <= 0) {
        throw exception("Сторона треугольника не может быть меньше или равна нулю!\n");
    }
    this->secondSide = secondSide;
}
void Triangle::SetCorner(double corner) {
    if (corner <= 0 || corner >= 180) {
        throw exception("Угол не может быть отрицательным или быть равным 180!\n");
    }
    this->corner = corner;
}
void Triangle::ZoomCorner() {
    double k;
    cout << "Во сколько раз вы хотите уменьшить/увеличить угол треугольника?\n";
    cout << "Если вы хотите уменьшить то введите отрицательное число, если увеличить, то положительное:\n";
    cin >> k;
    if (k < 0) {
        corner *= abs((1 / k));
    }
    else if (k == 0) {
        corner = corner;
    }
    else if (k > 0) {
        corner = k * corner;
    }
}
double Triangle::Bisectors(int number) {
    double bisec[3];
    double sum = firstSide + secondSide + GetThirdSide();
    bisec[0] = sqrt(firstSide * secondSide * (sum) * (firstSide + secondSide - GetThirdSide())) / (firstSide + secondSide);
    bisec[1] = sqrt(firstSide * GetThirdSide() * sum * (firstSide + GetThirdSide() - secondSide)) / (firstSide + GetThirdSide());
    bisec[2] = sqrt(secondSide * GetThirdSide() * sum * (secondSide + GetThirdSide() - firstSide)) / (secondSide + GetThirdSide());
    return bisec[number];
}
double Triangle::Corners(int number) {
    double corners[3];
    corners[0] = corner;
    corners[1] = acos(((pow(firstSide, 2) + pow(GetThirdSide(), 2) - pow(secondSide, 2)) / (2 * firstSide * GetThirdSide()))) * 180 / 3.14;
    corners[2] = acos(((pow(secondSide, 2) + pow(GetThirdSide(), 2) - pow(firstSide, 2)) / (2 * secondSide * GetThirdSide()))) * 180 / 3.14;
    return corners[number];
}
void Triangle::ShowAllCorner() {
    cout << "Первый угол: ";
    cout << Corners(0) << "\n";
    cout << "Второй угол: ";
    cout << Corners(1) << "\n";
    cout << "Третий угол: ";
    cout << Corners(2) << "\n";
}
double Triangle::GetThirdSide() {
    return sqrt(pow(firstSide, 2) + pow(secondSide, 2) - 2 * (firstSide * secondSide * cos((3.14 * corner) / 180)));
}
void Triangle::ShowBisector() {
    
    cout << "Первая биссекриса: ";
    cout << Bisectors(0) << "\n";
    cout << "Вторая биссекриса: ";
    cout << Bisectors(1) << "\n";
    cout << "Третья биссекриса: ";
    cout << Bisectors(2) << "\n";
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle tr1;
    bool T = true;
    double firstSide, secondSide, corner;
    while (T) 
    {
        cout << "Введите первую сторону: " << "\n";
        cin >> firstSide;
        cout << "Введите вторую сторону:\n";
        cin >> secondSide;
        cout << "Введите угол между сторонами:\n";
        cin >> corner;
        try
        {
            tr1.SetSecondSide(secondSide);
            tr1.SetCorner(corner);
            tr1.SetFirstSide(firstSide);
        }
        catch (const std::exception& exn)
        {
            cout << exn.what();
            break;

        }
        cout << "Третья сторона треугольника: " << tr1.GetThirdSide() << "\n";
        tr1.ShowAllCorner();
        tr1.ShowBisector();
        tr1.ShowSideBisector();
        tr1.ZoomCorner();
        cout << "Третья сторона треугольника: " << tr1.GetThirdSide() << "\n";
        tr1.ShowAllCorner();
        tr1.ShowBisector();
        tr1.ShowSideBisector();
    }
    
    
    

}