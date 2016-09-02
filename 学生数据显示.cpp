#include <iostream>
using namespace std;
typedef struct _Student { //学生数据
    string Student_num;        //学号
    string Student_name;      //姓名
    double score[10];   //成绩
    char Class[10];
    struct _Student *next;
} Student;
#define STUDENTADRESS "/Users/dawn/zpy/studentinformation.txt"

int main(int argc, char *argv[]) {
    Student x;
    FILE *fp;
    int filesize,count;
    if ((fp = fopen(STUDENTADRESS, "rb")) == NULL) {
        cout << "文件打开失败" << endl;
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    count = filesize / sizeof(Student);
    cout << "结构体数量" <<count << "文件大小" << filesize << endl;
    rewind(fp);
    for (int i = 0; i < count; i++) {
        fread(&x, sizeof(Student), 1, fp);
        cout << x.Student_name << endl;
        cout << x.Student_num << endl;
        cout << "语文:" << x.score[0] << endl;
        cout << "数学:" << x.score[1] << endl;
        cout << "英语:" << x.score[2] << endl;
    }
    fclose(fp);
}