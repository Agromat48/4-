#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book {
    string author;
    string title;
    string publisher;
    int year;
    int pages;
    int chapters;
    string discipline;
};

void save(string namefile, Book books[]) {
    ofstream file(namefile);
    if (file.is_open()) {
        for (int i = 0; i < 8; i++) {
            file << books[i].author << endl;
            file << books[i].title << endl;
            file << books[i].publisher << endl;
            file << books[i].year << endl;
            file << books[i].pages << endl;
            file << books[i].chapters << endl;
            file << books[i].discipline << endl;
            file << "==========" << endl;
        }
    }
    else {
        cout << "Ошибка открытия файла!" << endl;
    }
    file.close();
}

void printAll(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Все книги в файле:" << endl;

        while (getline(file, line)) {
            if (line == "==========") {
                cout << "-------------------" << endl;
            }
            else {
                cout << line << endl;
            }
        }
    }
    else {
        cout << "Ошибка открытия файла для чтения!" << endl;
    }
    file.close();
}

void getbooks(string filename, string name) {
    ifstream file(filename);
    string line, author, title, publisher, year, pages, chapters, discipline;
    int i = 0;

    if (file.is_open()) {
        cout << "Литература по курсу: " << name << " была издана в следующих годах и издательствах." << endl;

        while (getline(file, author)) {
            getline(file, title);
            getline(file, publisher);
            getline(file, year);
            getline(file, pages);
            getline(file, chapters);
            getline(file, discipline);
            getline(file, line);

            if (discipline == name) {
                cout << "Год издания: " << year << ". Издательство: " << publisher << endl;
                i++;
            }
        }
        if (i == 0)
            cout << "Ошибка!" << endl;
    }
    else {
        cout << "Ошибка открытия файла!" << endl;
    }
    file.close();
}

int main() {
    system("chcp 1251");
    string filename = "books.txt";

    Book books[8] = {
        {"Иванов И.И.", "Программирование на C++", "Наука", 2020, 350, 12, "Информатика"},
        {"Петров П.П.", "Алгоритмы и структуры данных", "Бином", 2018, 420, 15, "Информатика"},
        {"Сидоров С.С.", "Математический анализ", "Просвещение", 2015, 600, 20, "Математика"},
        {"Кузнецов К.К.", "Физика для инженеров", "ФИЗМАТЛИТ", 2019, 500, 18, "Физика"},
        {"Лебедев Л.Л.", "Базы данных", "Питер", 2021, 300, 10, "Информатика"},
        {"Смирнов С.С.", "Операционные системы", "ЛАНЬ", 2017, 250, 8, "Информатика"},
        {"Гончаров Г.Г.", "Линейная алгебра", "Мир", 2016, 400, 14, "Математика"},
        {"Михайлов М.М.", "Электротехника", "Энергоатом", 2022, 450, 16, "Электротехника"}
    };

    save(filename, books);
    printAll(filename);

    string name;
    cout << "Введите дисциплину для поиска: ";
    cin >> name;

    getbooks(filename, name);

    return 0;
}
