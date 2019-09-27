#include "order.h"

Order::Order()
{

}

void Order::SetSum(int sum)
{
    m_summary = sum;
}

int Order::GetSum()
{
    return m_summary;
}

QString Order::GetId()
{
    return m_id;
}

QString Order::GetClientId()
{
    return client.GetId();
}

QString Order::GetIngredientId()
{
    return ingredient.GetId();
}

bool Order::InsertOrder(QString id, QString name, QString address, QString ingName, QString pizzaName, QString summary, QString paymentName)
{
     QSqlQuery query;
     bool isRightQuery = query.exec("INSERT INTO Orders (ID_client, clientname, address, ingredientname, pizzaname, summary, payment) VALUES ('"+id+"', '"+name+"', '"+address+"', '"+ingName+"', '"+pizzaName+"', '"+summary+"', '"+paymentName+"')");
     //bool isRightQuery = query.prepare("INSERT INTO Orders (ID_client, clientname, address, ingredientname, pizzaname, summary, payment) VALUES (:id1, :id2, :id3, :id4, :id5, :id6, :id7)");
     query.first();
     /*query.bindValue(":id1", id);
     query.bindValue(":id2", name);
     query.bindValue(":id3", address);
     query.bindValue(":id4", ingName);
     query.bindValue(":id5", pizzaName);
     query.bindValue(":id6", summary);
     query.bindValue(":id7", paymentName);*/
     //qDebug() << query.value(5).toInt();
     //qDebug() << query.lastError();
     m_db.close();
     return isRightQuery;
}

QMap<int,QString> Order::GetOrders()
{
     QSqlQuery query;
     QMap<int, QString> map;
     int i=0;
     query.exec("SELECT ID_order, summary, ingredientname, pizzaname FROM Orders WHERE ID_client = 1");
     query.first();
     while (query.next())
     {
     QString ido = query.value(0).toString();
     QString ordsum = query.value(1).toString();
     QString ingdw = query.value(2).toString();
     QString pizza = query.value(3).toString();
     QString str = ""+ido+"                  "+ordsum+"                         "+ingdw+"               "+pizza+" \n";
     map.insert(i,str);
     i++;
     }

     m_db.close();
     return map;
}

/*bool Client::Find()
{
    // вызов функции из DM на поиск артиста в базе
   m_id = FormQueryToSearchClient(m_clientName);
   if(m_id.isEmpty())
   {
       m_isInDataBase = false;
       return m_isInDataBase;
   }
   else
   {
       m_isInDataBase = true;
       return m_isInDataBase;
   }
}

bool Order::SaveInDataBase()
{
    // добавила данные по артитисту в табл -артист-
    //bool isRightQuery = Insert(1, client.SelectClientName(QString str1), client.SelectClientAddress(QString address),ingredient.GetIngredientName(),pizza.GetPizzaName(), m_summary, pay.GetPaymentName());
    // если запрос выполнился корректно(узнаю присвоенный id добавленному артисту
    if(isRightQuery)
    {
        // узнать id добаленного артиста(необходимо для формирования талицы -гонорар-)
       // m_id = FormQueryToSearchClient(m_clientName);
        // добавление прошло корректно
        return true;
    }
    else
    {
        return false;
    }
}*/
