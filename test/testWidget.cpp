#ifndef BOOST_TEST_DYN_LINK
    #define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE "test"
#define BOOST_AUTO_TEST_MAIN

#include "../src/Vizkit3DWidget.hpp"
#include "../src/QtThreadedWidget.hpp"
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(vizkit3d_test)

/** Test of the changeCameraView*/
BOOST_AUTO_TEST_CASE(changeCameraView_test)
{
    std::cout << "Testing changeCameraView method" << std::endl;

    QtThreadedWidget<vizkit3d::Vizkit3DWidget> app;
    app.start();
    std::cout << "Close the visualization window to abort this test." << std::endl;
    vizkit3d::Vizkit3DWidget *widget = dynamic_cast<vizkit3d::Vizkit3DWidget*>(app.getWidget());
    assert(widget);
    for( int i=0; i<30000 && app.isRunning(); i++ )
    {
        double r = i/1000.0;
        double s = r/10;
        widget->setCameraEye(cos(r)*s, sin(r)*s, 0);
        usleep( 500 );
    }

    for( int i=0; i<30000 && app.isRunning(); i++ )
    {
        double r = i/1000.0;
        double s = r/10;
        widget->setCameraLookAt(cos(r)*s, sin(r)*s, 0);
        usleep( 500 );
    }
}

BOOST_AUTO_TEST_SUITE_END();
