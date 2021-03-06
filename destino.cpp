#include "destino.h"
#include "QString"
#include <fstream>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
using namespace std;
Destino::Destino()
{
}
Destino::Destino(QString codigo, QString nombre_Destino,QString nombre_ciudad,QString nombre_pais)
{
    Destino::codigo=codigo;
    Destino::Nombre_Destino=nombre_Destino;
    Destino::Nombre_Ciudad=nombre_ciudad;
    Destino::Nombre_Pais=nombre_pais;
}
bool Destino::guardar(Destino tmp){
    Connector con;
    try {
        QSqlDatabase db = con.initDataBase();
        if(db.open()){
            QSqlQuery query;
            query.prepare("INSERT INTO Destino VALUES(?,?,?,?)");
            query.bindValue(0, tmp.getCodigo());
            query.bindValue(1, tmp.getNombreDestino());
            query.bindValue(2, tmp.getNombreCiudad());
            query.bindValue(3, tmp.getNombrePais());

            if(query.exec()){
                db.close();
                return true;
            }else{
                db.close();
                throw QString(query.lastError().text());
            }
        }else
          throw QString("No se pudo abrir la base de datos");

    } catch (QString &e) {
      throw e;
    }
}
bool Destino::modificar(Destino tmp){
    Connector con;
    try {
        QSqlDatabase db = con.initDataBase();
        if(db.open()){
            QSqlQuery query;
            query.prepare("UPDATE Destino SET nombre=?, ciudad=?, pais=? WHERE codigo=?");
            query.addBindValue(tmp.getNombreDestino());
            query.addBindValue(tmp.getNombreCiudad());
            query.addBindValue(tmp.getNombrePais());

            query.addBindValue(tmp.getCodigo());

            if(query.exec()){
                if(query.numRowsAffected() > 0){
                    db.close();
                    return true;
                }else{
                    db.close();
                    throw QString("No se encontro ningun registro para actualizar");
                }
            }else{
                db.close();
                throw QString(query.lastError().text());
            }
        }else
            throw QString("No se pudo abrir la base de datos");
    } catch (QString &e) {
        throw e;
    }
}
bool Destino::eliminar(QString codigo){
    Connector con;
    try {
        QSqlDatabase db = con.initDataBase();
        if(db.open()){
            QSqlQuery query;
            query.prepare("DELETE FROM Destino WHERE codigo = ?");
            query.bindValue(0, codigo);
            if(query.exec()){
                if(query.numRowsAffected() > 0){
                    db.close();
                    return true;
                }else{
                    db.close();
                    throw QString("No se encontro el registro a eliminar");
                }
            }else{
                db.close();
                throw QString(query.lastError().text());
            }
        }else
            throw QString("No se pudo abrir la base de datos");
    } catch (QString &e) {
        throw e;
    }
}
Destino Destino::buscarPorCodigo(QString codigo){
    Connector con;
    try {
        QSqlDatabase db = con.initDataBase();
        if(db.open()){
            QSqlQuery query;
            query.prepare("SELECT * FROM Destino WHERE codigo=?");
            query.addBindValue(codigo);
            if(query.exec()){
                if(query.next()){
                    Destino temp(
                                    query.value(0).toString(),
                                    query.value(1).toString(),
                                    query.value(2).toString(),
                                    query.value(3).toString()
                                );
                    db.close();
                    return temp;
                }else{
                    throw QString("No se encontro el Destino");
                }
            }else{
                db.close();
                throw QString(query.lastError().text());
            }
        }else
            throw QString("No se pudo abrir la base de datos");
    } catch (QString &e) {
        throw e;
    }
}
QVector<Destino> Destino::todos(){
    Connector con;
    try {
        QSqlDatabase db = con.initDataBase();
        if(db.open()){
            QSqlQuery query;
            if(query.exec("SELECT * FROM Destino")){
                QVector<Destino> data;
                QDateTime fechaNac;
                while(query.next()){

                    data << Destino(
                                query.value(0).toString(),
                                query.value(1).toString(),
                                query.value(2).toString(),
                                query.value(3).toString()
                            );
               }
                return data;
            }else{
                throw QString(query.lastError().text());
            }
        }else
            throw QString("Error al aperturar la base de datos");
    } catch (QString &e) {
        throw e;
    }
}

QString Destino::getCodigo()
{
    return Destino::codigo;
}
void Destino::setCodigo(QString codigo){
    Destino::codigo= codigo;
}

QString Destino::getNombrePais()
{
    return Destino::Nombre_Pais;
}
void Destino::setNombrePais(QString Nombre_pais){
    Destino::Nombre_Pais = Nombre_pais;
}

QString Destino::getNombreCiudad()
{
    return Destino::Nombre_Ciudad;
}
void Destino::setNombreCiudad(QString Nombre_ciudad){
    Destino::Nombre_Ciudad = Nombre_ciudad;
}
QString Destino::getNombreDestino()
{
    return Destino::Nombre_Destino;
}
void Destino::setNombreDestino(QString Nombre_Destino){
    Destino::Nombre_Destino = Nombre_Destino;
}
