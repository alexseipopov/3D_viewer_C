#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
//ui->scale_slider->setSliderPosition(50);
//ui->scale_lineedit->setText("1");

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_OpenobjFile_clicked() {
  //    exit_st st ={0};
  //   st = s21_parse("test.obj");
}

void MainWindow::on_EditFile_clicked()
{
     QString str = QFileDialog::getOpenFileName(this,"Open file","/Users/", "*.obj");
     std::string v_str = str.toStdString();
       const char* strch = v_str.c_str();
       auto s = const_cast<char*>(strch);

     exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
     s21_parse(st, s);
     setting_to_center(st);
     double scale = normalize(st);
     set_scale(st, scale);
     ui->widget->res= st;
}


void MainWindow::on_Draw_clicked()
{
      ui->widget->update();
}

