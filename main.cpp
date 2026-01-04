#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QPainter>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Aerial Assaults Your Internet");
    window.resize(800, 500);

    // Background troop[er
    window.setStyleSheet(
        "QWidget {"
        "background-image: url(./resources/background.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "}"
    );

    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    // Big banner
    QLabel* banner = new QLabel;
    QPixmap bannerImg("./resources/banner.png");
    banner->setPixmap(bannerImg.scaledToHeight(50, Qt::SmoothTransformation));
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("background: transparent;");

    // IP Input
    QLineEdit* ipInput = new QLineEdit;
    ipInput->setPlaceholderText("Enter IP");
    ipInput->setStyleSheet("background: white; color: black;");
    ipInput->setMaximumWidth(300);

    // Port Input
    QLineEdit* portInput = new QLineEdit;
    portInput->setPlaceholderText("Enter Port");
    portInput->setStyleSheet("background: white; color: black;");
    portInput->setMaximumWidth(300);

    // Put on same row
    QHBoxLayout* inputRow = new QHBoxLayout;
    inputRow->addStretch();
    inputRow->addWidget(ipInput);
    inputRow->addSpacing(40);
    inputRow->addWidget(portInput);
    inputRow->addStretch();
    inputRow->addWidget(ipInput, 0, Qt::AlignLeft);

    // Method box
    QComboBox* comboBox = new QComboBox();
    QStringList items = {"SYN Flood", "HTTP Flood", "UDP Amp", "IP Fragmentation", "Slowloris"};
    comboBox->addItems(items);
    comboBox->setStyleSheet("background: white; color: black;");

    // Run button
    QPushButton* startButton = new QPushButton("       Start       ");
    startButton->setStyleSheet("background: white; color: black;");
    startButton->setMaximumWidth(200);

    // Stop button
    QPushButton* stopButton = new QPushButton("       Stop       ");
    stopButton->setStyleSheet("background: white; color: black;");
    stopButton->setMaximumWidth(200);

    // Put on same row
    QHBoxLayout* buttonRow = new QHBoxLayout;
    buttonRow->addStretch();
    buttonRow->addWidget(startButton);
    buttonRow->addSpacing(80);
    buttonRow->addWidget(stopButton);
    buttonRow->addStretch();

    QObject::connect(startButton, &QPushButton::clicked, [&]() {
        qDebug("Starting super mega DDOS on %s at port %s", qPrintable(ipInput->text()), qPrintable(portInput->text()));
    });

    QObject::connect(stopButton, &QPushButton::clicked, [&]() {
        qDebug("Stopping super mega DDOS");
    });

    layout->addWidget(banner);
    layout->addStretch();
    layout->addLayout(inputRow);
    layout->addWidget(comboBox);
    layout->addLayout(buttonRow);
    layout->addStretch();

    window.show();
    return app.exec();
}
