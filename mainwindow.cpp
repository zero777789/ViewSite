#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  // tableWidget[0] = new QTableWidget(10,2,this);

    SetTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetTab()
{
            centralWidget = new QWidget(this);
            setCentralWidget(centralWidget);

       // здесь будут реализованы примеры создания интерьера формы
        layout = new QHBoxLayout(centralWidget);

          {

            // Here some first widget
               QWidget *wid1 = new QWidget(this);
               QHBoxLayout *wid1Lay = new QHBoxLayout(wid1);
               QTextEdit * ple = new QTextEdit(this);
               wid1Lay->addWidget(ple);

           //---------
               // Here some second widget
               QWidget *wid2 = new QWidget(this);
               QHBoxLayout *wid2Lay = new QHBoxLayout(wid2);
               wid2Lay->addWidget(new QLabel(tr("Widget2")));

          // Here some third widget
               QWidget *wid3 = new QWidget(this);
               QHBoxLayout *wid3Lay = new QHBoxLayout(wid3);
               wid3Lay->addWidget(new QLabel(tr("Widget3")));

               // Here your Tab bar with only bars
               bar = new QTabBar(this);
               bar->addTab("One");
               bar->addTab("Two");
               bar->addTab("Three");


               // Main layouts
               QVBoxLayout *vLay = new QVBoxLayout(this );
               layout->addLayout(vLay,70);
               QHBoxLayout *hLay = new QHBoxLayout();

               vLay->addLayout(hLay);
               hLay->addWidget(bar);
               // Spacer for expanding left and right sides
               hLay->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

               vLay->addWidget(wid1);
               vLay->addWidget(wid2);
               vLay->addWidget(wid3);

               // Some simple connect with lambda for navigation
               connect(bar, &QTabBar::currentChanged, [=] (int index)
               {

                   wid1->setVisible(false);
                   wid2->setVisible(false);
                   wid3->setVisible(false);

                   switch(index) {
                   case 0: wid1->setVisible(true);
                       break;
                   case 1: wid2->setVisible(true);
                       break;
                   case 2: wid3->setVisible(true);
                       break;
                   default:{}
                   }

               });

               emit bar->currentChanged(0);




                  }

                  {
                      QTextEdit * ple = new QTextEdit(this);
                      layout->addWidget(ple, 30 );
                  }


          setLayout(layout);
          centralWidget->show();
}

