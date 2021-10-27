import QtQuick 2.0
import QtGraphicalEffects 1.0
import MicroAnalyzer 1.0

Item {
    Rectangle {
        id:mainBackground
        anchors.fill: parent
        color: "#E5E5E5"
    }

    Rectangle {
        height : 88
        width: mainBackground.width
        id: top_rect
        anchors.top: mainBackground.top
        color: "#102027"
    }

    Image {
        id: edit_icon
        anchors {
            top: top_rect.top
            left: top_rect.left
            topMargin: 5
            leftMargin: 30
        }
        width: 181
        height: 78
        source: "qrc:/UI/Assets/edit_icon.png"

    }

    ColorOverlay {
        anchors.fill: edit_icon
        source: edit_icon
        color: "#FFFFFF"
    }

    Image {
        id: settings_icon
        anchors {
            top: top_rect.top
            right: top_rect.right
            topMargin: 20
            rightMargin: 30
        }
        width: 48
        height: 48
        source: "qrc:/UI/Assets/settings.png"
    }

    Image {
        id: recipe_icon
        anchors {
            top: top_rect.top
            right: settings_icon.left
            topMargin: 20
            rightMargin: 30
        }
        width: 48
        height: 48
        source: "qrc:/UI/Assets/shopping-list.png"
    }

    Rectangle {
        height: 88
        width: mainBackground.width
        id: title_rect
        anchors.top: top_rect.bottom
        color: "#37474F"
    }

    Image {
        id: connect_icon
        anchors {
            top: top_rect.bottom
            right: title_rect.right
            topMargin: 20
            rightMargin: 30
        }
        width: 48
        height: 48
        source: "qrc:/UI/Assets/link.png"
        MouseArea {
            anchors.fill: parent
            onClicked: maControl_Object.connectSensor()
        }
    }

    Text {
        id: device_title
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: top_rect.bottom
            topMargin: 20
        }
        font.pixelSize: 40
        font.bold: true
        color: "white"
        text: "MICRO-ANALYZER"
    }

    Rectangle {
        height: 848
        width: 387
        id: parametters_left
        anchors.left: mainBackground.left
        anchors.top: title_rect.bottom
        color: "#62717B"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                maControl_Object.readData()
            }
        }

    }

    Text {
        id: parametters_title
        anchors {
            horizontalCenter: parametters_left.horizontalCenter
            top: parametters_left.top
            topMargin: 30
        }

        font.pixelSize: 25
        font.bold: true
        color: "white"
        text: "SENSOR'S PARAMETERS"
    }

    Text {
        id: temperature_mv
        anchors {
            left: parametters_left.left
            top: parametters_title.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Temperature(mv)"
    }

    Text {
        id: temperature_mv_value
        anchors {
            right: parametters_left.right
            top: temperature_mv.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.temperaturemv
    }


    Text {
        id: temperature_degrees
        anchors {
            left: parametters_left.left
            top: temperature_mv_value.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Temperature(Degrees)"
    }

    Text {
        id: temperature_degrees_value
        anchors {
            right: parametters_left.right
            top: temperature_degrees.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.temperatureDegrees
    }
    Text {
        id: phase_mv
        anchors {
            left: parametters_left.left
            top: temperature_degrees_value.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Phase(mv)"
    }

    Text {
        id: phase_mv_value
        anchors {
            right: parametters_left.right
            top: phase_mv.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.phasemv

    }
    Text {
        id: phase_degrees
        anchors {
            left: parametters_left.left
            top: phase_mv_value.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Phase(Degrees)"
    }

    Text {
        id: phase_degrees_value
        anchors {
            right: parametters_left.right
            top: phase_degrees.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.phaseDegrees
    }

    Text {
        id: attenuation_mv
        anchors {
            left: parametters_left.left
            top: phase_degrees_value.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Attenuation(mv)"
    }

    Text {
        id: attenuation_mv_value
        anchors {
            right: parametters_left.right
            top: attenuation_mv.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.attenuationmv
    }
    Text {
        id: attenuation_db
        anchors {
            left: parametters_left.left
            top: attenuation_mv_value.bottom
            topMargin: 20
            leftMargin: 30
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: "Attenuation(dB)"
    }

    Text {
        id: attenuation_db_value
        anchors {
            right: parametters_left.right
            top: attenuation_db.bottom
            topMargin: 20
            rightMargin: 50
        }

        font.pixelSize: 15
        font.bold: true
        color: "white"
        text: maControl.sensorValues.attenuationdb
    }

    MaControl {
        sensorValues.onPhasemvChanged: {
            console.log("Estaaaa ha cmabiado")
        }
    }

}
