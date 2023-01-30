#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
ui->scale_slider->setSliderPosition(50);
ui->scale_line_edit->setText("1");
ui->x_move->setText("0");
ui->y_move->setText("0");
ui->z_move->setText("0");
ui->x_rotate->setText("0");
ui->y_rotate->setText("0");
ui->z_rotate->setText("0");
ui->x_move_slider->setSliderPosition(50);
ui->y_move_slider->setSliderPosition(50);
ui->z_move_slider->setSliderPosition(50);   // -50   0.5  0.01
ui->x_rotate_slider->setSliderPosition(50);
ui->y_rotate_slider->setSliderPosition(50);
ui->z_rotate_slider->setSliderPosition(50);

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_OpenobjFile_clicked() {
  //    exit_st st ={0};
  //   st = s21_parse("test.obj");
}

void MainWindow::on_EditFile_clicked()
{
     QString str = QFileDialog::getOpenFileName(this,"Open file","/Users/cherylls/Desktop/3D_viever/", "*.obj");
     ui->filepath->setText(str);
     std::string v_str = str.toStdString();
       const char* strch = v_str.c_str();
       auto s = const_cast<char*>(strch);

     exit_st *st = (exit_st *)calloc(1, sizeof(exit_st));
     s21_parse(st, s);
     setting_to_center(st);
     double scale = normalize(st);
     set_scale(st, scale);
     ui->widget->res= st;
      QString buf_line = QString::number(st->amount_struct_pol/2);
     ui->label_line ->setText(buf_line);
     buf_line = QString::number(st->amount_struct_ver/3);
     ui->label_vertex->setText(buf_line);
}


void MainWindow::on_Draw_clicked()
{
      ui->widget->update();
}


//void MainWindow::on_scale_slider_sliderMoved(int position)
//{
//   ui->widget->scale -=  ui->scale_slider->value() * 0.02;
//    ui->widget->update();

//}


void MainWindow::on_scale_slider_sliderReleased()
{
if (ui->widget->scale - ui->scale_slider->value() * 0.02 > 0) {
    ui->widget->scale  = 1 - ui->scale_slider->value() * 0.02 ;
} else {
     ui->widget->scale  = 1 + ui->scale_slider->value() * 0.02 ;
}

     ui->widget->update();

}


void MainWindow::on_scale_but_minus_clicked()
{
    ui->widget->scale = 1.1;
    ui->widget->update();
   //  ui->widget->scale = 1;
}


void MainWindow::on_scale_scale_plus_clicked()
{
    ui->widget->scale = 0.9;
    ui->widget->update();
    // ui->widget->scale = 1;
}


void MainWindow::on_scale_slider_valueChanged(int value)
{

//    if (ui->scale_slider->value() * 0.02 > 0) {
//        ui->widget->scale  = 1 - ui->scale_slider->value() * 0.02 ;
//    } else {
//         ui->widget->scale  = 1 + ui->scale_slider->value() * 0.02 ;
//    }

//         ui->widget->update();

}





void MainWindow::on_scale_line_edit_returnPressed()
{
    ui->widget->scale = ui->scale_line_edit->text().toDouble();
    ui->widget->update();
    ui->widget->scale = 1;
}


void MainWindow::on_x_rotate_returnPressed()
{
     ui->widget->scale = 1;
    double radian = ui->x_rotate->text().toDouble() * (M_PI / 180.0);
    rotation_x(radian,ui->widget->res);
    ui->widget->update();
}


void MainWindow::on_y_rotate_returnPressed()
{ ui->widget->scale = 1;
    double radian = ui->y_rotate->text().toDouble() * (M_PI / 180.0);
    rotation_y(radian,ui->widget->res);
    ui->widget->update();
}


void MainWindow::on_z_rotate_returnPressed()
{ ui->widget->scale = 1;
    double radian = ui->z_rotate->text().toDouble() * (M_PI / 180.0);
    rotation_z(radian,ui->widget->res);
    ui->widget->update();
}


void MainWindow::on_x_move_returnPressed()
{ ui->widget->scale = 1;
    double a = ui->y_move->text().toDouble() ;

     //double radian = ui->z_rotate->text().toDouble() * (M_PI / 180.0);
     s21_move(ui->widget->res,a*0.1,'x');
      ui->widget->update();
}


void MainWindow::on_y_move_returnPressed()
{ ui->widget->scale = 1;
    double a = ui->y_move->text().toDouble() ;
//    if (a > 1. ){
//        a = 1.;
//    }
//    if (a < -1.){
//        a = -1.;
//    }
    //double radian = ui->z_rotate->text().toDouble() * (M_PI / 180.0);
    s21_move(ui->widget->res,a*0.1,'y');
     ui->widget->update();
}


void MainWindow::on_z_move_returnPressed()
{ ui->widget->scale = 1;
    double a = ui->y_move->text().toDouble() ;
    if (a > 1 ){
        a = 1;
    }
    if (a < -1){
        a = -1;
    }
    s21_move(ui->widget->res,a*0.1,'z');
     ui->widget->update();
}


void MainWindow::on_backgroundcolor_clicked()
{
    ui->widget->background_color =
         QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

