#pragma once
#include <QAbstractTableModel>
#include <QObject>

namespace monitor {

class MonitorInterModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit MonitorInterModel(QObject *parent = nullptr)
      : QAbstractTableModel(parent) {}
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override; //基类中为纯虚函数必须重写才可以实例化对象
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override; // 可以选择不重写，因为在基类中不是纯虚函数
  virtual ~MonitorInterModel() {} //Qt::Orientation 是 Qt 框架中的一个枚举类型，定义了对象的方向
};

}  // namespace monitor