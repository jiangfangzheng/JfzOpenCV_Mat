#include <QCoreApplication>

#include<opencv2/opencv.hpp> // OpenCV2
#include"opencv/cv.h"        // OpenCV1
#include"opencv/cxcore.h"
#include"opencv/highgui.h"
using namespace cv;
using namespace std;

// 异想家自用的方便函数
void show(string name, Mat img, const char* style = "csv")
{
    cout << name << " = " << endl << " " << format(img,style) << endl << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // OpenCV2代码测试
    Mat image=imread("poi.png");         // 载入图片
    namedWindow("OpenCV2代码测试");       // 创建窗口
    imshow("OpenCV2代码测试",image);      // 显示图像
    imwrite("FuckPOI2.png",image);       // 保存图像

    // OpenCV2 Mat矩阵学习

    // 【1、Mat的复制与传递】
    // 以下代码中的所有Mat对象最终都指向同一个数据矩阵，通过任何一个对象所做的改变也会影响其它对象
    Mat A, C;                                   // 只创建信息头
    A = imread("poi.png", CV_LOAD_IMAGE_COLOR); // 为矩阵开辟内存
    Mat B(A);                                   // 拷贝构造函数
    C = A;                                      // 赋值运算符
    Mat D(A, Rect(10, 10, 100, 100) );          // ROI是某个矩形
    // 复制矩阵本身，使用函数clone()或copyTo()
    Mat E = A.clone();
    Mat F;
    A.copyTo(F);                                // 改变E、F不会影响A

    // 【2、Mat的创建】
    // 1、使用Mat()构造函数
    Mat G(2,2, CV_8UC3, Scalar(0,0,255));       // 行数、列数、存储元素的数据类型及通道数、颜色数值
    cout << "G = " << endl << " " << G << endl << endl;
    // 2、为已存在IplImage指针创建信息头
    IplImage* img = cvLoadImage("poi.png", 1);
    Mat MatImg(img);                            // 转换IplImage*到Mat
    // 3、使用Create()函数
    Mat H;                                      // 这个创建方法不能为矩阵设初值
    H.create(4,4, CV_8UC3);
    cout << "H = "<< endl << " " << H << endl << endl;
    // 4、用Matlab式的初始化方式
    // matlab初始化有zeros()、ones()、eye()
    Mat I = Mat::eye( 4, 4, CV_64F);
    cout << "I = "<< endl << " " << I << endl << endl;
    Mat J = Mat::zeros( 4, 4, CV_32F);
    cout << "J = "<< endl << " " << J << endl << endl;
    Mat K = Mat::ones( 4, 4, CV_8UC1);
    cout << "K = "<< endl << " " << K << endl << endl;
    // 5、用逗号分隔的初始化方式
    Mat L = (Mat_<double>(3,3) << 1.234, -3.223, 0, -4.324, 5.544, -1, 0, -1, 0);
    cout << "L = " << endl << " " << L << endl << endl;

    // 【3、Mat的格式化打印】
    // 1、用randu()来对一个矩阵使用随机数填充，需要指定随机数的上界和下界
    Mat M = Mat(3, 2, CV_8UC3);
    randu(M, Scalar::all(0), Scalar::all(255));
    // 2、OpenCV默认、逗号、C语言、python风格
    cout << "M(OpenCV默认风格) = " << endl << " " << M << endl << endl;
    cout << "M(逗号分隔风格) = " << endl << " " << format(M,"csv") << endl << endl;
    cout << "M(C语言风格) = " << endl << " " << format(M,"C") << endl << endl;
    show("M",M,"python");
    // 3、输出2维、3维、向量点
    Point2f N(5, 1);
    cout << "Point(2D) = " << endl << N << endl << endl;  // 2维点
    Point3f O(2, 6, 7);
    cout << "Point(3D) = " << endl << O << endl << endl;  // 3维点
    vector<float> P;
    P.push_back((float)CV_PI);
    P.push_back(2);
    P.push_back(3.01f);
    cout << "Mat的vector = " << endl << Mat(P) << endl << endl;   // 基于cv::Mat的std::vector
    vector<Point2f> Q(20);
    for (size_t E = 0; E < Q.size(); E++)  Q[E] = Point2f((float)(E * 5), (float)(E % 7));
    cout << "std的vector = " << endl << Q << endl << endl;        // std::vector点

    return a.exec();
}
