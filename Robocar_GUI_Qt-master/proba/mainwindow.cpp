#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myutilities.h"

#include <QtDebug>
#include <QtConcurrent>

#include <string>
#include <chrono>
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setting integer limits for the port numbers
    ui->c2o1Tex->setValidator(new QIntValidator(10000, 62000, this));
    ui->c3o1Tex->setValidator(new QIntValidator(10000, 62000, this));

    // Setting integer limits for the number of random cars
    ui->c2o3Tex->setValidator(new QIntValidator(1, 2000, this));

    // Setting integer limits for the catch distance
    ui->c2o4Tex->setValidator(new QIntValidator(1, 200, this));

    // Setting integer limits for the length of simulation
    ui->c3o2Tex->setValidator(new QIntValidator(1, 360, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startSimBtn_released()
{
    const std::vector<std::string> options_smart_city {
        ui->c1o1Tex->text().toStdString(),  // 0.: osm
        ui->c1o2Tex->text().toStdString(),  // 1.: shm
        ui->c1o3Tex->text().toStdString(),  // 2.: node2gps
        ui->c1o4Tex->text().toStdString()   // 3.: city
    };

    processes::start_smart_city(options_smart_city);
    std::this_thread::sleep_for(std::chrono::seconds(7));

    const std::vector<std::string> options_traffic {
        ui->c2o1Tex->text().toStdString(),              // 0.: port
        ui->c2o2Tex->text().toStdString(),              // 1.: shm
        ui->c2o3Tex->text().toStdString(),              // 2.: nrcars
        ui->c3o2Tex->text().toStdString(),              // 3.: minutes
        ui->c2o4Tex->text().toStdString(),              // 4.: catchdist
        ui->traffictCmbox->currentText().toStdString()  // 5.: traffict
    };

    processes::start_traffic(options_traffic);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    const std::vector<std::string> options_samplemyshmclient {
        ui->c3o1Tex->text().toStdString(),  // 0.: port
        ui->c3o2Tex->text().toStdString(),  // 1.: minutes
        ui->c3o3Tex->text().toStdString(),  // 2.: shm
        ui->c3o4Tex->text().toStdString()   // 3.: team
    };

    processes::start_samplemyshmclient(options_samplemyshmclient);
    std::this_thread::sleep_for(std::chrono::seconds(5));

    const std::vector<std::string> options_java_gui_map {
        ui->c4o1Tex->text().toStdString()   // 0.: node2gps
    };

    processes::start_map_gui(options_java_gui_map);

    ui->startSimBtn->setEnabled(false);
}
