#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSalvar_triggered();

    void on_actionSalvar_Como_triggered();

    void on_actionAbrir_triggered();

    void on_actionNovo_Ctrl_N_triggered();

    void on_actionDesfazer_triggered();

    void on_actionRefazer_Ctrl_Y_triggered();

    void on_actionCopiar_Ctrl_C_triggered();

    void on_actionColar_Ctrl_V_triggered();

    void on_actionRecortar_Ctrl_X_triggered();

    void on_actionFonte_triggered();

    void on_actionCor_triggered();

    void on_actionCor_de_Fundo_triggered();

private:
    Ui::MainWindow *ui;

    QString local;
};
#endif // MAINWINDOW_H
