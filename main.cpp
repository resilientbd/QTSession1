#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include "Student.h"
#include "iostream"
using namespace std;

void createTable() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT)");
    if (query.lastError().isValid()) {
        qDebug() << "Error creating table:" << query.lastError().text();
    }




}
void createStudent(string name)
{

    Student student;
    student.id = 1;
    student.name = name;
    student.className = "VII";
    student.mobile = "2212342";
    student.roll = 1121;

    cout<<"name:"<<student.name<<endl;
    cout<<"class name:"<<student.className<<endl;
    cout<<"role:"<<student.roll<<endl;
}

void insertData(const QString &name) {
    QSqlQuery query;
    query.prepare("INSERT INTO users (name) VALUES (:name)");
    query.bindValue(":name", name);
    query.exec();
    if (query.lastError().isValid()) {
        qDebug() << "Error inserting data:" << query.lastError().text();
    }
}

void displayData() {
    QSqlQuery query("SELECT * FROM users");
    while (query.next()) {
        qDebug() << "ID:" << query.value("id").toInt() << "Name:" << query.value("name").toString();
    }
}

void updateData(int id, const QString &newName) {
    QSqlQuery query;
    query.prepare("UPDATE users SET name = :newName WHERE id = :id");
    query.bindValue(":newName", newName);
    query.bindValue(":id", id);
    query.exec();
    if (query.lastError().isValid()) {
        qDebug() << "Error updating data:" << query.lastError().text();
    }
}

void deleteData(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.lastError().isValid()) {
        qDebug() << "Error deleting data:" << query.lastError().text();
    }
}

int main(int argc, char *argv[]) {
    createStudent("Aninda");
   // QCoreApplication a(argc, argv);

    // Set up the database connection
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("my_database.sqlite");
//
//    if (!db.open()) {
//        qDebug() << "Failed to connect to the database:" << db.lastError().text();
//        return 1;
//    }
//
//    // Create the 'users' table if it doesn't exist
//    createTable();
//
//    // Insert some data
//    insertData("John Doe");
//    insertData("Jane Smith");
//    insertData("Faisal");
//    insertData("Soumik");
//    insertData("Masud");
//    insertData("Anindya");

    /*// Display the data
    qDebug() << "Data before update:";
    displayData();

    // Update data
    updateData(1, "John Updated");

    // Display the data after update
    qDebug() << "Data after update:";
    displayData();

    // Delete data
    deleteData(2);

    // Display the data after delete
    qDebug() << "Data after delete:";
    displayData();*/

  //  return a.exec();
}
