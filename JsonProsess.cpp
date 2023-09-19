#include "JsonProsess.h"
#include <QFile>
#include <QCoreApplication>
#include <QDir>

QJsonDocument jsonDoc;
QStringList root_Keys;
QJsonObject root_Obj;

void LoadData()
{
    if(!QDir(QCoreApplication::applicationDirPath()+"/data/").exists())
    {
        QDir().mkdir(QCoreApplication::applicationDirPath()+"/data/");
        return;
    }

    QFile file(QCoreApplication::applicationDirPath()+"/data/data.json");
    QByteArray jsonData;

    if(file.open(QIODevice::ReadOnly))
    {
        jsonData = file.readAll();
        file.close();
    }

    jsonDoc = QJsonDocument::fromJson(jsonData);

    if(jsonDoc.isObject())
    {
        root_Obj = jsonDoc.object();
        root_Keys = root_Obj.keys();
//        for(auto key : keys)
//        {
//            QJsonValue value = obj_root.value(key);
//            if(value.isString())
//            {

//            }
//            else if(value.isDouble())
//            {

//            }
//            else if(value.isArray())
//            {

//            }
//            else if(value.isObject())
//            {

//            }
//        }
    }
}
