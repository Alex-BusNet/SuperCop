/********************************************************************************
** Form generated from reading UI file 'controls.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLS_H
#define UI_CONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controls
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QWidget *Controls)
    {
        if (Controls->objectName().isEmpty())
            Controls->setObjectName(QStringLiteral("Controls"));
        Controls->resize(400, 300);
        label = new QLabel(Controls);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 158, 13));
        label->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(Controls);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 80, 231, 171));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_13 = new QLabel(horizontalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_3->addWidget(label_13);

        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_3->addWidget(label_14);

        label_15 = new QLabel(horizontalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_3->addWidget(label_15);

        label_16 = new QLabel(horizontalLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_3->addWidget(label_16);

        label_17 = new QLabel(horizontalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_3->addWidget(label_17);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(Controls);

        QMetaObject::connectSlotsByName(Controls);
    } // setupUi

    void retranslateUi(QWidget *Controls)
    {
        Controls->setWindowTitle(QApplication::translate("Controls", "Controls", nullptr));
        label->setText(QApplication::translate("Controls", "Controls", nullptr));
        label_6->setText(QApplication::translate("Controls", "Action:", nullptr));
        label_9->setText(QApplication::translate("Controls", "Move Right", nullptr));
        label_7->setText(QApplication::translate("Controls", "Move Left", nullptr));
        label_8->setText(QApplication::translate("Controls", "Jump", nullptr));
        label_10->setText(QApplication::translate("Controls", "Roll", nullptr));
        label_11->setText(QApplication::translate("Controls", "Pause", nullptr));
        label_2->setText(QApplication::translate("Controls", "Key", nullptr));
        label_13->setText(QApplication::translate("Controls", "Right Arrow", nullptr));
        label_14->setText(QApplication::translate("Controls", "Left Arrow", nullptr));
        label_15->setText(QApplication::translate("Controls", "Up Arrow ", nullptr));
        label_16->setText(QApplication::translate("Controls", "Down Arrow", nullptr));
        label_17->setText(QApplication::translate("Controls", "Escape, P", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Controls: public Ui_Controls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLS_H
