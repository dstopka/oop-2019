#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);

    auto unlockedState = new QState(stateMachine);
    auto lockedState = new QState(stateMachine);

    auto historyState = new QHistoryState(unlockedState);

    auto startupState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto saveState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);

    unlockedState->assignProperty(ui->pbOpen, "enabled", true);
    unlockedState->assignProperty(ui->pbSave, "enabled", true);
    unlockedState->assignProperty(ui->teText, "enabled", true);
    unlockedState->assignProperty(ui->pbToggle, "text", "Lock");

    startupState->assignProperty(ui->pbOpen, "enabled", true);
    startupState->assignProperty(ui->pbSave, "enabled", false);
    startupState->assignProperty(ui->teText, "enabled", false);
    startupState->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    lockedState->assignProperty(ui->pbOpen, "enabled", false);
    lockedState->assignProperty(ui->pbSave, "enabled", false);
    lockedState->assignProperty(ui->teText, "enabled", false);
    lockedState->assignProperty(ui->pbToggle, "text", "Unlock");

    errorState->assignProperty(ui->pbOpen, "enabled", true);
    errorState->assignProperty(ui->pbSave, "enabled", false);
    errorState->assignProperty(ui->teText, "enabled", false);
    errorState->assignProperty(ui->teText, "placeholderText", "Error occured. Open file to start editing...");

    viewState->assignProperty(ui->pbOpen, "enabled", true);
    viewState->assignProperty(ui->pbSave, "enabled", false);
    viewState->assignProperty(ui->teText, "enabled", true);

    editState->assignProperty(ui->pbOpen, "enabled", false);
    editState->assignProperty(ui->pbSave, "enabled", true);
    editState->assignProperty(ui->teText, "enabled", true);

    unlockedState->addTransition(ui->pbToggle, SIGNAL(clicked(bool)), lockedState);
    lockedState->addTransition(ui->pbToggle,SIGNAL(clicked(bool)), historyState);
    startupState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    openState->addTransition(this, SIGNAL(error()), errorState);
    errorState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    openState->addTransition(this, SIGNAL(opened()), viewState);
    viewState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    viewState->addTransition(ui->teText, SIGNAL(textChanged()), editState);
    editState->addTransition(ui->pbSave, SIGNAL(clicked(bool)), saveState);
    saveState->addTransition(this, SIGNAL(error()), errorState);
    saveState->addTransition(this, SIGNAL(saved()), viewState);

    // TODO: Set initial state
    stateMachine->setInitialState(unlockedState);
    unlockedState->setInitialState(startupState);

    historyState->setDefaultState(startupState);

    connect(openState, SIGNAL(entered()), SLOT(open()));
    connect(saveState, SIGNAL(entered()), SLOT(save()));

    // TODO: Start state machine
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    auto dialogFile = new QFileDialog();
    QString fileName = dialogFile->getOpenFileName(this,tr("Open File"), "",
                                                   tr("All Files (*)"));
    this->fileName = fileName;
    QFile file(this->fileName);
    if(!file.open(QIODevice::ReadOnly))
        emit error();
    QTextStream in(&file);
    ui->teText->setText(in.readAll());
    file.close();
    emit opened();
}

void MainWindow::save()
{
    QFile file(this->fileName);
    if (!file.open(QIODevice::WriteOnly))
        emit error();
    QTextStream out(&file);
    out << ui->teText->toPlainText();
    file.close();
    emit saved();
}

void MainWindow::log()
{
    qDebug() << "inside log() foo...";
    emit done();
}
