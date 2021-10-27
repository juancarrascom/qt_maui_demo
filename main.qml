import QtQuick 2.12
import QtQuick.Window 2.12
import MicroAnalyzer 1.0
import MicroAnalyzer_Object 1.0
import MicroAnalyzer_Values 1.0


Window {
    width: 1440
    height: 1024
    visible: true
    title: qsTr("Micro Analyzer Demo")

        MaControl_Values {
            id: maControl_Values
        }

        MaControl_Object {
            id: maControl_Object
        }

        MaControl {
            id: maControl
        }

    Loader{
        id: mainLoader
        anchors.fill: parent
        source: "./UI/home_screen/home_screen.qml"
    }
}
