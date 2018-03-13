/********************************************************************************
** Form generated from reading UI file 'highscores.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORES_H
#define UI_HIGHSCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScores
{
public:
    QLabel *label;
    QPushButton *reset;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *Score1_1;
    QLabel *Score1_2;
    QLabel *Score1_3;
    QLabel *Score1_4;
    QLabel *Score1_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLabel *Score2_1;
    QLabel *Score2_2;
    QLabel *Score2_3;
    QLabel *Score2_4;
    QLabel *Score2_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLabel *Score3_1;
    QLabel *Score3_2;
    QLabel *Score3_3;
    QLabel *Score3_4;
    QLabel *Score3_5;

    void setupUi(QWidget *HighScores)
    {
        if (HighScores->objectName().isEmpty())
            HighScores->setObjectName(QStringLiteral("HighScores"));
        HighScores->resize(400, 300);
        label = new QLabel(HighScores);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 71, 20));
        reset = new QPushButton(HighScores);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(130, 250, 75, 23));
        horizontalLayoutWidget = new QWidget(HighScores);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 80, 221, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        Score1_1 = new QLabel(horizontalLayoutWidget);
        Score1_1->setObjectName(QStringLiteral("Score1_1"));

        verticalLayout->addWidget(Score1_1);

        Score1_2 = new QLabel(horizontalLayoutWidget);
        Score1_2->setObjectName(QStringLiteral("Score1_2"));

        verticalLayout->addWidget(Score1_2);

        Score1_3 = new QLabel(horizontalLayoutWidget);
        Score1_3->setObjectName(QStringLiteral("Score1_3"));

        verticalLayout->addWidget(Score1_3);

        Score1_4 = new QLabel(horizontalLayoutWidget);
        Score1_4->setObjectName(QStringLiteral("Score1_4"));

        verticalLayout->addWidget(Score1_4);

        Score1_5 = new QLabel(horizontalLayoutWidget);
        Score1_5->setObjectName(QStringLiteral("Score1_5"));

        verticalLayout->addWidget(Score1_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        Score2_1 = new QLabel(horizontalLayoutWidget);
        Score2_1->setObjectName(QStringLiteral("Score2_1"));

        verticalLayout_3->addWidget(Score2_1);

        Score2_2 = new QLabel(horizontalLayoutWidget);
        Score2_2->setObjectName(QStringLiteral("Score2_2"));

        verticalLayout_3->addWidget(Score2_2);

        Score2_3 = new QLabel(horizontalLayoutWidget);
        Score2_3->setObjectName(QStringLiteral("Score2_3"));

        verticalLayout_3->addWidget(Score2_3);

        Score2_4 = new QLabel(horizontalLayoutWidget);
        Score2_4->setObjectName(QStringLiteral("Score2_4"));

        verticalLayout_3->addWidget(Score2_4);

        Score2_5 = new QLabel(horizontalLayoutWidget);
        Score2_5->setObjectName(QStringLiteral("Score2_5"));

        verticalLayout_3->addWidget(Score2_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        Score3_1 = new QLabel(horizontalLayoutWidget);
        Score3_1->setObjectName(QStringLiteral("Score3_1"));

        verticalLayout_4->addWidget(Score3_1);

        Score3_2 = new QLabel(horizontalLayoutWidget);
        Score3_2->setObjectName(QStringLiteral("Score3_2"));

        verticalLayout_4->addWidget(Score3_2);

        Score3_3 = new QLabel(horizontalLayoutWidget);
        Score3_3->setObjectName(QStringLiteral("Score3_3"));

        verticalLayout_4->addWidget(Score3_3);

        Score3_4 = new QLabel(horizontalLayoutWidget);
        Score3_4->setObjectName(QStringLiteral("Score3_4"));

        verticalLayout_4->addWidget(Score3_4);

        Score3_5 = new QLabel(horizontalLayoutWidget);
        Score3_5->setObjectName(QStringLiteral("Score3_5"));

        verticalLayout_4->addWidget(Score3_5);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(HighScores);

        QMetaObject::connectSlotsByName(HighScores);
    } // setupUi

    void retranslateUi(QWidget *HighScores)
    {
        HighScores->setWindowTitle(QApplication::translate("HighScores", "High Scores", nullptr));
        label->setText(QApplication::translate("HighScores", "High Scores:", nullptr));
        reset->setText(QApplication::translate("HighScores", "Reset", nullptr));
        label_10->setText(QString());
        label_2->setText(QApplication::translate("HighScores", "1", nullptr));
        label_3->setText(QApplication::translate("HighScores", "2", nullptr));
        label_4->setText(QApplication::translate("HighScores", "3", nullptr));
        label_5->setText(QApplication::translate("HighScores", "4", nullptr));
        label_6->setText(QApplication::translate("HighScores", "5", nullptr));
        label_7->setText(QApplication::translate("HighScores", "Easy", nullptr));
        Score1_1->setText(QApplication::translate("HighScores", "0", nullptr));
        Score1_2->setText(QApplication::translate("HighScores", "0", nullptr));
        Score1_3->setText(QApplication::translate("HighScores", "0", nullptr));
        Score1_4->setText(QApplication::translate("HighScores", "0", nullptr));
        Score1_5->setText(QApplication::translate("HighScores", "0", nullptr));
        label_8->setText(QApplication::translate("HighScores", "Medium", nullptr));
        Score2_1->setText(QApplication::translate("HighScores", "0", nullptr));
        Score2_2->setText(QApplication::translate("HighScores", "0", nullptr));
        Score2_3->setText(QApplication::translate("HighScores", "0", nullptr));
        Score2_4->setText(QApplication::translate("HighScores", "0", nullptr));
        Score2_5->setText(QApplication::translate("HighScores", "0", nullptr));
        label_9->setText(QApplication::translate("HighScores", "Hard", nullptr));
        Score3_1->setText(QApplication::translate("HighScores", "0", nullptr));
        Score3_2->setText(QApplication::translate("HighScores", "0", nullptr));
        Score3_3->setText(QApplication::translate("HighScores", "0", nullptr));
        Score3_4->setText(QApplication::translate("HighScores", "0", nullptr));
        Score3_5->setText(QApplication::translate("HighScores", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HighScores: public Ui_HighScores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORES_H
