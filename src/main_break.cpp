
#include <vizkit3d/Vizkit3DWidget.hpp>
#include <vizkit3d/QVizkitMainWindow.hpp>
#include <vizkit3d/RigidBodyStateVisualization.hpp>
#include <vizkit3d/TrajectoryVisualization.hpp>
#include <QApplication>
#include <iostream>

int main(int argc, char** argv)
{
    QString stim300_stl = argv[1];
    std::cout<<"NAME: "<<stim300_stl.toLocal8Bit().constData()<<"\n";

    /** QT Main application **/
    QApplication app(argc, argv);
    vizkit3d::QVizkitMainWindow window;

    /** Widget. The Widget load the vizkit3d  plugin **/
    vizkit3d::Vizkit3DWidget *widget = window.getVizkitWidget();
    QStringList *available_widgets = widget->getAvailablePlugins();
    widget->setTransformation("world_osg","imu_frame",QVector3D(1,1,1),QQuaternion());

    /** List of available widgets according to the env variable VIZKIT_PLUGIN_RUBY_PATH **/
    std::cout<<"Available widget are: "<< available_widgets->size()<<"\n";
    for (int i = 0; i < available_widgets->size(); ++i)
         std::cout << available_widgets->at(i).toLocal8Bit().constData() << std::endl;

    /** Load the STIM300 visualization as RBS **/
    //vizkit3d::RigidBodyStateVisualization *imu_stim300 = new vizkit3d::RigidBodyStateVisualization();
    vizkit3d::RigidBodyStateVisualization *imu_stim300 = dynamic_cast<vizkit3d::RigidBodyStateVisualization*>(widget->loadPlugin("base", "RigidBodyStateVisualization"));

    /*imu_stim300->setPluginName("imu_stim300");
    if(!stim300_stl.isEmpty())
    {
      imu_stim300->loadModel(stim300_stl);
    }
    */

    //widget.addPlugin(dynamic_cast<QObject*>(imu_stim300));
    //widget.setPluginDataFrame("imu_frame", imu_stim300);


    /** Load the Grid visualization **/
    widget->loadPlugin("vizkit3d", "GridVisualization");

    window.show();
    app.exec();

    return 0;
}
