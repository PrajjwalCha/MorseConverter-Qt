#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString Eng_word = "",morse = "";
QMap<QChar, QString> morseMap ={

    {'a',".-"},
    {'b',"-..."},
    {'c',"-.-."},
    {'d',"-.."},
    {'e',"."},
    {'f',"..-."},
    {'g',"--."},
    {'h',"...."},
    {'i',".."},
    {'j',".---"},
    {'k',"-.-"},
    {'l',".-.."},
    {'m',"--"},
    {'n',"-."},
    {'o',"---"},
    {'p',".--."},
    {'q',"--.-"},
    {'r',".-."},
    {'s',"..."},
    {'t',"-"},
    {'u',"..-"},
    {'v',"...-"},
    {'w',".--"},
    {'x',"-..-"},
    {'y',"-.--"},
    {'z',"--.."},
    {'0',"-----"},
    {'1',".----"},
    {'2',"..---"},
    {'3',"...--"},
    {'4',"....-"},
    {'5',"....."},
    {'6',"-...."},
    {'7',"--..."},
    {'8',"---.."},
    {'9',"----."},
    {'.',".-.-.-"},
    {',',"--..--"},
    {'?',"..--.."},
    {'!',"-.-.--"}
};
QMap<QString,QChar> ReversemorseMap ={

    {".-",'a'},
    {"-...",'b'},
    {"-.-.",'c'},
    {"-..",'d'},
    {".",'e'},
    {"..-.",'f'},
    {"--.",'g'},
    {"....",'h'},
    {"..",'i'},
    {".---",'j'},
    {"-.-",'k'},
    {".-..",'l'},
    {"--",'m'},
    {"-.",'n'},
    {"---",'o'},
    {".--.",'p'},
    {"--.-",'q'},
    {".-.",'r'},
    {"...",'s'},
    {"-",'t'},
    {"..-",'u'},
    {"...-",'v'},
    {".--",'w'},
    {"-..-",'x'},
    {"-.--",'y'},
    {"--..",'z'},
    {"-----",'0'},
    {".----",'1'},
    {"..---",'2'},
    {"...--",'3'},
    {"....-",'4'},
    {".....",'5'},
    {"-....",'6'},
    {"--...",'7'},
    {"---..",'8'},
    {"----.",'9'},
    {".-.-.-",'.'},
    {"--..--",','},
    {"..--..",'?'},
    {"-.-.--",'!'}
};


QString morseconvert(QString Eng_word){
    QString Morse_code;
    for(int i = 0 ;i<Eng_word.length() ;i++){
        if(Eng_word[i] == ' '){
            Morse_code += '/';
        }
        else{
            Morse_code  += morseMap.value(Eng_word[i],"");
            Morse_code  += ' ';
        }

    }
    return Morse_code;
}
QString engconverter(QString morse) {
    QString eng_word, sample = "";
    for (int i = 0; i < morse.length(); i++) {
        if(morse[i] == ' '|| morse[i]== '/'){
            if(!sample.isEmpty()){
                QChar alphabet = ReversemorseMap.value(sample);
                eng_word += alphabet;
                sample = "";
            }
            if(morse[i] == ' '||morse[i] == '/'){
                eng_word +=' ';
            }


        }
        else{
            sample += morse[i];
        }

    }
    if(!sample.isEmpty()){
        QChar alphabet =  ReversemorseMap.value(sample);
        eng_word += alphabet;
    }

    return eng_word;
}



void MainWindow::on_change_clicked()
{
    Eng_word = ui->textEdit_EngWord->toPlainText();
    morse =ui->textEdit_morse->toPlainText();
    if(Eng_word.isEmpty()){
        ui->textEdit_EngWord->setText(engconverter(morse));
    }
    else {
        ui->textEdit_morse->setText(morseconvert(Eng_word));
    }

}

