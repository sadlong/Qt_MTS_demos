#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口固定大小 不能让鼠标拖动伸缩窗口
    setFixedSize(this->width(), this->height());

    // =============================================================================================

    //菜单栏设计与实现
    QMenuBar* pMenuBar = new QMenuBar(this);
    setMenuBar(pMenuBar);   //用于将 QMenuBar 设置为 QMainWindow 的菜单栏。这个函数的作用是将指定的 QMenuBar 对象作为主窗口的菜单栏，使其显示在窗口的顶部。
    //文件管理(F)
    QMenu* pMenuBarFile = new QMenu("文件管理(F)");
    //客房管理(R)
    QMenu* pMenuBarRoom = new QMenu("客房管理(R)");
    //餐饮管理(C)
    QMenu* pMenuBarCater = new QMenu("餐饮管理(C)");
    //帮助(H)
    QMenu* pMenuBarHelp = new QMenu("帮助(H)");


    pMenuBar->addMenu(pMenuBarFile);
    pMenuBar->addMenu(pMenuBarRoom);
    pMenuBar->addMenu(pMenuBarCater);
    pMenuBar->addMenu(pMenuBarHelp);

    // =============================================================================================

    //工具栏设计与实现
    QToolBar* pToolBar = addToolBar("toolBars");    //addToolBar()是mainwindow自带的成员函数

    QStringList icons = {":/new/prefix1/images/OIP-C.jpg", ":/new/prefix1/images/1.jpg", ":/new/prefix1/images/2.jpg", ":/new/prefix1/images/3.jpg"};
    QStringList labels = {"打开", "关闭", "哈哈", "喜喜"};
    for(int i = 0; i < icons.size(); i++) {
        QToolButton* pActionOpenBar = new QToolButton(this);
        pActionOpenBar->setIconSize(QSize(60, 60)); //设置按钮大小
        pActionOpenBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);    //设置这个按钮的标签在按钮的哪个位置(有under和besides两个选项)
        pActionOpenBar->setIcon(QIcon(icons[i]));   //设置按钮图案 路径':/new/prefix1/images/'基本是一样的
        pActionOpenBar->setText(labels[i]);  //设置按钮标签
        pToolBar->addWidget(pActionOpenBar);    //addWidget()是mainwindow自带的成员函数 这样才能使各控件合理排布
    }


    // =============================================================================================

    //状态栏设计与实现
    QStatusBar* pStatusBars = statusBar();

    //将其添加到窗口当中
    setStatusBar(pStatusBars);

    //在状态栏中存放一个标签控件
    QLabel* pLabel = new QLabel("系统提示信息");
    pStatusBars->addWidget(pLabel);

    QTextEdit* pTextEdit = new QTextEdit(this);
    pTextEdit->setStyleSheet("font-size:20pt");
    setCentralWidget(pTextEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

