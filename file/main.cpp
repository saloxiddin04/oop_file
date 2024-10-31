//
//  main.cpp
//  file
//
//  Created by Saloxiddin Sayfuddinov on 16/10/24.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//int main() {
//    ofstream file("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/example.txt");
//    if (file.is_open()) {
//        file << "Hello Saloxiddin!" << endl;
//        file << "OOP fayllar bn ishlash" << endl;
//        file.close();
//
//    } else {
//        cout << "Fayl ochilmadi \n" << endl;
//    }
//
//    return 0;
//}

//int main() {
//    ifstream fayl("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/example.txt");
//    string line;
//    
//    if (fayl.is_open()) {
//        while (getline(fayl, line)) {
//            cout << line << endl;
//        }
//        fayl.close();
//    } else {
//        cout<<"Fayl ochilmadi!"<<endl;
//    }
//}

//int main() {
//    ofstream fayl("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/example.txt", ios::app);
//    if (fayl.is_open()) {
//        fayl << "Yangi talaba: Ali, Yosh: 20" << endl;
//        fayl.close();
//    } else {
//        cout<<"Fayl ochilmadi!"<<endl;
//    }
//}

void bubble_sort(int a[10], int n) {
    int tmp;
    for (int k=n-1; k>=0; k--) {
        for (int i = 0; i<=k-1; i++) {
            if (a[i]>a[i+1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1]=tmp;
            }
        }
    }
    
//    cout<< "result: ";
//    for (int i = 0; i<n; i++) {
//        cout<< a[i] << " ";
//    }
//    cout<< "\n" <<endl;
};

int main() {
    ifstream fayl("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/student.txt");
    ofstream file("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/sorted_student.txt", ios::app);
    ifstream grades("/Users/saloxiddinsayfuddinov/Documents/c++/OOP/file/file/grades.txt");
    
    string line, name, lineGrade;
    int engKattaYosh = 0;
    int j = 0;
    int arr[10];
    
    vector<int> grade;
    int gradeInterator = 0;
    int result;
    
    if (grades.is_open()) {
        while (getline(grades, lineGrade)) {
            stringstream ss(lineGrade);
            int ball;
            
            ss >> ball;
            
            grade.push_back(ball);
            gradeInterator++;
        }
        
        for (int i = 0; i < grade.size(); i++) {
            cout << grade[i] << endl;
            result+=grade[i] / grade.size();
        }
        cout << "O'rtacha hisob: " << result << endl;
    } else {
        cout<<"Fayl ochilmadi!"<<endl;
    }
    
    if (fayl.is_open() && file.is_open()) {
        while (getline(fayl, line)) {
            stringstream ss(line);
            string talaba;
            int yosh;
            
            ss >> talaba >> yosh; // satrni alohida bo'lib oq'ib olish (talaba 20)
            if (yosh > engKattaYosh) {
                engKattaYosh = yosh;
                name = talaba;
            }
            arr[j] = yosh;
            j++;
            
        }
        
        bubble_sort(arr, 10);
        
        for (int i = 0; i < 10; i++) {
            file << arr[i] << endl;
        }
        file.close();
        fayl.close();
    } else {
        cout<<"Fayl ochilmadi!"<<endl;
    }
}
