#ifndef FORMDIALOG_H
#define FORMDIALOG_H

#include <QDialog>
#include <QScopedPointer>

class ExcelBase;
class plu;

#define cmdUPDATE       'U'     //为更新数据请求
#define cmdDOWNLOAD     'D'     //为下载数据请求
#define cmdFLOWDATA     'F'     //为请求收款机流水数据
#define cmdANSWER       'A'     //为对host的应答命令
#define cmdGRAPHIC      'G'     //为下载图片
#define cmdCLEAR        'C'     //清除报表
#define cmdINIT         'I'     //收款机初始化
#define cmdSERVER       'S'     //设置收款机的服务器地址
#define cmdPASSWORD     'W'     //设置收款员密码

namespace Ui {
class formDialog;
}

class formDialog : public QDialog
{
    Q_OBJECT

public:
    explicit formDialog(QWidget *parent = 0);
    ~formDialog();

private:
    Ui::formDialog *ui;

    QScopedPointer<ExcelBase> m_xls;
    QList< QList<QVariant> > m_datas;

    plu *PluType;

    int itemindex;
    int senditemmax;
    char recvbuf[1024];
    char sendbuf[1024];

    void createdata(int type);

signals:
    void unconnecthost();
    void connecthost();
    void recvdata(char *buf, int len);
    void senddata(char *buf, int len);

private slots:
    void recvdataok(int sizelen);
    void tcpstate(int type);
    void on_openfile_clicked();
    void on_update_clicked();
};

#endif // FORMDIALOG_H
