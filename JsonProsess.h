#ifndef JSONPROSESS_H
#define JSONPROSESS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

extern QJsonDocument jsonDoc;
extern QStringList root_Keys;
extern QJsonObject root_Obj;

void LoadData();

#endif // JSONPROSESS_H
