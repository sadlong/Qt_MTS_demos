#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//菜单栏头文件
#include <QMenuBar>

//工具栏对应头文件
#include <QToolBar>
#include <QToolButton>

//状态栏对应头文件
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
