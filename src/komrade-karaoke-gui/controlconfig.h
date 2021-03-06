#ifndef CONTROLCONFIG_H
#define CONTROLCONFIG_H

#include <QWidget>
#include "midiinmanager.h"

namespace Ui {
class ControlConfig;
}

class ControlConfig : public QWidget
{
    Q_OBJECT

public:
    explicit ControlConfig(MidiInManager* midiInManager, QWidget *parent = nullptr);
    ~ControlConfig();

    QByteArray playMidiControl() const;
    QByteArray clearMidiControl() const;
    QByteArray queueMidiControl() const;
    QByteArray volumeControl() const;

    void setPlayMidiControl(const QByteArray &playMidiControl);
    void setClearMidiControl(const QByteArray &clearMidiControl);
    void setQueueMidiControl(const QByteArray &queueMidiControl);
    void setVolumeControl(const QByteArray &volumeControl);

public slots:
    void loadSettings();
    void saveSettings();

private slots:
    void on_pb_playEdit_clicked();

    void on_pb_cycleEdit_clicked();

    void on_pb_clearEdit_clicked();

    void on_pb_volumeControl_clicked();

private:
    Ui::ControlConfig *ui;

    MidiInManager* m_midiInManager;

    QByteArray m_playMidiControl;
    QByteArray m_clearMidiControl;
    QByteArray m_queueMidiControl;
    QByteArray m_volumeControl;
};

#endif // CONTROLCONFIG_H
