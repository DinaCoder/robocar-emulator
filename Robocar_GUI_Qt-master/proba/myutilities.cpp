#include "myutilities.h"

#include <QMessageBox>
#include <QDebug>
#include <QProcess>
#include <QStringList>

#include <vector>
#include <string>

void processes::start_smart_city (const std::vector<std::string>& v)
{
    QString program {"/home/nor/robocar/robocar-emulator/justine/rcemu/src/smartcity"};
    QStringList arguments {};

    std::string arg_osm {
        std::string {R"(--osm=)"}
        + v[0]
    };

    arguments << arg_osm.c_str();

    std::string arg_city {
        std::string {R"(--city=)"}
        + v[1]
    };

    arguments << arg_city.c_str();

    std::string arg_shm {
        std::string {R"(--shm=)"}
        + v[2]
    };

    arguments << arg_shm.c_str();

    std::string arg_node {
        std::string {R"(--node2gps=)"}
        + v[3]
    };

    arguments << arg_node.c_str();

    QProcess p {};
    p.startDetached(program, arguments);
    p.waitForFinished();
}

void processes::start_traffic (const std::vector<std::string>& v)
{
    QString program {"/home/nor/robocar/robocar-emulator/justine/rcemu/src/traffic"};
    QStringList arguments {};

    std::string arg_por {
        std::string {R"(--port=)"}
        + v[0]
    };
    arguments << arg_por.c_str();

    std::string arg_shm {
        std::string {R"(--shm=)"}
        + v[1]
    };
    arguments << arg_shm.c_str();

    std::string arg_nrcars {
        std::string {R"(--nrcars=)"}
        + v[2]
    };
    arguments << arg_nrcars.c_str();

    std::string arg_minutes {
        std::string {R"(--minutes=)"}
        + v[3]
    };
    arguments << arg_minutes.c_str();

    std::string arg_catchdist {
        std::string {R"(--catchdist=)"}
        + v[4]
    };
    //arguments << arg_catchdist.c_str();

    std::string arg_traffict {
        std::string {R"(--traffict=)"}
        + v[5]
    };
    arguments << arg_traffict.c_str();

    qDebug() << arguments;

    QProcess p {};
    p.startDetached(program, arguments);
    p.waitForFinished();
}

void processes::start_samplemyshmclient (const std::vector<std::string>& v)
{
    QString program_1 {R"(sleep 1; echo "<init Norbi 200 g>"; sleep 1)|telnet localhost 10007)"}; // Port number attribute should be built in here, too
    QString program_2 {"/home/nor/robocar/robocar-emulator/justine/rcemu/src/samplemyshmclient"};
    QStringList arguments {};

    std::string arg_por {
        std::string {R"(--port=)"}
        + v[0]
    };
    arguments << arg_por.c_str();

    std::string arg_min {
        std::string {R"(int minutes {)"}
        + v[1] + R"(})"
    };
    arguments << arg_min.c_str();

    std::string arg_shm {
        std::string {R"(--shm=)"}
        + v[2]
    };
    arguments << arg_shm.c_str();

    std::string arg_team {
        std::string {R"(--team=)"}
        + v[3]
    };
    arguments << arg_team.c_str();

    QProcess p_1 {};
    p_1.startDetached(program_1);
    p_1.waitForFinished();

    QProcess p_2 {};
    p_2.startDetached(program_2, arguments);
    p_2.waitForFinished();
}

void processes::start_map_gui (const std::vector<std::string>& v)
{
    QString program {"java"};
    QStringList arguments {};

    arguments << "-jar";
    arguments << "/home/nor/robocar/robocar-emulator/justine/rcwin/target/site/justine-rcwin-0.0.16-jar-with-dependencies.jar";

    std::string arg_node {v[0]};
    arguments << arg_node.c_str();

    QProcess p {};
    p.startDetached(program, arguments);
    p.waitForFinished();
}
