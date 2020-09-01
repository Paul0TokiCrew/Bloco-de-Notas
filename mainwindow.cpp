#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QColor>
#include <QColorDialog>
#include <QFont>
#include <QFontDialog>
#include <QDir>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionSalvar_triggered() {
    QFile file(local);
     if(!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, "Erro", "Arquivo não pôde ser salvo");
         return;
     }
     QTextStream output(&file);
     QString text = ui->textEdit->toPlainText();
     output << text;
     file.flush();
     file.close();
}

void MainWindow::on_actionSalvar_Como_triggered() {
    QString filter = "Arquivo de Texto (*.txt) ;; Todos os Arquivos (*.*)";
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar Como...", QDir::homePath(), filter);
    QFile file(fileName);
    local = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Erro", "Arquivo não pôde ser salvo");
        return;
    }
    QTextStream output(&file);
    QString text = ui->textEdit->toPlainText();
    output << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionAbrir_triggered() {
    QString filter = "Arquivo de Texto (*.txt) ;; Todos os Arquivos (*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir...", QDir::homePath(), filter);
    QFile file(fileName);
    local = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Erro", "Arquivo não pôde ser aberto");
        return;
    }
    QTextStream input(&file);
    QString text = input.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionNovo_Ctrl_N_triggered() {
    local = " ";
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

void MainWindow::on_actionDesfazer_triggered() {
    ui->textEdit->undo();
}

void MainWindow::on_actionRefazer_Ctrl_Y_triggered() {
    ui->textEdit->redo();
}

void MainWindow::on_actionCopiar_Ctrl_C_triggered() {
    ui->textEdit->copy();
}

void MainWindow::on_actionColar_Ctrl_V_triggered() {
    ui->textEdit->paste();
}

void MainWindow::on_actionRecortar_Ctrl_X_triggered() {
    ui->textEdit->cut();
}

void MainWindow::on_actionFonte_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
        ui->textEdit->setFont(font);
    else
        return;
}

void MainWindow::on_actionCor_triggered() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Escolha uma Cor");
    if(color.isValid())
        ui->textEdit->setTextColor(color);
}

void MainWindow::on_actionCor_de_Fundo_triggered() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Escolha uma Cor");
    if(color.isValid())
        ui->textEdit->setTextBackgroundColor(color);
}
