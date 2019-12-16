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

    // TODO: Create state machine
    auto stateMachine = new QStateMachine(this);

    // TODO: Create states
    auto unlockedState = new QState(stateMachine);
    auto lockedState = new QState(stateMachine);

    auto startupState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto saveState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);
/*
    auto greenState = new QState(stateMachine);
    auto yellowState = new QState(stateMachine);
    auto redState = new QState(stateMachine);

    auto logState = new QState(stateMachine);

    // TODO: Set appropriate 'assignProperty'
    greenState->assignProperty(ui->pbToggle,"text","GREEN");
    redState->assignProperty(ui->pbToggle,"text","RED");
    yellowState->assignProperty(ui->pbToggle,"text","YELLOW");

    // TODO: Set state transitions including this class events and slots
    greenState->addTransition(ui->pbToggle,SIGNAL(clicked()),redState);
    redState->addTransition(ui->pbToggle,SIGNAL(clicked()),yellowState);
    yellowState->addTransition(ui->pbToggle,SIGNAL(clicked()),logState);
    //TODO add transition
    logState->addTransition(this,SIGNAL(done()),greenState);
    connect(logState,SIGNAL(entered()),SLOT(log()));
*/
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
    lockedState->addTransition(ui->pbToggle, SIGNAL(clicked(bool)), unlockedState);
    startupState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    openState->addTransition(this, SIGNAL(error()), errorState);
    errorState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    openState->addTransition(this, SIGNAL(opened()), viewState);
    viewState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    viewState->addTransition(ui->teText, SIGNAL(textChanged()), editState);
    editState->addTransition(ui->pbSave, SIGNAL(clicked(bool)), saveState);
    editState->addTransition(this, SIGNAL(error()), errorState);

    // TODO: Set initial state
    stateMachine->setInitialState(unlockedState);
    unlockedState->setInitialState(startupState);

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
    // TODO: Show file dialog
    auto dialogFile = new QFileDialog();
    dialogFile->open();
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    QString fileName = dialogFile->getSaveFileName(this,"All Files (*)");
    this->fileName = fileName;
    QFile file(this->fileName);
    qDebug() << this->fileName;
    if(!file.open(stderr, QIODevice::ReadOnly))
        emit error();

    // TODO: Set text and emit 'opened' if suceeded
    QTextStream in(&file);
    ui->teText->setText(in.readAll());
    emit opened();
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
}

void MainWindow::log()
{
    qDebug() << "inside log() foo...";
    emit done();
}
